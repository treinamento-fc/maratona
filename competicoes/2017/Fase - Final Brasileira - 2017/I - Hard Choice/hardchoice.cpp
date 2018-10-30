/============================================================================

// Name        : Problema H - hardchoice.cpp - Final Brasileira - 2017

// Author      : Wilson

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2017 - Latin American Regional Contests

//============================================================================

#include <iostream>

#include <algorithm>

using namespace std;

int Ca, Ba, Pa, Cr, Br, Pr, aux;int main() {   // Pegar quantidade de refeições disponíves (Chicken, Beef e Pasta)

  cin >> Ca >> Ba >> Pa;

  cout << Ca << " " << Ba << " " << Pa << endl;   // Pegar quantidade de refeições solicitadas pelos passageiros (Chicken, Beef e Pasta)

  cin >> Cr >> Br >> Pr;

  cout << Cr << " " << Br << " " << Pr << endl;   // Calcular quantos passaram fome na viagem

  aux = 0;

  if (Ca < Cr) {

      aux = Cr - Ca;

  }

  if (Ba < Br) {

      aux = aux + (Br - Ba);

  }

  if (Pa < Pr) {

      aux = aux + (Pr - Pa);

  }

  // Resultado

  cout << aux;

  return 0;

}