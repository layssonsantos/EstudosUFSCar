#include "Pintura.h"

// Construtor da classe Pintura capaz de setar os atributos tecnica da Pintura, cor e classificacao:
Pintura::Pintura(string titulo, string artista, string material, int anoCriacao, string tecnica, string cor, string classificacao) : 
ObraDeArte(titulo, artista, material, anoCriacao, tecnica),  cor(cor), classificacao(classificacao) {}

// Destrutor da classe Pintura:
Pintura::~Pintura(){}

// Destrutor da classe Pintura:
int Pintura::getArte() const {
    return PINTURA;
}

// Imprime os dados de uma arte Pintura:
void Pintura::imprimeFicha() const {
    ObraDeArte::imprime();
    cout << "Cor: " << cor << endl;
    cout << "Classificacao: " << classificacao << endl;
}

// Getters and setters:

string Pintura::getCor() const {
    return cor;
}

void Pintura::setCor(string cor) {
    this->cor = cor;
}

string Pintura::getClassificacao() const {
    return classificacao;
}

void Pintura::setClassificacao(string classificacao) {
    this->classificacao = classificacao;
}