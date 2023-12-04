#include "Funcionario.h"
#include "Empresa.h"


Funcionario::Funcionario(string nome, int CPF, double salario) :
Pessoa(nome, CPF), salario(salario) {
}

Empresa* Funcionario::getEmpresa() {
    return empresa;
}

void Funcionario::setEmpresa(Empresa *e) {
    this->empresa = e;
}

double Funcionario::getSalario() {
    return salario;
}

string Funcionario::getClasse() {
    return "Funcionario";
}

void Funcionario::imprime() {
    Pessoa::imprime();
    cout << "Salário: " << this->salario << endl;
    cout << "Empresa: " << endl;
    this->empresa->imprime();
}