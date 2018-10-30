#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long int operacao(long int A, long int B,long int C,long int D){
    if(C % A == 0){
    	long int raiz = sqrt(C);
    	for(int i = A; i <= raiz; i += A){
			if(i % B != 0 && D % i != 0 && C % i == 0)
				return i;
    	}
    	if(C % 2 == 0)
			if((C/2) % B != 0 && D % (C/2) != 0 && C % (C/2) == 0)
				return (C/2);
    	if(C % B != 0 && D % C != 0)
    	  return C;
    }
    return -1;
}

int main() {
    long int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << operacao(A,B,C,D) << endl;
}
 
