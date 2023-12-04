#ifndef OBRADEARTE_H
#define OBRADEARTE_H

#include <string>
#include <iostream>
using namespace std;

enum ARTE { PINTURA, ESCULTURA}; // Pintura = 0 e Escultura = 1

class ObraDeArte
{ // Classe abstrata (A)
public:
    ObraDeArte(string titulo, string artista, string material, int anoCriacao, string tecnica);
    virtual ~ObraDeArte();
    virtual int getArte() const = 0;       // método abstrato
    virtual void imprimeFicha() const = 0; // método abstrato
    virtual void imprime() const;
    // Getters and setters:
    virtual string getTitulo() const;
    virtual void setTitulo(string titulo);
    virtual string getArtista() const;
    virtual void setArtista(string artista);
    virtual string getMaterial() const;
    virtual void setMaterial(string material);
    virtual int getAnoCriacao() const;
    virtual void setAnoCriacao(int anoCriacao);
    virtual string getTecnica() const;
    virtual void setTecnica(string tecnica);
    static bool comparaTitulo(const ObraDeArte *oda1, const ObraDeArte *oda2);
    static bool comparaAno(const ObraDeArte *oda1, const ObraDeArte *oda2);
private:
    string titulo;
    string artista;
    string material;
    int anoCriacao;
    string tecnica;
};

#endif // OBRADEARTE_H