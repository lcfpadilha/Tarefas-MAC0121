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
#include <stdlib.h>
#include "lista.h"

lista *criaLista (int n) {
    lista *cabeca;
    cabeca = malloc (sizeof (lista));
    cabeca->prox = malloc (sizeof (lista));
    cabeca->prox->linha = n;
    cabeca->prox->prox = NULL;
    return cabeca;
}

void insereLista (lista *ini, int n) {
    lista *nova, *p;
    p = ini;
    while (p->prox != NULL) 
        p = p->prox;
    if (p->linha != n) {
        nova = malloc (sizeof (lista));
        nova->linha = n;
        nova->prox = NULL;
        p->prox = nova;
    }
}

void desalocaLista (lista *ini) {
    lista *p, *q;
    p = ini;
    q = ini->prox;
    while (q != NULL) {
        free (p);
        p = q;
        q = q->prox;
    }
    free (p);
}