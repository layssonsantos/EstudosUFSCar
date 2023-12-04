#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
using namespace std;

// Classe Pessoa que represeta pessoas
class Pessoa {
    public:
        Pessoa(string CPF, string Nome); 
        virtual void imprime() const;
        // getters and setters:
        string getCPF() const;
        string getNome() const;
        void setCPF(string Nome);
        void setNome(string CPF);
    private:
        string CPF; 
        string Nome;
};

#endif /* PESSOA_H */