#include "CD.h"

namespace catalogo {
    // Getters and setters:

    /* ==== Principal getter (abstrato) ==== */
    // Método que retorna um inteiro
    // que represta o tipo: (CD = 1):
    int CD::getTipo() const {
        return 1;
    }

    // Método que retorna o artista (compositor/intérprete da obra)
    string CD::getArtista() const {
        return artista;
    }

    // Método que aplica o artista da obra:
    void CD::setArtista(string artista) {
        this->artista = artista;
    }

    /*
    Construtor único da classe que recebe
    os valores iniciais dos atributos título, 
    ano de criação e artista:
    */
    CD::CD(string titulo, int anoCriacao, string artista) : 
    Midia(titulo, anoCriacao), artista(artista) {}

    // Destrutor da classe DVD:
    CD::~CD() {}

    // Método usado para adicionar uma faixa
    // (e sua duração) ao CD de música:
    void CD::adicionaFaixa(string faixaNome, int faixaDuracao) {
        this->faixaNome.push_back(faixaNome); // Adiciona o nome da faixa no final da lista
        this->faixaDuracao.push_back(faixaDuracao); // Adiciona a duração da faixa no final da lista (em segundos)
    }

    // Método que imprime os dados do CD: (imprime o mesmo que a ficha (a))
    void CD::imprimeDados() const {
        cout << "Artista: " << this->artista << endl;
        for (unsigned long int i = 1; i <= faixaNome.size(); i++) {
            cout << "Faixa " << i << ": " << this->faixaNome[i - 1];
            // Converter os segundos em MINUTOS:SEGUNDOS (adicionando 0 a esquerda)
            // caso os segundos sejam menores do que 10:
            int faixaSec = this->faixaDuracao[i - 1];
            int resto, segundos, minutos;
            resto = faixaSec % 3600;
            minutos = resto / 60;
            segundos = resto % 60;
            cout << ", duração: ";
            cout << minutos << ":";
            if (segundos < 10)
                cout << "0";
            cout << segundos << endl;
        }
    }
}