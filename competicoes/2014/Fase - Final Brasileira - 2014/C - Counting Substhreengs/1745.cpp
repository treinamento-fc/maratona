/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Counting Substhreengs                                                          */
/* SOLUÇÃO:                                                                                 */
/********************************************************************************************/

#include <iostream>

#define MAX 1000005

#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x " = " << x << endl;)

using namespace std;


int main(){
char str[MAX];
int sum;
long long ans;

    while( scanf("%s", str) != EOF ){
        ans = 0;
        WATCH(str)
        for(int i=0; str[i]; i++){
            if(!(str[i] >= '0' && str[i] <= '9'))
               continue;
            int r[] = {1, 0, 0};
            sum = 0;
            while(str[i] >= '0' && str[i] <= '9'){
                sum = (sum + (str[i] - '0'))%3;
                ans += r[sum];
                r[sum]++;
                i++;  
            }
            i--;
        }
        cout << ans << endl;
    }
}

