#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

#define MAX 40000

/* //////////////////////////////////////////////////////////////
// Funcao teste: recebe um vetor v[0..n-1] e verifica se ele esta
//em ordem crescente ou nao. Imprime na tela o resultado do teste.
////////////////////////////////////////////////////////////// */
void teste (int *v, int n) {
   int i;
   for (i = 1; i < n; i++) {
      if (v[i] < v[i - 1]) {
         printf ("ERRO! O vetor nao esta ordenado!\n");
         return;
      }
   }
   printf ("Vetor ordenado!\n");
}

int main (void) {
   int i, *a, *b, *c, *d;
   a = malloc (MAX * sizeof (int));
   b = malloc (MAX * sizeof (int));
   c = malloc (MAX * sizeof (int));
   d = malloc (MAX * sizeof (int));
   for (i = 0; i < MAX; i++){
      a[i] = rand (); b[i] = rand ();
      c[i] = rand (); d[i] = rand ();
   }
   printf ("Ordenando com insercao:\n");
   insercao (a, MAX);
   teste (a, MAX);

   printf ("Ordenando com Mergesort:\n");
   mergesort (b, MAX);
   teste (b, MAX);

   printf ("Ordenando com Quicksort:\n");
   mergesort (c, MAX);
   teste (c, MAX);

   printf ("Ordenando com Heapsort:\n");
   mergesort (d, MAX);
   teste (d, MAX);

   return EXIT_SUCCESS;
}