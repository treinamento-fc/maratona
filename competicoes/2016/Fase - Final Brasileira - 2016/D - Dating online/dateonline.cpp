//============================================================================

// Name        : Problema D - datingonline.cpp

// Author      : Wilson / Hélio

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2016 - Latin American Regional Contests

//============================================================================

#include <iostream>

#include <algorithm>

#include <math.h>

#include <iomanip>using namespace std;int dados[100000],  N, i, j, temp;

double area, angulo;   // Testei com float em vez de double e os resultados dos cálculos das áreas ficaram iguais aos casos de teste.

double PI = 3.14159265358979323846; // Testei PI com menos casas decimais. Esse ai deu melhores resultados nos cálculos.int main() {    // Ler N

   cin >> N ;    // Pegar Scores

   for (i=0;i<N;i++) {

       cin >> dados[i];

   }    // Ordenar dados - Usando bubble sort só para testar (se tiver tempo trocar por Quick Sort ou outro método)

   for(i=0; i<(N-1); i++) {

       for(j=0; j<(N-i-1); j++) {

           if(dados[j]>dados[j+1]) {

                  temp=dados[j];

                  dados[j]=dados[j+1];

                  dados[j+1]=temp;

              }

          }

      }    area = 0;

   angulo = 360 / float(N);

   // Caso particular N = 3

   if (N == 3)  {

       area = (dados[0] * dados[1] * sin(angulo * PI / 180)) / 2 +

                 (dados[0] * dados[2] * sin(angulo * PI / 180)) / 2 +

               (dados[1] * dados[2] * sin(angulo * PI / 180)) / 2;

   } else { // Caso geral

       area = (dados[0] * dados[1] * sin(angulo * PI / 180)) / 2  + (dados[N-1] * dados[N-2] * sin(angulo * PI / 180)) / 2 ;

       if ((N % 2) == 0) {  // N é par

            for (i=0; i<=N-4; i=i+2 ) {

                area = area  + ((dados[i+1] * dados[i+3] * sin(angulo * PI / 180) / 2)) + ((dados[i] * dados[i+2] * sin(angulo * PI / 180) / 2));

            }

        } else {   // N é ímpar

            for (i=0; i< N-3; i=i+2 ) {

                area = area  + ((dados[i+1] * dados[i+3] * sin(angulo * PI / 180) / 2)) + ((dados[i] * dados[i+2] * sin(angulo * PI / 180) / 2));

            }

            area = area  + ((dados[N-1] * dados[N-3] * sin(angulo * PI / 180) / 2));

        }

   }

   // Imprimir area

   cout.precision(3);    // define a precisão

   cout << setiosflags (ios::fixed) << area << endl;
   return 0;
}