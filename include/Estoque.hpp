#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Filme.hpp"
#include <string.h>

class Estoque
{
private:
    std::vector<Filme*> estoque;
    std::string diretorio;
public:
    void lerArquivo(std::string diretorio);
    void inserirFilme(Filme* filme);
    void removerFilme(int codigo);
    std::vector<Filme*> pesquisarFilmesCodigo(int filtro);
    std::vector<Filme*> pesquisarFilmesTitulo(std::string filtro);
};

#endif