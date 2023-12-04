#include "Escultura.h"

// Construtor da classe Escultura que seta os atributos altura, tipo e tecnica da Escultura:
Escultura::Escultura(string titulo, string artista, string material, int anoCriacao, string tecnica, double altura, string tipo, string epoca) :
ObraDeArte(titulo, artista, material, anoCriacao, tecnica), altura(altura), tipo(tipo), epoca(epoca){}

// Destrutor da classe Escultura:
Escultura::~Escultura() {}

// Método abstrato que retorna uma arte do tipo Escultura:
int Escultura::getArte() const {
    return ESCULTURA;
}

// Imprime os dados de uma Arte Escultura:
void Escultura::imprimeFicha() const {
    ObraDeArte::imprime();
   	cout << "Altura: " << altura << endl;
    cout << "Tipo: " << tipo << endl;
}

// Getters and setters:

double Escultura::getAltura() const {
    return altura;
}

void Escultura::setAltura(double altura) {
    this->altura = altura;
}

string Escultura::getTipo() const {
    return tipo;
}

void Escultura::setTipo(string tipo) {
    this->tipo = tipo;
}

string Escultura::getEpoca() const {
    return epoca;
}

void Escultura::setEpoca(string epoca) {
    this->epoca = epoca;
}