#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	int a;
	int cont;
	bool dir,operou;
	
	while(1){
		n=0;
		cin >> n;
		if(!n) break;
		a = 1;
		dir = operou = false;
		cont = 0;
		
		do{
			a*=2;
			if(a>n/2){
				a = abs(a-n) + 1;
				dir=!dir;
			}
			cont++;
		}while(a!=1 || dir);
		
		printf("%d\n",cont);
	}
}
