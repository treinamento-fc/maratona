//============================================================================
// Name        : handbol.cpp
// Author      : Wilson
// Version     :
// Copyright   : ICPC - Regional 2014 - Problema H - Handebol
// Description :
//============================================================================

#include <iostream>
using namespace std;

int N, M;

int main() {

	// cout << "Handebol" << endl; // prints Handebol

   int i, j, jogadores, gols[101][1001];

   // Zerar matriz de desempenho
   for (i=0; i < 100; i++) {
	   gols[i][1000] = 9;
	   for (j=0; j < 1000; j++ ) {
		   gols[i][j] = 0;
	   }
   }

   // Obter número de jogadores e número de partidas
   cin >> N >> M;
   for (i=0; i< N; i++) {
	   for (j=0; j < M; j++ ){
          cin >> gols[i][j];
          // Se jogador i não fez gol na partida j então não entrará na estatística
          if (gols[i][j] == 0) gols[i][1000] = 0;
       }
   }

   jogadores = 0;
   for (i=0; i< N; i++) {
       if (gols[i][1000] == 9) jogadores++;
   }

   cout << jogadores << endl;
   return 0;
}
