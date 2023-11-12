#include "cadastro_clientes.hpp"

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
