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
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int *geraVetor (int n) {
   int i, *v;
   v = malloc (n * sizeof (int));
   for (i = 0; i < n; i++) 
      v[i] = (rand () % 900000000) + 100000000;
   return v;
}

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
   int *a, *b, tamanho;
   tamanho = 40000;
   printf ("Iniciando ordenacao com %d elementos:\n", tamanho);
   a = geraVetor (tamanho);
   b = geraVetor (tamanho);

   printf ("Ordenando com Heapsort!\n");
   heapsort (a, tamanho);
   printf ("Ordenando com Radix!\n");
   digital (b, tamanho);

   teste (a, tamanho);
   teste (b, tamanho);

   free (a);
   free (b);

   tamanho *= 2;
   
   printf ("Iniciando ordenacao com %d elementos:\n", tamanho);
   a = geraVetor (tamanho);
   b = geraVetor (tamanho);

   printf ("Ordenando com Heapsort!\n");
   heapsort (a, tamanho);
   printf ("Ordenando com Radix!\n");
   digital (b, tamanho);

   teste (a, tamanho);
   teste (b, tamanho);

   free (a);
   free (b);
   return EXIT_SUCCESS;
}