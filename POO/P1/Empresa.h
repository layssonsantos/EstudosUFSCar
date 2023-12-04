#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <iostream>

using namespace std;

class Empresa {
    private:
        string nome;
        string CNPJ;
    public:
        Empresa(string nome, string CNPJ);
        virtual ~Empresa();
        virtual void imprime();
};


#endif //EMPRESA_H