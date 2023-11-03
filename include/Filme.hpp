#ifndef FILME_H
#define FILME_H

#include <string>
#include <iostream>
#include <map>

// Declaracao de constantes globais para facilitar a legibilidade do codigo;

const int LANCAMENTO = 0;
const int ESTOQUE = 1;
const int PROMOCAO = 2;

// Map para ser usado na leitura de filmes, no programa principal;

std::map<std::string, int> Categoria = {
    {"Lancamento", LANCAMENTO},
    {"Estoque", ESTOQUE},
    {"Promocao", PROMOCAO}
};

class Filme {

protected:
    int identificador;
    int unidades;
    std::string titulo;

public:
    Filme(int, int, std::string); 
    virtual int calculaPreco(int) = 0; // Método virtual puro. Impede a instaciação de objetos da classe Filme diretamente
};


// Subclasse DVD que herda todos os atributos básicos da Classe Filme

class DVD : private Filme {
private:
    int categoria; // 0 - Lancamento, 1 - Estoque, 2 - Promocao;
    
public:
    DVD(int, int, std::string, int); // Construtor
    int calculaPreco(int) override; // Método que calcula preço do filme em função da categoria do DVD
};

// Subclasse FITA que herda todos os atributos básicos da Classe Filme

class FITA: private Filme {
private:
    bool estaRebobinado;

public:
    FITA(int, int, std::string, bool); // Construtor
    int calculaPreco(int) override; // Método que calcula o preço do filme levando em conta se a fita está ou não rebobinada
};

#endif