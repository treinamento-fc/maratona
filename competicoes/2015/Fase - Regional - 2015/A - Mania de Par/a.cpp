/*******************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                              */
/* PROBLEMA: Mania de Par                                                                  */
/* Solução: Modifição do Dijkstra. Basta acrescentar uma coordenada no vetor de distâncias */
/* para encontrar o caminho mínimo passando por um número par/ímpar de arestas             */
/*******************************************************************************************/

#include <iostream>
#include <queue>

#define INF 2000000
#define MAX_V 10001
#define MAX_A 10001

using namespace std;

typedef struct {
    int v, w;
} TAdj; 

TAdj adj[MAX_V][MAX_A];
int grau[MAX_V];
pair<int, int> d[MAX_V];

int C, V;



void dijkstra(){
    priority_queue < pair<int, int> > heap;
    int s, t, weight;
    

    for(int i=1; i<= C; i++)
        d[i] = make_pair(INF, INF);
    d[1] = make_pair(0, INF);
    heap.push(make_pair(0, 1));
    
    while(!heap.empty()){
        s = heap.top().second;
        heap.pop();
        for(int i=0; i<grau[s]; i++){
            t = adj[s][i].v;
            weight = adj[s][i].w;
            if(d[s].first + weight < d[t].second){
                d[t].second = d[s].first + weight;
                heap.push(make_pair(-d[t].second, t));
            }
            if(d[s].second + weight < d[t].first){
                d[t].first = d[s].second + weight;
                heap.push(make_pair(-d[t].first, t));                
            }
        }
    }
}

int main(){
    int u, v, w;

    while(scanf("%d %d", &C, &V) != EOF){
        for(int i=1; i<grau[C]; i++)
           grau[i] = 0;
        for(int i=0; i<V; i++){
            scanf("%d %d %d", &u, &v, &w);
            adj[u][grau[u]].v = v;
            adj[u][grau[u]++].w = w;
            adj[v][grau[v]].v = u;
            adj[v][grau[v]++].w = w;
        }
        dijkstra();
        if(d[C].first != INF)
           printf("%d\n", d[C].first);
        else
           printf("-1\n");

    }
}



