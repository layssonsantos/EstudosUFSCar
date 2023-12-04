#include "Museu.h"
#include "Escultura.h"
#include "Pintura.h"
#include <iostream>
using namespace std;


int main() {

    char op;
    string titulo;

    Museu museu("museu.dat");
    cout <<"\n";
    cout << "========== Museu de Arte ==========" << endl;
    cout <<"\n";
    cout << "O que deseja?" << endl;
    cout <<"\n";
    
    // Opções de escolha para realizar as chamadas do CRUD de arquivo:
    do {
        op = Museu::opcao();
        switch (op) {
            case 'I': { 
                museu.imprime();
                break;
            }
            case 'T': {
                cout << "Titulo: ";
                cin >> titulo;
                museu.imprime(titulo);
                break;
            }
            case 'O': {
                museu.imprime(true);
                break;
            }
            case 'E': {
                museu.adiciona(ESCULTURA);
                break;
            }
            case 'P': {
                museu.adiciona(PINTURA);
                break;
            }
            case 'M': {
                cout << "Titulo: ";
                cin >> titulo;
                bool ok = museu.atualizaMaterial(titulo);
                cout << "Atualizacao " << (ok ? "feita!" : "sem sucesso =(") << endl;
                break;
            }
            case 'B': {
                cout << "Titulo: ";
                cin >> titulo;
                bool ok = museu.atualizaTecnica(titulo);
                cout << "Atualizacao " << (ok ? "feita!" : "sem sucesso =(") << endl;
                break;
            }
            case 'R': {
                cout << "Titulo: ";
                cin >> titulo;
                bool ok = museu.remove(titulo);
                cout << "Remocao " << (ok ? "feita!" : "nao feita =(") << endl;
                break;
            }
            case 'L': {
                bool ok = museu.removeTodos();
                cout << "Remocao " << (ok ? "feita!" : "nao feita =( ou nao existem obras no Museu...") << endl;
                break;
            }
        }
        cout << endl;
    } while (op != 'F');

    return 0;
}