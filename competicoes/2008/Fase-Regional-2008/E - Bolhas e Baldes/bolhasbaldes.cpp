//============================================================================
// Name        : E.cpp
// Author      : Wilson
// Version     :
// Copyright   : Maratona Programa��o - Regional - 2008 - Problema E - Bolhas e Baldes
// Description : Ordena��o caminhando por pares de elementos no vetor testando se deve trocar de posi��o
//               Contamos o n�mero de trocas, se impar o vencedor � Marcelos, se � par, o vencedor � Carlos
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

int N, arr[1000000], trocas, arr_size;

// Merges dois subarrays de arr[]. Primeiro subarray � arr[l..m]. Segundo subarray � arr[m+1..r]
void merge(int arr[], int l, int m, int r) {

	int i, j, k, n1, n2;
	n1 = m - l + 1;
    n2 = r - m;

    // Criar o array tempor�rio
    int L[n1], R[n2];

    // Copia dados para o arrays tempor�rios L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Merge os arrays tempor�rios  de volta para arr[l..r]
    i = 0; // �ndice inicial do primeiro subarray
    j = 0; // �ndice inicial do segundo  subarray
    k = l; // �ndice inicial do subarray merged
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
        	trocas += n1 - i; // Acumulando n�mero de trocas de elementos
            j++;
        }
        k++;
    }

    // Copia o restante dos elementos de L[], (se existir)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copia o restante dos elementos de R[], (se existir)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


}

// Se k est� no �ndice a esquerda e r est� no �ndice da direita do subrray de arr para ser ordenado
void mergeSort(int arr[], int l, int r) {

	if (l < r) {
    	// Mesmo como (l+r)/2, mas evita transborto (overflow) para maiores de l e h
        int m = l+(r-l)/2;
        // Ordena as metades (primeira e a segunda)
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    while (1) {

    	arr_size = sizeof(arr)/sizeof(arr[0]);

    	//  Quantos n�meros na sequ�ncia?
		cin >> N;
        // cout << N << endl;

		if (N == 0) break;

		//  Ler os N n�meros e armazenar em arr
		for (int i=0; i < N; i++ ) {
		    cin >> arr[i];
		}


		trocas = 0;
		mergeSort(arr, 0, N - 1);


		/*  Mostrar n�meros ordenados
		for (int i=0; i < N; i++ ) {
		    cout << arr[i] << " ";
		}
        cout << endl;
        */

       //  cout << trocas << " ";

		if ((trocas % 2) == 0)	{
		   cout << "Carlos" << endl;
		} else {
		   cout << "Marcelo" << endl;
		}
    }
	return 0;
}
