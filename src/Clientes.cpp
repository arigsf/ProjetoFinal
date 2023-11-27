#include "Clientes.hpp"

// FORMATO CPF: xxx.xxx.xxx-xx
// FORMATO Data de Nascimento: dd/mm/yyyy

// Implementação do construtor da classe Cliente
Cliente::Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento /*const std::string endereco*/)
    : _cpf(cpf), _nome(nome), _dataNascimento(dataNascimento) /*endereco(endereco)*/ {}

// Implementação dos métodos da classe Cliente
const std::string Cliente::getCPF() const
{
    return _cpf;
}

const std::string Cliente::getNome() const
{
    return _nome;
}

const std::string Cliente::getDataNascimento() const
{
    return _dataNascimento;
}

/*
const std::string Cliente::getEndereco() const {
    return endereco;
}*/

int Cliente::getIdade() const
{
    // Obtém hora e data do sistema
    std::time_t t = std::time(0);
    std::tm *atual = std::localtime(&t);

    // Obtém a data atual e de nascimento do cliente
    int AnoAtual = atual->tm_year + 1900;
    int MesAtual = atual->tm_mon + 1;
    int DiaAtual = atual->tm_mday;

    // Utilizar o formato dia/mês/ano, ou seja, dd/mm/yyyy. Ex: 06/04/1998
    int AnoNascimento = std::stoi(_dataNascimento.substr(6));
    int MesNascimento = std::stoi(_dataNascimento.substr(3, 2));
    int DiaNascimento = std::stoi(_dataNascimento.substr(0, 2));

    // Calcula e retorna a idade
    int Idade = AnoAtual - AnoNascimento;

    if (MesAtual < MesNascimento || (MesAtual == MesNascimento && DiaAtual < DiaNascimento))
    {
        Idade--;
    }
    return Idade;
}
