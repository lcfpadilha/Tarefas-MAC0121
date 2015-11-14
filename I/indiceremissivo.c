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


void imprimeLinha (lista *ini, FILE *saida) {
    lista *p;
    p = ini->prox;
    fprintf (saida, "  %d", p->linha);
    p = p->prox;
    while (p != NULL){
        fprintf (saida, ", %d", p->linha);
        p = p->prox;
    }
    fprintf (saida, "\n");
}

void imprimeDic (arvore dic, FILE *saida) {
    if (dic == NULL) return;
    imprimeDic (dic->esq, saida);
    fprintf (saida, "%s ", dic->chave);
    imprimeLinha (dic->conteudo, saida);
    imprimeDic (dic->dir, saida);
}

int main (int numargs, char *arg[]) {
    double tInicio, tFim;
    arvore dic;
    FILE *saida, *entrada;
    if (numargs != 3) {
        printf ("ERRO! Numero de argumentos devem ser 3!\n");
        return EXIT_FAILURE;
    }
    entrada = fopen (arg[1], "r");
    saida = fopen (arg[2], "w");
    tInicio = (double) clock () / CLOCKS_PER_SEC;
    dic = constroiDicionario (entrada);
    tFim = (double) clock () / CLOCKS_PER_SEC;
    imprimeDic (dic, saida); 
    printf ("Tempo gasto: %3f segundos\n", tFim - tInicio);
    fclose (entrada);
    fclose (saida);
    return EXIT_SUCCESS;
}