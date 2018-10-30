//============================================================================
// Name        : e.cpp
// Author      : Comini/Giulia/Paiola
// Version     :
// Copyright   : ICPC - Regional 2018 - Problema E - Enigma
// Description :
//============================================================================
#include<bits/stdc++.h>

using namespace std;

int main(){
	string crib, msg;
	int cont = 0;
	
	cin >> msg >> crib;
	
	int tam_msg = msg.size();
	int tam_crib = crib.size();
	
	for(int i = 0; i < tam_msg - tam_crib + 1; i++){
		for(int j = 0; j < tam_crib; j++){
			if (msg[j + i] == crib[j]){
				cont++;
				break;
			}
		}
	}
	
	printf("%d\n", (tam_msg - tam_crib + 1) - cont);
}
