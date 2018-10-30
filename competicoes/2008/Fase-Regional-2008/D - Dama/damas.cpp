//============================================================================
// Name        : D.cpp
// Author      : Wilson
// Version     :
// Copyright   : Maratona Programa��o - Regional - 2008 - Problema D - Damas
// Solu��o     : Dama (rainha) no jogo de xadrez alcan�a qualquer posi��o do
//               tabuleiro em no m�ximo 2 movimentos.
//============================================================================

#include <iostream>
using namespace std;

bool diagonal(int x1, int y1, int x2, int y2) {
   bool sit = false;
   if ((x1 == y1) && (x2 == y2)) {  // Ambos na diagonal principal
	  sit = true;
   } else {	// Verifica as demais diagonais
       if ((x1 -y1) == (x2 - y2) || (x1 + y1) == (x2 + y2)) {
    	   sit = true;
       } else {
    	   sit = false;
       }
   }
   return sit;
}

int main() {
	// x1, y1 = coordenadas da Dama
	// x2, y2 = coordenadas de onde a Dama deve ir
	// movto = quantidade de movimento da Dama
    int x1, y1, x2, y2, movto;

	// cout << "Damas" << endl; // prints Damas

	while (1) {
		cin >> x1 >> y1 >>  x2 >> y2;
	    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	    // Verificar condi��o de termino dos dados
	    if ((x1 + y1 + x2 + y2) == 0) break;

	    // Se (x1,y1) = (x2,y2) ent�o n�o h� movimento
	    if ((x1 == x2) && (y1 == y2)) {
	       movto = 0;
	    } else {
           // Se x1 = x2 ou  y1 = y2 (Dama e a posi��o est�o na mesma linha ou coluna
		    if ((x1 == x2) || (y1 == y2)) {
		       movto = 1;
		    } else {
              // Est�o na mesma diagonal?
		      if (diagonal(x1, y1, x2, y2)) {
		    	 movto = 1;
		      } else {
		    	 movto = 2;
		      }
		    }

	    }
	    cout << movto << endl;
	}
	return 0;
}
