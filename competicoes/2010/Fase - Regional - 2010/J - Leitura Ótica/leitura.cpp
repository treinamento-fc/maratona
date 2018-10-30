#include <iostream>
using namespace std;

int main() {
	int n,resp,flag=0,i=0,aux;
	char letra;
	//entrada de dados e teste para n!=0 (termina o programa se for 0)
	while(cin>>n && n){
	while(n>0){ //executa n vezes o codigo (n = qtde de questoes)
		flag=0;
		for(i=0;i<5;i++){
			cin>>resp; //faz o teste assim que lê cada resposta, nao sendo necessário o uso de um vetor por exemplo
			if(resp<128){
				aux=i; //armazena qual resposta foi selecionada
				flag++;
			}
		}
		if(flag==1){//flag serve para ver se apenas uma das opções que foi selecionada
			letra = 65+aux; //65 na tabela ascii eh A, somado a aux fica a letra da resposta correspondente
		}
		else letra ='*';
		cout<<letra<<endl;
		n--;
	}}
	return 0;
}
