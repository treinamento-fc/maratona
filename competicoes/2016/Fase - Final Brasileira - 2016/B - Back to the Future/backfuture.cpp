//============================================================================

// Name        : Problema B - backfuture.cpp

// Author      : Wilson / Hélio

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2016 - Final Brasileira

//============================================================================

#include <iostream>

#include <algorithm>

using namespace std;int dados[100001][2],  compativeis[100001], auxiliar[100001], n, m, a, b, qtd,  qtd_sim;int main() {int i, elemento1, elemento2;

   // Limpar vetores

   for(i=1;i<=n;i++) {

       compativeis[i] = 0;

       auxiliar[i] = 0;

   }

   // Ler n, m, a, b

   cin >> n >> m >> a >> b;

   // cout << n << " " << m << " " << a << " " << b << endl;    // Ler e guardar a lista de compatibilidade

   for (i=1; i<=m;i++) {

       cin >> elemento1 >> elemento2;

       dados[i][0] =  elemento1;

       dados[i][1] =  elemento2;

   }    // Ler os m elementos da lista de compatibilidades

   for (i=1; i<=m;i++) {

       // cout << dados[i][0] << "  " << dados[i][1] << endl;

       compativeis[dados[i][0]]++;

       compativeis[dados[i][1]]++;

   }    qtd_sim = 0;

   for (i=1; i<=n; i++) {

       if (((n - 1 - compativeis[i]) >= b) && (compativeis[i] >= a)) {

           auxiliar[i] = 1;   // 1 = Sim  0 = Não

           qtd_sim++;

       }

   }

   qtd = 0;

   while (qtd_sim != qtd)  {

       qtd = qtd_sim;        // Limpar vetor compatíveis

        for(i=1;i<=n;i++) {

            compativeis[i] = 0;

        }        // Ler toda lista novamente para contar compatibilidades

        for (i=1; i<=m;i++) {

            if ((auxiliar[dados[i][0]] == 1) && (auxiliar[dados[i][1]] == 1)) {

                 compativeis[dados[i][0]]++;

                 compativeis[dados[i][1]]++;

            }

        }

        for(i=1;i<=n;i++) {

            auxiliar[i] = 0;

            //cout << i << " - " << compativeis[i] << endl;

        }        // O metal i atende os requisitos B e A?

        for (i=1; i<=n;i++) {

            if (((qtd - 1 - compativeis[i]) >= b) && ((compativeis[i]) >= a)) {

                auxiliar[i] = 1;   // 1 = Sim  0 = Não

            }

        }

       // Contar quantos metais atendem os requisitos B e A

        qtd_sim = 0;

        for(i=1;i<=n;i++) {

            if (auxiliar[i] == 1) qtd_sim++;

        }

   }

   // Resultado o maior conjunto de metais que atende os requisitos

   cout << qtd_sim << endl;
   return 0;

}