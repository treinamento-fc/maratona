/*********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                                */
/* PROBLEMA: Highway Decommission                                                            */
/* SOLUÇÃO: Pequena alteração no Dijkstra. Caso exista mais de um caminho com a mesma        */
/* distância, basta armazenar a aresta com custo mínimo de manutenção, senão armazena        */ 
/* o custo encontrado.                                                                       */
/*********************************************************************************************/

#include <iostream>
#include <queue>

#define MAXN 10005
#define MAXM 10005


#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

const long long INF = 1000000000000l;

using namespace std;

typedef struct {
    int v, length, cost;
} t_adj;

t_adj adj[MAXN][MAXM];
int degree[MAXN];
long long dist[MAXN], cost[MAXN];

int N, M;

void dijkstra(int start){
priority_queue< pair<int, int> > heap;
int u, v, l, c;

    heap.push(make_pair(dist[start] = 0, start));
    while(!heap.empty()){
        u = heap.top().second;
        heap.pop();

        for(int i=0; i<degree[u]; i++){
            
            v = adj[u][i].v;
            l = adj[u][i].length;
            c = adj[u][i].cost;
            if(dist[u] + l <= dist[v]){
                if(dist[u] + l == dist[v]){
                    if(c < cost[v])
                       cost[v] = c;
                }
                else {
                    cost[v] = c;
                }
                   
                dist[v] = dist[u] + l;
                heap.push(make_pair(-dist[v], v));
            }
        }
    }
}

int main(){
int a, b, l, c;
    while(scanf("%d %d", &N, &M) != EOF){
        for(int i=0; i<=N; i++){
            degree[i] = 0;
            dist[i] = cost[i] = INF;
        }
        for(int i=0; i<M; i++){
            scanf("%d %d %d %d", &a, &b, &l, &c);
            adj[a][degree[a]].v = b;
            adj[a][degree[a]].length = l;
            adj[a][degree[a]].cost = c;
            adj[b][degree[b]].v = a;
            adj[b][degree[b]].length = l;
            adj[b][degree[b]].cost = c;
            degree[a]++; degree[b]++;
        }
        dijkstra(1);
        long long sum = 0;
        for(int i=2; i<=N; i++){
            sum += cost[i];
        }
        cout << sum << endl;
    }
}


