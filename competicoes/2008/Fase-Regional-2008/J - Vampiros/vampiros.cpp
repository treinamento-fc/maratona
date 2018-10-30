//============================================================================
// Name        : vampiros.cpp
// Author      : Paiola / Comini
// Version     : 
// Copyright   : ICPC - Regional 2008 - Problema J - Vampiros
// Description : Usa uma vers�o um pouco mais gen�rica da f�rmula de Gambler's ruin
//============================================================================

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	float ev1, ev2, at, d;
	float p, q;
	while(true){
		cin >> ev1 >> ev2 >> at >> d;	
		if (at == 0)
			break;
		ev1 = ceil(ev1/d);
		ev2 = ceil(ev2/d);
		if (at == 3){
			p = ev1 / (float)(ev1 + ev2);	
		}
		else{
			p = at/6.;
			q = (6 - at)/6.;
			p = (1 - pow(q/p,ev1)) / (1 - pow(q/p,ev1 + ev2));
		}
		printf("%.1f\n",round(p*1000)/10);
	}
}
