#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <string>
#include <iostream>
using namespace std;

// Classe DataHorario capaz de setar um horário:
class DataHorario {
    public:
        DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo);
        ~DataHorario();
        int compara(const DataHorario&) const;
        void imprime(bool) const;
        void imprimePorExtenso() const;
        // getters and setters:
        int getDia() const;
        void setDia(int dia);
        int getMes() const;
        void setMes(int mes);
        int getAno() const;
        void setAno(int ano);
        int getHora() const;
        void setHora(int hora);
        int getMinuto() const;
        void setMinuto(int minuto);
        int getSegundo() const;
        void setSegundo(int segundo);
    private:
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
        int segundo;
};

#endif /* DATAHORARIO_H */