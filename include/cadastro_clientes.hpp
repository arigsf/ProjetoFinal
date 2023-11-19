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
    void listarClientesOrdenados(bool porCPF) const;
    //Método que verifica a existência de algum cliente
    bool clienteExiste(const std::string& cpf) const;
    //Destrutor
    ~CadastroClientes();

private:
    //Lista dos clientes
    std::vector<Cliente*> clientes;
};

#endif
