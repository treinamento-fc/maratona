//============================================================================
// Name        : fundindo_arvores.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Regional 2016 - Problema F - Fundindo �rvores
// Description :
//============================================================================
#include<iostream>

using namespace std;

typedef struct{
	int filho_esq;
	int filho_central;
} arvoreC;

typedef struct{
	int filho_central;
	int filho_dir;
} arvoreD;

int sequenciaCentraisC[10000];
int sequenciaCentraisD[10000];

//Retorna a sequ�ncia m�xima de n�s centrais a partir de um n� da �rvore
int seqMax(arvoreC arvC[], int no){
	if (sequenciaCentraisC[no] != -1)
		return sequenciaCentraisC[no];
	if (no == -1){
		return 0;
	}

	int qtde = 1 + seqMax(arvC, arvC[no].filho_central);
	sequenciaCentraisC[no] = qtde;
	return qtde;
}

int seqMax(arvoreD arvD[], int no){
	if (sequenciaCentraisD[no] != -1)
		return sequenciaCentraisD[no];
	if (no == -1){
		return 0;
	}

	int qtde = 1 + seqMax(arvD, arvD[no].filho_central);
	sequenciaCentraisD[no] = qtde;
	return qtde;
}


int main(){
	arvoreC arvC[10000];
	arvoreD arvD[10000];
	int nC, nD, v, v1, v2, i;
	int maxC = 0, maxD = 0, maxCRaiz, maxDRaiz;
	
	cin >> nC;
	for(i = 0; i < nC; i++){
		cin >> v >> v1 >> v2;
		sequenciaCentraisC[v-1] = -1;
		arvC[v-1].filho_esq = v1 - 1;
		arvC[v-1].filho_central = v2 - 1;
	}
	
	cin >> nD;
	for(i = 0; i < nD; i++){
		cin >> v >> v1 >> v2;
		sequenciaCentraisD[v-1] = -1;
		arvD[v-1].filho_central = v1 - 1;
		arvD[v-1].filho_dir = v2 - 1;
	}
	
	//Apenas n�s centrais podem se fundir (devido a estrutura das �rvores), dessa forma queremos encontrar
	//a sequ�ncia m�xima de n�s centrais nas duas �rvores, s� tomando o cuidado de considerar que temos que
	//manter uma estrutura de �rvore, com apenas uma raiz, um n� n�o pode ser filho de dois pais n�o fundidos.
	//Para isso, n�o pode acontecer de uma sequ�ncia qualquer de uma �rvore se fundir a uma qualquer da outra,
	//uma delas deve come�ar da raiz da �rvore em quest�o
	
	maxCRaiz = seqMax(arvC, 0);
	for(i = 0; i < nC; i++)
		maxC = max(maxC, seqMax(arvC, i));
	maxDRaiz = seqMax(arvD, 0);
	for(i = 0; i < nD; i++)
		maxD = max(maxD, seqMax(arvD, i));
		
	cout << (nD + nC - max(min(maxCRaiz, maxD),min(maxDRaiz, maxC)))<< endl;
}
