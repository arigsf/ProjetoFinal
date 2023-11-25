#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "Filme.hpp"
#include "Funcoes.hpp"
#include <functional>

/**
 * @file Estoque.hpp
 * @brief Definição da classe Estoque, responsável por gerenciar o estoque de filmes.
 */

const std::map<std::string, std::function<bool(const Filme *, const Filme *)>> COMPARADORES_FILME = {
    {"C", [](const Filme *a, const Filme *b)
     { return a->getIdentificador() < b->getIdentificador(); }},
    {"N", [](const Filme *a, const Filme *b)
     { return a->getTitulo() < b->getTitulo(); }},
    {"U", [](const Filme *a, const Filme *b)
     { return a->getUnidades() < b->getUnidades(); }}};

/**
 * @class Estoque
 * @brief Classe para gerenciar o estoque de filmes.
 */
class Estoque
{
private:
    std::vector<Filme *> estoque;
    std::string diretorio;

public:
    Estoque();
    ~Estoque();

    /**
     * @brief Lê os filmes em estoque de um arquivo.
     * @param diretorio O caminho do arquivo a ser lido.
     */
    void lerArquivo(const std::string diretorio);

    /**
     * @brief Insere um novo filme no estoque.
     * @param novoFilme Ponteiro para o novo filme a ser inserido.
     * @return true se o filme foi inserido com sucesso, false caso contrário.
     */
    bool inserirFilme(Filme *novoFilme);

    /**
     * @brief Remove um filme do estoque.
     * @param identificador O identificador do filme a ser removido.
     */
    void removerFilme(const int identificador);

    /**
     * @brief Pesquisa filmes pelo identificador.
     * @param identificador O identificador a ser pesquisado.
     */
    void pesquisarFilmesCodigo(const int identificador) const;

    /**
     * @brief Pesquisa filmes pelo título.
     * @param titulo O título a ser pesquisado.
     */
    void pesquisarFilmesTitulo(const std::string titulo) const;

    /**
     * @brief Lista os filmes ordenados por critério.
     * @param ordenacao O critério de ordenação (C - Código, N - Nome, U - Unidades).
     */
    void listarFilmesOrdenados(const std::string ordenacao) const;

    /**
     * @brief Verifica se um filme com determinado identificador existe no estoque.
     * @param identificador O identificador a ser verificado.
     * @return Ponteiro para o filme se existir, nullptr caso contrário.
     */
    Filme *filmeExiste(const int identificador) const;

    /**
     * @brief Verifica se um filme com determinado identificador é válido para locação.
     * @param identificador O identificador a ser verificado.
     * @return Ponteiro para o filme se válido, nullptr caso contrário.
     */
    Filme *filmeValido(const int identificador) const;

    /**
     * @brief Salva os filmes do estoque em um arquivo.
     * @param limparDados Indica se os filmes do estoque devem ser desalocados após a escrita.
     */
    void salvarDados(const bool limparDados);
};

#endif
