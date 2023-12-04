#include "Museu.h"
#include "Escultura.h"
#include "Pintura.h"
#include <algorithm>
#include <fstream>

// Construtor capaz de setar os atributos da classe e fazer a leitura dos dados de uma Escultura ou Pintura:
Museu::Museu(string fileName) : fileName(fileName) {
    salvar();
}

// Destrutor da classe Museu:
Museu::~Museu() {}

// Escrever os dados de uma Escultura ou Pintura:
void Museu::escrever() {

    string titulo, artista, material, tecnica; // Atributos principais das artes
    string cor, classificacao; // Atributos da classe Pintura
    string tipo, epoca; double altura; // Atributos da classe Escultura
    int tam, arte; // Tamanho das strings e arte selecionada
    int anoCriacao; // Atributo Ano das artes
    Pintura *p1;
    Escultura *e1;

    ofstream saida(fileName, ios::binary);

    for (unsigned long int i = 0; i < obras.size(); i++) {

        // Escrever a arte (PINTURA ou ESCULTURA):
        arte = obras[i]->getArte();
        saida.write(reinterpret_cast<char*>(&arte), sizeof(arte));

        // Escrever o titulo:
        titulo = obras[i]->getTitulo();
        tam = titulo.size();

        // Escrever o tamanho da string (titulo):
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

        // Escrever os caracteres da string (titulo):
        saida.write(reinterpret_cast<char*>(&titulo[0]), tam);
        
        // Escrever o artista:
        artista = obras[i]->getArtista();
        tam = artista.size();

        // Escrever o tamanho da string (artista):
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

        // Escrever os caracteres da string (artista):
        saida.write(reinterpret_cast<char*>(&artista[0]), tam);

        // Escrever o material:
        material = obras[i]->getMaterial();
        tam = material.size();

        // Escrever o tamanho da string (material):
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

        // Escrever os caracteres da string (material):
        saida.write(reinterpret_cast<char*>(&material[0]), tam);

        // Escrever o ano:
        anoCriacao = obras[i]->getAnoCriacao();
        saida.write(reinterpret_cast<char*>(&anoCriacao), sizeof(anoCriacao));

        // Escrever a técnica:
        tecnica = obras[i]->getTecnica();
        tam = tecnica.size();

        // Escrever o tamanho da string (tecnica):
        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

        // Escrever os caracteres da string (tecnica):
        saida.write(reinterpret_cast<char*>(&tecnica[0]), tam);

        // Escrever as caracteristicas especificas das Obras de Arte
        // (atributos da classe Pintura e Escultura):
        switch(arte) {
            case PINTURA: {

                // Escrever a cor:
                p1 = dynamic_cast<Pintura*>(obras[i]);
                cor = p1->getCor();
                tam = cor.size();

                // Escrever o tamanho da string (cor):
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

                // Escrever os caracteres da string (cor):
                saida.write(reinterpret_cast<char*>(&cor[0]), tam);

                // Escrever a classificacao:
                classificacao = p1->getClassificacao();
                tam = classificacao.size();

                // Escrever o tamanho da string (classificacao):
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

                // Escrever os caracteres da string (classificacao):
                saida.write(reinterpret_cast<char*>(&classificacao[0]), tam);

                break;
            }
            case ESCULTURA: {

                // Escrever a altura:
                e1 = dynamic_cast<Escultura*>(obras[i]);
                altura = e1->getAltura();
                saida.write(reinterpret_cast<char*>(&altura), sizeof(altura));
                
                // Escrever o tipo da escultura:
                tipo = e1->getTipo();
                tam =  tipo.size();

                // Escrever o tamanho da string (tipo):
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

                // Escrever os caracteres da string (tipo):
                saida.write(reinterpret_cast<char*>(&tipo[0]), tam);

                // Escrever a epoca:
                epoca = e1->getEpoca();
                tam = epoca.size();

                // Escrever o tamanho da string (epoca):
                saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));

                // Escrever os caracteres da string (epoca):
                saida.write(reinterpret_cast<char*>(&epoca[0]), tam);

                break;
            }  
        }
    }

    saida.close();    
}

