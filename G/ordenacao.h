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
// Funcoes das bibliotecas de ordenacao.
//
////////////////////////////////////////////////////////////// */

#ifndef _ORDENACAO_H
#define _ORDENACAO_H

/* //////////////////////////////////////////////////////////////
// Funcao insercao: recebe um vetor de inteiros v[0..n-1] e 
//rearranja seus elementos de forma a deixa-los em ordem crescente
//usando o algoritimo de ordenacao por insercao.
//Esta funcao consome um tempo proporcional a n^2 no pior caso
//e proporcional a n no melhor caso.
////////////////////////////////////////////////////////////// */
void insercao (int *v, int n);

/* //////////////////////////////////////////////////////////////
// Funcao mergesort: recebe um vetor de inteiros v[0..n-1] e 
//rearranja seus elementos de forma a deixa-los em ordem crescente.
//Esta funcao consome um tempo proporcional a n*log(n).
////////////////////////////////////////////////////////////// */
void mergesort (int *v, int n);

/* //////////////////////////////////////////////////////////////
// Funcao quicksort: recebe um vetor de inteiros v[0..n-1] e 
//rearranja seus elementos de forma a deixa-los em ordem crescente.
//Esta funcao consome um tempo proporcional a n^2 no pior caso,
//mas em geral ela consome tempo proporcional a n*log(n) pois o
//pior caso e bem raro.
////////////////////////////////////////////////////////////// */
void quicksort (int *v, int n);

/* //////////////////////////////////////////////////////////////
// Funcao heapsort: recebe um vetor de inteiros v[0..n-1] e 
//rearranja seus elementos de forma a deixa-los em ordem crescente.
//Esta funcao consome um tempo proporcional a n*log(n) no pior
//caso.
////////////////////////////////////////////////////////////// */
void heapsort (int *v, int n);

#endif