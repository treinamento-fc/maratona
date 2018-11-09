/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Exposing Corruption                                                            */
/* SOLUÇÃO: Montar o grafo com nomes de vértices únicos. Por exemplo, na primeira entrada   */
/* de teste existem dois vértices em DSP e três em PPP, então os vértices de DSP terão      */
/* os rótulos 1 e 2, enquanto os vértices de PPP terão 3, 4, 5.                             */
/* Os relacionamentos do grafo podem ser vistos como componentes. No exemplo de entrada     */
/* há 3 componentes: o primeiro formando pelos vértices {DSP(1), DSP(2), PPP(3)},           */
/* o segundo pelo vértice {PPP(1)} e o terceiro pelo vértice {PPP(2)}.                      */
/* Se for subornar qualquer vértice de um componente, é preciso trocar todos os vértices.   */
/* Assim, para subornar o componente {DSP(1), DSP(2), PPP(3)} o custo será 20 + 30 + 1 = 51,*/
/* e dois vértices sairão de DSP para PPP, enquanto um vértice virá de PPP para DSP.        */
/* Então, é preciso maximizar o número de vértices sujeito a um custo, que é basicamente o  */
/* problema da mochila. Como é necessário fazer a otimização de DSP e PPP, basta colocar um */
/* parâmetro com a direção.                                                                 */
/********************************************************************************************/

#include <iostream>

#define MAXN 205
#define MAXB 10005

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x " = " << x << endl;)
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

int D, P, R, B;
int DSP[MAXN], PPP[MAXN];

int adj[MAXN][MAXN], degree[MAXN];
int component[MAXN];
int N;

int memo[MAXN][MAXB];

typedef struct {
    int dsp, ppp, cost;
} t_comp_prop;

t_comp_prop prop[MAXN];

void dfs(int s, int id){
int t;
    component[s] = id;
    for(int i=0; i<degree[s]; i++){
        t = adj[s][i];
        if(component[t] < 0){
            dfs(t,id);
        }
    }
}

int knapsack(int w, int i, int direction){
    if(w == 0 || i == 0){
          if(direction == 0)
             return D;
          return P;
    }

    if(memo[i-1][w] > 0)
       return memo[i-1][w];
       
    if(prop[i-1].cost > w)
       return memo[i-1][w] = knapsack(w, i-1, direction);
    
    if(direction == 0){
        return memo[i-1][w] = MAX(
                   knapsack(w, i-1, direction),
                   (prop[i-1].ppp - prop[i-1].dsp) + knapsack(w - prop[i-1].cost, i - 1, direction)
                );
    } else {
        return memo[i-1][w] = MAX(
                   knapsack(w, i-1, direction),
                   (prop[i-1].dsp - prop[i-1].ppp)  + knapsack(w - prop[i-1].cost, i - 1, direction)
                );
    }
}


int main(){
int x, y, id;
        while(scanf("%d %d %d %d", &D, &P, &R, &B) != EOF){
            N = P + D;

            for(int i=0; i<MAXN; i++){
                degree[i] = 0;
                component[i] = -1;
            }
               
            for(int i=1; i<=D; i++)
                scanf("%d", &DSP[i]);
            for(int i=D+1; i<=P+D; i++)
                scanf("%d", &PPP[i]);
            for(int i=0; i<R; i++){
                scanf("%d %d", &x, &y);
                y = y + D;
                adj[x][degree[x]++] = y;
                adj[y][degree[y]++] = x;
            }

            id = 1;
            for(int i=1; i<=N; i++){
                if(component[i] < 0){
                    dfs(i, id);
                    id++;
                }
            }

            for(int i=1; i<id; i++){
                int count_dsp = 0, count_ppp = 0, cost = 0;
                for(int j=1; j<=N; j++){
                    if(component[j] == i){
                        if(j <= D){
                            count_dsp++;
                            cost += DSP[j];
                        } else {
                            count_ppp++;
                            cost += PPP[j];
                        }
                    }
                }
                prop[i].dsp = count_dsp;
                prop[i].ppp = count_ppp;
                prop[i].cost = cost;
            }

            for(int i=0; i<MAXN; i++)
               for(int j=0; j<MAXB; j++)
                   memo[i][j] = -1;                   
            printf("%d ", knapsack(B, id, 0));

            for(int i=0; i<MAXN; i++)
               for(int j=0; j<MAXB; j++)
                   memo[i][j] = -1;
            printf("%d\n", knapsack(B, id, 1));
        }
}


