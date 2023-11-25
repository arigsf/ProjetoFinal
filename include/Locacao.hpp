#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"

class Locacao
{
private:
    static int numeroLocacoes;
    std::vector<std::pair<std::string, std::pair<Filme *, int>>> locacoes; // Vector de pares com (CPF, par(filme, dias))

    /**
     * @brief Remove uma locação após a devolução.
     * @param posNoVetorLocacoes A posição no vetor de locações a ser removida.
     */
    void removeLocacao(int posNoVetorLocacoes);

    /**
     * @brief Encontra a posição da locação no vetor de locações.
     * @param locacao A locação a ser encontrada.
     * @return A posição da locação no vetor de locações, ou -1 se não encontrada.
     */
    int getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme *, int>>);

    /**
     * @brief Encontra uma locação com base no CPF do cliente e no filme alugado.
     * @param CPF O CPF do cliente.
     * @param filme O filme alugado.
     * @return A locação encontrada.
     */
    std::pair<std::string, std::pair<Filme *, int>> getLocacao(std::string cpf, Filme *filme);

public:
    /**
     * @brief Construtor da classe Locacao.
     */
    Locacao();

    /**
     * @brief Obtém o número de locações pendentes para um cliente.
     * @param CPF O CPF do cliente.
     * @return O número de locações pendentes para o cliente.
     */
    int getLocacoesPorCliente(std::string cpf);

    /**
     * @brief Realiza o aluguel de filmes para um cliente.
     * @param CPF O CPF do cliente.
     * @param filmes Um vetor de ponteiros para os filmes a serem alugados.
     * @param dias O número de dias de locação.
     */
    void alugar(std::string cpf, std::vector<Filme *> filmes, int dias);

    /**
     * @brief Verifica se um cliente pode alugar mais filmes sem ultrapassar o limite de 10 locações pendentes.
     * @param CPF O CPF do cliente.
     * @param qtdFilmes A quantidade de filmes a serem alugados.
     * @return Verdadeiro se o cliente pode alugar mais filmes, falso caso contrário.
     */
    bool verificarCPFmaxFilmes(std::string cpf, int qtdFilmes);

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
     * @brief Imprime um relatório das locações pendentes.
     */
    void relatorio();
};

#endif