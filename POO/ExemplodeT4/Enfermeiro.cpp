#include "Enfermeiro.h"

Enfermeiro::Enfermeiro(int CPF, string nome, double salario, int CRE) :
Funcionario(CPF, nome, salario), CRE(CRE) {
}

Enfermeiro::~Enfermeiro() {
}

int Enfermeiro::getProfissao() const {
    return ENFERMEIRO;
}

int Enfermeiro::getCRE() const {
    return CRE;
}

void Enfermeiro::imprime() const {
    Funcionario::imprime();
    cout << "CRE : " << CRE << endl;
}

