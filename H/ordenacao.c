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
#include <string.h>
#include "ordenacao.h"

/*///////////////////////////////////////////////////////////////
// Funcoes auxiliares privadas ////////////////////////////////*/

/*//////////////////////////////////////////////////////////////
// Funcao peneira: recebe p em 1..m e rearranja o vetor de string
//v[1..m] de modo que o "subvetor" cuja raiz e p seja um heap. 
//Supoe que os "subvetores" cujas raizes sao filhos de p 
//ja sao heaps.
//////////////////////////////////////////////////////////////*/
static void peneira (char **v, int p, int m) {
   int f = 2 * p;
   char *x = v[p];
   while (f <= m) {
      if (f < m && strcmp (v[f], v[f + 1]) < 0) f++;
      if (strcmp (x, v[f]) >= 0) break;
      v[p] = v[f];
      p = f; f = 2 * p;
   }
   v[p] = x;
}

/*//////////////////////////////////////////////////////////////
// Funcao heap: rearranja os elementos do vetor de strings v[1..n]
//de modo que fiquem em ordem lexicografica.
//////////////////////////////////////////////////////////////*/
static void heap (char **v, int n) {
   int p, m;
   char *x;
   for (p = n / 2; p >= 1; p--)
      peneira (v, p, n);
   for (m = n; m >= 2; m--) {
      x = v[1]; v[1] = v[m]; v[m] = x;
      peneira (v, 1, m - 1);
   }
}

/*//////////////////////////////////////////////////////////////
// Funcao ordenaDigital: recebe um vetor v[0..n-1] de strings
//de tamanho W sobre o alfabeto ASCII e ordena lexicograficamente 
//o vetor v.
//////////////////////////////////////////////////////////////*/
static void ordenacaoDigital (char *v[], int n, int W) {
   int d, i, r;
   int R = 128;
   int *fp; 
   char **aux;
   fp = malloc ((R + 1) * sizeof (int));
   aux = malloc (n * sizeof (char *));
   for (d = W - 1; d >= 0; d--) {
      for (r = 0; r <= R; r++)
         fp[r] = 0;
      for (i = 0; i < n; i++)
         fp[(unsigned char) v[i][d] + 1] += 1;
      for (r = 1; r <= R; r++)
         fp[r] += fp[r - 1];
      for (i = 0; i < n; i++) {
         aux[fp[(unsigned char) v[i][d]]] = v[i];
         fp[(unsigned char) v[i][d]]++;
      }
      for (i = 0; i < n; i++)
         v[i] = aux[i];
   }
   free (fp);
   free (aux);
}

/*///////////////////////////////////////////////////////////////
// Funcoes publicas //////////////////////////////////////////*/

/* Veja documentacao em ordenacao.h */
void heapsort (char **v, int n) {
   heap (v - 1, n);
}

/* Veja documentacao em ordenacao.h */
void digital (char **v, int n) {
   ordenacaoDigital (v, n, 9);
}
