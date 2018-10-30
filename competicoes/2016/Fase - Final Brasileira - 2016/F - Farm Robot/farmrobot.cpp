/============================================================================

// Name        : Problema F - farmrobot.cpp

// Author      : Wilson

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2016 - Latin American Regional Contests

//============================================================================

#include <iostream>

#include <algorithm>

using namespace std;

int N, C, S, comando, contador, posAtual;

int main() {

    int i;

    // Ler N, C, S

   cin >> N >> C >> S;

   // cout << N << "\t" << C << "\t" << S << endl;

   posAtual = 1;

   contador = 0;

   if (posAtual == S) contador = 1;

   // Ler comandos

   for (i=1; i<=C; i++) {

      cin >> comando;

      // cout << comando << " " << posAtual << " " << contador << endl;

      if (comando == 1) {  // Movimento para frente

         if (posAtual == N) {

             posAtual = 0;

         }

      } else  // Movimento para trás

          if (posAtual == 1) posAtual = N+1;

      posAtual += comando;

      if (posAtual == S) contador++;

   }

   // Imprimir situação da estação S

   cout << contador << endl;
   return 0;

}