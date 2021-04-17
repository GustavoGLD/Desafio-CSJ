#include <iostream>

int main() {
  int n = 1234;

  int unidade = n % 10; // 4
  int dezena = n % 100 - unidade; //30 = 34 - 4
  int centena = n % 1000 - dezena - unidade; //200 = 234 - 30 - 4
  int milhar = n % 10000 - centena - dezena - unidade; //1000 = 1234 - 200 - 30 - 4

  unidade *= 1000; //1000 porque é milhar
  dezena *= 10; //10 = 1000 / 100^1
  centena *= 0.1; //0.1 = 1000 / 100^2
  milhar *= 0.001; //0.001 = 1000 / 100^3

  std::cout << unidade << "\n";
  std::cout << dezena << "\n";
  std::cout << centena << "\n";
  std::cout << milhar << "\n";

  return 0;
}