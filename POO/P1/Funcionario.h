#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
#include "Empresa.h"

using namespace std;

class Funcionario : public Pessoa{
    private:
        Empresa* empresa;
    protected:
        double salario;
    public:
        Funcionario(string nome, int CPF, double salario);
        virtual ~Funcionario();
        double getSalario();
        string getClasse();
        Empresa* getEmpresa();
        void setEmpresa(Empresa* e);
        virtual void imprime();
};


#endif // FUNCIONARIO_H