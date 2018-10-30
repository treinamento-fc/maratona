//============================================================================
// Name        : containers.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Regional 2016 - Problema C - Containers
// Description : 
//============================================================================
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#define MAX_V 40320

using namespace std;

//Defini��o de um container
typedef int container[2][4];

int qtdeVertices;			//Qtde de v�rtices, ou de possibilidade de disposi��o de containers
container inicial, final;	//Configura��o inicial e final
container vertice[MAX_V];	//Armazena os containers representados pelos v�rtices
int d[MAX_V];				//"Dist�ncia"/custo para chegar a uma certa configura��o

//Compara duas configura��es de containers
bool igual(container c1, container c2)
{
	for(int i = 0; i < 4; i++)
	{
		if (c1[0][i] != c2[0][i] || c1[1][i] != c2[1][i])
			return false;
	}
	return true;
}

//Copia a configura��o de um container
void copiar(container origem, container destino)
{
	for(int i = 0; i < 4; i++)
	{
		destino[0][i] = origem[0][i];
		destino[1][i] = origem[1][i];
	}
}

//Faz uma movimenta��o (existem 10 movimenta��es poss�veis)
int movimentar(container origem, container destino, int possib)
{
	int custo;
	copiar(origem, destino);
	switch(possib)
	{
		case 0:	//[0][0] <-> [1][0]
			custo = origem[0][0] + origem[1][0];
			destino[0][0] = origem[1][0];
			destino[1][0] = origem[0][0];
			break;
		case 1:	//[0][1] <-> [1][1]
			custo = origem[0][1] + origem[1][1];
			destino[0][1] = origem[1][1];
			destino[1][1] = origem[0][1];
			break;
		case 2:	//[0][2] <-> [1][2]
			custo = origem[0][2] + origem[1][2];
			destino[0][2] = origem[1][2];
			destino[1][2] = origem[0][2];
			break;
		case 3:	//[0][3] <-> [1][3]
			custo = origem[0][3] + origem[1][3];
			destino[0][3] = origem[1][3];
			destino[1][3] = origem[0][3];
			break;
		case 4:	//[0][0] <-> [0][1]
			custo = origem[0][0] + origem[0][1];
			destino[0][0] = origem[0][1];
			destino[0][1] = origem[0][0];
			break;
		case 5:	//[0][1] <-> [0][2]
			custo = origem[0][1] + origem[0][2];
			destino[0][1] = origem[0][2];
			destino[0][2] = origem[0][1];
			break;
		case 6:	//[0][2] <-> [0][3]
			custo = origem[0][2] + origem[0][3];
			destino[0][2] = origem[0][3];
			destino[0][3] = origem[0][2];
			break;
		case 7:	//[1][0] <-> [1][1]
			custo = origem[1][0] + origem[1][1];
			destino[1][0] = origem[1][1];
			destino[1][1] = origem[1][0];
			break;
		case 8:	//[1][1] <-> [1][2]
			custo = origem[1][1] + origem[1][2];
			destino[1][1] = origem[1][2];
			destino[1][2] = origem[1][1];
			break;
		case 9:	//[1][2] <-> [1][3]
			custo = origem[1][2] + origem[1][3];
			destino[1][2] = origem[1][3];
			destino[1][3] = origem[1][2];
			break;
		default:
			return -1;
	}	
	return custo;
}

map< vector<int>, int> mapa;	//Map para agilizar a busca de configura��es de containers j� encontradas

//Verifica se a configura��o encontrada j� apareceu antes (se n�o, armazena no map)
int procurarContainer(container c){
	vector<int> aux;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			aux.push_back(c[i][j]);
			
	//Usamos um map para agilizar essa consulta, uma busca linear estouraria o tempo (testado e compravado)
	if(mapa.count(aux))
		return mapa[aux];
		
	mapa[aux] = qtdeVertices;
	return -1;
}

/*void exibirContainer(container c){
	cout << endl;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}*/

//Buscar um caminho m�nimo at� a configura��o final (baseado no algoritmo de Dijkstra)
int buscar(int ini){
	priority_queue< pair<int,int> > heap;
	int s, t, peso, i;
	container novo;
	
	for(i = 0; i < MAX_V; i++)
		d[i] = 100000000;
	
	heap.push(make_pair(d[ini] = 0, ini));
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		
		//Se a configura��o final ou retirada da heap, como estamos seguindo o algoritmo de Dijkstra,
		//sabemos que encontramos a menor dist�ncia at� esse v�rtice, ou seja, o menor custo para chegar
		//a essa configura��o
		if (igual(final,vertice[s]))
			return d[s];
		
		//Passo em que visitariamos os v�rtices adjacentes, aqui, vamos gerar esses
		//v�rtices a partir das 10 movimenta��es poss�veis
		for(i = 0; i < 10; i++){
			peso = movimentar(vertice[s], novo, i);
			//exibirContainer(novo);
			t = procurarContainer(novo);
			if (t != -1)	//Se a nova configura��o j� tinha sido encontrada
			{
				if (d[s] + peso < d[t]){		//Verificamos se este caminho tem menor custo
					d[t] = d[s] + peso;
					heap.push(make_pair(-d[t],t));
				}
			}
			else			//Se a nova configura��o n�o tinha sido encontrada
			{
				//Criamos o novo v�rtice		
				t = qtdeVertices;
				qtdeVertices++;
				copiar(novo, vertice[t]);	
				//Consideramos esse caminho como o melhor, por ora, j� que n�o conheciamos nenhum outro 
				d[t] = d[s] + peso;
				heap.push(make_pair(-d[t],t));
			}
		}
	}
	return -1;
}

int main(){
	int i, j;
	qtdeVertices = 0;
	
	//Leitura dos dados
	for(i = 0; i < 2; i++)
		for(j = 0; j < 4; j++)
			cin >> inicial[i][j];
			
	for(i = 0; i < 2; i++)
		for(j = 0; j < 4; j++)
			cin >> final[i][j];
			
	//Inserindo a configura��o inicial como v�rtice inicial
	qtdeVertices++;
	copiar(inicial,vertice[0]);
	
	//Encontrando a solu��o
	cout << buscar(0) << endl;	
}
