//============================================================================
// Name        : identifyingtead.cpp
// Author      : Wilson
// Version     :
// Copyright   : Final Brasileira - Programa I
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int i, T, provadores[5], qtd;

	// Tipo do ch�
	cin >> T;

	// Limpar vetor de informa��es dos votantes
	provadores[0] = 0;
	provadores[1] = 0;
	provadores[2] = 0;
	provadores[3] = 0;
	provadores[4] = 0;

	// Cada provador informa que tipo de ch� acha que �
	cin >> provadores[0] >> provadores[1] >> provadores[2] >> provadores[3] >> provadores[4];

	// Descobre quantos provadores acertaram o tipo de ch�
	qtd = 0;
    for (i=0;i<5;i++) {
        if (provadores[i] == T) {
        qtd++;
        }
    }
    // Quantidade de provadores que acertaram o tipo de ch�
    cout << qtd << endl;

	return 0;
}
