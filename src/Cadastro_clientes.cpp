#include "Cadastro_clientes.hpp"
#include <unistd.h>
#include <algorithm> //Remoção de clientes
#include <regex> //Validar cpf e data de nascimento
#include <fstream> // Operações com arquivos
#include <sstream> // Operações com leitura de linha
#include <numeric> // Transformar vetor de strings em uma string


//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

std::string CadastroClientes::diretorio = "./data/Clientes/clientes.txt";

CadastroClientes::CadastroClientes() {
    this->lerArquivo();
    
}

//Implementação dos métodos da classe CadastroClientes
void CadastroClientes::inserirCliente(Cliente* cliente) {

    //Adiciona o cliente na lista se todos os dados estiverem corretos
    clientes.push_back(cliente);
}

void CadastroClientes::removerCliente(const std::string& cpf) {
    //Procura o cliente na lista
    std::vector<Cliente*>::iterator it = std::find_if(clientes.begin(), clientes.end(), [&cpf](const Cliente* cliente) {
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

void CadastroClientes::listarClientesOrdenados() const {
    //Gera uma cópia da lista dos clientes
    std::vector<Cliente*> clientesOrdenados = clientes;

    //Ordena a lista com base no nome;
    
    std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
        [](const Cliente* a, const Cliente* b) {
                return a->getNome() < b->getNome();
        });

    //Mostra os clientes ordenados na ordem: cpf, nome, data de nascimento, idade
    std::cout << '\n';
    for (const Cliente* cliente : clientesOrdenados) {
        std::cout << "CPF: " << cliente->getCPF() << ", Nome: " << cliente->getNome() << ", Data de nascimento: " << cliente->getDataNascimento() << ", Idade: " << cliente->getIdade() << std::endl;
    }
}

Cliente* CadastroClientes::clienteExiste(const std::string& cpf) const {
    //Verifica se um cliente de mesmo CPF está na lista
    for (Cliente *cliente : this->clientes)
        if (cliente->getCPF() == cpf)
            return cliente;

    return nullptr;
}

void CadastroClientes::salvarDados(const bool limparDados) { // O parametro limpardados decide, se após dos dados serem salvos eles devem ser desalocados


    // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
    std::ofstream arquivo(this->diretorio, std::ios::out | std::ios::trunc);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: não foi possível criar o arquivo" << std::endl;
        return;
    }

    if(limparDados) {

        for (Cliente *cliente : this->clientes) {
            arquivo << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
            delete cliente;
        }

        this->clientes.clear();
    }
    // Percorre a lista de filmes e adiciona no arquivo
    
    else 
        for (Cliente *cliente : this->clientes)
            arquivo << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;

    arquivo.close();   
}

void CadastroClientes::lerArquivo() {
    
    std::ifstream arquivo(this->diretorio, std::ios::in);

    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    std::string linha, palavra,cpf, nome, data_nascimento;
    std::vector<std::string> palavras;
    Cliente *novo_cliente;
    int aux = 0; //Variável auxiliar para guardar o n° de clientes cadastrados com sucesso

    while (getline(arquivo,linha)) {

        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
        std::istringstream iss(linha);
        // é um stream de input baseado em uma string
        iss >> cpf;

        while (iss >> palavra) palavras.push_back(palavra); // Todas as palavras pós cpf são separadas em um vetor,
        // devido ao fato de não sabermos a quantidade de palavras do nome

        data_nascimento = palavras.back(); // A ultima palavra do array, por consequencia é a data de nascimento
        palavras.pop_back();
        nome = std::accumulate(palavras.begin(), palavras.end(), std::string());        
        palavras.clear();
        novo_cliente = new Cliente(cpf,nome,data_nascimento);

        this->inserirCliente(novo_cliente);
        aux++;
    }

    arquivo.close();

    if(aux) std::cout << aux << " clientes cadastrados com sucesso" << std::endl;
}

//Implementa o destrutor
CadastroClientes::~CadastroClientes() {
    this->salvarDados(true);
}
