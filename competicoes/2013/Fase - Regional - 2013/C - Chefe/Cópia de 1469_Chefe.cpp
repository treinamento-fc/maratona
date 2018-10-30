#include <bits/stdc++.h>
using namespace std;
set<int> visitados;
vector<vector<int> > grafo(500);
int idade[500];
priority_queue <int, vector<int>, greater<int> > resultados; //min heap
int e;
int menor;
void bfs(int pessoa){
	visitados.insert(pessoa);
	if(idade[pessoa]<menor){
		if(pessoa!=e)
			menor=idade[pessoa];
	}
	int prox;
	for(int i=0;i<grafo[pessoa].size();i++){
		prox=grafo[pessoa][i];
		if(visitados.find(prox)==visitados.end()){
			bfs(prox);
		}
	}
}
int main(){
	int n,m,p,i,j,k,a,b;
	vector<int > aux;
	char c;
	while(cin>>n>>m>>p){
		for(i=0;i<n;i++)
			cin>>idade[i];
		for(i=0;i<n;i++)
			grafo[i].clear();
		for(i=0;i<m;i++){// creating the graph
			cin>>b>>a;
			a--;b--;
			grafo[a].push_back(b);
		}
		for(i=0;i<p;i++){
			cin>>c;
			if(c=='T'){ //trocando
				cin>>a>>b;
				a--;b--;
				aux=grafo[a];
				grafo[a]=grafo[b];
				grafo[b]=aux;
				for(k=0;k<n;k++){
					for(j=0;j<grafo[k].size();j++){
						if(grafo[k][j]==a){
							grafo[k][j]=b;	
						}else if(grafo[k][j]==b){
							grafo[k][j]=a;	
						}
					}
				}
			}else{
				cin>>e;
				e--;
				if(grafo[e].empty()){
					cout<<"*"<<endl;
				}else{
					visitados.clear();
					menor=101;
					bfs(e);
					cout<<menor<<endl;
				}
				/*for(k=0;k<n;k++){
					cout<<k+1<<" -> ";
					for(j=0;j<grafo[k].size();j++){
						cout<<grafo[k][j]+1<<" - ";
					}
					cout<<endl;
				}*/
			}
		}
	}
	return 0;
}
