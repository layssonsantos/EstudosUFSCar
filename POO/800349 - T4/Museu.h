#ifndef MUSEU_H
#define MUSEU_H

#include "ObraDeArte.h"
#include <vector>
using namespace std;

// Implementação do CRUD:

class Museu
{
public:
    Museu(string fileName);
    virtual ~Museu();
    bool adiciona(int arte);
    virtual void imprime(bool sorted = false);
    virtual void imprime(string titulo);
    bool remove(string titulo);
    bool removeTodos();
    bool atualizaMaterial(string titulo);
    bool atualizaTecnica(string titulo);
    static char opcao();
private:
    void escrever();
    void salvar();
    int encontrarObra(string titulo);
    // Arquivo e vetor de Artes:
    string fileName;
    vector<ObraDeArte *> obras;
};

#endif // MUSEU_H