#ifndef FILME_H
#define FILME_H

#include <string>
#include <iostream>
#include <map>

// Declaracao de constantes globais para facilitar a legibilidade do codigo;

const int LANCAMENTO = 0;
const int ESTOQUE = 1;
const int PROMOCAO = 2;

const int TIPO_DVD = 0;
const int TIPO_FITA = 1;

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
        int tipo;

    public:
        Filme(int, int, std::string);

        int getIdentificador();
        int getUnidades();
        std::string getTitulo();
        int getTipo();

        virtual int calculoPrecoLocacao(int); // Cálculo do valor de locação, se comporta de maneira diferente para DVD ou FITA
        virtual void imprimir(); // Método para imprimir dados do DVD ou FITA, se comporta de maneira diferente em cada um
        virtual bool validarDados();
};


// Subclasse DVD que herda todos os atributos básicos da Classe Filme

class DVD : public Filme {
    private:
        int categoria; // 0 - Lancamento, 1 - Estoque, 2 - Promocao;
        
    public:
        DVD(int, int, std::string, int); // Construtor
        int getCategoria();

        int calculoPrecoLocacao(int) override;
        void imprimir() override;
        bool validarDados() override;
};

// Subclasse FITA que herda todos os atributos básicos da Classe Filme

class FITA: public Filme {
    private:
        bool estaRebobinado;

    public:
        FITA(int, int, std::string, bool); // Construtor

        bool isRebobinado(); // Retorna no caso de FITA se a fita está ou não rebobinada
        int calculoPrecoLocacao(int) override;
        void imprimir() override;
};

#endif