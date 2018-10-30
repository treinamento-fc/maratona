//============================================================================
// Name        : automated.cpp
// Author      : Wilson
// Version     :
// Copyright   : Final Brasileira 2014 - Problema A
// Description :
//============================================================================

#include <iostream>
using namespace std;

int main() {
	// cout << "Automated Checking Machine" << endl; // prints Automated Checking Machine

   int i, conector1[5], conector2[5];
   bool compativel;

   while (1) {

	   cin >> conector1[0];
	   if (cin.eof()) {
		  break;
	   }
	   cin >> conector1[1];
	   cin >> conector1[2];
	   cin >> conector1[3];
	   cin >> conector1[4];

	   cin >> conector2[0];
	   cin >> conector2[1];
	   cin >> conector2[2];
	   cin >> conector2[3];
	   cin >> conector2[4];


	   // Verifica compatibilidade pino a pino (usando XOR)
	   compativel = true;
	   for (i=0; i<5; i++) {
		   if (!(conector1[i] ^ conector2[i])) {
			  compativel = false;
		   }
	   }

	   if (compativel) {
          cout << "Y" << endl;
	   } else {
          cout << "N" << endl;
	   }
   }
   return 0;
}
