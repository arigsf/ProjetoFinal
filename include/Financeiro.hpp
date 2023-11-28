#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include "Locacao.hpp"
#include <vector>
#include <iomanip>


class Financeiro {
    private:
        float saldo;
        std::vector<std::string, float> transacoes;

    public:
        void historicoTransacoes(); // dia, mẽs, total

        float getSaldo();

        // retorna true se o deposito for realizado com sucesso e false caso contraŕio
        bool deposito(float);

        // retorna true se o saque for realizado com sucesso e false caso contrário
        bool saque(float);
};


#endif