//============================================================================

// Name        : fase.cpp

// Solução     :

// Author      : Wilson

// Version     :

// Copyright   : Your copyright notice

// Description : Hello World in C++, Ansi-style

//============================================================================#include <iostream>

#include <algorithm>

using namespace std;

int i, N, K, pontuacao[1000], classificados, ptUltimo;

int main() {

    // Ler Ne K

    cin >> N >> K;

    // cout << N << " " << K << endl;

    // Ler N pontuação dos competidores

    for(i=0;i<N; i++) {

      cin >> pontuacao[i];

    }

    sort(pontuacao, pontuacao+N);

    /*

    for(i=0;i<N; i++) {

      cout << pontuacao[i] << "  ";

    }

    cout << endl;

   */

   if (N == K) { // Todos estão classificados

     classificados = N;

   } else {

       // K já estão classificados

       classificados = K;

       ptUltimo = pontuacao[N - K];

       // Verifica quantos dos restantes tem a mesma pontuação do último que se classificou

       for(i=N-K-1;i>=0; i--) {

           // cout << ptUltimo << "  " << i << "  " << pontuacao[i] << "  "  << classificados << endl;

           if (pontuacao[i] == ptUltimo) classificados++;

       }

   }

   cout << classificados << endl;

    return 0;

}