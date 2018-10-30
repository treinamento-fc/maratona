//============================================================================
// Name        : quebra_cabeca.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Regional 2015 - Problema D - Quebra Cabe�a
// Description : O problema consiste em encontrar o valor de cada vari�vel,
//				 mas � facilitado pelo fato de sabermos que sempre h� pelo menos 
//				 uma linha ou coluna com apenas uma vari�vel desconhecida.
//				 Como o problema � relativamente simples, aproveitei para praticar
//				 o uso das estruturas set e map do C++
//============================================================================

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

string quebraCabeca[100][100];
int somaLinha[100];
int somaColuna[100];
int l, c;

map<string, int> variaveis;
set<string> varDesconhecidasCol[100];
set<string> varDesconhecidasLin[100];

void descobrirValorCol(int col){
	int i, soma = 0, n = 0;
	string varDesconhecida;
	
	//Encontrando a vari�vel desconhecida (e o seu valor)
	for(i = 0; i < l; i++)
	{
		if (variaveis.count(quebraCabeca[i][col]))
			soma += variaveis[quebraCabeca[i][col]];
		else
		{
			n++;
			if (n == 1) varDesconhecida = quebraCabeca[i][col];
		}
	}
	variaveis[varDesconhecida] = (somaColuna[col] - soma) / n;
	
	//Removendo a vari�vel encontrada dos conjuntos de vari�veis desconhecidas
	for(i = 0; i < l; i++)
		varDesconhecidasLin[i].erase(varDesconhecida);
	for(i = 0; i < c; i++)
		varDesconhecidasCol[i].erase(varDesconhecida);
}

void descobrirValorLin(int lin){
	int i, soma = 0, n = 0;
	string varDesconhecida;
	
	//Encontrando a vari�vel desconhecida (e o seu valor)
	for(i = 0; i < c; i++)
	{
		if (variaveis.count(quebraCabeca[lin][i]))
			soma += variaveis[quebraCabeca[lin][i]];
		else
		{
			n++;
			if (n == 1) varDesconhecida = quebraCabeca[lin][i];
		}
	}
	variaveis[varDesconhecida] = (somaLinha[lin] - soma) / n;
	
	//Removendo a vari�vel encontrada dos conjuntos de vari�veis desconhecidas
	for(i = 0; i < l; i++)
		varDesconhecidasLin[i].erase(varDesconhecida);
	for(i = 0; i < c; i++)
		varDesconhecidasCol[i].erase(varDesconhecida);
}

int main(){
	int i, j;
	bool terminou = false;
	
	//Lendo os dados e iniciando os conjuntos que indicam as vari�veis desconhecidas
	//em cada linha e coluna	
	cin >> l >> c;
	for(i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++){
			cin >> quebraCabeca[i][j];
			varDesconhecidasCol[j].insert(quebraCabeca[i][j]);
			varDesconhecidasLin[i].insert(quebraCabeca[i][j]);
		}
		cin >> somaLinha[i];
	}
	for(j = 0; j < c; j++)
		cin >> somaColuna[j];
		
	//Enquanto ainda h� vari�veis para serem descobertas
	while(!terminou){
		terminou = true;
		//procuramos linhas que contenham apenas uma vari�vel desconhecida
		for(i = 0; i < l; i++){
			if (varDesconhecidasLin[i].size() == 1)
			{
				terminou = false;
				descobrirValorLin(i);
				break;
			}
		}
		//se n�o encontrarmos, procuramos uma coluna
		if (terminou){
			for(j = 0; j < c; j++){
				if (varDesconhecidasCol[j].size() == 1)
				{
					terminou = false;
					descobrirValorCol(j);
					break;
				}
			}
		}
	}
	//Exibindo o valor das vari�veis (o iterator do map percorre de forma ordenada em rela��o a chave)
	for(map<string, int>::iterator it = variaveis.begin(); it != variaveis.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
}
