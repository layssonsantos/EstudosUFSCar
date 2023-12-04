#include "Midia.h"

namespace catalogo {
    // Getters and setters:

    // Método que retorna o titulo da mídia:
    string Midia::getTitulo() const {
        return titulo;
    }

    // Método que aplica o título da mídia:
    void Midia::setTitulo(string titulo) {
        this->titulo = titulo;
    }

    // Método que retorna o ano da mídia:
    int Midia::getAnoCriacao() const {
        return anoCriacao;
    }

    // Método que aplica o ano da mídia:
    void Midia::setAnoCriacao(int anoCriacao) {
        this->anoCriacao = anoCriacao;
    }

    /*
    Construtor único da classe que 
    recebe os valores iniciais dos 
    atributos título e ano de criação
    */
    Midia::Midia(string titulo, int anoCriacao) : 
    titulo(titulo), anoCriacao(anoCriacao) {}

    // Destrutor da classe Midia:
    Midia::~Midia() {}

     // Ordenar as fichas de mídias do catálogo pelo ano + titulo
    bool Midia::comparaAnoTitulo(const Midia* m1, const Midia* m2) {
        // Ordenar o ano da mídia (ordem decrescente)
        // Caso duas mídias tenham o mesmo ano, então 
        // são ordenadas pelo título (ordem crescente):
        if (m1->anoCriacao == m2->anoCriacao) {
            return m1->titulo < m2->titulo;
        } else {
            return m1->anoCriacao > m2->anoCriacao;
        }
    }
    
    // Método que imprime uma ficha contendo os dados da mídia
    void Midia::imprimeFicha() const {
        cout << "Título: " << this->titulo << endl;
        cout << "Ano: " << this->anoCriacao << endl;
        if (getTipo() == 1) {
            cout << "Tipo: CD de música" << endl;
        }
        else if (getTipo()== 2) {
            cout << "Tipo: Filme em DVD" << endl;
        }
        else {
            cout << "Tipo: Jogo Eletrônico" << endl;
        }
        this->imprimeDados();
    }
}