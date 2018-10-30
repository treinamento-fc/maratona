//============================================================================
// Name        : espiral.cpp
// Author      : Paiola
// Version     :
// Copyright   : ICPC - Regional 2015 - Problema E - Espiral
// Description :
//============================================================================
#include<iostream>
#include<cmath>

using namespace std;

//Quantidade de voltas dadas (considero uma volta como caminhar por uma linha inteira e uma coluna inteira)
long long qtdeEspiras(long long N, long long B){
	double a, b, c;
	double delta, raiz, x1, x2;
	a = 1; b = 1 - 2*N; c = (B - N);
	delta = b * b - 4 * a * c;
	raiz = sqrt(delta);
	x1 = (-b + raiz)/2*a;
	x2 = (-b - raiz)/2*a;

	if (x1 < 0)
		return floor(x2);
	else if (x2 < 0)
		return floor(x1);
	else
		return floor(min(x1, x2));
}

int main(){
	long long N, B, jaColocadas;
	cin >> N >> B;
	if (B < N)
		cout << 1 << " " << B << endl;
	else
	{
		long long i = qtdeEspiras(N, B), j, k;
		long long posL, posC;
		j = (i+1)/2;
		k = i/2;
		posL = 1 + (N - j)*j - (N - k - 1)*k;
		posC = N - (N - j)*j + (N - k - 1)*k;
		jaColocadas = N + (2*N - 1)*i - i*i;
		if (B > jaColocadas)
		{
			i++;
			if (i % 2)
			{
				if ( (jaColocadas + N - i) >= B)
					posL += B - jaColocadas;
				else
				{
					posL += N - i;
					posC -= B - (jaColocadas + (N - i));
				}
			}
			else
			{
				if ( (jaColocadas + N - i) >= B)
					posL -= (B - jaColocadas);
				else
				{
					posL -= (N - i);
					posC += B - (jaColocadas + (N - i));
				}	
			}
		}
		
		cout << posL << " " << posC << endl;
	}
}
