#include <stdio.h>
#include <stdlib.h>

/*

====================================
Nome: Laysson Santos da Silva
Curso: Ciência da Computação (BCC)
RA: 800349           
====================================

*/

// Resolver a partir de de uma lista ligada circular
// Criando a célula com os homens da guerra hebraica:
typedef struct homem Homem;
struct homem {
    int posicao;
    Homem *prox;
};

int resolveJosephus(int n, int m) { // n = pessoas e m = quantidade de passos
    // Lista circular (Inicialização):
    Homem *ini = NULL; // Célula inicial
    Homem *atual = NULL; // Célula atual

    // Inserindo a quantidade de Homens:
    int i;
    for (i = 1; i <= n; i++) {
        Homem *novo_hom; // Célula nova (Homem)
        novo_hom = malloc(sizeof(Homem)); // Alocação dinâmica
        novo_hom->posicao = i;
        novo_hom->prox = NULL;

        if (atual == NULL) {
            ini = novo_hom;
            atual = novo_hom;
        } else {
            atual->prox = novo_hom; // Apontando para a próxima célula
            atual = novo_hom; // Recebendo a próxima célula
        }
    }

    // Última célula aponta para a primeira para ser circular:
    atual->prox = ini;
    
    // Processo de eliminar os homens no cúrculo:
    Homem *homem_morto = ini; // Célula para saber quem eliminar
    Homem *ini_turno = ini; // Célula do homem que começa a eliminar

    while (homem_morto->prox != homem_morto) {
        Homem *morta;
        for (i = 1; i < m; i++)
            homem_morto = homem_morto->prox;
        // Elimina:
        morta = homem_morto->prox;
        // Se o mesmo homem for eliminar a si, deve-se ir para o próximo homem:
        if (ini_turno == morta) {
            homem_morto = homem_morto->prox;
            morta = morta->prox;
        }
        homem_morto->prox = morta->prox;
        homem_morto = homem_morto->prox;
        ini_turno = homem_morto;
        free(morta);
    }

    return homem_morto->posicao;
}


int main() {
    int nroexecs;

    scanf("%d", &nroexecs);
    int *n = malloc(nroexecs * sizeof(int));
    int *m = malloc(nroexecs * sizeof(int));

    for (int i = 0; i < nroexecs; i++) {
        scanf("%d", &n[i]);
        scanf("%d", &m[i]);
    }

    for (int i = 0; i<nroexecs; i++) {
        printf("Usando n=%d, m=%d, resultado=%d\n", n[i], m[i], resolveJosephus(n[i], m[i]));
    }

    return 0;
}
