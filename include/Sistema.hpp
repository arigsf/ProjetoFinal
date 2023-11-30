#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estoque.hpp"
#include "Locacao.hpp"
#include "Cadastro_Clientes.hpp"
#include "Funcoes.hpp"
#include "Financeiro.hpp"
#include <iterator>
#include <unistd.h>

/**
 * @file Sistema.hpp
 * @brief Definição da classe Sistema, responsável por gerenciar todo o CineAluguel.
 */

const char ARQUIVO_FILMES = 'F';
const char ARQUIVO_CLIENTES = 'C';

/**
 * @brief Classe que representa o sistema de locação de filmes.
 */
class Sistema
{

private:
    Estoque _estoque;
    Locacao _locacao;
    CadastroClientes _clientes;
    Financeiro _financeiro;

public:
    /**
     * @brief Construtor da classe Sistema.
     */
    Sistema();

    /**
     * @brief Lê informações de um arquivo e atualiza o estoque.
     * @param diretorio O caminho do arquivo a ser lido.
     */
    void lerArquivo();

    /**
     * @brief Cadastra um novo filme no estoque.
     * @param novo_filme Ponteiro para o novo filme a ser cadastrado.
     */
    void cadastrarFilme();

    /**
     * @brief Remove um filme do estoque com base no identificador.
     * @param identificador O identificador único do filme a ser removido.
     */
    void removerFilme();

    /**
     * @brief Lista os filmes ordenados por critérios específicos.
     * @param ordenacao O critério de ordenação dos filmes.
     */
    void listarFilmesOrdenados() const;

    /**
     * @brief Cadastra um novo cliente no sistema.
     * @param cliente Ponteiro para o novo cliente a ser cadastrado.
     */
    void cadastrarCliente();

    /**
     * @brief Lista os clientes ordenados por critérios específicos.
     * @param ordenacao O critério de ordenação dos clientes.
     */
    void listarClientesOrdenados() const;

    /**
     * @brief Remove um cliente do sistema com base no CPF.
     * @param cpf O CPF único do cliente a ser removido.
     */
    void removerCliente();

    /**
     * @brief Realiza a locação de filmes para um cliente.
     * @param cpf O CPF do cliente.
     * @param ids Vetor de identificadores dos filmes a serem locados.
     * @param dias O número de dias para a locação.
     */
    void alugarFilmes();

    /**
     * @brief Realiza a devolução de filmes por um cliente.
     * @param cpf O CPF do cliente.
     * @param ids Vetor de identificadores dos filmes a serem devolvidos.
     * @param dias O número de dias de locação.
     */
    void devolverFilmes();

    /**
     * @brief Lista o histórico de locações.
     */
    void listarLogLocacoes();

    /**
     * @brief Lista as locações atuais.
     */
    void listarLocacoes();

    /**
     * @brief Limpa o terminal.
     */
    void limparTerminal();

    /**
     * @brief Mostra o histórico de transações financeiras.
     */
    void mostrarTransacoes();

    /**
     * @brief Cancela a última transação financeira.
     */
    void cancelarTransacao();

    /**
     * @brief Mostra as opções disponíveis no sistema.
     */
    void mostrarOpcoes();
};

#endif