/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Exposing Corruption                                                            */
/* SOLUÇÃO:                                                                                 */
/********************************************************************************************/

#include <iostream>
#include <cmath>

#define MAXN 1005

#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x " = " << x << endl;)

using namespace std;

int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}


int main(){
int n;
int T[MAXN];
int tmp, sum, sum2;

    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++)
            scanf("%d", &T[i]);
        
        qsort(T, n, sizeof(int), cmp);

        sum = sum2 = 0;
        for(int i=0; i<n-1; i+=2){
            tmp = abs(T[i] - T[i+1]);
            sum += min(tmp, 24 - tmp);
        }

        tmp = abs(T[0] - T[n-1]);
        sum2 += min(tmp, 24 - tmp);

        for(int i=1; i<n-1; i+=2){
             tmp = abs(T[i] - T[i+1]);
             sum2 += min(tmp, 24 - tmp);
        }
        printf("%d\n", sum < sum2 ? sum : sum2);


    }

}

