//============================================================================
// Name        : pizza.cpp
// Author      : Paiola / Giulia
// Version     :
// Copyright   : ICPC - Regional 2014 - Problema K - Pizza do Vô Pepe
// Description :
//============================================================================

#include<iostream>

using namespace std;

int main()
{
	int C, N;					//Circunferência e Números de azeitonas
	int X[10001];				//Posição das azeitonas
	int tamSetor;				//Tamanho de cada setor
	int corte_ini, corte_fim; 	//Intervalo possível para corte
	bool cortePossivel = true;
	int i, j;

	cin >> C >> N;
	for(i = 0; i < N; i++)
		cin >> X[i];
	
	tamSetor = C / N;
		
	//Entre uma azeitona e outra sempre temos que ter um corte, vamos usar isso para calcular um intervalo
	//possível de corte. Se esse intervalo não existir, a resposta final é N.
	//Quando dizemos que temos um intervalo de corte entre 2 e 4, por exemplo, se cada setor tiver tamanho 3,
	//isso quer dizer que o próximo corte estará entre 5 e 7, e isso deve ser levado em consideração.
	
	corte_ini = X[0];
	corte_fim = X[1];
	
	for(i = 1; i < (N - 1); i++){
		corte_ini = corte_ini + tamSetor;
		corte_fim = corte_fim + tamSetor;
		if (X[i] > corte_ini)
			corte_ini = X[i];
		if (X[i+1] < corte_fim)
			corte_fim = X[i+1];
		if (corte_fim - corte_ini <= 0){
			cortePossivel = false;
			break;
		}
	}
	
	if (cortePossivel){
		corte_ini = corte_ini + tamSetor;
		corte_fim = corte_fim + tamSetor;
		if (X[N-1] > corte_ini)
			corte_ini = X[N-1];
		if (X[0] + C < corte_fim)		//para simplificar, consideramos a primeira azeitona na posição X[0] + C
			corte_fim = X[0] + C;
		if (corte_fim - corte_ini <= 0)
			cortePossivel = false;
	}
	
	cout << (cortePossivel ? "S" : "N") << endl;	
}
