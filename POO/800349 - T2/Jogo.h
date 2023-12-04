#ifndef JOGO_H
#define JOGO_H

#include "Midia.h"

// Organizada no namespace catalogo: Classe Jogo, subclasse de Midia, representa um jogo eletrônico:
namespace catalogo {
    class Jogo : public Midia{
        public:
            Jogo(string titulo, int anoCriacao, string genero);
            virtual ~Jogo();
            virtual int getTipo() const;
            virtual void imprimeDados() const;
            // Getters and setters:
            virtual string getGenero() const;
            virtual void setGenero(string genero);
        private:
            string genero; // gênero do jogo
    };
}


#endif // JOGO_H