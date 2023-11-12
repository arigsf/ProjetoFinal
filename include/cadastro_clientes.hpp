#ifndef CADASTRO_CLIENTES_HPP
#define CADASTRO_CLIENTES_HPP

#include "clientes.hpp"
#include <iostream>
#include <vector>

class CadastroClientes {
public:
    //Métodos que manipulam a lista dos clientes
    void inserirCliente(Cliente* cliente);
    void removerCliente(const std::string& cpf);
    void listarClientesOrdenados(bool porCPF) const;

    //Destrutor
    ~CadastroClientes();

private:
    //Método que verifica a existência de algum cliente
    bool clienteExiste(const std::string& cpf) const;

    //Lista dos clientes
    std::vector<Cliente*> clientes;
};

#endif