// Ler os dados de uma Escultura ou Pintura:
void Museu::salvar() {
    string titulo, artista, material, tecnica; // Atributos principais das artes
    string cor, classificacao; // Atributos da classe Pintura
    string tipo, epoca; double altura; // Atributos da classe Escultura
    int tam, arte; // Tamanho das strings e arte selecionada
    int anoCriacao; // Atributo Ano das artes

    ifstream entrada(fileName, ios::binary);

    if (entrada.is_open()) {

        obras.clear();

        // Ler Arte (PINTURA ou ESCULTURA):
        entrada.read(reinterpret_cast<char*>(&arte), sizeof(arte));
        
        while(entrada.good()) {

            // Ler o titulo

            // Ler o tamanho da string (titulo):
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            titulo.resize(tam);
            
            // Ler os caracteres da string (titulo):
            entrada.read(reinterpret_cast<char*>(&titulo[0]), tam);
            
            // Ler o artista
            
            // Ler o tamanho da string (artista):
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            artista.resize(tam);
            
            // Ler os caracteres da string (artista):
            entrada.read(reinterpret_cast<char*>(&artista[0]), tam);
            
            // Ler o material
            
            // Ler o tamanho da string (material):
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            material.resize(tam);

            // Ler os caracteres da string (material):
            entrada.read(reinterpret_cast<char*>(&material[0]), tam);

            // Ler o ano de criação:
            entrada.read(reinterpret_cast<char*>(&anoCriacao), sizeof(anoCriacao));

            // Ler a técnica

            // Ler o tamanho da string (tecnica):
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            tecnica.resize(tam);

            // Ler os caracteres da string (tecnica):
            entrada.read(reinterpret_cast<char*>(&tecnica[0]), tam);

            // Ler as caracteristicas especificas das Obras de Arte
            // (atributos da classe Pintura e Escultura):
            switch(arte) {
                case PINTURA: {

                    // Ler a cor
                    
                    // Ler o tamanho da string (cor):
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    cor.resize(tam);

                    // Ler os caracteres da string (cor):
                    entrada.read(reinterpret_cast<char*>(&cor[0]), tam);

                    // Ler a classificacao
            
                    // Ler o tamanho da string (classificacao):
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    classificacao.resize(tam);
                    
                    // Ler os caracteres da string (classificacao):
                    entrada.read(reinterpret_cast<char*>(&classificacao[0]), tam);

                    // Seta os atributos do objeto:
                    obras.push_back(new Pintura(titulo,  artista,  material,  anoCriacao,  tecnica, cor, classificacao));

                    break;
                }
                case ESCULTURA: {

                    // Ler a altura
                    
                    entrada.read(reinterpret_cast<char*>(&altura), sizeof(altura));
                
                    // Ler o tipo da escultura
                    
                    // Ler o tamanho da string (tipo):
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    tipo.resize(tam);

                    // Ler os caracteres da string (tipo):
                    entrada.read(reinterpret_cast<char*>(&tipo[0]), tam);

                    // Ler a epoca

                    // Ler o tamanho da string (epoca):
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    epoca.resize(tam);

                    // Ler os caracteres da string (epoca):
                    entrada.read(reinterpret_cast<char*>(&epoca[0]), tam);

                    // Seta os atributos do objeto:
                    obras.push_back(new Escultura(titulo, artista, material, anoCriacao, tecnica, altura, tipo, epoca));

                    break;
                }  
            }
            // Ler as artes
            entrada.read(reinterpret_cast<char*>(&arte), sizeof(arte));
        }
    }
    entrada.close();    
}

