#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>
using namespace std;

// Organizada no namespace catalogo: Classe Midia, responsável por armazenar dados sobre as mídias CD, DVD, Jogo e Catalogo:
namespace catalogo {
    class Midia { // Classe abstrata (A)
        public:
            Midia(string titulo, int anoCriacao);
            virtual ~Midia();
            virtual int getTipo() const = 0; // método abstrato
            virtual void imprimeDados() const = 0; // método abstrato
            virtual void imprimeFicha() const;
            // Getters and setters:
            string getTitulo() const;
            void setTitulo(string titulo);
            virtual int getAnoCriacao() const;
            virtual void setAnoCriacao(int anoCriacao);
            static bool comparaAnoTitulo(const Midia* m1, const Midia* m2);
        private:
            string titulo; // título de cada mídia
            int anoCriacao; // Ano de criação da mídia
    };
}


#endif // MIDIA_H