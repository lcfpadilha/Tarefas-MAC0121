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
//  Programa 
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#include "dicionario.h"
#include "lista.h"


void imprimeLista (lista *ini) {
    lista *p;
    p = ini->prox;
    while (p != NULL){
        printf ("%d ", p->linha);
        p = p->prox;
    }
}

void imprimeDic (arvore dic) {
    if (dic == NULL) return;
    imprimeDic (dic->esq);
    printf ("%s ", dic->chave);
    imprimeLista (dic->conteudo);
    printf ("\n");
    imprimeDic (dic->dir);
}

int main (int numargs, char *arg[]) {
    arvore dic;
    if (numargs != 3) {
        printf ("ERRO! Numero de argumentos devem ser 3!\n");
        return EXIT_FAILURE;
    }
    dic = constroiDicionario (arg[1]);
    imprimeDic (dic); /*podia estar na arvore, ne?*/
    return EXIT_SUCCESS;
}