// Adicionar uma Escultura ou Pintura pelo parametro passado: (arte)
bool Museu::adiciona(int arte) {

    string titulo, artista, material;
    string tecnica, cor, classificacao;
    string tipo, epoca; double altura; 
    int anoCriacao;
    ObraDeArte *obra;

    cin.ignore();
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Artista: ";
    getline(cin, artista);
    cout << "Material: ";
    getline(cin, material);
    cout << "Ano: ";
    cin >> anoCriacao;
    cin.ignore();
    cout << "Tecnica: ";
    getline(cin, tecnica);

    // Atributos especificos de cada arte
    switch(arte) { 
        case PINTURA: {
            cout << "Cor: ";
            getline(cin, cor);
            cout << "Classificacao: ";
            getline(cin, classificacao);
            obra = new Pintura(titulo,  artista,  material,  anoCriacao, tecnica, cor, classificacao);
            break;
        }
        case ESCULTURA: {
            cout << "Altura: ";
            cin >> altura;
            cout << "Tipo: ";
            cin.ignore();
            getline(cin, tipo);
            cout << "Epoca: ";
            getline(cin, epoca);
            obra = new Escultura(titulo, artista, material, anoCriacao, tecnica, altura, tipo, epoca);
            break;
        }
    }

    obras.push_back(obra);
    escrever();
    return true;
}

// Atualiza o atributo material da Escultura ou Pintura pelo titulo:
bool Museu::atualizaMaterial(string titulo) {

    string material;
    bool ok = false;
    int pos = encontrarObra(titulo);

    if (pos != -1) {
        cout << "Material: ";
        cin.ignore();
        getline(cin, material);
        obras[pos]->setMaterial(material);
        escrever();
        ok = true;
    }

    return ok;
}

bool Museu::atualizaTecnica(string titulo) {
    
    string tecnica;
    bool ok = false;
    int pos = encontrarObra(titulo);

    if (pos != -1) {
        cout << "Tecnica: ";
        cin.ignore();
        getline(cin, tecnica);
        obras[pos]->setTecnica(tecnica);
        escrever();
        ok = true;
    } else return -1;

    return ok;
}

// Remove uma Escultura ou Pintura pelo titulo:
bool Museu::remove(string titulo) {
    bool ok = false;
    int pos = encontrarObra(titulo);

    if (pos != -1) {
        obras.erase(obras.begin() + pos);
        escrever();
        ok = true;
    }

    return ok;
}

// Remove todas as obras do Museu
// Caso esteja vazia, retorne falso:
bool Museu::removeTodos() {

    if (obras.empty()) {
        return false;
    }

    obras.clear();
    escrever();

    return true;
}

// Função capaz de encontrar uma obra pelo titulo:
int Museu::encontrarObra(string titulo) {
    unsigned long int tam = obras.size();
    unsigned long int pos = 0;

    while (pos < tam && obras[pos]->getTitulo() != titulo) {
        pos++;
    }

    if (pos < tam) 
        return pos;
    else 
        return -1;    
}

// Imprime uma Escultura ou Pintura pelo titulo:
void Museu::imprime(string titulo) {
    int pos = encontrarObra(titulo);

    if (pos != -1) 
        obras[pos]->imprimeFicha();
    else
        cout << "Titulo nao encontrado";
}

// Imprimir ordenado uma Obra ou imprimir todas as obras:
void Museu::imprime(bool sorted) {
    vector<ObraDeArte*> copia = obras;
    if (sorted) {
        sort(copia.begin(), copia.end(), ObraDeArte::comparaAno);
    }
    for (unsigned long int i = 0; i < copia.size(); i++) {
        copia[i]->imprimeFicha();
        cout << endl;
    }
}

// Definir qual metodo ser chamado pela letra digitada:
char Museu::opcao() {
    char c;
    cout << "[I] Imprimir todas as Artes" << endl;
    cout << "[T] Imprimir por Titulo" << endl;
    cout << "[O] Imprimir ordenado (Titulo + Ano)" << endl;
    cout << "[E] Adicionar Escultura" << endl;
    cout << "[P] Adicionar Pintura" << endl;
    cout << "[M] Atualizar Material (pelo Titulo)" << endl;
    cout << "[B] Atualizar Tecnica (pelo Titulo)" << endl;
    cout << "[R] Remover (pelo Titulo)" << endl;
    cout << "[L] Remover todas as obras!" << endl;
    cout << "[F] Fim" << endl;
    cout << "> ";
    cin >> c;
    return (toupper(c));
}