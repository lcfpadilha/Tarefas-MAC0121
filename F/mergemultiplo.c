#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  cel {
	int i;
	int n;
};
typedef struct cel celula;

int minimo (int f[], int fimArquivo[], int i, int n) {
	int j, min;
	min = i;
	for (j = i; j < n; j++)
		if (fimArquivo[j] == 0 && f[j] < f[min])
			min = j;
	return min;
}

int verificaFim (int v[], int n) {
	int i;
	for (i = 0; i < n; i++) 
		if (v[i] == 0) 
			return i;
	return -1;
}

void corrige_subindo (celula v[], int f) {
	int p, x;
	p = f / 2;
	while (p >= 1) {
		if (v[p].n > v[f].n) {
			x = v[p].n;
			v[p].n = v[f].n;
			v[f].n = x;
			f = p;
			p = f / 2;
		}
		else break;
	}
}

int main (int numargs, char *args[]) {
	int i, k, n, *f, *fimArquivo, iMin;
	celula *v;
	FILE **entrada, *saida;
	n = numargs - 3;
	entrada = malloc (n * sizeof (FILE *));
	saida = fopen (args[numargs - 1], "w");
	if (strcmp (args[1], "-s") == 0) {
		f = malloc (n * sizeof (int));
		fimArquivo = malloc (n * sizeof (int));
		for (i = 2; i < numargs - 1; i++) {
			entrada[i - 2] = fopen (args[i], "r");
			if (fscanf (entrada[i - 2], "%d", &f[i - 2]) == EOF)
				fimArquivo[i - 2] = 1;
			else 
				fimArquivo[i - 2] = 0;
		}
		while (1) {
			i =  verificaFim(fimArquivo, n);
			if (i == -1) break;
			iMin = minimo (f, fimArquivo, i, n);
			fprintf (saida, "%d ", f[iMin]);
			if ((fscanf (entrada[iMin], "%d", &f[iMin])) == EOF)
				fimArquivo[iMin] = 1;
		}
		free (f);
		free (fimArquivo);

	}
	else {
		v = malloc ((n + 1) * sizeof (celula));
		k = 1;
		for (i = 2; i < numargs - 1; i++) {
			entrada[i - 2] = fopen (args[i], "r");
			if (fscanf (entrada[i - 2], "%d", &v[k].n) != EOF) {
				v[k++].i = i;
				corrige_subindo (v, k - 1);
			}
		}
		/*Retira primeiro elemento, adiciona proximo do indice i,
		corrige descendo (se for EOF, pega o menor dos filhos, diminui
		k) faz isso ate k >= 1*/
	}

	for (i = 0; i < n; i++) fclose (entrada[i]);
	free (entrada);
	fclose (saida);
	return 0;
}