// Informações do estudante
// Nome: Laysson Santos
// Curso: BCC - Ciência da Computação
// RA: 800349

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int palindromoR(int i, int f, char *s)
{
    // implemente essa função recursiva
    if (f < i || s == NULL) // Caso a última posicao da string seja menor que a primeira ou a string seja vazia (composta por nenhuma letra/número), é Palíndromo (Caso Base)
        return 1;
    if (s[i] != s[f]) // Caso a primeira letra/número seja diferente da última, não é Palíndromo
        return 0;
    return palindromoR(i + 1, f - 1, s); // Chamando a função para ir comparando as letras do meio e diminuindo a string para determinar se é igual a string original

    return 0; 
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{
    // implemente essa função recursiva

    if (*str) { // Caso base --> Se for string, é chamada a função novamente para inverter os conteúdos até o '\0'
        inversaR(str + 1);
        printf("%c", *str);
    }
}

void inversa(char *s)
{
    inversaR(s);
    printf("\n");
}

unsigned long stirlingR(unsigned long n, unsigned long k)
{
    // implemente essa função recursiva
    if (n < 0 && k < 0) return 1; // Caso sejam negativos, interrompe o código

    if (n == 0 && k == 0) return 1; // Coeficientes zerados
    else if (k > n) return 0; // Se k for maior q n, o total de partições é zero 
    else if  (n == 0 || k == 0) return 0; // Caso algum seja 0, o resultado é zero
    else {
        return stirlingR(n - 1, k) * (n - 1) + stirlingR(n - 1, k - 1); // Propriedade de cálculo de contagem de números
    }

    return 0;
}

void stirling(int n, int k)
{
    printf("%lu\n", stirlingR(n, k));
}

void padraoR(unsigned n)
{
    // implemente essa função recursiva
    if (n < 0) return; // Caso base --> Se for número negativo, não acontece nada

    if (n == 0) // Verifica o funcionamento da função até os números chegarem á 0
        printf("%i%i", n, n);
    else {
        printf("%u", n); // Printa o número (n) inicialmente
        padraoR(n - 1); // Decresce 1 de n
        printf("%u", n); // Printa novamente o número (n) pós recursão
    }
}

void padrao(unsigned n)
{
    padraoR(n);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char file_name[MAX], aux[MAX];
    FILE *entrada;
    int t, a, b;

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("Nao encontrei o arquivo!");
        exit(EXIT_FAILURE);
    }

    fscanf(entrada, "%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar Stirling]\n");
        printf("tp01_recursao 4 [para testar padrao]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        fscanf(entrada, "%s", aux);
        while (aux[0] != '.')
        {
            palindromo(aux);
            fscanf(entrada, "%s", aux);
        }
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        fscanf(entrada, "%s", aux);
        while (aux[0] != '.')
        {
            inversa(aux);
            fscanf(entrada, "%s", aux);
        }
    }
    else if (t == 3)
    {
        printf("\nTestando Stirling()\n\n");
        fscanf(entrada, "%d %d", &a, &b);
        while (a != -1)
        {
            stirling(a, b);
            fscanf(entrada, "%d %d", &a, &b);
        }
    }
    else if (t == 4)
    {
        printf("\nTestando padrao()\n\n");

        fscanf(entrada, "%d", &a);
        while (a != -1)
        {
            padrao(a);
            fscanf(entrada, "%d", &a);
        }
    }

    return 0;
}
