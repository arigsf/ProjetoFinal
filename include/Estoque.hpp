#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "Filme.hpp"
#include "Funcoes.hpp"
#include <functional>


const std::map<std::string, std::function<bool(const Filme*, const Filme*)>> COMPARADORES_FILME = {
    {"C", [](const Filme* a, const Filme* b) { return a->getIdentificador() < b->getIdentificador(); }},
    {"N", [](const Filme* a, const Filme* b) { return a->getTitulo() < b->getTitulo(); }},
    {"U", [](const Filme* a, const Filme* b) { return a->getUnidades() < b->getUnidades(); }}
};

class Estoque
{
private:
    std::vector<Filme*> estoque;
    std::string diretorio;

public:
    Estoque();
    ~Estoque();
    void lerArquivo(const std::string);
    bool inserirFilme(Filme*);
    void removerFilme(const int);
    void pesquisarFilmesCodigo(const int) const;
    void pesquisarFilmesTitulo(const std::string) const;
    void listarFilmesOrdenados(const std::string) const;
    Filme *filmeExiste(const int) const;
    Filme *filmeValido(const int) const;
    void salvarDados(const bool);
};

#endif
