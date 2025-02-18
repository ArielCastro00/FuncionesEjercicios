#include <iostream>

using namespace std;

bool FechaValida(int dia, int mes, int anio) {
  // Se valida el rango de a�o (siglo 20 o 21)
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
  // Si todas las validaciones son correctas, la fecha es v�lida
  return true;
}

int main() {
  int dia, mes, anio;
  
  cout << "Ingrese el dia: ";
  cin >> dia;
  
  cout << "Ingrese el mes: ";
  cin >> mes;
  
  cout << "Ingrese el anio: ";
  cin >> anio;
  
  if (FechaValida(dia, mes, anio)) {
    cout << "La fecha ingresada es valida." << endl;
  } else {
    cout << "La fecha ingresada no es valida." << endl;
  }
  
  return 0;
}


