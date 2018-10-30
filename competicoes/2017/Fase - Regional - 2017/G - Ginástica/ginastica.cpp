//============================================================================
// Name        : Ginastica.cpp
// Author      : Wilson/Rene
// Solução     : Recursividade + Programação Dinâmica
// Version     :
// Copyright   :
// Description : Problema G - Maratona de Programação - Fase Regional - 2017
//============================================================================

#include <limits>
#include <iostream>
#include<cstring>

using namespace std;

long int i, T, M, N;
unsigned long long int tot, ptot, pot, pd[100001][51];

unsigned long long int prog(int nivel, int profundidade) {

  if (profundidade == 0) {
    return 1;
  } else {
      if (nivel == M) {
          if (pd[nivel][profundidade] == 0) {
              pd[nivel][profundidade] = prog(nivel + 1, profundidade-1);
          }
     } else {
         if (nivel == N) {
             if (pd[nivel][profundidade] == 0) {
                pd[nivel][profundidade] = prog(nivel - 1, profundidade-1);
             }
         } else {
             if (pd[nivel][profundidade] == 0) {
                pd[nivel][profundidade] = prog(nivel + 1, profundidade-1) + prog(nivel - 1, profundidade-1);
             }
         }
     }
  }

  pd[nivel][profundidade] %= 1000000007;  // Pense no motivo dessa operação estar aqui.

  return pd[nivel][profundidade];
}

int main() {
    // Obter T, M, N
    cin >> T >> M >> N;

    //cout << "Minimum value for int: "<<numeric_limits<int>::min() << '\n';
    //cout << "Maximum value for int: " << numeric_limits<int>::max() << '\n';
    //cout << "Maximum value for long long : " << numeric_limits<long long>::max() << '\n';
    //cout << "Minimum value for long long : " << numeric_limits<long long>::min() << '\n';
    //cout << "Maximum value for unsigned long long : " << numeric_limits<unsigned long long>::max() << '\n';
    //cout << "Minimum value for unsigned long long : " << numeric_limits<unsigned long long>::min() << '\n';
    //cout << "T: " << T << " M: " << M << " N: " << N << endl;

    memset(pd, 0, sizeof(pd));
    // cout << sizeof(pd) << endl;

    ptot = 0;
    for(i = M; i <= N; i++) {
       	// cout << "Nível " << i << endl;
        ptot += prog( i, T-1);
    }

    // Programas possíveis
    cout << (ptot % 1000000007) << endl;

    return 0;
}
