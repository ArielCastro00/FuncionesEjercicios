#include <iostream>

using namespace std;

int registroAcademico(int Curso, int PrimerParcial, int SegundoParcial, int PrimerRecPrimerP, int PrimerRecSegundoP, int SegundoRecPrimerP, int SegundoRecSegundoP) {
  // Añadimos un contador para los recuperatorios
  float contRec;
  
  // Suponiendo que la nota no "pisa", si el valor de un recuperatorio es mayor al de la nota del parcial (o primer recuperatorio) esta se reemplaza pero aumenta el numero de recuperatorios hechos
    if (PrimerRecPrimerP > PrimerParcial){
  	PrimerParcial = PrimerRecPrimerP;
  	contRec++;
  }
	if (SegundoRecPrimerP > PrimerParcial){
  	PrimerParcial = SegundoRecPrimerP;
  	contRec++;
  }
    if (PrimerRecSegundoP > SegundoParcial){
  	SegundoParcial = PrimerRecSegundoP;
  	contRec++;
  }
	if (SegundoRecSegundoP > SegundoParcial){
  	SegundoParcial = SegundoRecSegundoP;
  	contRec++;
  }
  
  // Determinamos la condicion del alumno
  if (PrimerParcial >= 7 && SegundoParcial >=7) 
  {
    if (PrimerParcial >= 8 && SegundoParcial >=8 && contRec <= 1){ // Si solo dio 1 recuperatorio o menos, esta en condicion de promocion
      return 1; // Promoción
    } 
	else{
      return 2; // Aprobado
    }
  } else if (PrimerParcial == 0 && SegundoParcial == 0) {
    return 4; // Ausente
  }
    else{
    return 3; // No Aprobado
	}
}

int main() {
  // Ejemplo de uso de la función
  int curso, primerParcial, segundoParcial, primerRecPrimerP, primerRecSegundoP, segundoRecPrimerP, segundoRecSegundoP;

  cout << "Ingrese el numero de curso: ";
  cin >> curso;

  cout << "Ingrese la nota del primer parcial: ";
  cin >> primerParcial;

  cout << "Ingrese la nota del segundo parcial: ";
  cin >> segundoParcial;
  
  cout << "Ingrese la nota del primer recuperatorio del primer parcial (si no hay, ingrese el mismo valor que el anterior): ";
  cin >> primerRecPrimerP;
  
  cout << "Ingrese la nota del primer recuperatorio del segundo parcial (si no hay, ingrese el mismo valor que el anterior): ";
  cin >> primerRecSegundoP;

  cout << "Ingrese la nota del segundo recuperatorio del primer parcial (si no hay, ingrese el mismo valor que el anterior): ";
  cin >> segundoRecPrimerP;

  cout << "Ingrese la nota del segundo recuperatorio del segundo parcial (si no hay, ingrese el mismo valor que el anterior): ";
  cin >> segundoRecSegundoP;

  int resultado = registroAcademico(curso, primerParcial, segundoParcial, primerRecPrimerP, primerRecSegundoP, segundoRecPrimerP, segundoRecSegundoP);
  
  cout <<"Condicion del alumno del curso K"<< curso << ": ";

  switch (resultado) {
    case 1:
      cout << "Promocionado" << endl;
      break;
    case 2:
      cout << "Aprobado" << endl;
      break;
    case 3:
      cout << "No aprobado" << endl;
      break;
    case 4:
      cout << "Ausente" << endl;
      break;
  }
  return 0;
}

