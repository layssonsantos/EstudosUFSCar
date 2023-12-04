#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

#include <string>
#include <iostream>
using namespace std;

// Classe Aluno, subclasse da classe Pessoa:
class Aluno : public Pessoa {
    public:
        Aluno(string CPF, string Nome, int RA, double n1, double n2, double nt);
        double media() const;  
        bool aprovado() const;
        bool sac() const;
        double notaSAC() const;
        virtual void imprime() const;
        // getters and setters:
        int getRA() const;
        void setRA(int RA);
        double getN1() const;
        void setN1(double n1);
        double getN2() const;
        void setN2(double n2);
        double getNT() const;
        void setNT(double nt);
    private:
        int RA;
        double n1;
        double n2;
        double nt;
};

#endif /* ALUNO_H */