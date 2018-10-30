#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int main(){
	int h1,h2,m1,m2,aux=0,aux2=0;
	while(cin>>h1>>m1>>h2>>m2){ // entrada de dados hora 1 minuto 1  hora 2 minuto 2
		if (!h1&&!h2&&!m1&&!m2){ //para quando for 0 0 0 0 
			break;
		}
		aux = 0; //auxiliar que conta minutos
		aux2 = 0; //auxiliar que conta hora
		if(m2<m1){ //se o minuto 2 for menor que m1
			aux = 60 - m1; //adiciona na auxliar de minutos o quanto o ponteiro de minutos 1 gira até dar 1 hora
			aux += m2; // adiciona m2 na auxiliar de minutos
		//	cout << aux<<endl;
			h1 ++; //acrescenta uma hora na "hora atual"
		}else{
			aux = m2-m1; // coloca na auxiliar a diferença entre os minutos
		}
		if (h2<h1){ // caso hora 2 > hora 1
			aux2 = 24 - h1; //adiciona no auxiliar de hora o restando do dia "começando de h1"
			aux2 += h2; // adiciona na auxilia de hora a hora 2
			//cout << aux2<<endl;
		}else{
				if(h2>h1)aux2 = h2-h1; // // adiciona na auxiliar de hora as horas restantes para o despertador tocar
				//maior hora - menor hora
				else if(m2!=m1 && h1==h2) aux2+=0; //caso a hora for igual e os minutos difrentes quer dizer que os despertadores estao iguais
					 else if(h1==h2 && m1==m2) aux2+= 24;//caso os tempos forem iguais, soma 24 horas no auxiliar de horas
		}		
		cout<< (aux+aux2*60)<<endl; // minutos + horas * 60 minutos
	}
}
