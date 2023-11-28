#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include "Locacao.hpp"
#include <vector>
#include <iomanip>

struct Data {
    time_t now = time(0);
    
    int _dia = localtime(&now)->tm_mday;
    int _mes = localtime(&now)->tm_mon + 1;
    int _ano = localtime(&now)->tm_year + 1900;
};

struct Transacao {
    Data data;
    std::string tipo; // Saque ou Deposito
    float valor;

    Transacao(Data, std::string, float);
};


class Financeiro {
    private:
        float saldo;
        std::vector<Transacao> transacoes;

    public:
        void historicoTransacoes(); // dia, mẽs, total

        float getSaldo();

        // retorna true se o deposito for realizado com sucesso e false caso contraŕio
        bool deposito(float);

        // retorna true se o saque for realizado com sucesso e false caso contrário
        bool saque(float);
};


#endif