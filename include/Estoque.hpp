#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "Filme.hpp"
#include "Funcoes.hpp"
#include <functional>

const std::string DIRETORIO_PADRAO_FILMES = "./data/Filmes/filmes";
const std::string DIRETORIO_LOG_FILMES = "./data/Filmes/logs";

const std::map<std::string, std::function<bool(const Filme *, const Filme *)>> COMPARADORES_FILME = {
    {"C", [](const Filme *a, const Filme *b)
     { return a->getIdentificador() < b->getIdentificador(); }},
    {"N", [](const Filme *a, const Filme *b)
     { return a->getTitulo() < b->getTitulo(); }},
    {"U", [](const Filme *a, const Filme *b)
     { return a->getUnidades() < b->getUnidades(); }}};

class Estoque
{
private:
    std::vector<Filme *> _estoque;
    std::string _diretorio;

public:
    Estoque();
    ~Estoque();
    void lerArquivo(const std::string diretorio);
    bool inserirFilme(Filme *novoFilme);
    void removerFilme(const int identificador);
    void pesquisarFilmesCodigo(const int identificador) const;
    void pesquisarFilmesTitulo(const std::string titulo) const;
    void listarFilmesOrdenados(const std::string ordenacao) const;
    Filme *filmeExiste(const int identificador) const;
    Filme *filmeValido(const int identificador) const;
    void salvarDados(const bool limparDados);
};

#endif
