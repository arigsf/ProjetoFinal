#include "cadastro_clientes.hpp"
#include <algorithm> //remoção de clientes
#include <regex> //validar cpf e data de nascimento

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

//Implementação dos métodos da classe CadastroClientes
void CadastroClientes::inserirCliente(Cliente* cliente) {
    //Verificação de existência do cliente
    if (clienteExiste(cliente->getCPF())) {
        std::cout << "ERRO: CPF repetido" << std::endl;
        return;
    }

    bool DadosIncorretos;
    //Expressão singular que verifica e valida (ou não) o CPF
    std::regex regexCPF(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
    if (!std::regex_match(cliente->getCPF(), regexCPF)) {
        DadosIncorretos = true;
    }

    if (cliente->getNome().empty()){
        DadosIncorretos = true;
    }
    //Expressão singular que verifica e valida (ou não) a data de nascimento
    std::regex regexDataNascimento(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(cliente->getDataNascimento(), regexDataNascimento)) {
        DadosIncorretos = true;
    }
    //Se o CPF estiver inválido, nome vazio ou data de nascimento inválida, retorna erro
    if (DadosIncorretos) {
        std::cout << "ERRO: dados incorretos" << std::endl;
        return;
    }

    //Adiciona o cliente na lista
    clientes.push_back(cliente);
    std::cout << "Cliente de CPF: " << cliente->getCPF() << " cadastrado com sucesso" << std::endl;
}

void CadastroClientes::removerCliente(const std::string& cpf) {
    //Procura o cliente na lista
    auto it = std::find_if(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
        return cliente->getCPF() == cpf;
    });

    //Caso o cliente seja encontrado, ele é removido
    if (it != clientes.end()) {
        //Guarda o CPF removido para dizer qual é ele logo abaixo
        std::string cpfRemovido = (*it)->getCPF();
        //Libera a memória do cliente
        delete *it;
        clientes.erase(it);
        std::cout << "Cliente de CPF: " << cpfRemovido << " removido com sucesso" << std::endl;
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

    //Mostra os clientes ordenados na ordem: cpf, nome, data de nascimento, idade
    for (const auto& cliente : clientesOrdenados) {
        std::cout << "CPF: " << cliente->getCPF() << ", Nome: " << cliente->getNome() << ", Data de nascimento: " << cliente->getDataNascimento() << ", Idade: " << cliente->getIdade() << std::endl;
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
