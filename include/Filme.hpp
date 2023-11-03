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
        int getIdentificador();
        virtual void imprimir(); // Método para imprimir dados do DVD ou FITA, se comporta de maneira diferente em cada um
};


// Subclasse DVD que herda todos os atributos básicos da Classe Filme

class DVD : private Filme {
    private:
        int categoria; // 0 - Lancamento, 1 - Estoque, 2 - Promocao;
        
    public:
        DVD(int, int, std::string, int); // Construtor
        void imprimir() override;
};

// Subclasse FITA que herda todos os atributos básicos da Classe Filme

class FITA: private Filme {
    private:
        bool estaRebobinado;

    public:
        FITA(int, int, std::string, bool); // Construtor
        bool isRebobinado();
        void imprimir() override;
};

#endif