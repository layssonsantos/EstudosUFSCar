#include "Empresa.h"

Empresa::Empresa(string nome, string CNPJ) : nome(nome), CNPJ(CNPJ) {
}

void Empresa::imprime() {
    cout << "Nome: " << this->nome << endl;
    cout << "CNPJ: " << this->CNPJ << endl;
}