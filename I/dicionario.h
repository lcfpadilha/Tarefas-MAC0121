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
/* //////////////////////////////////////////////////////////////
//
// Funcoes da biblioteca dicionario.c 
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include "arvore.h"

#ifndef _DICIONARIO_H
#define _DICIONARIO_H

/*///////////////////////////////////////////////////////////////
// Funcao controiDicionario: recebe um ponteiro de arquivo entrada
//e retorna uma arvore de busca binaria cujas chaves sao as 
//palavras maiores que 2 caracteres que estao na entrada, o 
//conteudo dos nohs sao cabecas para uma lista encadeada onde cada
//elemento da lista eh um inteiro que representa a linha na qual
//aquela palavra pode ser encontrada.
///////////////////////////////////////////////////////////////*/
arvore constroiDicionario (FILE *entrada);

#endif
