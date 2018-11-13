/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Intrepid climber                                                               */
/* SOLUÇÃO: Todo caminho até um landmark será percorrido e irá voltar para visitar o        */
/* próximo landmark. O único caso que não irá voltar é no último landmark. Então o custo    */
/* mínimo de visitar todos landmarks é o peso total da árvore menos os nós não visitados    */
/* e o maior caminho de retorno.                                                            */
/********************************************************************************************/

#include <iostream>
#include <cmath>

#define MAXN 100005

#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x " = " << x << endl;)

using namespace std;

int N, F;
int parent[MAXN], weight[MAXN], visited[MAXN], dist[MAXN];
int landmark[MAXN];

void visitNode(int u){
    if(u <= 0)
       return;

    visited[u] = 1;

    if(!visited[parent[u]])
        visitNode(parent[u]);

    dist[u] = dist[parent[u]] + weight[u];
}


int main(){
int a, b, c;
long long sum;
        while(scanf("%d %d", &N, &F) != EOF){
            for(int i=1; i<=N; i++){
                parent[i] = -1;
                visited[i] = 0;
                dist[i] = 0;
                weight[i] = 0;
            }
            parent[1] = 0;
            dist[0] = 0;
            visited[0] = 1;
            sum = 0;

            for(int i=1; i<N; i++){
                scanf("%d %d %d", &a, &b, &c);
                parent[b] = a;
                weight[b] = c;
                sum += c;
            }

            for(int i=0; i<F; i++){
                scanf("%d",&landmark[i]);
                visitNode(landmark[i]);
            }

            int notVisitedSum = 0;
            for(int i=1; i<=N; i++){
                if(!visited[i]){
                    notVisitedSum += weight[i];
                }
            }

            sum = sum - notVisitedSum;
            int longestPath = 0;
            for(int i=0; i<F; i++)
                longestPath = max(longestPath, dist[landmark[i]]);

            sum = sum - longestPath;
            cout << sum << endl;
        }
}

