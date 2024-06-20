#include <iostream>
#include <math.h>

using namespace std;

double Seno(double medidaAngulo, char tipoMedida) {
  // Se hace una conversion a Radianes si se ingresa un valor sexagesimal
  double anguloEnRadianes;
  if (tipoMedida == 's') {
    anguloEnRadianes = medidaAngulo * M_PI / 180;
  } else if (tipoMedida == 'r') {
    anguloEnRadianes = medidaAngulo;
  } else {
    cout << "Tipo de medida de ángulo inválido." << endl;
    return -1;
  }

  // Calcular el seno del ángulo utilizando la serie de Taylor
  int i, j, expo=1;
  double resultado, factorial;

  for (i = 1; i <= 12; i++) {
  	factorial = 1;
  	for (j = 1; j <= expo; j++)
  		factorial*=j;
  		
  	if (i%2 == 0) // El termino es Par
  		resultado = resultado - pow(anguloEnRadianes, expo) / factorial;
  	else  // El termino es Impar
  		resultado = resultado + pow(anguloEnRadianes, expo) / factorial;
  	
  	expo = expo + 2;
  }

  return resultado;
}

int main() {
  double medidaAngulo;
  char tipoMedida;

  cout << "Ingresar el valor del angulo: ";
  cin >> medidaAngulo;

  cout << "Especifique el tipo de medida del angulo: (s: grados sexagesimales, r: radianes): ";
  cin >> tipoMedida;

  double senoAngulo = Seno(medidaAngulo, tipoMedida);

  if (senoAngulo != -1) {
    cout << "El seno del ángulo es: " << senoAngulo << endl;
  }

  return 0;
}


