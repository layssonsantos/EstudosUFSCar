#include "Aluno.h"

// Construtor capaz de setar os atributos do objeto
Aluno::Aluno(string CPF, string Nome, int RA, double n1, double n2, double nt) : 
Pessoa(CPF, Nome), RA(RA), n1(n1), n2(n2), nt(nt) {
}


/* <---GETTERS AND SETTERS---> */

// Método responsável por retornar o RA do aluno
int Aluno::getRA() const {
    return RA;
}
// Método responsável por setar o atributo RA do objeto aluno
void Aluno::setRA(int RA) {
    this->RA = RA;
}
// Método responsável por retornar a n1 (1° nota) do aluno
double Aluno::getN1() const {
    return n1;
}
// Método responsável por setar o atributo n1 do objeto aluno
void Aluno::setN1(double n1) {
    this->n1 = n1;
}
// Método responsável por retornar a n2 (2° nota) do aluno
double Aluno::getN2() const {
    return n2;
}
// Método responsável por setar o atributo n2 do objeto aluno
void Aluno::setN2(double n2) {
    this->n2 = n2;
}
// Método responsável por retornar o nt (nota do trabalho) do aluno
double Aluno::getNT()const {
    return nt;
}
// Método responsável por setar o atributo nt do objeto aluno
void Aluno::setNT(double nt) {
    this->nt = nt;
}

/* <--- Métodos ---> */

// Método responsável por calcular a média final (MF)
// do aluno – cada prova tem peso 7 e o
// trabalho tem peso 6
// retornando a sua media.
double Aluno::media() const { 
    return (n1 * 7 + n2 * 7 + nt * 6) / 20; 
}

// Método responsável por retornar verdadeiro se o aluno foi aprovado 
// (MF ≥ 6.0) e falso, caso contrário.
bool Aluno::aprovado() const {
    if (media() >= 6.0) {
        return true;
    } else {
        return false;
    }
}

// Método responsável por retornar verdadeiro se o aluno ficou em SAC – 
// Sistema de Avaliação Complementar
// (5.0 ≤ MF < 6.0) e falso, caso contrário.
bool Aluno::sac() const {
    double rec = media();
    if (rec >= 5.0 && rec < 6.0) {
        return true;
    } else {
        return false;
    }
}

// Método responsável por calcular qual a nota mínima necessária, 
// na prova de avaliação complementar (SAC), 
// para aprovação na disciplina. Para o aluno ser aprovado após a prova 
// de avaliação complementar (SAC) precisa atender a seguinte regra:
// SAC + MF / 2 ≥ 6.0
// Caso o aluno não ficou em SAC, retornar 0.
double Aluno::notaSAC() const {
    if (sac() == false) {
        return 0;
    } else {
        return 12 - media();
    }
}

// Método responsável pela impressão das informações 
// (CPF, nome, RA e média final) de um aluno e verificar
// se foi aprovado, nota mínima para aprovação ou reprovado
// com média x, retornando a sua situação e sua média.
void Aluno::imprime() const {
    cout << "CPF: " << getCPF() << endl;
    cout << "Nome: " << getNome() << endl;
    cout << "RA: " << getRA() << endl;
    if (media() >= 6.0) {
        cout << "Aprovado com média " << media() << endl;
    } else if(sac()){
        cout << "(SAC) Nota mínima aprovação: " << notaSAC() << endl;
    } else {
        cout << "Reprovado com média " << media() << endl;
    }
}
