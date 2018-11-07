/************************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                                   */
/* PROBLEMA: Brincadeira                                                                        */
/*                                                                                              */
/* Solução: O circuito LFSR é só um pretexto para chegar ao problema principal que é            */
/* encontrar uma subsequência de tamanho >= Y que seja divisível por X. Como o tamanho do       */
/* problema é grande, não é possível usar uma solução O(N^2).                                   */ 
/* A solução deve começar com o acúmulo das somas em um vetor, por exemplo:                     */
/* Sequência: 169, 212, 106, 53,  26,  141, ...                                                 */
/* Soma:      0,   169, 381, 487, 540, 566, 707, ...                                            */
/* Soma no intervalo:  s(i,j) = Soma[j] - Soma[i-1]                                             */
/* Exemplo: s(2,3) = Soma[3] - Soma[1] = 487 - 169 = 318, pois 212 + 106 = 318                  */
/* E então, basta verificar se a soma do intervalo é divisível por X, portanto:                 */
/*     (Soma[j] - Soma[i-1])%X = 0                                                              */
/*                                                                                              */
/* Porém, o acúmulo das somas irá causar um overflow rapidamente, então deve ser armazenado     */
/* o módulo da soma em cada posição, no examplo abaixo X = 238.                                 */
/* Soma: 0, 169, 143, 11, 64, 90, 231, 63 ...                                                   */
/*                                                                                              */
/* Agora para encontrar o intervalo que seja divisível por X, basta encontrar o intervalo (i,j) */
/* cuja diferença seja zero, pois (Soma[j]%X - Soma[i-1]%X) é equivalente a                     */
/* (Soma[j] - Soma[j])%X, e este valor deve ser zero, como mostrado anteriormente.              */
/* Evidentemente, para que Soma[j] - Soma[i-1] seja zero é preciso que os valores sejam iguais. */
/* Assim, não é preciso percorrer o vetor, basta verificar se a soma do módulo já foi calculada */
/* anteriormente. Em caso positivo, a diferença será zero, e basta verificar se o comprimento   */
/* é maior que Y.                                                                               */
/************************************************************************************************/

#include <iostream>

#define MAX 1000002

using namespace std;

unsigned int N, T, A, X, Y;
int bits[MAX], idx[MAX];


void clock_circuit(){
unsigned int current=0, previous=0, result=0, index=0;

    for(int i=0; i<T; i++){
        current = (1 << bits[i]) & A;
        // se houver apenas uma torneira o outro bit é zero, então previous não ser alterado para o valor do bit atual
        if(i == 0 && T > 1){
            previous = current;
        } else {
            if(( previous == 0 && current > 0 ) || ( previous > 0 && current == 0 )) 
                result = 1;
            else 
                result = 0;
            previous = result;
        }
    }

    A = A >> 1;

    if(result > 0)       
        A = A | ( 1 << ( N-1 ) );
    
}


int main(){
  
   while( scanf("%d %d %d %d %d", &N, &T, &A, &X, &Y) != EOF ){
        for(int i=0; i<T; i++)
            scanf("%d", &bits[i]);
        
        unsigned int acc = 0;

        for(int i=0; i<MAX; i++)
           idx[i] = 0;
        
        idx[0] = 1;

        for(int i=2; ; i++){
           acc = (acc +  A)%X;
           if(idx[acc]){
               if( i - idx[acc]  >=  Y){
                   printf("%d %d\n", idx[acc] - 1 , i - 2);
                   break;
               }
           } else {
               idx[acc] = i;
           }
           clock_circuit();   
        }
   }
}


