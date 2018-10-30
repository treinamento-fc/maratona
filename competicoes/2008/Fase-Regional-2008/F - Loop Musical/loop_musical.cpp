
//============================================================================
// Name        : loop.cpp
// Author      : Pedro, João Comini e Giulia (Time: Colecionnadores de Balões)
// Version     :
// Copyright   : 
// Description : ICPC - Regional 2008 - Problema F - Loop Musical
//============================================================================

#include<iostream>
#define CRESCENDO -1
#define DECRESCENDO 1

using namespace std;

int main(){
	int n, h, hAnt, hIni, qtdePicos, comportamento, comportamentoInicial, i;
	
	do {
		qtdePicos = 0;
		
		cin >> n;
		
		if (n == 0)
			return 0;
		
		cin >> hAnt;
		hIni = hAnt;
		for (i = 1; i < n; i++) {
			cin >> h;
			
			if (h < hAnt){   //Decrescendo
				if (i == 1) {
					comportamento = comportamentoInicial = DECRESCENDO;
				}
				else
				{
					if (comportamento != DECRESCENDO) {
						comportamento = DECRESCENDO;
						qtdePicos++;
					}
				}
			} else {         //Crescendo
				if (i == 1) {
					comportamento = comportamentoInicial = CRESCENDO;
				}
				else
				{
					if (comportamento != CRESCENDO) {
						comportamento = CRESCENDO;
						qtdePicos++;
					}
				}
			}
			
			hAnt = h;
		}
		if (hIni < h) {
			if (comportamento != DECRESCENDO){
				comportamento = DECRESCENDO;
				qtdePicos++;
			}
		} else {
			if (comportamento != CRESCENDO){
				comportamento = CRESCENDO;
				qtdePicos++;
			}
		}
		if (comportamento != comportamentoInicial)
			qtdePicos++;
		cout << qtdePicos << endl;
	} while (true);
	
}
