#ifndef LOCACAO_H
#define LOCACAO_H

#include <vector>
#include <string>

class Locacao {
    private:
        int numeroLocacoes;
        std::vector<std::pair<std::string, std::vector<std::string>>> locacoes; // Vector de pares com (CPF, vector de códigos)

    public:
        Locacao(); // Construtor

        void alugar(std::string CPF, std::vector<std::string> codigos);
        int verificarCPF(std::string CPF);
        int devolucao(std::string CPF, int dias); // Devolução para DVDs
        int devolucao(std::string CPF, int dias, int rebobinado); // Devolução para fitas
        void relatorio();

};

#endif