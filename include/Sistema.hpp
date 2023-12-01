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
     * @details O usuário deve digitar se deseja abrir o arquivo de filmes ou de clientes [F | C].
     * Em seguida, deve inserir o diretório do arquivo.
     */
    void lerArquivo();

    /**
     * @brief Cadastra um novo filme no estoque.
     * @details O usuário deve digitar primeiramente o tipo do filme [D | F]. Em seguida, deve inserir,
     * respectivamente, a quantidade, o identificador e o título. Se o tipo for D, também deve ser inserido
     * a categoria [E | L | P].
     */
    void cadastrarFilme();

    /**
     * @brief Remove um filme do estoque com base no identificador.
     * @details O usuário deve digitar o identificador do filme que deseja remover.
     */
    void removerFilme();

    /**
     * @brief Lista os filmes ordenados por critérios específicos.
     * @details O usuário deve digitar o tipo de ordenação que deseja [C | U | N].
     */
    void listarFilmesOrdenados() const;

    /**
     * @brief Cadastra um novo cliente no sistema.
     * @details O usuário deve digitar os dados do cliente, respectivamente, o CPF, o nome e a data de nascimento.
     */
    void cadastrarCliente();

    /**
     * @brief Lista os clientes ordenados por critérios específicos.
     */
    void listarClientesOrdenados() const;

    /**
     * @brief Remove um cliente do sistema com base no CPF.
     * @details O usuário deve digitar o CPF do cliente que deseja remover.
     */
    void removerCliente();

    /**
     * @brief Realiza a locação de filmes para um cliente.
     * @details O usuário deve digitar, respectivamente, o CPF do cliente, os ids dos filmes e o número de dias do aluguel.
     */
    void alugarFilmes();

    /**
     * @brief Realiza a devolução de filmes por um cliente.
     * @details O usuário deve digitar, respectivamente, o CPF do cliente, o número de dias decorridos desde o aluguel e os ids dos filmes.
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