/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: A Symmetrical Pizza                                                            */
/********************************************************************************************/
#include <iostream>

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)


using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
int p1, p2;
    scanf("%d.%d", &p1, &p2);

    printf("%d\n", 36000/gcd(p1*100+p2, 36000));

}
