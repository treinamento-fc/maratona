//============================================================================
// Name        : cartoes.cpp
// Author      : Wilson
// Version     :
// Copyright   : Maratona Programação - Regional - 2012 - Problema C - Cartoes
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include <climits>

using namespace std;

int N;
int cartoes[10000];
long long int memo[10000][10000];

long long int f(int i, int j) {

	if (memo[i][j] == INT_MAX) {
		if (i == j - 1) {
			memo[i][j] = max(cartoes[i], cartoes[j]);
		} else {
			memo[i][j] = max(cartoes[i] + min(f(i + 1, j - 1), f(i + 2, j)),
					cartoes[j] + min(f(i + 1, j - 1), f(i, j - 2)));
		}
	}
	return memo[i][j];
}

int main() {
	// cout << "Cartões" << endl; // prints Cartões
    // cout << sizeof(long long int);
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memo[i][j] = INT_MAX;
			}
 		}

		// Lendo dados dos cartões e guardando no vetor
		for (int i = 0; i < N; i++) {
			cin >> cartoes[i];
 		}

		long long int res = f(0, N - 1);
		cout << res << endl;
	}
	return 0;
}
