//============================================================================
// Name        : J.cpp
// Author      : Rafael
// Version     :
// Copyright   : Maratona Programação - Final - 2010 - Problema J - Jollo
// Solução     : Encontrar a menor carta que garanta a vitória
//============================================================================

#include <stdio.h>

int main(){
	int a, b, c, x, y, aux;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	while(a && b && c && x && y){
		//Reatribui os valores, ordenando a>b>c
		if(a>b){
			if(a>c){
				if(b>c){	//a>b>c
				}
				else{		//a>c>b
				aux=c;
				c=b;
				b=aux;
				}
			}
			else{			//c>a>b
				aux=a;
				a=c;
				c=b;
				b=aux;
			}
		}else{
			if(b>c){
				if(a>c){	//b>a>c
					aux=a;
					a=b;
					b=aux;
				}
				else{		//b>c>a
					aux=a;
					a=b;
					b=c;
					c=aux;
				}
			}
			else{			//c>b>a
				aux=a;
				a=c;
				c=aux;
			}
		}
		//Reatribui os valores, ordenando x>y
		if(y>x){
			aux=x;
			x=y;
			y=aux;
		}
		
		if(y>a){							//jogo ganho, precisa da menor possivel
			if		(c!=1) 	aux=1;
			else if	(b!=2) 	aux=2;
			else if	(a!=3) 	aux=3;
			else if (y!=4)	aux=4;
			else if (x!=5)	aux=5;
			else 			aux=6; 
		}
		else if(x>a){						//possui a maior carta
			if(y>b){						//possui a terceira maior carta, precisa da quarta melhor carta
				if		(y!=b+1)	aux=b+1;
				else if	(a!=y+1)	aux=y+1;
				else if	(x!=a+1)	aux=a+1;
				else if	(x!=52)		aux=x+1;
				else				aux=0;
			}
			else{							//nao possui a terceira melhor carta, precisa da segunda melhor carta
				if(a!=51){
					if(x!=a+1)	aux=a+1;
					else		aux=x+1;
				}	
				else			aux=0;		//nao é possivel conseguir a segunda melhor carta
			}
		}else if(y>b){						//nao possui a melhor carta, possui a segunda e a terceira melhor carta, precisa da quarta melhor
			if		(y!=b+1)	aux=b+1;
			else if	(x!=y+1)	aux=y+1;
			else if	(a!=x+1)	aux=x+1;
			else if	(a!=52)		aux=a+1;
		}else 					aux=0;		//nao possui a melhor carta, nao possui a segunda e a terceira melhor carta, impossivel garantir
		
		if(aux)	printf("%d\n", aux);		//imprimime a menor carta necessaria
		else	printf("-1\n");				//impossivel garantir a vitoria... :(
		
		scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);	//reprocessamento
	}
	return 0;
}
