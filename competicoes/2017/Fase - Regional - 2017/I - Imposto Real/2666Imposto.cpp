#include <bits/stdc++.h>
using namespace std;

stack<int> cidades;
vector<vector<int> > grafo(10000);
vector<bool> visitados(10000);
vector<int> pais(10000);

void visita(int city){
	visitados[city]=true;
	for(int i=0;i<grafo[city].size();i++){
		if(!visitados[grafo[city][i]]){
			cidades.push(grafo[city][i]);
			visita(grafo[city][i]);
			pais[grafo[city][i]]=city;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,carga,a,b,c;
	int capital=0;
	int imposto[10000];
	cin>>n>>carga;
	map<pair<int,int> ,int> distancia;
	
	
	for(int i=0;i<n;i++){
		cin>>imposto[i];
	}
	
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		a--;b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		distancia[{a,b}]=c;
		distancia[{b,a}]=c;
	}
	
	visita(0);
	
	int km=0;
	
	int city;
	
	while(!cidades.empty()){
		city=cidades.top();
		cidades.pop();
		km+=distancia[{pais[city],city}]*2*ceil(1.0*imposto[city]/(1.0*carga));
		imposto[pais[city]]+=imposto[city];
	}
	
	cout<<km<<endl;
	
	return 0;
}
