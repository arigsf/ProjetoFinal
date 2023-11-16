#include "clientes.hpp"

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

//Implementação do construtor da classe Cliente
Cliente::Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento)
    : cpf(cpf), nome(nome), dataNascimento(dataNascimento) {}

//Implementação dos métodos da classe Cliente
const std::string Cliente::getCPF() const {
    return cpf;
}

const std::string Cliente::getNome() const {
    return nome;
}

const std::string Cliente::getDataNascimento() const {
    return dataNascimento;
}

int Cliente::getIdade() const {
    //Obtém hora e data do sistema
    std::time_t t = std::time(0);
    std::tm* atual = std::localtime(&t);

    //Obtém o ano atual e o ano de nascimento do cliente
    int anoAtual = atual->tm_year + 1900;
    int anoNascimento = std::stoi(dataNascimento.substr(6)); //Utilizar o formato dia/mês/ano, ou seja, dd/mm/yyyy. Ex: 06/04/1998

    //Calcular e retornar a idade
    return anoAtual - anoNascimento;
}
