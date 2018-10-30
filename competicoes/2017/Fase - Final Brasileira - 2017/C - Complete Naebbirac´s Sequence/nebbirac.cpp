//============================================================================

// Name        : Problema C - nebbirac.cpp - Final Brasileira - 2017

// Author      : Wilson

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2017 - Latin American Regional Contests

//============================================================================

#include <iostream>

#include <algorithm>

using namespace std;

int K, N, M, i, qtdM, qtdmais, qtdmenos, aux;

bool temErro;

int seq[1001];int main() {    // Ler K, N

   cin >> K >> N;

   M =  (N+1) / K;

   cout << K << " " << N << " " << M << endl;

   // Limpar vetor de contadores

   for (i=1;i<=K;i++) {

       seq[i] = 0;

   }    // Ler Sequencia de N números

   for (i=1;i<=N;i++) {

       cin >> aux;

       seq[aux]++;

        cout << aux << " ";

   }

   cout << endl;    // Procurar se algum tem frequencia maior que M+2 ou menor que M-2

   temErro = false;

    for (i=1;i<=K;i++) {

        //cout << seq[i] << " ";

       if (M >= 2) {

            if (abs(seq[i] - M) > 1) temErro = true;

       }

    }

   cout << endl;    if (!temErro) {

        // Procurar quantos elementos aparecem M, M-1 e M+2 vezes

        qtdM= 0;

        qtdmais = 0;

        qtdmenos = 0;

        for (i=1;i<=K;i++) {

            if (seq[i] == M)   qtdM++;

            if (seq[i] == M-1) qtdmenos++;

            if (seq[i] == M+1) qtdmais++;

        }

        cout << qtdM << " " << qtdmenos << " " << qtdmais << endl;        // Se todos elementos aparecem M vezes, então não tem solução

        if (qtdM == K)  {

            cout << "*" ;

            return 0;

        }

        // Se K - 1 elementos aparecem M vezes então apenas um elemento aparece M+1 ou M-1 vezes

        if ((qtdmenos == 1) && (qtdmais == 0))  {

            // Procurar por seq[i] == qtdmenos

            for (i=1;i<=K;i++) {

                if (seq[i] == M-1) {

                    cout << "+" << i << endl;

                    break;

                }

            }

             return 0;

        }

        if ((qtdmenos == 0) && (qtdmais == 1))  {

            // Procurar por seq[i] == qtdmais

            for (i=1;i<=K;i++) {

                // cout << i << " " << seq[i] << endl;

                if (seq[i] == M+1) {

                    cout << "-" << i << endl;

                    break;

                }

            }

            return 0;

        }        // Se K - 2 elementos aparecem M vezes então um elemento aparece M+1 vezes e outro elemento M-1 vezes        if ((qtdmenos == 1) && (qtdmais == 1))  {

            // Procurar por seq[i] == qtdmais

            for (i=1;i<=K;i++) {

                if (seq[i] == M+1) {

                   cout << "-" << i << " ";

                   break;

                }

            }

            // Procurar por seq[i] == qtdmenos

            for (i=1;i<=K;i++) {

                if (seq[i] == M-1) {

                    cout << "+" << i << endl;

                    break;

                }

            }

            return 0;

        }

   }

    cout << "*";

    return 0;

}