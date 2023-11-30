#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include "Locacao.hpp"
#include <deque>
#include <iomanip>

/**
 * @file Financeiro.hpp
 * @brief Definição da classe Financeiro, responsável pelo controle financeiro da locadora.
 */

const std::string DIRETORIO_HISTORICO_FINANCEIRO = "./data/Financeiro/historico_financeiro";

/**
 * @struct Data
 * @brief Estrutura para representar a data das transações financeiras.
 */
struct Data
{
    time_t now = time(0);

    int dia = localtime(&now)->tm_mday;
    int mes = localtime(&now)->tm_mon + 1;
    int ano = localtime(&now)->tm_year + 1900;
};

/**
 * @struct Transacao
 * @brief Estrutura para representar uma transação financeira.
 */
struct Transacao
{
    Data data;
    char tipo; // SAQUE OU DEPOSITO
    float valor;
    float saldo_final; // saldo final após a transação

    /**
     * @brief Construtor da estrutura Transacao.
     * @param _data Data da transação.
     * @param _tipo Tipo de transação ('D' para depósito, 'S' para saque).
     * @param _valor Valor da transação.
     * @param _saldo_final Saldo final após a transação.
     */
    Transacao(Data, char, float, float);

    /**
     * @brief Imprime os detalhes da transação.
     */
    void imprimeTransacao();
};

/**
 * @class Financeiro
 * @brief Classe para controle financeiro da locadora.
 */
class Financeiro
{
private:
    float saldo;
    std::deque<Transacao> transacoes;

public:
    /**
     * @brief Construtor da classe Financeiro.
     */
    Financeiro();

    /**
     * @brief Destrutor da classe Financeiro.
     */
    ~Financeiro();

    /**
     * @brief Exibe o histórico de transações com opção de visualização por dia, mês ou total.
     */
    void historicoTransacoes(); // dia, mẽs, total

    /**
     * @brief Obtém o saldo atual.
     * @return O saldo atual.
     */
    float getSaldo();

    /**
     * @brief Realiza um depósito na conta.
     * @param valor O valor a ser depositado.
     * @return True se o depósito for bem-sucedido, False caso contrário.
     */
    bool deposito(float);

    /**
     * @brief Realiza um saque na conta.
     * @param valor O valor a ser sacado.
     * @return True se o saque for bem-sucedido, False caso contrário.
     */
    bool saque(float);

    /**
     * @brief Salva os dados do histórico financeiro em um arquivo.
     */
    void salvarDados();

    /**
     * @brief Cancela a última transação realizada.
     */
    void cancelarUltimaTransacao();
};

#endif