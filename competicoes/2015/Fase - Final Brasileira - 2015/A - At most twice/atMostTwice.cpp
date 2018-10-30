//============================================================================
// Name        : atMostTwice.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Final 2015 - Problema A - At most twice
// Description : 
//============================================================================

#include<iostream>

using namespace std;

int main()
{
	unsigned long long u, l, comprimento, j;
	int i, pos;
	bool ok;
	int digs[10];
	cin >> u;
	
	do{
		//variável para indicar se não há digitos que aparecem mais de duas vezes
		ok = true;
		
		//preparando as variáveis
		for(i = 0; i < 10; i++)
			digs[i] = 0;
		l = u;
		comprimento = 1;
		
		//contabilizando a quantidade de vezes q cada digito aparece e calculando o comprimento do número		
		while(l != 0)
		{
			digs[l % 10]++;
			if (digs[l % 10] > 2)
				ok = false;
			l /= 10;
			comprimento *= 10;	
		}
		comprimento /= 10;
		
		//Se o número ainda não for o que procuramos
		if (!ok){
			l = u;
			for(i = 0; i < 10; i++)
				digs[i] = 0;
			
			//percorremos os digitos da esquerda para a direita (do mais significativo para o menos)
			for(j = comprimento; j >= 1; j /= 10){
				pos = (l / j) % 10;
				digs[pos]++;
				//Para o primeiro digito que der problema, subtraimos j, mas alteramos todos os números
				//a direita para 9, fazendo os devidos cálculos, chegamos que temos que substrair 1 + (l % j) 
				if (digs[pos] > 2){
					l -=  1 + (l % j);
					break;
				}
			}
			u = l;
		}
		
	} while (!ok);
	
	cout << u << endl;
}
