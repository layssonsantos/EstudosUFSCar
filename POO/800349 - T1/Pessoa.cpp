#include "Pessoa.h"

// Construtor responsável pela criação do objeto Pessoa, setando os seus atributos
Pessoa::Pessoa(string CPF, string Nome) : CPF(CPF), Nome(Nome) {
}

// Método responsável por retornar o CPF da Pessoa
string Pessoa::getCPF() const {
    return CPF;
}

// Método responsável por setar o atributo CPF do objeto Pessoa
void Pessoa::setCPF(string CPF) {
    this->CPF = CPF;
}

// Método responsável por retornar o nome da pessoa
string Pessoa::getNome() const {
    return Nome;
}

// Método responsável por setar o atributo Nome do objeto Pessoa
void Pessoa::setNome(string Nome) {
    this->Nome = Nome;
}

// Método responsável pela impressão das informações (CPF e nome) de uma pessoa
void Pessoa::imprime() const {
    cout << "CPF: " << getCPF() << endl;
    cout << "Nome: " << getNome() << endl;
}