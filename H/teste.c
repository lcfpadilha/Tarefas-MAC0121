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
// Biblioteca teste.c
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <string.h>
#include "teste.h"

/*///////////////////////////////////////////////////////////////
// Funcoes publicas //////////////////////////////////////////*/

/* Veja documentacao em teste.h */
void teste (char **v, int n) {
   int i;
   for (i = 1; i < n; i++) {
      if (strcmp (v[i], v[i - 1]) < 0) {
         printf ("ERRO! O vetor nao esta ordenado!\n");
         return;
      }
   }
   printf ("Vetor ordenado!\n");
}
