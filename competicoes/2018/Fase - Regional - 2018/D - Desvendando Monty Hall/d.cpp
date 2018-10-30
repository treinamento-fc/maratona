//============================================================================
// Name        : d.cpp
// Author      : Comini/Giulia/Paiola
// Version     :
// Copyright   : ICPC - Regional 2018 - Problema D - Desvendando Monty Hall
// Description :
//============================================================================
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, i, x, cont = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if (x != 1)
			cont++;
	}
	printf("%d\n",cont);
}
