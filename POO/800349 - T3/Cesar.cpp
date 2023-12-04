#include "Cesar.h"

using namespace cifra;

void Cesar::encripte(string fileIn, string fileOut, int k) {
    // Arquivo texto de entrada e saída:
    ifstream arq_entrada(fileIn);
    ofstream arq_saida(fileOut);

    // Verificar se o arquivo abriu:
    if (!arq_entrada.good() || !arq_saida.good()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }
    
    // Caracter a ser lido e as linhas:
    char c;
    while (arq_entrada.get(c)) // É lido cada caracter do arquivo de entrada
    {
        if (isupper(c) == 1) // Se o caracter é uma letra e é maiúscula
        {
            if (k > 0) // Verifica a rotação ( k > 0 = direita)
            { 
                // Essa fórmula calcula a posição da letra no alfabeto após a 
                // rotação, e + 'A' adiciona o código ASCII da letra 'A' para 
                // obter o código ASCII do novo caractere:
                char novoC = ((c - 'A' + k + 26) % 26 + 'A'); 
                arq_saida.put(novoC);
            }
            else // Verifica a rotação ( k < 0 = esquerda)
            {
                char novoC = ((c - 'A' + k + 26) % 26 + 'A');
                arq_saida.put(novoC);
            }
        }
        else if (islower(c) == 1) // Se o caracter é uma letra e é minúscula
        {
            {
                if (k > 0)
                {
                    // Mesma fórmula, porém para as letras minúsculas da tabela
                    // ASCII da letra 'a':
                    char novoC = ((c - 'a' + k + 26) % 26 + 'a');
                    arq_saida.put(novoC);
                }
                else 
                {
                    char novoC = ((c - 'a' + k + 26) % 26 + 'a');
                    arq_saida.put(novoC);
                }
            }
        }
        else // Se o caractere não é uma letra, ele é simplesmente copiado para o arquivo de saída
            arq_saida.put(c);
    }

    // Fechar os arquivos pós utilização:
    arq_entrada.close();
    arq_saida.close();
}

    
