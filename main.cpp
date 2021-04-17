#include <iostream>

int main() {
  int n = 123;

  int unidade = n % 10;
  int dezena = n % 100 - unidade;
  int centena = n % 1000 - dezena - unidade;

  unidade *= 100;
  dezena *= 1;
  centena *= 0.01;

  std::cout << unidade << "\n";
  std::cout << dezena << "\n";
  std::cout << centena << "\n";

  return 0;
}