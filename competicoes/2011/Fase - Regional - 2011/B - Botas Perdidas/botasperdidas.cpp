//============================================================================
// Name        : botasperdidas.cpp
// Author      : Wilson
// Version     :
// Copyright   : Regional 2011 - Problema B
// Description : Botas Perdidas
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
	// cout << "Botas Perdidas" << endl; // prints Botas Perdidas

	int i, N, numero, pares;
	char lado;

	struct pes {
		int direita;
		int esquerda;
	} botas[61];

    while(1) {

    	cin >> N;
    	if (cin.eof()) {
    		break;
    	}
    	// cout << N << endl;

    	for (i = 1; i <= 60; i++) {
           botas[i].direita  = 0;
           botas[i].esquerda = 0;
    	}

    	for (i = 0; i < N; i++) {
        	cin >> numero >> lado;
        	// cout << numero << " " << lado << endl;
        	// Verifica se já existe no conjunto numero+lado
            if (lado == 'D') {
                botas[numero].direita++;
            } else {
                botas[numero].esquerda++;
            }
    	}

        // Só para chegar que está guardando os dados corretamente
        /*
    	for (i = 30; i <= 60; i++) {
            if ((botas[i].direita > 0) || (botas[i].esquerda > 0)) {
        		cout << i <<  " D: " << botas[i].direita << " E: " << botas[i].esquerda << endl;
            }
    	}
        */
    	// Calcular quantidade de pares de botas correta
    	pares = 0;
    	for (i = 30; i <= 60; i++) {
            if ((botas[i].direita > 0) && (botas[i].esquerda > 0)) {
                // Mesma quantidade de botas de pé direito e pé esquerdo
                if (botas[i].direita == botas[i].esquerda)  {
                	pares = pares + botas[i].direita;
                } else {
                    // Mais botas de pé direito do que de pé esquerdo
                	if (botas[i].direita > botas[i].esquerda)  {
                    	pares = pares + botas[i].esquerda;
                	} else {
                        // Mais botas de pé esquerdo do que de pé direito
                		pares = pares + botas[i].direita;
                	}
                }
            }
    	}
    	// Mostrar quantidade de pares de botas corretos
    	cout << pares << endl;
    }
	return 0;
}
