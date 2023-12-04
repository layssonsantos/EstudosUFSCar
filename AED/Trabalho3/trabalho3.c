/*

====================================
Nome: Laysson Santos da Silva
Curso: Ciência da Computação (BCC)
RA: 800349           
====================================

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

unsigned long long nroDeInversoes(int v[], int w[], int n)
{
    int i, j, aux, pos;
    unsigned long long inversoes = 0;

    // Enquanto os vetores tiverem valores diferentes em suas posições
    // o vetor que precisa ser mudado tem o valor encontrado e invertido
    // até estar na posição correta:
    for (i = 0; i < n; i++)
    {
        if (w[i] != v[i])
        {
            pos = i;

            while (w[pos] != v[i])
            {
                pos++;
            }
            for (j = pos; j > i; j--)
            {
                aux = w[j - 1];
                w[j - 1] = w[j];
                w[j] = aux;
                inversoes++;
            }
        }
    }
    return inversoes;
}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;
    unsigned long long num_inv = 0;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);
    //imprime(v, n);
    int *w = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &w[i]);
    //imprime(w, n);
    // crie uma funcao que calcule o numero de inversoes entre v e w
    num_inv = nroDeInversoes(v, w, n);

    // printf("%I64u\n", num_inv);
    printf("%llu\n", num_inv);

    free(v);
    free(w);

    fclose(entrada);
    return 0;
}
