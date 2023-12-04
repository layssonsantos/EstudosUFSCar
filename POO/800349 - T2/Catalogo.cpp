#include "Catalogo.h"
#include <algorithm>

namespace catalogo {

    // Construtor vazio da classe Catalogo que inicializa
    // as posições do vetor de mídias como 0:
    Catalogo::Catalogo() {

        for (unsigned long int i = 0; i < midias.size(); i++) {
            this->midias[i] = 0;
        }
    }

    // Destrutor da classe Catalogo:
    Catalogo::~Catalogo() {
        this->midias.clear();
    }

    // Adiciona uma mídia ao catálogo:
    bool Catalogo::adicionaMidia(Midia& midia) {
        this->midias.push_back(&midia);
        return 1;
    }  

    // Remove uma mídia (cujo título é igual ao parâmetro
    // passado) do catálogo:
    bool Catalogo::removeMidia(string titulo) {
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTitulo() == titulo) { // remover a mídia se o titulo for igual ao parâmetro
                this->midias.erase(this->midias.begin() + i); // remove o i-esimo elemento
                return 1;
            }
        } 
        return 0;
    }  

    // Método que retorna a mídia cujo título é igual ao
    // parâmetro passado e null, caso a mídia não seja 
    // encontrada no catálogo:
    Midia* Catalogo::obtemMidia(string titulo) {
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTitulo() == titulo) {
                return midias[i];
            }
        }
        return nullptr;
    }

    // Fornece a quantidade de mídias no catálogo:
    int Catalogo::quantidadeDeMidias() {
        return this->midias.size();
    }

    // Fornece a quantidade de CDs no catálogo:
    int Catalogo::quantidadeDeCDs() {
        int nroDeCDS = 0; // quantidade de CDs
        // verificar cada mídia e encontrar os CDs (tipo = 1):
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTipo() == 1) {
                nroDeCDS++;
            }
        }
        return nroDeCDS;
    }

    // Fornece a quantidade de DVDs no catálogo:
    int Catalogo::quantidadeDeDVDs() {
        int nroDeDVDs = 0; // quantidade de DVDs
        // verificar cada mídia e encontrar os DVDs (tipo = 2):
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTipo() == 2) {
                nroDeDVDs++;
            }
        }
        return nroDeDVDs;
    }
    
    // Fornece a quantidade de jogos no catálogo:
    int Catalogo::quantidadeDeJogos() {
        int nroDeJogos = 0; // quantidade de Jogos
        // verificar cada mídia e encontrar os Jogos (tipo = 3):
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTipo() == 3) {
                nroDeJogos++;
            }
        }
        return nroDeJogos;
    }


    // Imprime as fichas das mídias do catálogo, 
    // ordenadas pelo ano + título:
    void Catalogo::imprimeColecao() {
        sort(midias.begin(), midias.end(), Midia::comparaAnoTitulo);
        for (unsigned long int i = 0; i < midias.size(); i++) {
            this->midias[i]->imprimeFicha();
            cout << endl;
        }
    }

    // Imprime as fichas das mídias de um determinado tipo,
    // ordenadas pelo ano + título:  
    void Catalogo::imprimeColecaoPorTipo(int tipo) {
        sort(midias.begin(), midias.end(), Midia::comparaAnoTitulo);
        for (unsigned long int i = 0; i < midias.size(); i++) {
            if (this->midias[i]->getTipo() == tipo) {
                this->midias[i]->imprimeFicha();
                cout << endl;
            }
        }
    }
}


