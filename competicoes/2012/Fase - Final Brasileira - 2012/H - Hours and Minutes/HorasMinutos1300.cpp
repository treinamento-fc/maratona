#include <iostream>
using namespace std;

int main() {
	int a;
	while(1){
		cin>>a;
		if(cin.eof()) break; //lê enquanto não tiver terminado o arquivo
		if(a%6 == 0) cout<<"Y"<<endl;  //um relógio possui 360° dividido em 60 parcelas de tempo
		else cout<<"N"<<endl; //sendo assim, cada parcela representa 6°. Para saber se um ângulo A pertence a algum
		//minuto do relógio, é só verificar se esse ângulo é divisível por 6
	}
	return 0;
}
