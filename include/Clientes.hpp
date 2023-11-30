#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <ctime>

/**
 * @file Cliente.hpp
 * @brief Definição da classe Cliente, que representa um cliente com dados pessoais.
 */

// FORMATO CPF: xxx.xxx.xxx-xx
// FORMATO Data de Nascimento: dd/mm/yyyy

/**
 * @class Cliente
 * @brief Classe que representa os clientes.
 */
class Cliente
{
public:
    /**
     * @brief Construtor da classe Cliente.
     * @param cpf O CPF do cliente.
     * @param nome O nome do cliente.
     * @param dataNascimento A data de nascimento do cliente no formato dd/mm/yyyy.
     */
    Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento /*const std::string endereco*/);

    /**
     * @brief Obtém o CPF do cliente.
     * @return O CPF do cliente.
     */
    const std::string getCPF() const;

    /**
     * @brief Obtém o nome do cliente.
     * @return O nome do cliente.
     */
    const std::string getNome() const;

    /**
     * @brief Obtém a data de nascimento do cliente.
     * @return A data de nascimento do cliente no formato dd/mm/yyyy.
     */
    const std::string getDataNascimento() const;

    /**
     * @brief Obtém a idade do cliente com base na data de nascimento.
     * @return A idade do cliente.
     */
    int getIdade() const;

private:
    std::string _cpf;
    std::string _nome;
    std::string _dataNascimento;
    /*std::string endereco;*/
};

#endif