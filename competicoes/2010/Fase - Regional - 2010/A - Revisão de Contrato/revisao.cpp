//============================================================================
// Name        : revisao.cpp
// Author      : Wilson
// Version     :
// Copyright   : Regional 2010 - Problema A
// Description : Revis�o de Contrato
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;


int main() {
	// cout << "Revis�o de Contrato" << endl;
	int i;
	char D;
	string N, R;
    bool zeros;

    while (1) {
		// Ler digito e n�mero (em formato string)
		cin >> D >> N;
		//cout << D << " " << N << endl;

		if (D == '0') break;
        R = "";
        // Percorre N procurando D, se n�o encontrou D em N, copia o caracter de N para R;
		for (i=0; i < (int) N.length(); i++) {
			if (N.at(i) != D ) {
			   R = R + N.at(i);
			}
		}

        // Imprimir resultado R
		// Verifica se tamanho de R � ZERO
		if (R.length() == 0) {
		    cout << "0" << endl;
		} else { // Verifica se todos os digitos de R s�o ZERO
			zeros = true;
			for (i=0; i < (int) R.length(); i++) {
				if (R.at(i) != '0' ) {
                   zeros = false;
                   break;
				}
			}
			if (zeros) {
			    cout << "0" << endl;

			} else {
			    cout << R << endl;
			}
		}
    }
    return 0;
}
