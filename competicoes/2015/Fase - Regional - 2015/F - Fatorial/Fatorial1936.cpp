#include <iostream>
using namespace std;

int main() {
	int fat[]={1,2,6,24,120,720,5040,40320}; //de 0 a 7 (fatorial 1 ao 8 - como o limite eh 10^5, nunca vai ser
											 //maior do que 8!
	int n,i=7,cont=0,aux;
	cin >> n;
	while(n>0){//repete até o N ser igual ou menor que zero
		aux=n-fat[i];
		if(aux >= 0){ //se for negativo, no pode mais ser essa opção de fatorial, então tenta o proximo
			n=aux;
			cont++;
		} else{
			i--;
		}
	}
	cout<<cont<<endl;
	return 0;
}
