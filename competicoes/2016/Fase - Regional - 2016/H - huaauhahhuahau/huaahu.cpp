//============================================================================
// Name        : huaahu.cpp
// Author      : eu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string x;
	string a;
	cin >> x ;
	//Percorre a string recebida, verificando se o elemento é uma vogal.
	//Se for, é concatenado em outra string a
	for(int i=0; i < x.size();i++){
		if(x[i] == 'a' || x[i]=='e' || x[i] == 'i' || x[i]== 'o'||x[i]=='u')
			a+=x[i];
	}
	int flag = 1;
	//verifica se os elementos equidistantes são iguais, se não for é interrompido
	for(int i=0;i<a.size()/2;i++)
	{
		if(a[i] != a[a.size()-i-1]){
			flag = 0;
			break;
		}
	}
	if(flag) cout<<"S"<<endl;
	else cout<<"N"<<endl;
}
