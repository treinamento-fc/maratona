/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Mount Marathon                                                                 */
/********************************************************************************************/
#include <iostream>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

#define MAXN 52

using namespace std;

int main(){
int card[MAXN], n;
int ans = 0, index = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &card[i]);
    
    while(index < n){
        while(index + 1 < n && card[index] >= card[index+1])
              index++;
        ans++;
        index++;
    } 
    cout << ans << endl;
}

