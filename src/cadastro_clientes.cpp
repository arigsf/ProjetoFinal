#include "cadastro_clientes.hpp"
#include <algorithm> //Remoção de clientes
#include <regex> //Validar cpf e data de nascimento

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

//Implementação dos métodos da classe CadastroClientes
void CadastroClientes::InserirCliente(Cliente* cliente) {
    //Verificação de existência do cliente
    if (ClienteExiste(cliente->GetCPF())) {
        std::cout << "ERRO: CPF repetido" << std::endl;
        return;
    }

    //Expressão regular para validar o formato do CPF
    std::regex regexCPF(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
    if (!std::regex_match(cliente->GetCPF(), regexCPF)) {
        std::cout << "ERRO: Formato inválido de CPF" << std::endl;
        return;
    }

    //Verificar se o nome do cliente está vazio
    if (cliente->GetNome().empty()) {
        std::cout << "ERRO: Nome vazio" << std::endl;
        return;
    }

    //Expressão regular para validar o formato da data de nascimento
    std::regex regexDataNascimento(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(cliente->GetDataNascimento(), regexDataNascimento)) {
        std::cout << "ERRO: Formato inválido de data de nascimento" << std::endl;
        return;
    }

    //Adiciona o cliente na lista se todos os dados estiverem corretos
    clientes.push_back(cliente);
    std::cout << "Cliente de CPF: " << cliente->GetCPF() << " cadastrado com sucesso" << std::endl;
}

void CadastroClientes::RemoverCliente(const std::string& cpf) {
    //Procura o cliente na lista
    std::vector<Cliente*>::iterator it = std::find_if(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
        return cliente->GetCPF() == cpf;
    });

    //Caso o cliente seja encontrado, ele é removido
    if (it != clientes.end()) {
        //Guarda o CPF removido para dizer qual é ele logo abaixo
        std::string cpfRemovido = (*it)->GetCPF();
        //Libera a memória do cliente
        delete *it;
        clientes.erase(it);
        std::cout << "Cliente de CPF: " << cpfRemovido << " removido com sucesso" << std::endl;
    } else {
        std::cout << "ERRO: CPF inexistente" << std::endl;
    }
}

void CadastroClientes::ListarClientesOrdenados(bool porCPF) const {
    //Gera uma cópia da lista dos clientes
    std::vector<Cliente*> clientesOrdenados = clientes;

    //Ordena a lista com base na opção escolhida
    if (porCPF) {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](const Cliente* a, const Cliente* b) {
                      return a->GetCPF() < b->GetCPF();
                  });
    } else {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](const Cliente* a, const Cliente* b) {
                      return a->GetNome() < b->GetNome();
                  });
    }

    //Mostra os clientes ordenados na ordem: cpf, nome, data de nascimento, idade
    for (const Cliente* cliente : clientesOrdenados) {
        std::cout << "CPF: " << cliente->GetCPF() << ", Nome: " << cliente->GetNome() << ", Data de nascimento: " << cliente->GetDataNascimento() << ", Idade: " << cliente->GetIdade() << std::endl;
    }
}

bool CadastroClientes::ClienteExiste(const std::string& cpf) const {
    //Verifica se um cliente de mesmo CPF está na lista
    return std::any_of(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
        return cliente->GetCPF() == cpf;
    });
}

//Implementa o destrutor
CadastroClientes::~CadastroClientes() {
    //Limpa o vetor de ponteiros
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
    clientes.clear();
}
