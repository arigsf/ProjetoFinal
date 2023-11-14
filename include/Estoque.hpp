#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <vector>
#include "Filme.hpp"
#include "Funcoes.hpp"

class Estoque
{
private:
    std::vector<Filme*> estoque;
    std::string diretorio;

public:
    Estoque();
    ~Estoque();
    void lerArquivo(const std::string diretorio);
    void inserirFilme(Filme* filme);
    void removerFilme(const int identificador);
    void pesquisarFilmesCodigo(const int identificador) const;
    void pesquisarFilmesTitulo(const std::string titulo) const;
    void salvarDados() const;
};

#endif
