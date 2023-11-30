#ifndef CADASTRO_CLIENTES_HPP
#define CADASTRO_CLIENTES_HPP

#include "Clientes.hpp"
#include "Funcoes.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> //Remoção de clientes
#include <regex>     //Validar cpf e data de nascimento
#include <fstream>   // Operações com arquivos
#include <sstream>   // Operações com leitura de linha
#include <numeric>   // Transformar vetor de strings em uma string
#include <stdexcept>

/**
 * @file cadastro_clientes.hpp
 * @brief Definição da classe CadastroCliente
 */

const std::string DIRETORIO_PADRAO_CLIENTES = "./data/Clientes/clientes";
const std::string DIRETORIO_LOG_CLIENTES = "./data/Clientes/logs";
const std::string DIRETORIO_HISTORICO_CLIENTES = "./data/Clientes/Historico/";

// FORMATO CPF: xxx.xxx.xxx-xx
// FORMATO Data de Nascimento: dd/mm/yyyy

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
    void listarClientesOrdenados() const;

    /**
     * @brief Verifica se um cliente com o CPF fornecido já existe.
     * @param cpf CPF a ser verificado.
     * @return Ponteiro para o cliente se existir; senão, nullptr.
     */
    Cliente *clienteExiste(const std::string &cpf) const;

    /**
     * @brief Lê os dados dos clientes do arquivo
     * @param diretorio O caminho do arquivo a ser lido.
     */
    void lerArquivo(std::string diretorio);

    /**
     * @brief Salva os dados dos clientes no arquivo.
     * @param limparDados Se verdadeiro, desaloca os dados após salvar.
     */
    void salvarDados(const bool limparDados);

    /**
     * @brief Construtor da classe CadastroClientes.
     */
    CadastroClientes();

    /**
     * @brief Destrutor da classe CadastroClientes.
     */
    ~CadastroClientes();

private:
    // Lista dos clientes
    std::vector<Cliente *> _clientes;
    // Salvar dados antes do enceramento do sistema, para garantir que nenhum dado se perca
};

#endif
