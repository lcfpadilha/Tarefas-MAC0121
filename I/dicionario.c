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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "lista.h"


static char *leLinha (FILE *entrada) {
    char *str, c;
    int tam, i;
    i = 0;
    tam = 300;
    str = aloca (tam * sizeof (char) + 1);
    while ((c = getchar ()) != '\n' && c != EOF) {
        if (i == tam)  {
            tam *= 2;
            str = realloc (str, (tam + 1) * sizeof (char) ); //reallocs com problema
        }
        str[i] = c;
        i++;
    }
    if (i == 0 && c == EOF) {
        free (str);
        return NULL;
    }
    if (i != 0 && c == '\n') str[i++] = '\n';
    str[i] = '\0';
    return str;
}

static void retiraPalavra (arvore dic, char *str, int linha) {
    int i, tam, k;
    char *p;
    noh *novo, *res;
    k = 0;
    tam = 300;
    p = malloc (tam * sizeof (char));
    for (i = 0; str[i] != '\0'; i++) { 
        if (isalnum (str[i])) {
            if (k == tam) {
                tam *= 2;
                str = realloc (str, (tam + 1) * sizeof (char)); //reallocs com problema
            }
            p[k++] = tolower (str[i]);
        }
        else if (k > 0) {
            if (k == tam) {
                tam *= 2;
                str = realloc (str, (tam + 1) * sizeof (char)); //reallocs com problema
            }
            p[k] = '\n';
            p[k + 1] = '\0';
            res = busca (dic, p);
            if (res == NULL && isalpha (p[0])) { //procura em arvore.h
                novo = criaNoh (p, linha);
                dic = insereNoh (dic, novo);
            }
            else if (res != NULL) 
                insereLista (res->conteudo, linha);
            k = 0;
        }
    }
    free (p);
}

arvore constroiDicionario (char *arq) {
    int linha = 1;
    char *str;
    arvore dic = NULL;
    FILE *entrada;
    entrada = fopen (arq, "r");
    str = leLinha (entrada);
    while (linha != NULL) {
        retiraPalavra (dic, str, linha);
        str = leLinha (entrada);
        linha++;
    }
    fclose (entrada);
    return arvore;
}