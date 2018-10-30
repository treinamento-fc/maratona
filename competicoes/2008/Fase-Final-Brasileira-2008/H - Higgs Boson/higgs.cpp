//============================================================================
// Name        : formula1.cpp
// Author      : Paiola / Giulia
// Version     :
// Copyright   : ICPC - Final 2008 - Problema H - Higgs Boson
// Description :
//============================================================================

#include<iostream>

using namespace std;

int mdc(int a, int b)
{
	int r;
	while (b != 0) 
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int mmc(int num1, int num2) 
{
    int resto, a, b;
    a = num1;
    b = num2;

    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);

    return ( num1 * num2) / a;
}

void simplificar(int &num, int &den)
{
	int aux;
	if (den == 0)
		return;
	if (den < 0)
	{
		den = -den;
		num = -num;
	}
	if (num < 0)
		aux = mdc(-num, den);
	else
		aux = mdc(num, den);
		
	num /= aux;
	den /= aux; 
}

void padronizarAngulo(int &num, int &den)
{
	int aux = mmc(den, 360), umaVolta;
	num = num * (aux / den);
	den = aux;
	
	umaVolta = 360 * aux;
	num = num < 0 ? umaVolta + (num % umaVolta) : num % umaVolta;
		
	simplificar(num, den);
}

void trocar(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

int main()
{
	int a1, b1, c1, d1, a2, b2, c2, d2;						//parâmetros de entrada
	int t1_num, t1_den, t2_num, t2_den, t3_num, t3_den;		//tempos de possível encontro (números racionais)
	int r1, r2;												//distâncias
	int ang1_num, ang1_den, ang2_num, ang2_den;				//ângulos da partícula em um dado instante (números racionais)
	
	while (true){
		//Lendo os parâmetros do problema
		cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
		if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0 && a2 == 0 && b2 == 0 && c2 == 0 && d2 == 0)
			break;
			
		//Antes de tudo, vamos verificar se as particulas já não colidem no instante 0
		if (abs(b1) == abs(b2)){
			if (b1 == 0){
				cout << "0 1" << endl;
				continue;
			}
			ang1_num = d1;
			ang2_num = d2;
			if (b1 < 0)
				ang1_num += 180;
			if (b2 < 0)
				ang2_num += 180;
				
			ang1_num = ang1_num < 0 ? 360 + (ang1_num % 360) : ang1_num % 360;
			ang2_num = ang2_num < 0 ? 360 + (ang2_num % 360) : ang2_num % 360;
			
			if (ang1_num == ang2_num){
				cout << "0 1" << endl;
				continue;
			}
		}
			
		
		//Se as partículas estão em um mesmo ponto, a distância até a origem de ambas (r) é a mesma
		//Só temos que tomar cuidado pois em coordenadas polares o r pode ser negativo, então temos
		//que considerar os instantes em que r1 = r2 (t1) e r1 = -r2 (t2)
		//Também é possível que |r1| = |r2| para todo t, nesse caso temos que considerar também o
		//instante em que os ângulos coincidem (t3), tomando o devido cuidado com os ângulos congruentes
		
		//Calculando t3, se necessário
		if ((a1 == a2 && b1 == b2) || (a1 == -a1 && b1 == -b2)){
			t3_num = d2 - d1;
			t3_den = c1 - c2;
			if (t3_den < 0)
			{
				t3_den *= -1;
				t3_num *= -1;
			}
			t3_num = t3_num % 360;
			if (t3_num < 0){
				t3_num += 360;
			}
			simplificar(t3_num,t3_den);
		} else 
			t3_den = 0;
		
		//Calculando t1 e t2
		t1_num = b2 - b1;
		t1_den = a1 - a2;
		simplificar(t1_num, t1_den);
		
		t2_num = - (b2 + b1);
		t2_den = a1 + a2;
		simplificar(t2_num, t2_den);
		
		//É importante verificar se os tempos são válidos (não podem ser negativos) e
		//se ambos são válidos, temos que começar a testar pelo menor tempo	
		if ((t1_num < 0 && t2_num < 0) || (t1_den == 0 && t2_den == 0) || (t1_num < 0 && t2_den == 0) || (t1_den == 0 && t2_num < 0))
		{
			if (t3_den == 0)
				cout << "0 0" << endl;
			else
				cout << t3_num << " " << t3_den << endl;
			continue;
		} else if (t1_num < 0 || t1_den == 0) {
			t1_num = t2_num;
			t1_den = t2_den;
		} else if (t2_num > 0 && t2_den != 0) {
			if ( (t2_num/(float)t2_den) < (t1_num/(float)t1_den)) {
				trocar(t1_num, t2_num);
				trocar(t1_den, t2_den);
			}
		}
		
		//Começando o teste pelo t1, temos que verificar se os ângulos das coordenadas polares
		//coincidem (se r1 = r2 = 0, então nem precisamos realizar esse teste)
		
		//Testando para t1 (antes verificiamos se t3, caso exista, já não é menor que t1)
		if (t3_den != 0 && (t3_num/(float)t3_den < t1_num/(float)t1_den))
		{
			cout << t3_num << " " << t3_den << endl;
			continue;
		}
		
		r1 = a1*t1_num + b1*t1_den; //apenas a parte inteira
		r2 = a2*t1_num + b2*t1_den;
		
		if (r1 == 0)
		{
			cout << t1_num << " " << t1_den << endl;
			continue;
		}
		
		
		ang1_den = ang2_den = t1_den;
		ang1_num = c1*t1_num + d1*t1_den;
		ang2_num = c2*t1_num + d2*t1_den;
		
		if (r1 < 0)
		{
			r1 = -r1;
			ang1_num += 180*t1_den;
		}
		if (r2 < 0)
		{
			r2 = -r2;
			ang2_num += 180*t1_den;
		}
		simplificar(ang1_num, ang1_den);
		padronizarAngulo(ang1_num, ang1_den);
		simplificar(ang2_num, ang2_den);
		padronizarAngulo(ang2_num, ang2_den);
		
		if (ang1_num == ang2_num && ang1_den == ang2_den)
		{
			cout << t1_num << " " << t1_den << endl;
			continue;
		}
		
		//Testando para t2 (se possível)
		if (t2_num < 0 || t2_den == 0){
			cout << "0 0" << endl;
			continue;
		}	
		
		r1 = a1*t2_num + b1*t2_den;
		r2 = a2*t2_num + b2*t2_den;
		
		if (r1 == 0)
		{
			cout << t2_num << " " << t2_den << endl;
			continue;
		}
		
		ang1_den = ang2_den = t2_den;
		ang1_num = c1*t2_num + d1*t2_den;
		ang2_num = c2*t2_num + d2*t2_den;
		
		if (r1 < 0)
		{
			r1 = -r1;
			ang1_num += 180*t2_den;
		}
		if (r2 < 0)
		{
			r2 = -r2;
			ang2_num += 180*t2_den;
		}
		
		simplificar(ang1_num, ang1_den);
		padronizarAngulo(ang1_num, ang1_den);
		simplificar(ang2_num, ang2_den);
		padronizarAngulo(ang2_num, ang2_den);
		
		if (ang1_num == ang2_num && ang1_den == ang2_den)
		{
			cout << t2_num << " " << t2_den << endl;
			continue;
		}
		
		cout << "0 0" << endl;		
	}
}
