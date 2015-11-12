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
//  Programa Busca Palavras: Cria um dicionario de todas as 
// palavras boas contidas em um arquivo cujo nome deve ser dado
// pelo usuario na linha de comando e imprime esse dicionario
// e o tempo gasto para construi-lo tambem em um arquivo de saida 
// cujo nome deve ser dado pelo usuario na linha de comando. 
// Alem disso, o usuario podera entrar com uma palavra boa 
// p qualquer e o programa imprimira o indice da palavra
// lexograficamente menor ou igual a p e lexograficamente maior
// que p, juntamente com a palavra correspondente a esses indices.
//
////////////////////////////////////////////////////////////// */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bb.h"
#include "dicionario.h"

/*///////////////////////////////////////////////////////////////
// Funções ////////////////////////////////////////////////////*/ 

/*///////////////////////////////////////////////////////////////
// Funcao imprimeDic: recebe um vetor de strings dic[0..n-1], uma
//string arq e um double tempo. Imprime todas as strings contidas
//em dic e o tempo no arquivo arq.
///////////////////////////////////////////////////////////////*/
void imprimeDic (char **dic, int n, char *arq, double tempo) {
    int i;
    FILE *entrada;
    entrada = fopen (arq, "w");
    for (i = 0; i < n; i++) 
       fprintf (entrada, "%s\n", dic[i]);
    fprintf (entrada, "\n");
    fprintf (entrada, "Tempo gasto: %f segundos\n", tempo);
    fclose (entrada);
}

/*///////////////////////////////////////////////////////////////
// Funcao leLinha: le a string digitada pelo usuario ate o '\n'
//e a retorna com todos os caracteres minusculos. Caso o usuario 
//digite apenas '\n', retorna NULL.
///////////////////////////////////////////////////////////////*/
char *leLinha (void) {
    char *linha, *novalinha;
    int i, c, tam;
    i = 0;
    tam = 120;
    linha = malloc (tam + 1);
    printf ("> ");
    c = getchar ();
    while (c != EOF && isalnum (c)) {  
        linha[i++] = tolower (c);
        if (i == tam) {
            tam *= 2;
            novalinha = malloc (tam + 1);
            strncpy (novalinha, linha, i);
            free (linha);
            linha = novalinha;
        }
        c = getchar ();
    }
    if (i == 0) {
        free (linha);
        return NULL;
    }
    linha[i] = '\0';
    novalinha = malloc (strlen (linha) + 1);
    strcpy (novalinha, linha);
    free (linha);
    return novalinha;
}

/*///////////////////////////////////////////////////////////////
// Funcao imprimePalavras: recebe um indice in, um vetor de 
//strings dic[0..n-1] e imprime os indices in e in + 1 e as 
//palavras v[in] e v[in + 1]. Se in for -1, imprime apenas o
//indice in + 1. Se in for n - 1, imprime apenas in.
///////////////////////////////////////////////////////////////*/
void imprimePalavras (int in, char **dic, int n) {
    if (in == -1) 
        printf ("( ) (%d, %s)\n", in + 1, dic[in + 1]);
    else if (in == n - 1)
        printf ("(%d, %s) ( )\n", in, dic[in]);
    else 
        printf ("(%d, %s) (%d, %s)\n", in, dic[in], in + 1, dic[in + 1]);
}

int main (int numargs, char *arg[]) {
    int i, n, in;
    char *pal, **dic;
    double tInicio, tFim;
    tInicio = (double) clock () / CLOCKS_PER_SEC;
    dic = constroiDicionario (arg[1], &n);
    tFim = (double) clock () / CLOCKS_PER_SEC;
    imprimeDic (dic, n, arg[2], tFim - tInicio);
    while ((pal = leLinha ()) != NULL) {
        in = buscaMenor (pal, n, dic);
        imprimePalavras (in, dic, n);
        free (pal);
    }
    for (i = 0; i < n; i++) free (dic[i]);
    free (dic);
    return EXIT_SUCCESS;
}