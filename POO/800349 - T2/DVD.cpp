#include "DVD.h"

namespace catalogo {
    // Getters and setters:

    /* ==== Principal getter (abstrato) ==== */
    // Método que retorna um inteiro
    // que represta o tipo: (DVD = 2):
    int DVD::getTipo() const {
        return 2;
    }

    // Método que retorna o diretor do filme (DVD):
    string DVD::getDiretor() const {
        return diretor;
    }

    // Método que aplica o diretor do filme (DVD):
    void DVD::setDiretor(string diretor) {
        this->diretor = diretor;
    }

    /*
    Construtor único da classe que recebe
    os valores iniciais dos atributos título, 
    ano de criação e artista:
    */
    DVD::DVD(string titulo, int anoCriacao, string diretor) :
    Midia(titulo, anoCriacao), diretor(diretor) {}

    // Destrutor da classe DVD:
    DVD::~DVD() {}

    /* Método usado para adicionar um
    ator/atriz e seu papel à lista dos 
    principais atores/artistas que 
    atuaram no filme:
    */
    void DVD::adicionaArtista(string artista, string papel) {
        this->artista.push_back(artista); // Adiciona artista no final da lista
        this->papel.push_back(papel); // Adiciona o papel desempenhado no final da lista
    }

    // Método que imprime os dados do DVD: (imprime o mesmo que a ficha (b))
    void DVD::imprimeDados() const {
        cout << "Diretor: " << this->diretor << endl;
        for (unsigned long int i = 1; i <= artista.size(); i++) {
            cout << "Artista " << i << ": ";
            cout << this->artista[i - 1] << ", ";
            cout << "papel: " << this->papel[i - 1] << endl;
        }
    }
}