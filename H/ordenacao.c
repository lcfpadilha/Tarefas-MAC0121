/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Leonardo de C. F. Padilha Aguilar
// Numero USP: 9298295
// Sigla: LEONARDO
// Data: 2015-11-01
// 
// Este arquivo faz parte da tarefa H
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* //////////////////////////////////////////////////////////////
//
// Biblioteca ordenacao.c
//
////////////////////////////////////////////////////////////// */

#include <stdlib.h>
#include "ordenacao.h"

/*///////////////////////////////////////////////////////////////
// Funcoes auxiliares privadas ////////////////////////////////*/

/*//////////////////////////////////////////////////////////////
// Funcao peneira: recebe p em 1..m e rearranja o vetor v[1..m]
//de modo que o "subvetor" cuja raiz e p seja um heap. Supoe que
//os "subvetores" cujas raizes sao filhos de p ja sao heaps.
//////////////////////////////////////////////////////////////*/
static void peneira (int *v, int p, int m) {
   int f = 2 * p, x = v[p];
   while (f <= m) {
      if (f < m && v[f] < v[f + 1]) f++;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f; f = 2 * p;
   }
   v[p] = x;
}

/*//////////////////////////////////////////////////////////////
// Funcao heap: rearranja os elementos do vetor v[1..n] de modo 
//que fiquem em ordem crescente.
//////////////////////////////////////////////////////////////*/
static void heap (int *v, int n) {
   int p, m, x;
   for (p = n / 2; p >= 1; p--)
      peneira (v, p, n);
   for (m = n; m >= 2; m--) {
      x = v[1]; v[1] = v[m]; v[m] = x;
      peneira (v, 1, m - 1);
   }
}

/*//////////////////////////////////////////////////////////////
// Funcao ordenaDigital: recebe um vetor de inteiros v[0..n-1]
//e um inteiro W que representa a quantidade de digitos que os
//elementos de v possuem. Ordena digitalmente os elementos desse
//vetor.
//////////////////////////////////////////////////////////////*/
static void ordenacaoDigital (int v[], int n, int W) {
   int d, i, r, pot;
   int *fp, *aux;
   pot = 1;
   fp = malloc (10 * sizeof (int));
   aux = malloc (n * sizeof (int));
   for (d = W - 1; d >= 0; d--) {
      for (r = 0; r <= 10; r++)
         fp[r] = 0;
      for (i = 0; i < n; i++)
         fp[(v[i] / pot) % 10 + 1] += 1;
      for (r = 1; r <= 10; r++)
         fp[r] += fp[r - 1];
      for (i = 0; i < n; i++) {
         aux[fp[(v[i] / pot) % 10]] = v[i];
         fp[(v[i] / pot) % 10]++;
      }
      for (i = 0; i < n; i++)
         v[i] = aux[i];
      pot = pot * 10;
   }
   free (fp);
   free (aux);
}

/*///////////////////////////////////////////////////////////////
// Funcoes publicas //////////////////////////////////////////*/

/* Veja documentacao em ordenacao.h */
void heapsort (int *v, int n) {
   heap (v - 1, n);
}

/* Veja documentacao em ordenacao.h */
void digital (int *v, int n) {
   ordenacaoDigital (v, n, 9);
}
