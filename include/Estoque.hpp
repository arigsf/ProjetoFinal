#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <vector>
#include "Filme.hpp"

class Estoque
{
private:
    std::vector<Filme*> estoque;
    std::string diretorio;

public:
    Estoque();
    ~Estoque();
    void inserirFilme(Filme* filme);
    void removerFilme(int codigo);
    void pesquisarFilmesCodigo(int codigo);
    void pesquisarFilmesTitulo(std::string titulo);
};

#endif
