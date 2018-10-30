//============================================================================
// Name        : ecologia.cpp
// Author      : Paiola / Comini
// Version     :
// Copyright   : ICPC - Regional 2014 - Problema E - Ecologia
// Description : 
//============================================================================

#include<iostream>
#include<set>
#include<map>
#include<queue>

using namespace std;

//Vari�veis do problema
int n, m;
int original[50][50];

/*a matriz mat conter� uma matriz alterada, atrav�s de uma t�cnica aprendida nas aulas de PO.
Vamos inverter o valor de todos os n�meros da matriz original, somando o maior valor da matriz
original a todas as posi��es, de forma que os n�meros fiquem todos n�o negativos. Isso vai permitir
encarar o problema como um problema de minimiza��o e, por consequ�ncia, os "ramos" do backtracking
que estrapolarem a menor soma encontrada at� o momento poder�o ser "cortados"*/
int mat[50][50], maximo;

/*O valorMin vai armazenar a menor soma encontrada, e arvoresSalvas o valor da maior soma encontrada na
matriz original (encontrado a partir da corre��o de valorMin) */
int valorMin = 999999999, arvoresSalvas = 0;

/*Uma sugest�o que encontramos no f�rum do URI � n�o explorar solu��es que partam de posi��es menores
que a m�dia de todos os elementos da matriz (considerando a matriz original)*/
double media;

/*Usamos uma heap para escolher por qual posi��o come�ar a testar as possibilidades, a ideia � come�ar
pelo menor valor (considerando a matriz alterada). Cada tupla � da forma <-mat[i][j], i, j>*/
priority_queue<tuple<int,int,int> > heap;

/*Por fim, usamos um map para salvar o valor encontrado em �reas j� testadas, de forma que 
n�o precisamos calcular denovo se o backtracking acabar passando por ela novamente*/
map<set<pair<int, int> >, int> memo;

//Fun��o para verificar se a posi��o est� dentro dos limites
bool ehValido(int i){
	return ((i >= 0) && (i < n));
}

//Cora��o do programa, encontra a area com a menor soma (na matriz alterada) usando backtracking e PD
int backtracking(set< pair<int,int> > area, int i, int j, int soma)
{
	int tamAnt = area.size(), tam;
	area.insert(make_pair(i,j));	//Inserindo posi��o (i,j)
	tam = area.size();
	if (tam == tamAnt)	//Se o elemento j� estava no conjunto, encerramos esse ramo
		return soma;
		
	if (memo.count(area)){	//Se j� passamos por esse caminho
		return memo[area];  //Retornamos o valor salvo
	}
		
	soma += mat[i][j];		
	if (soma > valorMin)	//Se a soma dessa �rea � maior do que a menor j� encontrada
		return soma;		//n�o h� porque continuar explorando esse caminho
	
	if (tam < m)			//Se ainda n�o temos uma �rea de tamanho m
	{
		pair<int, int> pos;
		int valorMinimo = 999999999;
		
		//Exploramos todas as possibilidades (tentando adicionar uma posi��o adjacente
		//a qualquer uma das posi��es j� inclusas dentro da nossa �rea)
		for(set< pair<int,int> >::iterator it = area.begin(); it != area.end(); it++){
			pos = *it;
			if (ehValido(pos.first - 1))
				valorMinimo = min(valorMinimo, backtracking(area, pos.first - 1, pos.second, soma));
			if (ehValido(pos.first + 1))
				valorMinimo = min(valorMinimo, backtracking(area, pos.first + 1, pos.second, soma));
			if (ehValido(pos.second - 1))
				valorMinimo = min(valorMinimo, backtracking(area, pos.first, pos.second - 1, soma));
			if (ehValido(pos.second + 1))
				valorMinimo = min(valorMinimo, backtracking(area, pos.first, pos.second + 1, soma));

		}
		//a menor soma que podemos encontrar por esse caminho
		soma = valorMinimo;		
	}
	else if (soma < valorMin)	//se a �rea j� est� completa (com tamanho m) e � a melhor que temos at� agora
	{
		valorMin = soma;						//alteramos o valorMin
		arvoresSalvas = -valorMin + m*maximo;	//e corrigimos o valor para obter o n�mero de �rvores salvas (revertendo as transforma��es feitas na matriz)
	}
	memo[area] = soma;				//Salvando o valor encontrado nesse caminho
	area.erase(make_pair(i,j));		//Retirando a posi��o (i, j) da �rea (nem seria necess�rio)
	return soma;
}

int resolver(){
	//essa fun��o basicamente chama o backtracking para cada uma das posi��es
	//inseridas na heap, e no final retorna o n�mero m�ximo de �rvores que podem
	//ser salvas
	set< pair<int, int> > area;
	int i, j;
	
	while(!heap.empty())
	{
		i = get<1>(heap.top());
		j = get<2>(heap.top());
		heap.pop();
		backtracking(area, i, j, 0);	
	}

	return arvoresSalvas;
}

int main(){	
	int i, j, minimo = 999999999;
	cin >> n >> m;
	media = 0;
	maximo = 0;

	//Lendo a matriz, somando seus valores para o c�lculo da m�dia e encontrando o m�nimo e o m�ximo
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
		{
			cin >> original[i][j];
			media += original[i][j];
			maximo = max(maximo, original[i][j]);
			minimo = min(minimo, original[i][j]);
		}
	}
	if (minimo != maximo)
	{
		media /= float(n*n);	//C�lculo da m�dia
		
		//Criando matriz alterada e inserindo os elementos na heap
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
			{
				mat[i][j] = -original[i][j] + maximo;
				if (original[i][j] >= media)
					heap.push(make_tuple(-mat[i][j], i, j));
			}
		}
		cout << resolver() << endl;	
	}
	else //Caso particular em que todos os elementos s�o iguais
	{
		cout << m*maximo << endl;
	}
}
