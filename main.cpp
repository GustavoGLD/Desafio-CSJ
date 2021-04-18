#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int inverterNumero(int n);

int main() {
  //Input
  int n; cin >> n;

  //Printar n invertido
  cout << inverterNumero(n) << endl;

  return 0;
}


int inverterNumero(int n){

  //Ordem de grandeza que dividirá n: 10, 100, 1000...
  int grandeza;

  //Criar um vetor com os algorismos
  //Ex.: 1234 será armazenado como 1000, 200, 30, 4
  vector<int> algorismos;

  //
  for (grandeza = 1;grandeza < n;){
    grandeza *= 10;

    //Resto da divisão da ordem de grandeza por `n`.
    //Ex.: 1234 % 10 = 4 (unidade)
    //Ex.: 1234 % 100 = 34 (dezena + unidade)
    int elemento = n % grandeza;
    
    //Como estamos trabalhando com inteiros, podemos por exemplo
    //transformar 234 em 200 divindo por 100, e multiplicando por 100.
    elemento = (elemento / (grandeza/10)) * (grandeza/10);

    //Agora passamos nosso elemento para o vetor de algorimos
    algorismos.push_back(elemento);
  }

  //Dividir por 10, agora representa a ordem de grandeza de `n`
  //ao invés da ordem de grandeza do número que é divido por `n`
  grandeza /= 10;

  //`nFinal` será o `n` invertido.
  int nFinal;

  //Agora que inverteremos os algorismos. Corrigir a ordem de grandeza de cada um
  //Ex.: 1234 foi decomposto, no vetor `algorismos` em {1000, 200, 30, 4}
  //Agora corrigiremos para {1, 20, 300, 4000}
  //`nFinal` será a soma desses elementos, 4321
  for (int pos = 0; pos < algorismos.size(); pos++){

    //Temos uma fórmula para corrigir a ordem de grandeza de tal algorismo em `n`
    //Sendo `grandeza` a ordem de grandeza de `n`
    //seja `pos` a posição antiga do algorismo em `n` (que coincide com a varredura do for)
    algorismos[pos] *= grandeza / pow(100, pos);

    //Já vamos somar esse algorismo novo em `nFinal`
    nFinal += algorismos[pos];
  }

  //`nFinal` será o retorno int da função
  return nFinal;
}