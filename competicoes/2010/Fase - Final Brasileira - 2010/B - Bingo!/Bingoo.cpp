//============================================================================
// Name        : B.cpp
// Author      : Rafael
// Version     :
// Copyright   : Maratona Programa��o - Final - 2010 - Problema B - Bingo!
// Solu��o     : Checar se todos os n�meros do bingo podem ser sorteados
//============================================================================

#include <stdio.h>

int main(){
	int n, b;								//n:0 a 90; b:2 a n+1;
	scanf("%d %d", &n, &b);					//Recebe os inputs
	while(n && b){							//Controle de recorrencia
		int setN[n+1], dif;					//Armazena o valor de verdade para possibilidade de tirar casa n�mero
		for(int i=0; i<=n; i++){			//Formata o vetor possibilidades
			setN[i]=0;						//
		}									//
		int setB[b];						//Armazena os numeros mantidos
		for(int i=0; i<b; i++){				//
			scanf("%d", &setB[i]);			//Recebe input dos numerod mantidos
			for(int j=0; j<=i; j++){		//Percorre o index de n�meros mantidos
				if(setB[i]-setB[j]>0){		//Checa se setB[i] � maior que setB[j]
					dif=setB[i]-setB[j];	//Armazena a diferen�a entre o setB[i] e setB[j]
					if(!setN[dif]){			//Checa se dif n�o foi adicionado ao vetor N
						setN[dif]=1;		//adiciona dif ao vetor N
					}
				}else{						//Caso setB[j] seja maior que setB[i] (i-j deu negativo acima)
					dif=setB[j]-setB[i];	//Armazena a diferen�a entre o setB[j] e setB[i]
					if(!setN[dif]){			//Checa se dif n�o foi adicionado ao vetor N
						setN[dif]=1;		//adiciona dif ao vetor N
					}
				}
			}
		}
		int sim=1;							//Registra se todos os n�meros podem ser sorteados
		for (int i=0; i<=n; i++){			//
			if(!setN[i]){					//Checa se algum n�mero NAO pode ser sorteado
				sim=0;						//Caso algum n�mero nao possa ser sorteado, muda sim para falso
			}
		}
		if(sim)	printf("Y\n");				//caso sim, SIM!
		else	printf("N\n");				//caso n�o, N�O...	:(
		scanf("%d %d", &n, &b);				//Recorrencia
	}
	return 0;
}
