#include "Gerente.h"

Gerente::Gerente(string nome, string CPF, double salario, Empresa *e, string departamento) : Funcionario(nome, CPF, salario, e), departamento(departamento) {}

string Gerente::getClasse() {
    return "Gerente";
}

double Gerente::getSalario() {
    return salario + 1500;
}

void Gerente::imprime() {
    Funcionario::imprime();
    cout << "Departamento: " << this->departamento << endl;
}

