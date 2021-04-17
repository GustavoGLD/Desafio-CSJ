#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int inverterNumero(int n);

int main() {
  int n;
  cin >> n;

  cout << inverterNumero(n) << endl;

  return 0;
}

int inverterNumero(int n){
  int grandeza;
  vector<int> algorismos;

  for (grandeza = 1;grandeza < n;){
    grandeza *= 10;
    algorismos.push_back(((n % grandeza) / (grandeza/10)) * (grandeza/10));
  }

  grandeza /= 10;
  int nFinal = 0;

  for (int x = 0; x < algorismos.size(); x++){
    algorismos[x] *= grandeza / pow(100, x);
    nFinal += algorismos[x];
  }

  return nFinal;
}