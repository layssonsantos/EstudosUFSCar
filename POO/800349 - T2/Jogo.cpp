#include "Jogo.h"

namespace catalogo {
    // Getters and setters:

    /* ==== Principal getter (abstrato) ==== */
    // Método que retorna um inteiro
    // que represta o tipo: (Jogo = 3):
    int Jogo::getTipo() const {
        return 3;
    }

    string Jogo::getGenero() const { // Método que retorna o gênero do jogo
        return genero;
    }

    void Jogo::setGenero(string genero) { // Método que aplica o gênero do jogo
        this->genero = genero;
    }

    /* Construtor único da classe que recebe
    os valores iniciais dos atributos título, 
    ano de criação e gênero:
    */
    Jogo::Jogo(string titulo, int anoCriacao, string genero) :
    Midia(titulo, anoCriacao), genero(genero) {}
    

    // Destrutor da classe Jogo:
    Jogo::~Jogo() {}

    // Método que imprime os dados do Jogo: (imprime o mesmo que a ficha (c))
    void Jogo::imprimeDados() const {
        cout << "Gênero: " << this->genero << endl; 
    }
}