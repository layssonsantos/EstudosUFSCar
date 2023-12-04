#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "Midia.h"

// Organizada no namespace catalogo: Classe catalogo, subclasse de Midia, representa um catálogo de mídias:
namespace catalogo {
    class Catalogo {
        public:
            Catalogo();
            virtual ~Catalogo();
            bool adicionaMidia(Midia& midia);
            bool removeMidia(string titulo);
            Midia* obtemMidia(string titulo);
            int quantidadeDeMidias();
            int quantidadeDeCDs();
            int quantidadeDeDVDs();
            int quantidadeDeJogos();
            
            void imprimeColecao();
            void imprimeColecaoPorTipo(int tipo);
        private:
            // Relacionamento de 1 para N com a classe abstrata Midia
            vector<Midia*> midias; // Vetor de midias
    };
}


#endif // CATALOGO_H