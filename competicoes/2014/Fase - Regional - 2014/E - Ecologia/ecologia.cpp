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

//Variáveis do problema
int n, m;
int original[50][50];

/*a matriz mat conterá uma matriz alterada, através de uma técnica aprendida nas aulas de PO.
Vamos inverter o valor de todos os números da matriz original, somando o maior valor da matriz
original a todas as posições, de forma que os números fiquem todos não negativos. Isso vai permitir
encarar o problema como um problema de minimização e, por consequência, os "ramos" do backtracking
que estrapolarem a menor soma encontrada até o momento poderão ser "cortados"*/
int mat[50][50], maximo;

/*O valorMin vai armazenar a menor soma encontrada, e arvoresSalvas o valor da maior soma encontrada na
matriz original (encontrado a partir da correção de valorMin) */
int valorMin = 999999999, arvoresSalvas = 0;

/*Uma sugestão que encontramos no fórum do URI é não explorar soluções que partam de posições menores
que a média de todos os elementos da matriz (considerando a matriz original)*/
double media;

/*Usamos uma heap para escolher por qual posição começar a testar as possibilidades, a ideia é começar
pelo menor valor (considerando a matriz alterada). Cada tupla é da forma <-mat[i][j], i, j>*/
priority_queue<tuple<int,int,int> > heap;

/*Por fim, usamos um map para salvar o valor encontrado em áreas já testadas, de forma que 
não precisamos calcular denovo se o backtracking acabar passando por ela novamente*/
map<set<pair<int, int> >, int> memo;

//Função para verificar se a posição está dentro dos limites
bool ehValido(int i){
	return ((i >= 0) && (i < n));
}

//Coração do programa, encontra a area com a menor soma (na matriz alterada) usando backtracking e PD
int backtracking(set< pair<int,int> > area, int i, int j, int soma)
{
	int tamAnt = area.size(), tam;
	area.insert(make_pair(i,j));	//Inserindo posição (i,j)
	tam = area.size();
	if (tam == tamAnt)	//Se o elemento já estava no conjunto, encerramos esse ramo
		return soma;
		
	if (memo.count(area)){	//Se já passamos por esse caminho
		return memo[area];  //Retornamos o valor salvo
	}
		
	soma += mat[i][j];		
	if (soma > valorMin)	//Se a soma dessa área é maior do que a menor já encontrada
		return soma;		//não há porque continuar explorando esse caminho
	
	if (tam < m)			//Se ainda não temos uma área de tamanho m
	{
		pair<int, int> pos;
		int valorMinimo = 999999999;
		
		//Exploramos todas as possibilidades (tentando adicionar uma posição adjacente
		//a qualquer uma das posições já inclusas dentro da nossa área)
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
	else if (soma < valorMin)	//se a área já está completa (com tamanho m) e é a melhor que temos até agora
	{
		valorMin = soma;						//alteramos o valorMin
		arvoresSalvas = -valorMin + m*maximo;	//e corrigimos o valor para obter o número de árvores salvas (revertendo as transformações feitas na matriz)
	}
	memo[area] = soma;				//Salvando o valor encontrado nesse caminho
	area.erase(make_pair(i,j));		//Retirando a posição (i, j) da área (nem seria necessário)
	return soma;
}

int resolver(){
	//essa função basicamente chama o backtracking para cada uma das posições
	//inseridas na heap, e no final retorna o número máximo de árvores que podem
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

	//Lendo a matriz, somando seus valores para o cálculo da média e encontrando o mínimo e o máximo
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
		media /= float(n*n);	//Cálculo da média
		
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
	else //Caso particular em que todos os elementos são iguais
	{
		cout << m*maximo << endl;
	}
}
