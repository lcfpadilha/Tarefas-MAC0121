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
// Data: 2015-10-10
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* //////////////////////////////////////////////////////////////
//
// Biblioteca de ordenacao: Este programa tem como objetivo 
//desenvolver uma biblioteca de funcoes de ordenacao (insertion
//sort, merge sort, quicksort e heapsort) de vetores de elementos
//inteiros.
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

/*///////////////////////////////////////////////////////////////
// Funcoes auxiliares privadas ////////////////////////////////*/

static void intercala (int *v, int p, int q, int r) {
   int i, j, k, *w;
   w = malloc ((r - p) * sizeof (int));
   i = p; j = q;
   k = 0;
   while (i < q && j < r) {
      if (v[i] <= v[j]) w[k++] = v[i++];
      else w[k++] = v[j++];
   }
   while (i < q) w[k++] = v[i++];
   while (j < r) w[k++] = v[j++];
   for (i = p; i < r; i++) v[i] = w[i - p];
   free (w);
}

static void merge (int *v, int p, int r) {
   if (p < r - 1) {
      int q = (p + r) / 2;
      merge (v, p, q);
      merge (v, q, r);
      intercala (v, p, q, r);
   }
}

static int separa (int *v, int p, int r) {
   int c = v[p], i = p + 1, j  = r, t;
   while (i <= j) {
      if (v[i] <= c) i++;
      else if (c < v[j]) j--;
      else {
         t = v[i]; v[i] = v[j]; v[j] = t;
         i++; j--;
      }
   }
   v[p] = v[j], v[j] = c;
   return j;
}

static void quick (int *v, int p, int r) {
   int j;
   if (p < r) {
      j = separa (v, p, r);
      quick (v, p, j - 1);
      quick (v, j + 1, r);
   }
}

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

static void heap (int *v, int n) {
   int p, m, x;
   for (p = n / 2; p >= 1; p--)
      peneira (v, p, n);
   for (m = n; m >= 2; m--) {
      x = v[1]; v[1] = v[m]; v[m] = x;
      peneira (v, 1, m - 1);
   }
}

void insercao (int *v, int n) {
   int i, j, x;
   for (i = 1; i < n; i++) {
      x = v[i];
      for (j = i - 1; j >= 0 && v[j] > x; j--)
         v[j + 1] = v[j];
      v[j + 1] = x;
   }
}

void mergesort (int *v, int n) {
   merge (v, 0, n);
}

void quicksort (int *v, int n) {
   quick (v, 0, n - 1);
}

void heapsort (int *v, int n) {
   heap (v - 1, n);
}