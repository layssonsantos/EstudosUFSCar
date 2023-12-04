#ifndef PESSOA_H
#define PESSOA_H

#include <string>

using namespace std;

class Pessoa {
    private:
        string nome;
        int CPF;
    public:
        Pessoa(string nome, int CPF);
        virtual ~Pessoa();
        string getNome();
        int getCPF();
        string getClasse();
        virtual void imprime();
};



#endif // PESSOA_H