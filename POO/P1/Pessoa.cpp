#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(string nome, int CPF) : nome(nome), CPF(CPF) {
}

string Pessoa::getNome() {
    return nome;
}

int Pessoa::getCPF() {
    return CPF;
}

string Pessoa::getClasse() {
    return "Pessoa";
}

void Pessoa::imprime() {
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << CPF << endl;
}

