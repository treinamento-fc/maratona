#include <iostream>
#include <math.h>

using namespace std;

bool ehPrimo(int x){
	int raiz = sqrt(x);
	for(int i = 2; i <= raiz; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main(){
	int x;
	while(cin >> x){
		for(int i = x; i >= 2; i--){
			if (ehPrimo(i)){
				cout << i << endl;
				break;
			}
		}
	}
}
