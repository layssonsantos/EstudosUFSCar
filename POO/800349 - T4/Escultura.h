#ifndef ESCULTURA_H
#define ESCULTURA_H

#include "ObraDeArte.h"

class Escultura : public ObraDeArte
{
public:
    Escultura(string titulo, string artista, string material, int anoCriacao, string tecnica, double altura, string tipo, string epoca);
    virtual ~Escultura();
    virtual int getArte() const; // método abstrato
    virtual void imprimeFicha() const; // método abstrato
    // Getters and setters:
    double getAltura() const;
    void setAltura(double altura);
    string getTipo() const;
    void setTipo(string tipo);
    string getEpoca() const;
    void setEpoca(string epoca);
private:
    double altura;
    string tipo;
    string epoca;
};

#endif // ESCULTURA_H