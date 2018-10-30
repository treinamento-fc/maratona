//============================================================================
// Name        : Problema M - maquinadecafe.cpp
// Solução     : Calcule os tempos considerando a máquina em cada um dos andares e depois ache o menor dos tempos
// Author      : Wilson
// Version     :
// Copyright   : Your copyright notice
// Description : Maratona de Programação 2017 - Latin American Regional Contests
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;
int a1, a2, a3, tempos[3];
int main() {
    // Ler a1, a2 e a3;
   cin >> a1 >> a2 >> a3;
   //cout << a1 << " " << a2 << " " << a3 << endl;
   // Computando tempos considerando a máquina nos andares 1, 2 e 3
   tempos[0] = (a2 *2) + (a3* 4);
   tempos[1] = (a1 *2) + (a3* 2);
   tempos[2] = (a1 *4) + (a2* 2);
   // Achar o menor tempo
   sort(tempos, tempos + 3);
   cout << tempos[0] << endl;
   return 0;
}