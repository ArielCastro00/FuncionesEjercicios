#include <iostream>

using namespace std;

bool Primos(int n) {
  // Si n es menor o igual a 1 no es un numero primo
  if (n <= 1){
  	return false;
  }
  
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false; // Si encuentra un n divisible por 2 o su raiz cuadrada no es primo 
  return true; // Si no encuentra un divisor entonces es primo
}

void ListaPrimos(int x) {
  // Recorre desde 2 hasta el valor ingresado
  for (int i = 2; i <= x; i++) 
    if (Primos(i)) cout << i << " "; // Por cada numero se llama a la funcion Primo para verificar si es primo. En caso de ser primo imprime el numero en pantalla
}

int main() {
  int x;
  cout << "Ingrese un numero limite: ";
  cin >> x;
  ListaPrimos(x);
  return 0;
}

