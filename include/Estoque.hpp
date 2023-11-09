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
    void lerArquivo(std::string diretorio);
    void inserirFilme(Filme* filme);
    void removerFilme(int codigo);
    std::vector<Filme*> pesquisarFilmesCodigo(int codigo);
    std::vector<Filme*> pesquisarFilmesTitulo(std::string titulo);
};

#endif
