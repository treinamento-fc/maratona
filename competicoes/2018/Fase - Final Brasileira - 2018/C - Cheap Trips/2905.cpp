/*********************************************************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                                                                    */
/* PROBLEMA: Cheap Trips                                                                                                         */
/* SOLUÇÃO: O problema pode ser modelado pela minimização da função abaixo.                                                      */
/* Apesar do N chegar até 10^4, a implementação top-down foi suficiente para resolver o problema. Evidentemente a solução        */
/* iterativa bottom-up é mais rápida.                                                                                            */
/*                                                                                                                               */
/* f(n) = min(                                                                                                                   */
/*  C[n] + f(n-1),                                                                                                               */
/*  C[n-1] + 0.5*C[n] + f(n-2),  ---> desde que D[n-1] seja < 120                                                                */
/*  C[n-2] + 0.5*C[n-1] + 0.25*C[n] + f(n-3), ---> desde que D[n-2 até n-1] seja < 120                                           */
/*  C[n-3] + 0.5*C[n-2] + 0.25*C[n-1] + 0.25*C[n] + f(n-4), ---> desde que D[n-3 até n-1] seja < 120                             */
/*  C[n-4] + 0.5*C[n-3] + 0.25*C[n-2] + 0.25*C[n-1] + 0.25*C[n] + f(n-5), ---> desde que D[n-4 até n-1] seja < 120               */
/*  C[n-5] + 0.5*C[n-4] + 0.25*C[n-3] + 0.25*C[n-2] + 0.25*C[n-1] + 0.25*C[n] + f(n-6), ---> desde que D[n-5 até n-1] seja < 120 */
/* )                                                                                                                             */
/*********************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

#define MAXN 10005
const double INF = 10000000000000.0;

using namespace std;

int N;
double D[MAXN];
double C[MAXN];
double memo[MAXN];

double topDownMemo(int index){
vector<double> tmp;
double cost, minval;
int duration;

    if(index < 0)
        return 0.0;

    if(memo[index] != INF )
        return memo[index];

    tmp.push_back(C[index] + topDownMemo(index-1));

    if(index-1 >= 0 && D[index-1] < 120.0)
        tmp.push_back(C[index-1] + 0.5*C[index] + topDownMemo(index-2));
    
    for(int i=index-5; i<=index-2; i++){
        if(i < 0)
            continue;
            
        cost = C[i] + 0.5*C[i+1];
        duration = D[i] + D[i+1];

        for(int k=i+2; k<N && k<=index; k++){
            cost += (0.25*C[k]);
            duration += D[k];
        }
            
        duration -= D[index];
        if(duration < 120.0)
            tmp.push_back(cost + topDownMemo(i-1));
        
    }

    minval = INF;
    for(int i=0; i<tmp.size(); i++){
        if(tmp[i] < minval)
            minval = tmp[i];
    }
    
    return memo[index] = minval;
}

double bottomUp(){
int i, j, k;
double cost;
int duration;

    memo[0] = C[0];
    for(i=1; i<N; i++){
        memo[i] = min(memo[i], memo[i-1] + C[i]);

        if(D[i-1] < 120.0){
            if(i - 2 >= 0)
                memo[i] = min(memo[i], C[i-1] + 0.5*C[i] + memo[i-2]);
            else
                memo[i] = min(memo[i], C[i-1] + 0.5*C[i]);
        }

        for(j=i-5; j<=i-2; j++){
            if(j < 0)
               continue;
            
            cost = C[j] + 0.5*C[j+1];
            duration = D[j] + D[j+1];

            for(k=j+2; k<N && k<=i; k++){
                cost += (0.25*C[k]);
                duration += D[k];
            }
            
            duration -= D[i];
            if(duration < 120.0){
                if(i-1 >= 0)
                    memo[i] = min(memo[i], cost + memo[j-1]);
                else
                    memo[i] = min(memo[i], cost);
            }
        }
    }

    return memo[N-1];
}


int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%lf %lf", &D[i], &C[i]);

    for(int i=0; i<MAXN; i++)
        memo[i] = INF;

//   printf("%.2lf\n", topDownMemo(N-1));

  printf("%.2lf\n", bottomUp());
}


