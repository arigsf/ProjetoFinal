#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "./Filme.hpp"
#include <string.h>

class Estoque
{
private:
    std::vector<Filme> estoque;
public:
    void lerArquivo();
    std::string inserirFilme(Filme filme);
    std::string removerFilme(int codigo);
    std::vector<Filme> pesquisarFilmes(std::string filtro);
    void imprimirRelatiorio();
};

Estoque::Estoque(/* args */)
{
}

Estoque::~Estoque()
{
}


#endif