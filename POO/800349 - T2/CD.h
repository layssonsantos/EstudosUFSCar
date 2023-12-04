#ifndef CD_H
#define CD_H

#include <vector>
using namespace std;

#include "Midia.h"

// Organizada no namespace catalogo:: Classe CD, subclasse de Midia, representa um CD de música:
namespace catalogo {
    class CD : public Midia{
        public:
            CD(string titulo, int anoCriacao, string artista);
            virtual ~CD();	
            virtual int getTipo() const;
            virtual void imprimeDados() const;
            void adicionaFaixa(string faixaNome, int faixaDuracao);
            // Getters and setters:
            virtual string getArtista() const;
            virtual void setArtista(string artista);
        private:
            string artista; // artista (compositor/intérprete da obra)
            vector<string> faixaNome; // lista de faixa de nome
            vector<int> faixaDuracao; // lista de faixa da duração em segundos
    };
}


#endif // CD_H