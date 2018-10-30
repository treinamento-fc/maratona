//============================================================================

// Name        : Problema A - assignteams.cpp

// Author      : Wilson

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2016 - Latin American Regional Contests

//============================================================================

#include <iostream>

#include <algorithm>

using namespace std;

int A, B, C, D, dif;

int main() {

   // Ler A, B, C, D

   cin >> A >> B >> C >> D;

   // cout << A << "\t" << B << "\t" << C << "\t" << D << endl;

   dif = abs((D + A) - (C + B));

   // Imprimir  diferença de skill

   cout << dif << endl;
   return 0;
}