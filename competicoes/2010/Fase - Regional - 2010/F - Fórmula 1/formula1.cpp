//============================================================================
// Name        : formula1.cpp
// Author      : Pedro H. Paiola
// Version     :
// Copyright   : ICPC - Regional 2010 - Problema F - Fórmula 1
// Description :
//============================================================================

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool sortDec(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.first > b.first);
}

int main(){
	int corrida[100][100];
	int sistema[10][100];
	int sk[10];
	vector<pair<int,int> > pontuacao[10];
	int g, p, s, k, i, j;
	
	while(true)
	{
		//Lendo quantidade de GPs e de competidores
		cin >> g >> p;
		if (g == 0)
			break;
			
		//Lendo a posição de cada jogador em cada gp
		for(i = 0; i < g; i++)
			for(j = 0; j < p; j++)	
				cin >> corrida[i][j];
				
		//Lendo os sistemas de pontuação
		cin >> s;
		for(i = 0; i < s; i++)
		{
			cin >> k;
			sk[i] = k;
			for(j = 0; j < k; j++)
				cin >> sistema[i][j];
		}
		
		//Inicializando pontuações
		for(j = 0; j < s; j++)
		{
			pontuacao[j].resize(p);
			for(i = 0; i < p; i++)
				pontuacao[j][i] = *(new pair<int,int>(0,i+1));
		}
		
		//Computando pontuações
		for(i = 0; i < g; i++){
			for(j = 0; j < p; j++){
				for(k = 0; k < s; k++){
					if (corrida[i][j] <= sk[k])
						pontuacao[k][j].first += sistema[k][corrida[i][j] - 1];
				}
			}
		}
		
		//Ordenando pontuações e exibindo o(s) campeão(ões)
		for(k = 0; k < s; k++){
			stable_sort(pontuacao[k].begin(), pontuacao[k].end(), sortDec);
			cout << pontuacao[k][0].second;
			i = 1;
			while (pontuacao[k][i].first == pontuacao[k][i-1].first)
			{
				cout << " " << pontuacao[k][i].second;
				i++;
			}
			cout << endl;
		}
	}
}
