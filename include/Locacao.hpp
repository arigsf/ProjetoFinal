#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"
#include <unistd.h>
#include <algorithm> //Remoção de clientes
#include <regex> //Validar cpf e data de nascimento
#include <fstream> // Operações com arquivos
#include <sstream> // Operações com leitura de linha
#include <numeric> // Transformar vetor de strings em uma string

class Locacao {
    private:
        static int numeroLocacoes;
        std::vector<std::pair<std::string, std::pair<Filme*, int>>> locacoes; // Vector de pares com (CPF, par(filme, dias))
        
        void removeLocacao(int); // Função para remoção de uma locação após a devolução, como parâmetro a posição no vetor locações
        int getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme*, int>>); // Encontra a posição da locação no vetor locações
        std::pair<std::string, std::pair<Filme*, int>> getLocacao(std::string, Filme*); // Função que encontra locação
        void salvarLocacaoLog(Filme*, std::string, int, int); // Salva locação após devolução em arquivo de log para locações já finalizadas
        // Salvo no formato (identificadorFilme nomeFilme CPFCliente dias multaPaga)
        std::vector<std::pair<std::vector<std::string>, std::vector<int>>> leituraLocacaoLog();
        // Formato vector das locações (par) par1 -> (nomeFilme, CPFCliente); par2 -> (identificadorFilme, dias, multaPaga)

    public:
        Locacao(); // Construtor
        int getLocacoesPorCliente(std::string); // CPF
        void alugar(std::string, std::vector<Filme*>, int); // CPF, Filmes, dias de locação
        bool verificarCPFmaxFilmes(std::string, int); // Verifica se o CPF pode alugar mais itens (qtdFilmes), sem que ultrapasse o limite de 10 locações
        int devolucao(std::string, Filme*, int, bool); // Devolução por filme e caracteristicas do mesmo na devolução, retornando o valor a ser pago (multas), sendo o ultimo booleanos isDanificado
        void relatorio();
        void historicoLocacoes(); // Imprime um log com todos os registros de locações já finalizadas (somente salvas após devolução), ordenado por CPF

};

#endif