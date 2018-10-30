#include <bits/stdc++.h>
using namespace std;
int main(){
	
	// declaração de variáveis
	int i,j,n;
	int notas[12]; for(i=0;i<12;i++) notas[i]=0;// iniciando a quantidade de notas tecladas
	int x;
	int invalidas[5]={1,3,6,8,10};
	bool ok;
	string nomes[]={"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
	
	cin>>n;
	//loop para receber os inteiros 
	for(i=0;i<n;i++){
		cin>>x;
		x--; // para a nota N=1 se tornar N=0 e coincidir com o índice do vetor
		
		x=x%12; // o teclado possui uma sequencia periódica de 12 notas, assim: do do# re re# mi     [...]       si    do do# re re# mi
				// ao transformar x no resto da divisão,						0   1  2   3   4   5 6 7 8 9 10  11    12 13  14 15  16
				//  o número normaliza para o começo da sequencia, assim:		0   1  2   3   4   5 6 7 8 9 10  11     0  1  2  3    4
				
		notas[x]++; // a nota teclada é armazenada
				
	}
	
	// precisamos encontrar uma escala
	for(i=0;i<12;i++){ // testaremos os 12 tons mas vamos parar se encontrarmos uma escala válida
		ok=true;//															ou seja, que não tenha sido utilizadas notas fora do intervalo
		for(j=0;j<5;j++){ // chamei as notas fora de escala de inválidas, agora vms verificar uma por uma
			if(notas[(i+invalidas[j])%12]>0){
				ok=false;
				break; // se uma das notas inválidas foi teclada não precisa testar as próximas, vamos para a proxima escala i+1
			}	
		}
		if(ok){
			// mostra resultado
			cout<<nomes[i]<<endl;
			break; // paramos de testar porque achamos uma escala
		}else{
			if(i==11){ // se tentamos a ultima escala e também nao foi competada, acabou
				cout<<"desafinado"<<endl;
			}
		}
	}
	
	return 0;
}
