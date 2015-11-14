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

noh *criaNoh (char *str, int i);

arvore insere (arvore r, noh *novo);

arvore busca (arvore r, char *s); 

int altura (arvore r);

int contaNoh (arvore r);

void desalocaArvore (arvore r);

#endif