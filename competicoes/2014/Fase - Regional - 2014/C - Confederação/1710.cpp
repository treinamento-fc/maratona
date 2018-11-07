/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Confederação                                                                   */
/* Solução: verificar se o ponto vem antes ou depois do plano, em seguida, atribuir o plano */
/* ao conjuto de regiões. Por fim, verificar qual região tem mais planetas.                 */
/* No exemplo de entrada, a região RL abaixo tem três planetas:                             */
/*   (0,1,0) fica à esquerda do primeiro e do segundo plano => LL                           */
/*   (2,2,2)  => RL                                                                         */
/*   (3,3,3)  => RL                                                                         */
/*   (5,5,5)  => RR                                                                         */
/*   (2,18,4) => RL                                                                         */
/*******************************************************************************************/

#include <iostream>
#include <string>
#include <map>

#define MAX 501


using namespace std;

typedef struct {
    int a, b, c, d;
} t_plane;

t_plane plane[MAX];

int main(){
map<string, int> :: iterator it;    
int M, N, x, y, z;
int ans, result;

    while(scanf("%d %d", &M, &N) != EOF){
        for(int i=0; i<M; i++)
            scanf("%d %d %d %d", &plane[i].a, &plane[i].b, &plane[i].c, &plane[i].d);
        
        map<string, int> counts;

        for(int i=0; i<N; i++){
            scanf("%d %d %d", &x, &y, &z);
            string region = "";

            for(int ii=0; ii<M; ii++){
                result = plane[ii].a*x + plane[ii].b*y + plane[ii].c*z;
                if(result > plane[ii].d)
                    region = region + "0";
                else 
                    region = region + "1";
            }
            counts[region] = counts[region] + 1;
        }
        ans = 0;
        for(it=counts.begin(); it!=counts.end(); it++){
            if(it->second > ans)
               ans = it->second;
        }
        printf("%d\n", ans);
    }  
}