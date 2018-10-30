
//============================================================================
/ Name        : Problema D - despojados.cpp

// Solução     : Fatorando por N primos e achando o números de combinações possíveis

// Author      : Wilson / Hélio

// Version     :

// Copyright   : Your copyright notice

// Description : Maratona de Programação 2016 - Latin American Regional Contests

//============================================================================
#include <iostream>

#include <algorithm>using namespace std;unsigned long long int N, M, resto;int totCombinacoes = 0;

int utilizados[200];

int primos[200] =

{

 2,   3,   5,   7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,

101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,

233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,

383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,

547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,

701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863,

877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};long int fatorial(long int num) {

    long int fat;

    int i;

    fat = 1;

    for(i=1; i <= num; i++) {

        fat = fat * i;

    }

    return fat;

}long int combina(long int a, long int b) {

  long int c;

  c = 0;

  c = fatorial(a) / (fatorial(b) * fatorial(a - b));

  return c;

}int main() {    int i, qtd, prim;    // Ler N

   cin >> N;

   // cout << N << endl;    // Limpar utilizados[]

   for (i=0;i<200;i++) {

       utilizados[i] = 0;

   }    // Fatorar N

   prim = 0;

   M = N;

   while (M > 1) {

       resto = M % primos[prim];

       if (resto > 0) {

          prim++;

       } else {

         utilizados[prim]++;

         M = M / primos[prim];

       }

   }    // Calcular quantos primos diferentes foram utilizados

   qtd = 0;

   for (i=0; i<200;i++) {

       if (utilizados[i] > 0) {

       qtd++;

       // cout << primos[i] << " expoente: " << utilizados[i] << endl;

       }

   }

   if (qtd < 2 ) {

       qtd = 0;

   } else {

       totCombinacoes = 0;

       // Calcular combinações possíveis

       for (i=qtd; i > 1; i--) {

           totCombinacoes = totCombinacoes + combina(qtd, i);

       }    }

    // cout << qtd << " " << totCombinacoes << endl;

    cout << totCombinacoes << endl;

   return 0;
}