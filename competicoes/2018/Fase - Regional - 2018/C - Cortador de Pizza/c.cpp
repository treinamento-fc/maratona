//============================================================================
// Name        : c.cpp
// Author      : Comini/Giulia/Paiola
// Version     :
// Copyright   : ICPC - Regional 2018 - Problema C - Cortador de pizza
// Description : A ideia do nosso programa ser� contar o n�mero de intersec��es.
//				 Se um plano tem N partes, uma reta ir� deix�-lo com N + 1 + I
//				 partes, onde I � o n�mero de intersec��es
//				 Para contabilizar a quantidade de intersec��es usamos uma �rvore
//				 Bin�ria de Busca
//============================================================================
#include<bits/stdc++.h>

using namespace std;

//�rvore Bin�ria de Busca
struct no{
	long long valor;
	struct no *esq;
	long long qtdeFilhosEsq;
	struct no *dir;
	long long qtdeFilhosDir;
};

typedef no* def_arvore;

void iniciaArvore(def_arvore &arvore, int valor)
{
	arvore = new no();
	arvore->valor = valor;
	arvore->dir = arvore->esq = NULL;
	arvore->qtdeFilhosDir = arvore->qtdeFilhosEsq = 0;
}

long long insere_arvore(def_arvore &arvore, int valor, long long qtdeIntersec){
    if(arvore != NULL)
	{
        if (arvore->valor > valor) 
        {
        	arvore->qtdeFilhosEsq++;
			return insere_arvore(arvore->esq, valor, qtdeIntersec + arvore->qtdeFilhosDir + 1);
        }
		else if (arvore->valor < valor) 
		{
			arvore->qtdeFilhosDir++;
			return insere_arvore(arvore->dir, valor, qtdeIntersec);
        }
        else
        	return qtdeIntersec;
	}
    else
	{
		iniciaArvore(arvore, valor);
		return qtdeIntersec;
	}
}

int main()
{
	long long X, Y, H, V, i;
	long long v1, v2;
	pair<long long, long long> xi[100000];
	long long qtdePartes;
	def_arvore arvore;
	
	
	scanf("%d %d", &X, &Y);	//Lendo X e Y, q na pr�tica n�o servir� para nada
	
	scanf("%d %d", &H, &V);	//n�mero de linhas horizontais e verticais
	
	qtdePartes = (H + V) + H*V + 1;	//De cara sabemos que todas as retas horizontais e verticais
									//se intersectam. (O "+ 1" � devido a pizza inteira, considerada como peda�o inicial)
	
	for(i = 0; i < H; i++)
	{
		scanf("%d %d", &v1, &v2);
		xi[i].first = v1;
		xi[i].second = v2;
	}
	
	//Como ordenamos as retas em rela��o a primeira coordenada, quando percorrermos o vetor
	//e inserirmos a segunda coordenada em uma ABB, se o valor se inserir a esquerda de um n�,
	//quer dizer que aquela reta tem seu ponto final anterior a outros que j� apareceram (o pai
	//e os seus filhos a direita, ou seja, maiores que ele), e essas s�o as intersec��es
	
	sort(xi, xi + H);
	iniciaArvore(arvore, xi[0].second);
	for(i = 1; i < H; i++)
	{
		qtdePartes += insere_arvore(arvore, xi[i].second, 0);
	}
	
	for(i = 0; i < V; i++)
	{
		scanf("%d %d", &v1, &v2);
		xi[i].first = v1;
		xi[i].second = v2; 
	}
		
	sort(xi, xi + V);
	iniciaArvore(arvore, xi[0].second);
	for(i = 1; i < V; i++)
	{
		qtdePartes += insere_arvore(arvore, xi[i].second, 0);
	}
	
	printf("%lld\n", qtdePartes);
}
