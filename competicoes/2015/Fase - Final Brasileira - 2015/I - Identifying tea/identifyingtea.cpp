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

	// Tipo do chá
	cin >> T;

	// Limpar vetor de informações dos votantes
	provadores[0] = 0;
	provadores[1] = 0;
	provadores[2] = 0;
	provadores[3] = 0;
	provadores[4] = 0;

	// Cada provador informa que tipo de chá acha que é
	cin >> provadores[0] >> provadores[1] >> provadores[2] >> provadores[3] >> provadores[4];

	// Descobre quantos provadores acertaram o tipo de chá
	qtd = 0;
    for (i=0;i<5;i++) {
        if (provadores[i] == T) {
        qtd++;
        }
    }
    // Quantidade de provadores que acertaram o tipo de chá
    cout << qtd << endl;

	return 0;
}
