#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>

// Declaracao de constantes globais para facilitar a legibilidade do codigo;

const int LANCAMENTO = 0;
const int ESTOQUE = 1;
const int PROMOCAO = 2;

const int TIPO_DVD = 0;
const int TIPO_FITA = 1;

// Maps para serem usados na leitura de filmes, no programa principal;

const std::map<int ,std::string> Categorias = {
    {LANCAMENTO, "Lançamento"},
    {ESTOQUE, "Estoque"},
    {PROMOCAO, "Promoção"}
};

const std::map<int ,char> Tipo_Filme = {
    {TIPO_DVD, 'D'},
    {TIPO_FITA, 'F'}
};



class Filme {
    protected:
        int identificador;
        int unidades;
        std::string titulo;
        int tipo;

    public:
        Filme(int, int, std::string, int);
        virtual ~Filme();

        const int getIdentificador() const;
        const int getUnidades() const;
        const std::string getTitulo() const;
        const int getTipo() const;

        void adicionarUnidades();
        void removerUnidades();

        // Cálculo do valor de locação, se comporta de maneira diferente para DVD ou FITA
        virtual int calculoPrecoLocacao(int) = 0; 
        virtual std::string listarInformacoes(); // Método para listar as informacoes do DVD ou FITA, se comporta de maneira diferente em cada um
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
        std::string listarInformacoes() override;
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
        std::string listarInformacoes() override;
};

#endif