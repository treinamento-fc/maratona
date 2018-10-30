//============================================================================
// Name        : guardacosteira.cpp
// Author      : Wilson
// Version     :
// Copyright   : Regional 2011 - Problema G
// Description : Guarda Costeira
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int D, Vf, Vg;
	// cout << "Guarda Costeira" << endl;

    while(1) {
       // Pega dados D = Distancia entre Fugitivo e Guardas
       // Vf = Velocidade do barco dos fugitivos
       // Vg = Velocidade do barco dos guardas
       cin >> D >> Vf >> Vg;
       // cout << D << " " << Vf << " " << Vg << endl;
       if (cin.eof()) {  // Termina se não há mais dados de entrada
          break;
       }

       // Fórmula do Movimento Retilineo Uniforme (calcular o tempo)
       float tf = (float) 12 / Vf; // Tempo dos fugitivos para atingir o ponto 12 milhas
       float tg = sqrt(12*12 + D*D) / Vg;	     // Tempo dos guardas   para atingir o ponto 12 milhas

       if (tf >= tg) { // Tempo do fugitivos > tempo dos guardas?
    	  // cout << "S" << " " << tf << " > " << tg << endl;
     	  cout << "S" <<  endl;
       } else {
    	   // cout << "N" << " " << tf << " <= " << tg << endl;
      	  cout << "N" <<  endl;

       }
    }
	return 0;
}
