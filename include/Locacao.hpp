#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"

class Locacao {
    private:
        static int numeroLocacoes;
        std::vector<std::pair<std::string, std::pair<Filme*, int>>> locacoes; // Vector de pares com (CPF, par(filme, dias))

        void removeLocacao(int); // Função para remoção de uma locação após a devolução, como parâmetro a posição no vetor locações
        int getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme*, int>>); // Encontra a posição da locação no vetor locações
        std::pair<std::string, std::pair<Filme*, int>> getLocacao(std::string, Filme*); // Função que encontra locação

    public:
        Locacao(); // Construtor

        int getLocacoesPorCliente(std::string); // CPF

        void alugar(std::string, std::vector<Filme*>&, int); // CPF, Filmes, dias de locação
        bool verificarCPFmaxFilmes(std::string, int); // Verifica se o CPF pode alugar mais itens (qtdFilmes), sem que ultrapasse o limite de 10 locações
        
        int devolucao(std::string, Filme*, int, bool); // Devolução por filme e caracteristicas do mesmo na devolução, retornando o valor a ser pago (multas), sendo o ultimo booleanos isDanificado

        void relatorio();

};

#endif