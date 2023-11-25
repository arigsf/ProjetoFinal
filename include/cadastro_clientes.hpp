#ifndef CADASTRO_CLIENTES_HPP
#define CADASTRO_CLIENTES_HPP

#include "clientes.hpp"
#include <iostream>
#include <vector>

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

class CadastroClientes {
public:
    //Métodos que manipulam a lista dos clientes

    void inserirCliente(Cliente* cliente);
    void removerCliente(const std::string& cpf);
    void listarClientesOrdenados() const;
    //Método que verifica a existência de algum cliente
    Cliente* clienteExiste(const std::string& cpf) const;
    //Construtor
    CadastroClientes();
    //Destrutor
    ~CadastroClientes();

private:
    //Lista dos clientes
    static std::string diretorio;
    std::vector<Cliente*> clientes;
    // Salvar dados antes do enceramento do sistema, para garantir que nenhum dado se perca
    void salvarDados(const bool);
    // Ler banco de dados com as informações de clientes registrados anteriormente
    void lerArquivo();
};

#endif
