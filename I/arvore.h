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
// Funcoes da biblioteca arvore.c 
//
////////////////////////////////////////////////////////////// */
#include "lista.h"

#ifndef _ARVORE_H
#define _ARVORE_H

struct cel {
    char *chave;
    lista *conteudo;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel noh;
typedef noh *arvore;

/* //////////////////////////////////////////////////////////////
// Funcao criaNoh: recebe uma string str e um inteiro i, cria um
//noh com chave str e com o conteudo uma lista encadeada cujo 
//primeiro elemento eh i e retorna um ponteiro para esse noh.
////////////////////////////////////////////////////////////// */
noh *criaNoh (char *str, int i);

/* //////////////////////////////////////////////////////////////
// Funcao busca: Recebe uma arvore de busca binaria r e uma 
//string s, retorna um ponteiro para noh cuja chave eh s.
//Se esse elemento nao existir, retorna NULL.
////////////////////////////////////////////////////////////// */
noh *busca (arvore r, char *s); 

/* //////////////////////////////////////////////////////////////
// Funcao insereNoh: recebe uma arvore de busca binaria r
//e um ponteiro para noh novo. Insere esse ponteiro para
//noh na posicao correta da arvore, de tal forma que ela continue
//uma arvore de busca binaria e retorna a raiz da arvore.
////////////////////////////////////////////////////////////// */
arvore insereNoh (arvore r, noh *novo);

/* //////////////////////////////////////////////////////////////
// Funcao altura: recebe uma arvore de busca binaria r e retorna 
//inteiro que representa a altura da arvore.
////////////////////////////////////////////////////////////// */
int altura (arvore r);

/* //////////////////////////////////////////////////////////////
// Funcao contaNoh: recebe uma arvore de busca binaria r e 
//retorna um inteiro que representa a quantidade de nohs da 
//arvore.
////////////////////////////////////////////////////////////// */
int contaNoh (arvore r);

/* //////////////////////////////////////////////////////////////
// Funcao desalocaArvore: recebe uma arvore r e desaloca todos 
//seus nohs, bem como suas chaves e a lista encadeada apontada
//pelo conteudo.
////////////////////////////////////////////////////////////// */
void desalocaArvore (arvore r);

#endif