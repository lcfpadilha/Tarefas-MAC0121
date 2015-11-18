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
// Funcoes da biblioteca lista.c 
//
////////////////////////////////////////////////////////////// */
#ifndef _LISTA_H
#define _LISTA_H

struct caixa {
	int linha;
	struct caixa *prox;
};
typedef struct caixa lista;

/* //////////////////////////////////////////////////////////////
// Funcao criaLista: recebe um inteiro n e retorna uma cabeca para
//uma lista cujo primeiro elemento eh n.
////////////////////////////////////////////////////////////// */
lista *criaLista (int n);

/* //////////////////////////////////////////////////////////////
// Funcao insereLista: recebe uma lista encadeada com cabeca ini
//e um inteiro n. Insere n no final da lista ini.
////////////////////////////////////////////////////////////// */
void insereLista (lista *ini, int n);

/* //////////////////////////////////////////////////////////////
// Funcao desalocaLista: recebe uma lista encadeada com cabeca ini
//e desaloca todos seus elementos.
////////////////////////////////////////////////////////////// */
void desalocaLista (lista *ini);

#endif