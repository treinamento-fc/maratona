#include <iostream>
using namespace std;

int main() {
	int n;
	while(1){
		cin>>n;
		if(cin.eof()) break;
		int s=((n*(n+1)*(2*n+1))/6); //simplifica��o da f�rmula da soma dos quadrados de n at� 1
		cout<<s<<endl;
	}
}
