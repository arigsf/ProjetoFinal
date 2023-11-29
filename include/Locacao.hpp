#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"
#include "Estoque.hpp"
#include <ctime>
#include <numeric> // Transformar vetor de strings em uma string
#include <sstream> // Leitura de arquivo
#include <stdexcept>

const int QTD_MAXIMO_FILMES_ALUGADOS = 10;

const std::string DIRETORIO_HISTORICO_LOCACOES = "./data/Locacoes/historico_Locacoes";
const std::string DIRETORIO_LOCACOES_PENDENTES = "./data/Locacoes/locacoes_Pendentes";

struct LocacaoData {                                                                     // Para o controle das locações
    std::string _CPFCliente;
    Filme* _filme;
    int _diasAlugados;
    // Implementação dia inicial do aluguel
};

struct LocacaoLogData {                                                                  // Para o histórico de locações
    std::string _nomeFilme;
    std::string _CPFCliente;

    int _identificadorFilme;
    int _diasAlugados;
    int _multaPaga;
    // Implementação dia inicial do aluguel
};

class Locacao
{
private:
    static int _numeroLocacoes;                                                          // Total de locações
    Estoque* _estoque;                                                                   // Ponteiro para o estoque da locadora
    std::vector<LocacaoData> _locacoes;                                                  // Vector que armazena todas as locações do sistema

    void removeLocacao(int posNoVetorLocacao);                                           // Função para remoção de uma locação após a devolução, como parâmetro a posição no vetor locações
    int getPosicaoLocacaoVetorLocacoes(LocacaoData* locacao);                            // Encontra a posição da locação no vetor locações
    LocacaoData getLocacao(std::string cpf, Filme * filme);                              // Função que encontra locação

    // Arquivos
    void salvarLocacaoPendentes();                                                       // Atualiza o arquivo de locações pendentes para manter em sincronia com o sistema
    void salvarLocacaoLog(Filme * filme, std::string cpf, int dias, int multaPaga);      // Salva locação após devolução em arquivo de log para locações já finalizadas
    // Salvo no formato (identificadorFilme nomeFilme CPFCliente dias multaPaga)
    std::vector<LocacaoData> leituraLocacoesPendentes();
    std::vector<LocacaoLogData> leituraLocacaoLog();

public:
    Locacao();                                                                           // Construtor
    void associarPtrEstoque(Estoque* estoque);                                           // Associar ponteiro de estoque a variavel _estoque da locação (para obter acesso aos itens de estoque)
    int getLocacoesPorCliente(std::string cpf);                                          // Retorna o número de locações de determinado cliente, com base em seu CPF
    int devolucao(std::string cpf, Filme *filme, int dias, bool isDanificado);           // Devolução por filme e caracteristicas do mesmo na devolução, retornando o valor a ser pago (multas)
    bool verificarFilmeAlugado(int identificador);                                       // Verifica se tal filme (através do identificador individual) já está alocado
    float alugar(std::string cpf, std::vector<Filme *> filmes, int dias);                 // Processo de criação de aluguel de filmes 
    void relatorio();                                                                    // Imprime um relatório de todas as locações pendentes no sistema
    void historicoLocacoes();                                                            // Imprime um log com todos os registros de locações já finalizadas (somente salvas após devolução), ordenado por CPF
};

#endif