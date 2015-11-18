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
// Data: 2015-09-18
// 
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////
//
// Biblioteca dicionario.c 
//
////////////////////////////////////////////////////////////// */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "dicionario.h"
#include "lista.h"

/*///////////////////////////////////////////////////////////////
// Variaveis globais privadas /////////////////////////////////*/

static arvore dic;

/*///////////////////////////////////////////////////////////////
// Funcoes auxiliares privadas ////////////////////////////////*/

/* //////////////////////////////////////////////////////////////
// Funcao leLinha: recebe um ponteiro para um arquivo entrada e
//retorna uma string que representa a linha lida da entrada,
//sempre com o ultimo caracter '\n'.
////////////////////////////////////////////////////////////// */
static char *leLinha (FILE *entrada) {
    char *str, c;
    int tam, i;
    i = 0;
    tam = 300;
    str = malloc ((tam + 1) * sizeof (char));
    while ((c = getc (entrada)) != '\n' && c != EOF) {
        if (i == tam - 1) {
            tam *= 2;
            str = realloc (str, (tam + 1) * sizeof (char) ); 
        }
        str[i] = c;
        i++;
    }
    if (i == 0 && c == EOF) {
        free (str);
        return NULL;
    }
    else if (i != 0) 
        str[i++] = '\n';
    str[i] = '\0';
    return str;
}

/* //////////////////////////////////////////////////////////////
// Funcao retiraPalavra: recebe uma string str e um inteiro linha,
//retiramos as palavras de str e colocamos elas no dicionario de
//tal forma que nao haja repeticoes no mesmo. Adicionamos a linha
//no fim da lista encadeada apontada pelo conteudo do noh que esta
//no dicionario e cuja chave eh a palavra.
////////////////////////////////////////////////////////////// */
static void retiraPalavra (char *str, int linha) {
    int i, tam, k;
    char *p;
    noh *novo, *res;
    k = 0;
    tam = 300;
    p = malloc ((tam + 1) * sizeof (char));
    for (i = 0; str[i] != '\0'; i++) { 
        if (isalnum (str[i])) {
            if (k == tam - 1) {
                tam *= 2;
                p = realloc (p, (tam + 1) * sizeof (char)); 
            }
            p[k++] = tolower (str[i]);
        }
        else if (k > 2) {
            p[k] = '\0';
            res = busca (dic, p);
            if (res == NULL && isalpha (p[0])) { 
                novo = criaNoh (p, linha);
                dic = insereNoh (dic, novo);
            }
            else if (res != NULL) 
                insereLista (res->conteudo, linha);
            k = 0;
        }
        else k = 0;
    }
    free (p);
}
/*///////////////////////////////////////////////////////////////
// Funcoes publicas //////////////////////////////////////////*/

/* Veja documentacao em dicionario.h */
arvore constroiDicionario (FILE *entrada) {
    int linha = 1;
    char *str;
    dic = NULL;
    str = leLinha (entrada);
    while (str != NULL) {
        retiraPalavra (str, linha);
        free (str);
        str = leLinha (entrada);
        linha++;
    }
    return dic;
}