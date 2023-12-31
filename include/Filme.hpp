#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

/**
 * @file Filme.hpp
 * @brief Definição da classe Filme e suas subclasses DVD e FITA.
 */

// Declaracao de constantes globais para facilitar a legibilidade do codigo;

const int LANCAMENTO = 0;
const int ESTOQUE = 1;
const int PROMOCAO = 2;

const int TIPO_DVD = 0;
const int TIPO_FITA = 1;

// Maps para serem usados na leitura de filmes, no programa principal;

const std::map<int, char> Categorias = {
    {LANCAMENTO, 'L'},
    {ESTOQUE, 'E'},
    {PROMOCAO, 'P'}};

// Usado na hora de salvar os dados;
const std::map<char, std::string> aux_Categorias = {
    {LANCAMENTO, "Lancamento"},
    {ESTOQUE, "Estoque"},
    {PROMOCAO, "Promocao"}};

const std::map<int, char> Tipo_Filme = {
    {TIPO_DVD, 'D'},
    {TIPO_FITA, 'F'}};

/**
 * @class Filme
 * @brief Classe pai para representar um filme.
 */
class Filme
{
protected:
    int _unidades;
    int _identificador;
    std::string _titulo;
    int _tipo;

public:
    /**
     * @brief Construtor da classe Filme.
     * @param unidades O número de unidades disponíveis do filme.
     * @param identificador O identificador único do filme.
     * @param titulo O título do filme.
     * @param tipo O tipo do filme (DVD ou FITA).
     */
    Filme(int unidades, int identificador, std::string titulo, int tipo);

    /**
     * @brief Destrutor da classe Filme.
     */
    virtual ~Filme();

    /**
     * @brief Obtém o identificador do filme.
     * @return O identificador do filme.
     */
    const int getIdentificador() const;

    /**
     * @brief Obtém o número de unidades disponíveis do filme.
     * @return O número de unidades disponíveis.
     */
    const int getUnidades() const;

    /**
     * @brief Obtém o título do filme.
     * @return O título do filme.
     */
    const std::string getTitulo() const;

    /**
     * @brief Obtém o tipo do filme (DVD ou FITA).
     * @return O tipo do filme.
     */
    const int getTipo() const;

    /**
     * @brief Adiciona uma unidade do filme.
     */
    void adicionarUnidades();

    /**
     * @brief Remove uma unidade do filme.
     */
    void removerUnidades();

    /**
     * @brief Calcula o valor de locação do filme.
     * @param dias O número de dias para locação.
     * @return O valor de locação calculado.
     */
    virtual float calculoPrecoLocacao(int dias) = 0;

    /**
     * @brief Lista as informações do filme.
     * @return Uma string contendo as informações do filme.
     */
    virtual std::string listarInformacoes();

    /**
     * @brief Valida os dados do filme.
     * @return true se os dados são válidos, false caso contrário.
     */
    virtual bool validarDados();
};

/**
 * @class DVD
 * @brief Subclasse de Filme que representa um DVD.
 */
class DVD : public Filme
{
private:
    int _categoria; // 0 - Lancamento, 1 - Estoque, 2 - Promocao;

public:
    /**
     * @brief Construtor da subclasse DVD.
     * @param unidades O número de unidades disponíveis do DVD.
     * @param identificador O identificador único do DVD.
     * @param titulo O título do DVD.
     * @param categoria A categoria do DVD.
     */
    DVD(int unidades, int identificador, std::string titulo, int categoria); // Construtor

    /**
     * @brief Obtém a categoria do DVD.
     * @return A categoria do DVD.
     */
    int getCategoria();

    float calculoPrecoLocacao(int dias) override;
    std::string listarInformacoes() override;
    bool validarDados() override;
};

/**
 * @class FITA
 * @brief Subclasse de Filme que representa uma FITA.
 */
class FITA : public Filme
{
private:
    bool _estaRebobinado;

public:
    /**
     * @brief Construtor da subclasse Fita.
     * @param unidades O número de unidades disponíveis da Fita.
     * @param identificador O identificador único da Fita.
     * @param titulo O título da Fita.
     */
    FITA(int unidades, int identificador, std::string titulo, bool estaRebobinado);

    /**
     * @brief Verifica se a fita está rebobinada.
     * @return true se a fita está rebobinada, false caso contrário.
     */
    bool isRebobinado();

    float calculoPrecoLocacao(int dias) override;
    std::string listarInformacoes() override;
};

#endif