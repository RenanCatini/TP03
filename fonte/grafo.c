#include <stdlib.h>
#include <math.h>

unsigned **criarGrafo(int tam)
{
    unsigned **grafo = malloc(tam*sizeof(unsigned*));
    for(int i = 0; i < tam; i++)
        grafo[i] = calloc(tam,sizeof(unsigned));

    return grafo;
}

void liberarGrafo(void **grafo, int tam)
{
    for(int i = 0; i < tam; i++)
        free(grafo[i]);
    free(grafo);
}

double **inverterArestas(unsigned **grafoInt, int tam)
{
    double **grafoDouble = malloc(tam*sizeof(double*));
    for(int i = 0; i < tam;i++)
        grafoDouble[i] = malloc(tam*sizeof(double));
    
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            grafoDouble[i][j] = (grafoInt[i][j] > 0) ? 1.0 / grafoInt[i][j] : INFINITY;
    return grafoDouble;
}