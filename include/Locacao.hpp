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

        void alugar(std::string, std::vector<std::string>); // CPF, Códigos
        int verificarCPF(std::string); // Verificação de 
        int devolucao(std::string, int); // Devolução para DVDs
        int calculoValor()
        int devolucao(std::string, int, bool); // Devolução para fitas
        void relatorio();

};

#endif

int DVD::calculaPreco (int dias){
    if (categoria == LANCAMENTO) return 20 * dias;
    
    else if (categoria == ESTOQUE) return 10 * dias;

    else if (categoria == PROMOCAO) return 10;

    //Elaborar tratamento de erro futuramente;
}

// Define um valor padrão para o número de dias, pois isso não tem influência no cálculo do preço da fita;

int FITA::calculaPreco (int dias = 0) { 
    return estaRebobinado ? 5 : 7; // R$5,00 se a fita estiver rebobinada, caso contrário há uma adição de R$2,00;
}