//============================================================================
// Name        : i.cpp
// Author      : Comini/Giulia/Paiola
// Version     :
// Copyright   : ICPC - Regional 2018 - Problema I - Interruptores
// Description :
//============================================================================
#include<bits/stdc++.h>

using namespace std;

int qtdeInt, qtdeLamp, qtdeLampAcesas;
bool lampadaAcesa[1000];
int interruptores[1000][1000];
int lampAfetadas[1000];

int resolver()
{
	int i, j, pos;
	int qtdeLampApagadas = qtdeLamp - qtdeLampAcesas;
	int mov = 0;
	
	if (qtdeLampApagadas == qtdeLamp)
		return mov;
		
	for(i = 0; i < qtdeInt; i++){
		mov++;
		for(j = 0; j < lampAfetadas[i]; j++){
			pos = interruptores[i][j];
			lampadaAcesa[pos] = !lampadaAcesa[pos];
			if (!lampadaAcesa[pos])
				qtdeLampApagadas++;
			else
				qtdeLampApagadas--;
		}
		if (qtdeLampApagadas == qtdeLamp)
			return mov;
	}
	for(i = 0; i < qtdeInt; i++){
		mov++;
		for(j = 0; j < lampAfetadas[i]; j++){
			pos = interruptores[i][j];
			lampadaAcesa[pos] = !lampadaAcesa[pos];
			if (!lampadaAcesa[pos])
				qtdeLampApagadas++;
			else
				qtdeLampApagadas--;
		}
		if (qtdeLampApagadas == qtdeLamp)
			return mov;
	}
	return -1;
}

int main(){
	int i, j;
	
	scanf("%d %d", &qtdeInt, &qtdeLamp);
	for(i = 0; i < qtdeLamp; i++)
		lampadaAcesa[i] = false;
	
	scanf("%d", &qtdeLampAcesas);
	
	for(i = 0; i < qtdeLampAcesas; i++)
	{
		scanf("%d", &j);
		lampadaAcesa[j-1] = true;
	}
	
	for(i = 0; i < qtdeInt; i++)
	{
		scanf("%d", &lampAfetadas[i]);
		for(j = 0; j < lampAfetadas[i]; j++)
		{
			scanf("%d", &interruptores[i][j]);
			interruptores[i][j]--;
		}
	}
	printf("%d\n",resolver());
}
