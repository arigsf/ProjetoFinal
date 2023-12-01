#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"
#include "Estoque.hpp"
#include <ctime>
#include <numeric> // Transformar vetor de strings em uma string
#include <sstream> // Leitura de arquivo
#include <stdexcept>

/**
 * @file Locacao.hpp
 * @brief Definição da classe Locacao, responsável por gerenciar as locações entre filmes e clientes.
 */

const int QTD_MAXIMO_FILMES_ALUGADOS = 10;

const std::string DIRETORIO_HISTORICO_LOCACOES = "./data/Locacoes/historico_Locacoes";
const std::string DIRETORIO_LOCACOES_PENDENTES = "./data/Locacoes/locacoes_Pendentes";

struct LocacaoData
{ // Para o controle das locações
    std::string _CPFCliente;
    Filme *_filme;
    int _diasAlugados;
    // Implementação dia inicial do aluguel
};

struct LocacaoLogData
{ // Para o histórico de locações
    std::string _nomeFilme;
    std::string _CPFCliente;

    int _identificadorFilme;
    int _diasAlugados;
    int _multaPaga;
};

/**
 * @class Locacao
 * @brief Classe para gerenciar as locações.
 */
class Locacao
{
private:
    static int _numeroLocacoes;
    Estoque *_estoque;
    std::vector<LocacaoData> _locacoes;

    /**
     * @brief Remove uma locação após a devolução.
     * @param posNoVetorLocacoes A posição no vetor de locações a ser removida.
     */
    void removeLocacao(int posNoVetorLocacao);

    /**
     * @brief Encontra a posição da locação no vetor de locações.
     * @param locacao A locação a ser encontrada.
     * @return A posição da locação no vetor de locações, ou -1 se não encontrada.
     */
    int getPosicaoLocacaoVetorLocacoes(LocacaoData *locacao);

    /**
     * @brief Encontra uma locação com base no CPF do cliente e no filme alugado.
     * @param CPF O CPF do cliente.
     * @param filme O filme alugado.
     * @return A locação encontrada.
     */
    LocacaoData* getLocacao(std::string cpf, Filme *filme);

    /**
     * @brief Salva as locações pendentes em um arquivo.
     */
    void salvarLocacaoPendentes();

    /**
     * @brief Salva as informações de uma locação no histórico de locações.
     * @param filme O filme alugado.
     * @param cpf O CPF do cliente.
     * @param dias O número de dias de locação.
     * @param valorMultas O valor total das multas pagas.
     */
    void salvarLocacaoLog(Filme *filme, std::string cpf, int dias, int multaPaga);

    /**
     * @brief Lê as locações pendentes de um arquivo.
     * @return Um vetor de LocacaoData com as locações pendentes.
     */
    std::vector<LocacaoData> leituraLocacoesPendentes();

    /**
     * @brief Lê o histórico de locações de um arquivo.
     * @return Um vetor de LocacaoLogData com o histórico de locações.
     */
    std::vector<LocacaoLogData> leituraLocacaoLog();

public:
    /**
     * @brief Construtor da classe Locacao.
     */
    Locacao();

    /**
     * @brief Associa um ponteiro para o Estoque à classe Locacao.
     * @param estoque Ponteiro para o Estoque.
     */
    void associarPtrEstoque(Estoque *estoque);

    /**
     * @brief Obtém o número de locações pendentes para um cliente.
     * @param CPF O CPF do cliente.
     * @return O número de locações pendentes para o cliente.
     */
    int getLocacoesPorCliente(std::string cpf);

    /**
     * @brief Realiza a devolução de um filme e calcula o valor a ser pago (multas).
     * @param CPF O CPF do cliente.
     * @param filme O filme a ser devolvido.
     * @param dias O número de dias que o filme foi alugado.
     * @param isDanificado Indica se o filme foi devolvido danificado.
     * @return O valor a ser pago (multas).
     */
    int devolucao(std::string cpf, Filme *filme, int dias, bool isDanificado);

    /**
     * @brief Verifica se um filme está alugado.
     * @param identificador O identificador do filme.
     * @return True se o filme está alugado, False caso contrário.
     */
    bool verificarFilmeAlugado(int identificador);

    /**
     * @brief Realiza o aluguel de filmes para um cliente.
     * @param CPF O CPF do cliente.
     * @param filmes Um vetor de ponteiros para os filmes a serem alugados.
     * @param dias O número de dias de locação.
     */
    float alugar(std::string cpf, std::vector<Filme *> filmes, int dias);

    /**
     * @brief Imprime um relatório das locações pendentes.
     */
    void relatorio();

    /**
     * @brief Imprime um histórico de todas as locações realizadas.
     */
    void historicoLocacoes();
};

#endif