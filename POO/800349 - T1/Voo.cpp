#include "Voo.h"

#include <iostream>
#include <string>
#include <iomanip>

Voo::Voo(int numero, DataHorario &data) : data(data) {
    this->numero = numero;
}

// Método responsável por retornar o número da próxima poltrona livre. 
// Retorna zero se não houver poltrona disponível no vôo.
int Voo::proximoLivre() const {
    int i;
    for (i = 1; i <= 100; i++) {
        if (!verifica(i)) {
            return i;
        }
    }
    return 0;
}

// Método responsável por verificar se o número da poltrona 
// recebido como parâmetro está ocupada.
bool Voo::verifica(int poltrona) const {
    if (passageiros[poltrona - 1] == nullptr) return false; // retorna false se a poltrona não estiver ocupada
    else return true; 
}

// Método responsável por ocupar determinada poltrona do vôo
// Verifica se a poltrona nao esta ocupada e ocupa com uma Pessoa
bool Voo::ocupa(int poltrona, Pessoa &p) {
    if (!verifica(poltrona)) {
        passageiros[poltrona - 1] = &p; // Poltrona recebe a pessoa
        poltronaDisp--; // Poltronas disponíveis é reduzida em 1
        return true;
    } else {
        return false;
    }
}

// Método responsável por desocupar determinada poltrona do vôo
bool Voo::desocupa(int poltrona) {
    if (verifica(poltrona)) { // Verifica se a poltrona está ocupada
        passageiros[poltrona - 1] = nullptr;
        poltronaDisp++; // Aumenta a quantidade de poltronas vagas
        return true;
    } else {
        return false;
    }
}

// Método responsável por retornar o número de poltronas 
// vagas disponíveis (não ocupadas) no vôo.
int Voo::vagas() const {
    return poltronaDisp;
}

// Método responsável pela impressão das informações de um vôo 
// (número, data/horário, quantidade de vagas
// e informações dos passageiros).
void Voo::imprime() const {
    cout << "Número do voo: " << numero << endl;
    cout << "Data do voo: ";
    data.imprime(false);
    cout << "Assentos livres: " << vagas() << endl;

    for (int i = 1; i <= 100; i++) {
        if (verifica(i)) {
            cout << "Assento: " << i << " ocupado por: " << endl;
            passageiros[i - 1]->Pessoa::imprime();
        }
    } 
}

/* <---GETTERS AND SETTERS---> */

int Voo::getNumero() const {
    return numero;
}

void Voo::setNumero(int numero) {
    this->numero = numero;
}

DataHorario Voo::getData() const {
    return data;
}

void Voo::setData(DataHorario &date) {
    data = date;
}