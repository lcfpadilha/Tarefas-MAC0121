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
// Programa radixLSDsort: Este programa tem como objetivo comparar
//experimentalmente a eficiencia do metodo de ordenacao Radix sort.
//Fazemos testes de ordenacao com vetores de strings compostos por
//40000, 80000, 160000 e 320000 elementos que representam numeros
//inteiros com 9 digitos. Exibimos na tela o tempo de ordenacao 
//com o uso do Radix Sort e com o uso do Heapsort.  
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "teste.h"

/* //////////////////////////////////////////////////////////////
// Funcao geraVetor: recebe um inteiro n e retorna um vetor 
//de strings indexado de 0..n-1. O vetor sera composto por strings
//que representam numeros aleatorios de 9 digitos.
////////////////////////////////////////////////////////////// */
char **geraVetor (int n) {
   int i, t;
   char **v;
   v = malloc (n * sizeof (char *));
   for (i = 0; i < n; i++) {
      v[i] = malloc (10 * sizeof (char));
      t = (rand () % 900000000) + 100000000;
      sprintf (v[i], "%d", t);
   }
   return v;
}

/* //////////////////////////////////////////////////////////////
// Funcao desaloca: recebe um vetor de strings v[0..n-1] e desaloca
//todos seus elementos.
////////////////////////////////////////////////////////////// */
void desaloca (char **v, int n) {
   int i;
   for (i = 0; i < n; i++) free (v[i]);
   free (v);
   v = NULL;
}

int main (void) {
   int tamanho, i;
   char **a, **b;
   double tInicio, tFim;
   tamanho = 40000;
   
   for (i = 0; i < 4; i++) {
      printf ("Iniciando ordenacao com %d elementos:\n", tamanho);
      a = geraVetor (tamanho);
      b = geraVetor (tamanho);
      printf ("-->Ordenando com Heapsort!\n");
      tInicio = (double) clock () / CLOCKS_PER_SEC;

      heapsort (a, tamanho);

      tFim = (double) clock () / CLOCKS_PER_SEC;
      printf ("Tempo gasto: %.2f segundos\n", tFim - tInicio);
      teste (a, tamanho);

      printf ("-->Ordenando com Radix!\n");
      tInicio = (double) clock () / CLOCKS_PER_SEC;

      digital (b, tamanho);

      tFim = (double) clock () / CLOCKS_PER_SEC;
      printf ("Tempo gasto: %.2f segundos\n", tFim - tInicio);
      teste (b, tamanho);
      printf ("\n");

      desaloca (a, tamanho); desaloca (b, tamanho);
      tamanho *= 2;
   }

   return EXIT_SUCCESS;
}