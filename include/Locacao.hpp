#ifndef LOCACAO_H
#define LOCACAO_H

#include <vector>
#include <string>
#include "Filme.hpp"

class Locacao {
    private:
        int numeroLocacoes;
        std::vector<std::pair<std::string, std::vector<Filme>>> locacoes; // Vector de pares com (CPF, vector de filmes)

    public:
        Locacao(); // Construtor

        void alugar(std::string, std::vector<Filme>); // CPF, Filmes
        int verificarCPF(std::string); // Verificação de possibilidade de tal CPF alugar
        
        int calculoPreco(int, Filme);
        int devolucao(std::string, int); // Devolução para DVDs

        void relatorio();

};

#endif