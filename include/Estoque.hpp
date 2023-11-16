#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <vector>
#include "Filme.hpp"
#include "Funcoes.hpp"
#include <sstream>


class Estoque
{
private:
    std::vector<Filme*> estoque;
    std::string diretorio;

public:
    Estoque();
    ~Estoque();
    void lerArquivo(const std::string diretorio);
    bool inserirFilme(Filme* filme, bool);
    void removerFilme(const int identificador);
    void pesquisarFilmesCodigo(const int identificador) const;
    void pesquisarFilmesTitulo(const std::string titulo) const;
    void listarFilmesOrdenados(const bool) const;
    void salvarDados() const;
};

#endif
