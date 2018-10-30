//============================================================================
// Name        : F.cpp
// Author      : Wilson
// Version     :
// Copyright   : Maratona de Programação - Final Brasileira - 2010 - Problema F
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
   string s, linha;
   char letra;

   bool primeira, tautograma;  // É a primeira palavra da frase?

   while (1) {
	  getline(cin, linha);
  	  // cout << linha << endl;
	  if (linha.at(0) == '*') break;
	  istringstream str(linha);
	  primeira = true;
      tautograma = true;
	  while (!str.eof()) {
	     str >> s;
	     if (primeira) {
	        letra = toupper(s.at(0));
	        primeira = false;
	     } else {

	        if (letra != toupper(s.at(0))) {
	           tautograma = false;
	           break;
	        }
	     }
	  }
      if (tautograma) {
    	 cout << "Y" << endl;
      } else {
    	 cout << "N" << endl;
      }
   }
   return 0;
}
