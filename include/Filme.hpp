#ifndef FILME_H
#define FILME_H

#include <string>
#include <iostream>

class Filme {

protected:
    int identificador;
    int unidades;
    std::string titulo;

public:
    Filme(int, int, std::string); 
};

// Subclasse DVD que herda todos os atributos básicos da Classe Filme

class DVD : private Filme {
private:
    int categoria; // 0 - Lançamento, 1 - Estoque, 2 - Promoção
    
public:
    DVD(int, int, std::string, int); // Construtor
    int calculaPreco(int); // Método que calcula preço do filme em função da categoria do DVD
};

// Subclasse FITA que herda todos os atributos básicos da Classe Filme

class FITA: private Filme {
private:
    bool estaRebobinado;

public:
    FITA(int, int, std::string, bool); // Construtor
    int calculaPreco(int); // Método que calcula o preço do filme levando em conta se a fita está ou não rebobinada
};

#endif