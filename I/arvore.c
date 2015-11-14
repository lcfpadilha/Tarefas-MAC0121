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
#include <string.h>
#include "arvore.h"
#include "lista.h"

noh *criaNoh (char *str, int i) {
	int tamanho;
	noh *novo;
	novo = malloc (sizeof (noh));
	tamanho = strlen (str);
	novo->chave = malloc ((tamanho + 1) * sizeof (char));
	strcpy (novo->chave, str);
	novo->conteudo = criaLista (i);
	novo->esq = NULL;
	novo->dir = NULL;
    return novo;
}

arvore insere (arvore r, noh *novo) {
	noh *filho, *pai;
    if (r == NULL) return novo;
    filho = r;
    while (filho != NULL) {
        pai = filho;
        if (strcmp (filho->chave, novo->chave) > 0)  
       		filho = filho->esq;
        else  
        	filho = filho->dir;
    }
    if (strcmp (pai->chave, novo->chave) > 0)  pai->esq = novo;
    else  pai->dir = novo;
    return r;
}

arvore busca (arvore r, char *s) {
	if (r == NULL || strcmp (r->chave, s) == 0)
       return r;
    if (strcmp (r->chave, s) > 0)
       return busca (r->esq, s);
    else
       return busca (r->dir, s);
}

int altura (arvore r) {
	int hEsq, hDir;
	if (r == NULL) return -1;
	hEsq = altura (r->esq);
	hDir = altura (r->dir);
	if (hEsq > hDir)
		return hEsq + 1;
	else 
		return hDir + 1;
}

int contaNoh (arvore r) {
	if (r == NULL) return 0;
	return contaNoh (r->esq) + contaNoh (r->dir) + 1;
}

void desalocaArvore (arvore r) {
	if (r == NULL) return;
	desalocaArvore (r->esq);
	desalocaArvore (r->dir);
	desalocaLista (r->conteudo);
	free (r->chave);
	free (r);
}