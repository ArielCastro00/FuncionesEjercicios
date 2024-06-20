#include <iostream>

using namespace std;

float calcularSueldoNeto(float sueldoBruto, int nivelEmpleado) {
  // Se valida el nivel de empleado, en caso de ingresar un valor invalido retorna mensaje de error
  if (nivelEmpleado < 0 || nivelEmpleado > 3) {
    cout << "Error: Nivel de empleado no valido." << endl;
    return -1;
  }

  // Se calcula los descuentos de ley
  float descuentoLeyISSS = sueldoBruto * 0.031;
  float descuentoGanancias = sueldoBruto * 0.093;

  // Se calcula el descuento por seguro (solo valido para los niveles 2 y 3)
  float descuentoSeguro = 0;
  if (nivelEmpleado == 2 || nivelEmpleado == 3) {
    descuentoSeguro = sueldoBruto * 0.114;
  }

  // Se calcula el bono por el esfuerzo
  float bono;
  switch (nivelEmpleado) {
    case 0: // En el nivel 0 se da un importe fijo en pesos
      cout <<"Ingrese el importe fijo en pesos: ";
      cin >> bono;
      break;
    case 1:
      bono = sueldoBruto * 0.064;
      break;
    case 2:
      bono = sueldoBruto * 0.1394;
      break;
    case 3:
      bono = sueldoBruto * 0.2104;
      break;
  }

  // Finalmente se calcula el sueldo neto
  float sueldoNeto = sueldoBruto - descuentoLeyISSS - descuentoGanancias - descuentoSeguro + bono;

  return sueldoNeto;
}

int main() {
  float sueldoBruto; // Valor en Float que representa el sueldo bruto de un empleado
  int nivelEmpleado; // Se representa el nivel del empleado con una variable Int

  cout << "Ingrese el sueldo bruto: ";
  cin >> sueldoBruto;

  cout << "Ingrese el nivel del empleado (0, 1, 2, 3): ";
  cin >> nivelEmpleado;

  float sueldoNeto = calcularSueldoNeto(sueldoBruto, nivelEmpleado);

  if (sueldoNeto != -1) {
    cout << "El sueldo neto del empleado es: " << sueldoNeto << endl;
  }

  return 0;
}

