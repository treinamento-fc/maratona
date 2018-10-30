//============================================================================
// Name        : B.cpp
// Author      : Rafael
// Version     :
// Copyright   : Maratona Programação - Final - 2010 - Problema B - Bingo!
// Solução     : Checar se todos os números do bingo podem ser sorteados
//============================================================================

#include <stdio.h>

int main(){
	int n, b;								//n:0 a 90; b:2 a n+1;
	scanf("%d %d", &n, &b);					//Recebe os inputs
	while(n && b){							//Controle de recorrencia
		int setN[n+1], dif;					//Armazena o valor de verdade para possibilidade de tirar casa número
		for(int i=0; i<=n; i++){			//Formata o vetor possibilidades
			setN[i]=0;						//
		}									//
		int setB[b];						//Armazena os numeros mantidos
		for(int i=0; i<b; i++){				//
			scanf("%d", &setB[i]);			//Recebe input dos numerod mantidos
			for(int j=0; j<=i; j++){		//Percorre o index de números mantidos
				if(setB[i]-setB[j]>0){		//Checa se setB[i] é maior que setB[j]
					dif=setB[i]-setB[j];	//Armazena a diferença entre o setB[i] e setB[j]
					if(!setN[dif]){			//Checa se dif não foi adicionado ao vetor N
						setN[dif]=1;		//adiciona dif ao vetor N
					}
				}else{						//Caso setB[j] seja maior que setB[i] (i-j deu negativo acima)
					dif=setB[j]-setB[i];	//Armazena a diferença entre o setB[j] e setB[i]
					if(!setN[dif]){			//Checa se dif não foi adicionado ao vetor N
						setN[dif]=1;		//adiciona dif ao vetor N
					}
				}
			}
		}
		int sim=1;							//Registra se todos os números podem ser sorteados
		for (int i=0; i<=n; i++){			//
			if(!setN[i]){					//Checa se algum número NAO pode ser sorteado
				sim=0;						//Caso algum número nao possa ser sorteado, muda sim para falso
			}
		}
		if(sim)	printf("Y\n");				//caso sim, SIM!
		else	printf("N\n");				//caso não, NÃO...	:(
		scanf("%d %d", &n, &b);				//Recorrencia
	}
	return 0;
}
