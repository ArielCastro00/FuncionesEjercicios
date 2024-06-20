#include <iostream>
#include <string>

using namespace std;

bool FechaValida(int dia, int mes, int anio) {
  // Se valida el rango de año (siglo 20 o 21)
  if (anio < 1901 || anio > 2100) {
    return false;
  }
  
  // Se valida el rango de mes
  if (mes < 1 || mes > 12) {
    return false;
  }
  
  // Se valida la cantidad de dias por mes si es bisiesto o no y se valida que los dias ingresados no sobrepasen los dias del mes
  if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0){
  	  int diasMes[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  	    if (dia > diasMes[mes - 1]) {
    		return false;
  			}
  		}
  else{
  	  int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  	    if (dia > diasMes[mes - 1]) {
    		return false;
  			}
		}
  // Si todas las validaciones son correctas, la fecha es válida
  return true;
}

int convertirStringAEntero(int dia, int mes, int anio) {
	  // Se convierten los valores a strings
  string diaStr = to_string(dia);
  string mesStr = to_string(mes);
  string anioStr = to_string(anio);
  
  // Se valida si la fecha es válida antes de convertirla
  if (!FechaValida(dia, mes, anio)) {
    return -1; // Si la fecha no es valida retorna un valor de error
  }
  

  // Agregamos ceros a la izquierda si es que no se insertaron 2 digitos (o 4 en lugar de año)
  while (diaStr.length() < 2) {
    diaStr = "0" + diaStr;
  }
  
  while (mesStr.length() < 2) {
    mesStr = "0" + mesStr;
  }
  
  while (anioStr.length() < 4) {
    anioStr = "0" + anioStr;
  }
  
  // Concatenar los strings y convertir a entero
  string fechaStr = anioStr + mesStr + diaStr;
  // stoi permite convertir string a int
  int stringEntero = stoi(fechaStr);
  
  return stringEntero;
}

int main() {
  int dia, mes, anio;
  
  cout << "Ingrese el día: ";
  cin >> dia;
  
  cout << "Ingrese el mes: ";
  cin >> mes;
  
  cout << "Ingrese el año: ";
  cin >> anio;
  
  int stringEntero = convertirStringAEntero(dia, mes, anio);
  
  if (stringEntero != -1) {
    cout << "La fecha en formato AAAAMMDD es: " << stringEntero << endl;
  } else {
    cout << "La fecha ingresada no es válida." << endl;
  }
  
  return 0;
}
