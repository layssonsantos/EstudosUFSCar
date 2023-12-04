#ifndef PINTURA_H
#define PINTURA_H

#include "ObraDeArte.h"

class Pintura : public ObraDeArte
{
public:
    Pintura(string titulo, string artista, string material, int anoCriacao, string tecnica, string cor, string classificacao);
    virtual ~Pintura();
    virtual int getArte() const; // método abstrato
    virtual void imprimeFicha() const; // método abstrato
    // Getters and setters:
    string getCor() const;
    void setCor(string cor);
    string getClassificacao() const;
    void setClassificacao(string classificacao);
private:
    string cor;
    string classificacao;
};

#endif // PINTURA_H
