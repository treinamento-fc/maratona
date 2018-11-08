/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: D as in Daedalus                                                               */
/* Solução: adhoc                                                                           */
/********************************************************************************************/

#include <iostream>

using namespace std;

int main(){
int n, m, budget;
int daedalus, sum, tmp;
int card[] = { 1, 10, 100, 1000, 10000};
int ans;

    while(scanf("%d %d", &n, &m) != EOF){
        ans = 0;
        for(int i=0; i<m; i++){
            scanf("%d %d", &budget, &daedalus);
            sum = daedalus;
            for(int j=0; j<n-1; j++){
                scanf("%d", &tmp);
                sum += tmp;
            }

            if(sum != budget){
                tmp = sum - daedalus;
                for(int j=4; j>=0; j--){
                    if(tmp + card[j] <= budget){
                        if(sum > budget)
                           ans += card[j];
                        else
                           ans += (card[j] - daedalus);
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}


