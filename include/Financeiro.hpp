#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include "Locacao.hpp"
#include <deque>
#include <iomanip>

const std::string DIRETORIO_HISTORICO_FINANCEIRO = "./data/Financeiro/historico_financeiro";

struct Data {
    time_t now = time(0);
    
    int dia = localtime(&now)->tm_mday;
    int mes = localtime(&now)->tm_mon + 1;
    int ano = localtime(&now)->tm_year + 1900;
};

struct Transacao {
    Data data;
    char tipo; // SAQUE OU DEPOSITO
    float valor;
    float saldo_final; // saldo final após a transação

    Transacao(Data, char, float, float);
    void imprimeTransacao();
};


class Financeiro {
    private:
        float saldo;
        std::deque<Transacao> transacoes;

    public:
        Financeiro();
        ~Financeiro();

        void historicoTransacoes(); // dia, mẽs, total

        float getSaldo();

        // retorna true se o deposito for realizado com sucesso e false caso contraŕio
        bool deposito(float);

        // retorna true se o saque for realizado com sucesso e false caso contrário
        bool saque(float);

        void salvarDados();

        void cancelarUltimaTransacao();
};


#endif