    #ifndef DVD_H
#define DVD_H

#include <vector>
#include "Midia.h"

// Organizada no namespace catalogo: Classe DVD, subclasse de Midia, representa um filme em DVD:
namespace catalogo {
    class DVD : public Midia{
        public:
            DVD(string titulo, int anoCriacao, string diretor);
            virtual ~DVD();
            virtual int getTipo() const;
            virtual void imprimeDados() const;
            virtual void adicionaArtista(string artista, string papel);
            // Getters and setters:
            virtual string getDiretor() const;
            virtual void setDiretor(string diretor);
        private:
            string diretor; // diretor do filme
            vector<string> artista; // lista dos principais artistas
            vector<string> papel; // lista do papel desempenhadon no filme
    };
}


#endif // DVD_H