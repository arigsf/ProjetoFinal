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
    void InserirCliente(Cliente* cliente);
    void RemoverCliente(const std::string& cpf);
    void ListarClientesOrdenados(bool porCPF) const;

    //Destrutor
    ~CadastroClientes();

private:
    //Método que verifica a existência de algum cliente
    bool ClienteExiste(const std::string& cpf) const;

    //Lista dos clientes
    std::vector<Cliente*> clientes;
};

#endif
