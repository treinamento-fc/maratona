#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int func(int N){
	int menor = 0, maior = 0, pulo;
	int vetor[N], original[N];
	int resultado =1;
	for(int i = 0; i < N; ++i){
			cin >> vetor[i];
			original[i] = vetor[i];
	}
	do{
	for(int i = 0; i < N; ++i){
		if(vetor[menor] > vetor[i])
			menor = i;
		else{
			if(vetor[maior] < vetor[i])
				maior = i;
		}
	}

	for(int i = 0; i < N; ++i){
		if(menor != i && maior != i){

		}
	}

	if(vetor[maior] == vetor[menor]){
		resultado = 0;
		for(int i = 0; i < N; ++i){
			resultado += abs(original[i] - vetor[i]);
		}
		return resultado / 2 + 1;
	}
	if(abs(vetor[maior] - vetor[menor]) == 1)
		return -1;
	pulo = (vetor[maior] - vetor[menor]) / 2;
	vetor[maior] -= pulo;
	vetor[menor] += pulo;
	resultado += pulo;
	}while(true);
}

int main() {
	int N;
	while(cin >> N){
		cout << func(N) << endl;
	}
}
