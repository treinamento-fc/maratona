//============================================================================
// Name        : subprime.cpp
// Author      : Wilson
// Version     :
// Copyright   : Regional 2009 - Problema D
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	 //cout << "Sub-prime" << endl; // prints Sub-prime

	int i, B, N, D, C, V;
    int creditos[21];
    bool temnegativo;

	while (1) {

		// Obter B = Banco e N = No. de debentures
		cin >> B >> N;

		// Testa fim dos casos de teste
		if ((B == 0) && (N == 0)) {
		   break;
		}

		//fill(creditos, creditos+21, 0);

		// Ler os créditos de cada banco
		for (i=1; i<=B; i++) {
            creditos[i] = 0;
			cin >> creditos[i];
		}

		// Ler os registros de debentures (debitar e creditar)
		for(i=1;i<=N; i++) {
			// D=Banco Débito  C=Banco Crédito   V=Valor
			cin >> D >> C >> V;
            creditos[D] = creditos[D] - V;
            creditos[C] = creditos[C] + V;
		}

		// Verifica se algum banco tem crédito negativo (quer dizer que não tem recursos
		// para liquidar as dívidas
        temnegativo = false;
		for(i=1;i<=B; i++) {
            if (creditos[i] < 0) {
               temnegativo = true;
               break;
            }
		}

		if (temnegativo) {
		   cout << "N" << endl;
		} else {
		   cout << "S" << endl;
		}
	}
	return 0;
}
