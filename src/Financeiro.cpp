#include "Financeiro.hpp"

bool Financeiro::deposito(float valor) {
    if (valor > 0) {
        this->saldo += valor;
        transacoes.push_back({"DEPOSITO", valor});
        return true;
    } 
        
    std::cout << "ERRO: Valor inválido" << std::endl;
    return false;
    
}

bool Financeiro::saque(float valor) {
    if (valor <= 0) {
        std::cout << "ERRO: Valor inválido" << std::endl;
        return false;
    }

    if (valor > saldo) {
        std::cout << std::fixed << std::setprecision(2) <<  "\nValor indisponível, saldo atual de R$" << saldo << std::endl; 
        return false;
    }

    this->saldo -= valor;
    transacoes.push_back({"SAQUE", valor});

    std::cout << std::fixed << std::setprecision(2) <<  "Saque de R$" << valor << " realizado com sucesso!\nSaldo atual: R$" << saldo << std::endl;

    return true; 
}

float Financeiro::getSaldo() {
    return this->saldo;
}

void Financeiro::historicoTransacoes() {
    
}