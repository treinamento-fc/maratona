#include <iostream>
using namespace std;

int main() {
	int a;
	while(1){
		cin>>a;
		if(cin.eof()) break; //l� enquanto n�o tiver terminado o arquivo
		if(a%6 == 0) cout<<"Y"<<endl;  //um rel�gio possui 360� dividido em 60 parcelas de tempo
		else cout<<"N"<<endl; //sendo assim, cada parcela representa 6�. Para saber se um �ngulo A pertence a algum
		//minuto do rel�gio, � s� verificar se esse �ngulo � divis�vel por 6
	}
	return 0;
}
