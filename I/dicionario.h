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
// Data: 2015-11-12
// 
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include "arvore.h"

#ifndef _DICIONARIO_H
#define _DICIONARIO_H



/*///////////////////////////////////////////////////////////////
// Funcao controiDicionario: Recebe uma string arq e um ponteiro
//para inteiro n e retorna um dicionario (vetor de ponteiros do
//tipo char) contendo todas as palavras em ordem lexicografica
//e sem repeticao do arquivo arq e altera o valor de n para a
//quantidade de palavras contidas no dicionario
///////////////////////////////////////////////////////////////*/
arvore constroiDicionario (FILE *entrada);

#endif
