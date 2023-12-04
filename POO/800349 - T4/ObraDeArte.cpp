#include "ObraDeArte.h"

ObraDeArte::ObraDeArte(string titulo, string artista, string material, int anoCriacao, string tecnica) :
titulo(titulo), artista(artista), material(material), anoCriacao(anoCriacao), tecnica(tecnica){}

// Destrutor da classe ObraDeArte:
ObraDeArte::~ObraDeArte() {}

// Getters and setters:

string ObraDeArte::getTitulo() const {
   	return titulo;
}

void ObraDeArte::setTitulo(string titulo) {
    this->titulo = titulo;
}

string ObraDeArte::getArtista() const {
    return artista;
}

void ObraDeArte::setArtista(string artista) {
    this->artista = artista;
}

string ObraDeArte::getMaterial() const {
    return material;
}

void ObraDeArte::setMaterial(string material) {
    this->material = material;
}

int ObraDeArte::getAnoCriacao() const {
    return anoCriacao;
}

void ObraDeArte::setAnoCriacao(int anoCriacao) {
    this->anoCriacao = anoCriacao;
}

string ObraDeArte::getTecnica() const {
    return tecnica;
}

void ObraDeArte::setTecnica(string tecnica) {
    this->tecnica = tecnica;
}

bool ObraDeArte::comparaTitulo(const ObraDeArte* oda1, const ObraDeArte* oda2) {
    return oda1->getTitulo() < oda2->getTitulo();
}

bool ObraDeArte::comparaAno(const ObraDeArte* oda1, const ObraDeArte* oda2) {
    if(oda1->getAnoCriacao() == oda2->getAnoCriacao())
   		return ObraDeArte::comparaTitulo(oda1, oda2);
   	 else
   		return oda1->getAnoCriacao() < oda2->getAnoCriacao();
}

void ObraDeArte::imprime() const {
    string arte;

    switch (getArte()) {
        case PINTURA: {
            arte = "Pintura";
            break;
        }
        case ESCULTURA: {
            arte = "Escultura";
            break;
        }
    }
    cout << "Arte Visual: " << arte << endl;
    cout << "Titulo: " << titulo << endl;
   	cout << "Artista: " <<  artista << endl;
   	cout << "Material: " << material << endl;
    cout << "Ano: " << anoCriacao << endl;
    cout << "Tecnica: " << tecnica << endl;
}