//============================================================================
// Name        : UVA-11498.cpp
// Author      : Wilson
// Version     :
// Copyright   : Exercícios UVA Online Judge
// Description : Division of Nlogonia
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int i, k, n, m, x, y;

	// cout << "Division of Nlogonia" << endl; // prints Division of Nlogonia

	// Ler t = número de casos de teste
	cin >> k;
    while (k > 0)   {

       // Ler n e m
    	cin >> n >> m;
        // cout << n << " " << m << endl;

        for(i=1; i<=k;i++) {
           cin >> x >> y;
           // cout << x << " " << y << endl;

           if ((x == n) || (y == m)) {
        	   cout << "divisa" << endl;
           } else {
        	   if ((x > n) && (y > m)) {
            	   cout << "NE" << endl;
        	   } else {
            	   if ((x > n) && (y < m)) {
                	   cout << "SE" << endl;
            	   } else {
                	   if ((x < n) && (y > m)) {
                    	   cout << "NO" << endl;
                	   } else {
                    	   cout << "SO" << endl;

                	   }
            	   }
        	   }
           }
        }

       // Ler próximo caso de teste
       cin >> k;

    }
	return 0;
}
