#ifndef CADASTRO_CLIENTES_HPP
#define CADASTRO_CLIENTES_HPP

#include "Clientes.hpp"
#include <iostream>
#include <vector>

/**
 * @file cadastro_clientes.hpp
 * @brief Definição da classe CadastroCliente
 */

/**
 * @brief Classe responsável pelo gerenciamento dos clientes.
 */
class CadastroClientes
{
public:
    /**
     * @brief Insere um novo cliente no cadastro.
     * @param cliente Ponteiro para o cliente a ser inserido.
     */
    void inserirCliente(Cliente *cliente);

    /**
     * @brief Remove um cliente do cadastro pelo CPF.
     * @param cpf CPF do cliente a ser removido.
     */
    void removerCliente(const std::string &cpf);

    /**
     * @brief Lista os clientes ordenados por CPF ou nome.
     * @param porCPF Se verdadeiro, ordena por CPF; senão, ordena por nome.
     */
    void listarClientesOrdenados(bool porCPF) const;

    /**
     * @brief Verifica se um cliente com o CPF fornecido já existe.
     * @param cpf CPF a ser verificado.
     * @return Ponteiro para o cliente se existir; senão, nullptr.
     */
    Cliente *clienteExiste(const std::string &cpf) const;

    /**
     * @brief Construtor da classe CadastroClientes.
     */
    CadastroClientes();

    /**
     * @brief Destrutor da classe CadastroClientes.
     */
    ~CadastroClientes();

private:
    static std::string diretorio;
    std::vector<Cliente *> clientes;

    /**
     * @brief Salva os dados dos clientes no arquivo.
     * @param limparDados Se verdadeiro, desaloca os dados após salvar.
     */
    void salvarDados(const bool);

    /**
     * @brief Lê os dados dos clientes do arquivo.
     */
    void lerArquivo();
};

#endif
