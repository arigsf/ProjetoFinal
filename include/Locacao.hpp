#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"
#include "Estoque.hpp"
#include <numeric> // Transformar vetor de strings em uma string

const int QTD_MAXIMO_FILMES_ALUGADOS = 10;

class Locacao
{
private:
    static int _numeroLocacoes;
    Estoque* _estoque; // Ponteiro para o estoque da locadora
    std::vector<std::pair<std::string, std::pair<Filme *, int>>> _locacoes; // Vector de pares com (CPF, par(filme, dias))

    void removeLocacao(int posNoVetorLocacao);                                           // Função para remoção de uma locação após a devolução, como parâmetro a posição no vetor locações
    int getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme *, int>>*); // Encontra a posição da locação no vetor locações
    std::pair<std::string, std::pair<Filme *, int>> getLocacao(std::string, Filme *);    // Função que encontra locação
    void salvarLocacaoPendentes();
    void salvarLocacaoLog(Filme *, std::string, int, int);                               // Salva locação após devolução em arquivo de log para locações já finalizadas
    // Salvo no formato (identificadorFilme nomeFilme CPFCliente dias multaPaga)
    std::vector<std::pair<std::string, std::pair<Filme *, int>>> leituraLocacoesPendentes();
    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> leituraLocacaoLog();
    // Formato vector das locações (par) par1 -> (nomeFilme, CPFCliente); par2 -> (identificadorFilme, dias, multaPaga)

public:
    Locacao();                                                                 // Construtor
    void associarPtrEstoque(Estoque* estoque);                                 // Associar
    bool verificarCPFmaxFilmes(std::string cpf, int qtdFilmes);                // Verifica se o CPF pode alugar mais itens (qtdFilmes), sem que ultrapasse o limite de 10 locações
    int getLocacoesPorCliente(std::string cpf);                                // CPF
    int devolucao(std::string cpf, Filme *filme, int dias, bool isDanificado); // Devolução por filme e caracteristicas do mesmo na devolução, retornando o valor a ser pago (multas), sendo o ultimo booleanos isDanificado
    void alugar(std::string cpf, std::vector<Filme *> filmes, int dias);       // CPF, Filmes, dias de locação
    void relatorio();
    void historicoLocacoes();                                                  // Imprime um log com todos os registros de locações já finalizadas (somente salvas após devolução), ordenado por CPF
};

#endif