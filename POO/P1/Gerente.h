#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"

using namespace std;

class Gerente : public Funcionario {
    private:
        string departamento;
    public:
        Gerente(string nome, string CPF, double salario, Empresa* e, string departamento);
        ~Gerente();
        string getClasse();
        double getSalario();
        virtual void imprime();
};

#endif //GERENTE_H