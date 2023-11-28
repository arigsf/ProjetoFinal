#include "Financeiro.hpp"

bool Financeiro::deposito(float valor) {
    if (valor > 0) {
        Data data;
        Transacao transacao(data, "DEPOSITO", valor);
        this->saldo += valor;

        transacoes.push_back(transacao);

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
    
    Data data;
    Transacao transacao(data, "SAQUE", valor);
    this->saldo -= valor;

    transacoes.push_back(transacao);

    std::cout << std::fixed << std::setprecision(2) <<  "Saque de R$" << valor << " realizado com sucesso!\nSaldo atual: R$" << saldo << std::endl;

    return true; 
}

float Financeiro::getSaldo() {
    return this->saldo;
}

void Financeiro::historicoTransacoes() {
    
}

Transacao::Transacao(Data _data, std::string _tipo, float _valor) : 
    data(_data), tipo(_tipo), valor(_valor) {}