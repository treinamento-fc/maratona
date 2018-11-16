/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Building a Field                                                               */
/********************************************************************************************/

#include <iostream>
#include <set>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

#define MAXN 100005

using namespace std;

int main(){
int n, L[MAXN], count;
long long aux, total;
set<int> points;

    scanf("%d", &n);
    
    total = 0;
    points.insert(0);
    for(int i=0; i<n; i++){
        scanf("%d", &L[i]);
        total += L[i];
        points.insert(total);
    }
    
    if(total%2 == 1){
        cout << "N" << endl;
        return 0;
    }
    
    count = aux = 0;
    for(int i=0; i<n; i++){
        aux += L[i];
        if(points.count((aux + total/2)%total) > 0){
            count++; 
        }
    }

    if(count >= 4)
        printf("Y\n");
    else
        printf("N\n");

}


