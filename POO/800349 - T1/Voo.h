#ifndef VOO_H
#define VOO_H

#include <string>
#include <iostream>
using namespace std;

#include "DataHorario.h"
#include "Pessoa.h"

class Voo {
    public:
        Voo(int numero, DataHorario &data);
        int proximoLivre() const;
        bool verifica(int) const;
        bool ocupa(int, Pessoa&);
        bool desocupa(int);
        int vagas() const ;
        void imprime() const;
        // getters and setters:
        int getNumero() const;
        void setNumero(int numero);
        DataHorario getData() const;
        void setData(DataHorario& Data);
    private:
        int numero;
        DataHorario data; // Data do Voo da classe DataHorario
        Pessoa *passageiros[100] = {nullptr}; // Ponteiro para array de pessoas
        int poltronaDisp = {100}; // Poltronas disponiveis
};



#endif /* VOO_H */