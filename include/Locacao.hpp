#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"

class Locacao {
    private:
        static int numeroLocacoes;
        std::vector<std::pair<std::string, Filme*>> locacoes; // Vector de pares com (CPF, filme)

        void removeLocacao(int); // Função para remoção de uma locação após a devolução, como parâmetro apenas a posição no vetor locacoes

    public:
        Locacao(); // Construtor

        int getLocacoesPorCliente(std::string); // CPF

        void alugar(std::string, std::vector<Filme*>&, int); // CPF, Filmes, dias de locação
        bool verificarCPFmaxFilmes(std::string, int); // Verifica se o CPF pode alugar mais itens (qtdFilmes), sem que ultrapasse o limite de 10 locações
        
        int devolucao(std::string, int); // Devolução para DVDs

        void relatorio();

};

#endif