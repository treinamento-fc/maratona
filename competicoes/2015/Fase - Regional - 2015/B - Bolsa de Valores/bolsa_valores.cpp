//============================================================================
// Name        : bolsa_valores.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Regional 2015 - Problema B - Bolsa de valores
// Description : 
//============================================================================

#include<iostream>

using namespace std;

int P[200000];
int N, C;

int resolver()
{
	int lucroMax[N], memo[N];		//O vetor lucroMax não é realmente necessário, considere refazer o algoritmo eleminando-o
	lucroMax[0] = 0;
	memo[0] = lucroMax[0] - (P[0] + C);
	for(int i = 1; i < N; i++){
		lucroMax[i] = lucroMax[i-1];
		/*Algoritmo ingênuo, mas importante pra compreensão da solução com PD
		for(int j = 0; j < i; j++)
		{
			lucroMax[i] = max(lucroMax[i], P[i] + (lucroMax[j] - (P[j] + C)); //veja que estamos procurando o maior P[i] + (lucroMax - (P[j] + C)), mas P[i] é fixo
		}
		*/
		lucroMax[i] = max(lucroMax[i], P[i] + memo[i-1]);
		memo[i] = max(memo[i-1], lucroMax[i] - (P[i] + C));
	}
	return lucroMax[N-1];
}


int main(){
	cin >> N >> C;	
	
	for(int i = 0; i < N; i++){
		cin >> P[i];	
	}

	cout << resolver() << endl;
}
