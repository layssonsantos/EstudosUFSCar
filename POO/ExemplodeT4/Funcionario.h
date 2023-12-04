#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

enum TIPO { ENFERMEIRO, MEDICO };

class Funcionario {
public:
    Funcionario(int CPF, string nome, double salario);
    virtual ~Funcionario();
    int getCPF() const;
    string getNome() const;
    double getSalario() const;
    void setSalario(double salario);
    virtual int getProfissao() const = 0; // método abstrato
    virtual void imprime() const;

    static bool comparaNome(Funcionario* f1, Funcionario* f2);
private:
    int CPF;
    string nome;
    double salario;
};

#endif /* PESSOA_H */