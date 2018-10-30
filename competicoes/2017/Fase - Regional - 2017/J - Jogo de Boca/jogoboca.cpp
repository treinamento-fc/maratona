//============================================================================
/ Name        : Problema J - jogodeboca.cpp
// Solução     : Teoria dos números - critério de divisibilidade por 3
// Author      : Wilson
// Version     :
// Copyright   : Your copyright notice
// Description : Maratona de Programação 2017 - Latin American Regional Contests
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>using namespace std;string  N;
char ch;
int resto, i, tot;int main() {    // Ler N
   cin >> N;
   //cout << N << endl;    // Somar todos os dígitos do número
   tot = 0;
   for(i=0;i < (int) N.length();i++) {
       ch = N.at(i);
       tot = tot + (int(ch) - 48);
   }
   // Resto da divisão da somatórias de todos os dígitos do número
   resto = tot % 3;
   cout << resto << endl;
   return 0;
 }