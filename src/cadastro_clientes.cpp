#include "cadastro_clientes.hpp"
#include <algorithm>

//Implementação dos métodos da classe CadastroClientes
void CadastroClientes::inserirCliente(Cliente* cliente) {
    //Verificação de existência do cliente
    if (clienteExiste(cliente->getCPF())) {
        std::cout << "ERRO: CPF repetido" << std::endl;
        return;
    }

    //Adiciona o cliente na lista
    clientes.push_back(cliente);
    std::cout << "Cliente cadastrado com sucesso" << std::endl;
}

void CadastroClientes::removerCliente(const std::string& cpf) {
    //Procura o cliente na lista
    auto it = std::find_if(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
        return cliente->getCPF() == cpf;
    });

    //Caso o cliente seja encontrado, ele é removido
    if (it != clientes.end()) {
        delete *it;  //Libera a memória do cliente
        clientes.erase(it);
        std::cout << "Cliente removido com sucesso" << std::endl;
    } else {
        std::cout << "ERRO: CPF inexistente" << std::endl;
    }
}

void CadastroClientes::listarClientesOrdenados(bool porCPF) const {
    //Gera uma cópia da lista dos clientes
    std::vector<Cliente*> clientesOrdenados = clientes;

    //Ordena a lista com base na opção escolhida
    if (porCPF) {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](const Cliente* a, const Cliente* b) {
                      return a->getCPF() < b->getCPF();
                  });
    } else {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](const Cliente* a, const Cliente* b) {
                      return a->getNome() < b->getNome();
                  });
    }

    //Mostra os clientes ordenados
    for (const auto& cliente : clientesOrdenados) {
        std::cout << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
    }
}

bool CadastroClientes::clienteExiste(const std::string& cpf) const {
    //Verifica se um cliente de mesmo CPF está na lista
    return std::any_of(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
        return cliente->getCPF() == cpf;
    });
}

//Implementa o destrutor
CadastroClientes::~CadastroClientes() {
    //Limpa o vetor de ponteiros
    for (auto& cliente : clientes) {
        delete cliente;
    }
    clientes.clear();
}
