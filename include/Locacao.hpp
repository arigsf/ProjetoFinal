#ifndef LOCACAO_H
#define LOCACAO_H

#include "Filme.hpp"

class Locacao {
    private:
        int numeroLocacoes;
        std::vector<std::pair<std::string, std::vector<Filme>>> locacoes; // Vector de pares com (CPF, vector de filmes)

        void removeLocacao(int); // Função para remoção de uma locação após a devolução, como parâmetro apenas a posição no vetor locacoes

    public:
        Locacao(); // Construtor

        void alugar(std::string, std::vector<Filme>); // CPF, Filmes
        bool verificarCPF(std::string); // Verificação se CPF já está com uma locação pendente
        
        int calculoPreco(int, Filme);
        int devolucao(std::string, int); // Devolução para DVDs

        void relatorio();

};

#endif