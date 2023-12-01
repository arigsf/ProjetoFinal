#include "Cadastro_Clientes.hpp"

/**
 * @file cadastro_clientes.cpp
 * @brief Implementação dos métodos da classe Cliente.
 */

CadastroClientes::CadastroClientes()
{
    this->lerArquivo(DIRETORIO_PADRAO_CLIENTES);
}

// Implementação dos métodos da classe CadastroClientes
void CadastroClientes::inserirCliente(Cliente *cliente)
{

    // Adiciona o cliente na lista se todos os dados estiverem corretos
    _clientes.push_back(cliente);
}

void CadastroClientes::removerCliente(const std::string &cpf)
{
    // Procura o cliente na lista
    std::vector<Cliente *>::iterator it = std::find_if(_clientes.begin(), _clientes.end(), [&cpf](const Cliente *cliente)
                                                       { return cliente->getCPF() == cpf; });

    // Caso o cliente seja encontrado, ele é removido
    if (it != _clientes.end())
    {
        // Guarda o CPF removido para dizer qual é ele logo abaixo
        std::string cpfRemovido = (*it)->getCPF();
        // Libera a memória do cliente
        delete *it;
        _clientes.erase(it);
        std::cout << "Cliente de CPF: " << cpfRemovido << " removido com sucesso" << std::endl;
    }
    else
    {
        std::cout << "ERRO: CPF inexistente" << std::endl;
    }
}

void CadastroClientes::listarClientesOrdenados() const
{
    // Gera uma cópia da lista dos clientes
    std::vector<Cliente *> clientesOrdenados = _clientes;

    // Ordena a lista com base no nome;

    std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
              [](const Cliente *a, const Cliente *b)
              {
                  return a->getNome() < b->getNome();
              });

    // Mostra os clientes ordenados na ordem: cpf, nome, data de nascimento, idade
    std::cout << '\n';
    for (const Cliente *cliente : clientesOrdenados)
    {
        std::cout << "CPF: " << cliente->getCPF() << ", Nome: " << cliente->getNome() << ", Data de nascimento: " << cliente->getDataNascimento() << ", Idade: " << cliente->getIdade() << std::endl;
    }
}

Cliente *CadastroClientes::clienteExiste(const std::string &cpf) const
{
    // Verifica se um cliente de mesmo CPF está na lista
    for (Cliente *cliente : this->_clientes)
        if (cliente->getCPF() == cpf)
            return cliente;

    return nullptr;
}

void CadastroClientes::salvarDados(const bool limparDados)
{ // O parametro limpardados decide, se após dos dados serem salvos eles devem ser desalocados

    try
    {
        // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
        std::ofstream arquivo(DIRETORIO_PADRAO_CLIENTES, std::ios::out | std::ios::trunc);

        if (!arquivo.is_open())
            throw std::runtime_error("Erro: nao foi possível criar o arquivo");

        std::chrono::system_clock::time_point agora = std::chrono::system_clock::now();
        std::time_t tempo = std::chrono::system_clock::to_time_t(agora);

        // Cria uma estrutura de tempo local
        std::tm *horaLocal = std::localtime(&tempo);

        // Formata a data e a hora como uma string
        std::ostringstream oss;
        oss << std::put_time(horaLocal, "%d-%m-%Y %H_%M_%S");

        std::string caminho_copia = DIRETORIO_HISTORICO_CLIENTES + "clientes " + oss.str();
        std::ofstream copia(caminho_copia, std::ios::out | std::ios::trunc);
        // Cria um arquivo com o nome sendo a data atual

        if (!copia.is_open())
            throw std::runtime_error("ERRO: nao foi possivel criar o arquivo copia");

        if (limparDados)
        {
            for (Cliente *cliente : this->_clientes)
            {
                arquivo << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
                copia << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
                delete cliente;
            }

            this->_clientes.clear();
        }
        // Percorre a lista de filmes e adiciona no arquivo

        else
            for (Cliente *cliente : this->_clientes)
            {
                arquivo << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
                copia << cliente->getCPF() << " " << cliente->getNome() << " " << cliente->getDataNascimento() << std::endl;
            }

        arquivo.close();
        copia.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void CadastroClientes::lerArquivo(std::string diretorio)
{

    try
    {

        std::ifstream arquivo(diretorio, std::ios::in);
        std::ofstream log(DIRETORIO_LOG_CLIENTES, std::ios::app);

        if (!arquivo.is_open())
            throw std::runtime_error("ERRO: arquivo inexistente");

        if (!log.is_open())
            throw std::runtime_error("ERRO: nao foi possivel encontrar ou criar o arquivo");

        std::string linha, palavra, cpf, nome, data_nascimento;
        std::vector<std::string> palavras;
        Cliente *novo_cliente;
        int total_lidos = 0, total_erros = 0;

        while (getline(arquivo, linha))
        {
            try
            {
                // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
                std::istringstream iss(linha);

                // é um stream de input baseado em uma string
                iss >> cpf;

                if (!isCPFValido(cpf))
                    throw std::runtime_error(linha + " - ERRO: CPF invalido");

                while (iss >> palavra)
                    palavras.push_back(palavra); // Todas as palavras pós cpf são separadas em um vetor,
                // devido ao fato de não sabermos a quantidade de palavras do none

                data_nascimento = palavras.back(); // A ultima palavra do array, por consequencia é a data de nascimento

                if (!isDataNascimentoValido(data_nascimento))
                    throw std::runtime_error(linha + " - ERRO: data de nascimento invalida");

                palavras.pop_back();

                std::ostringstream concatenar;
                for (std::vector<std::string>::iterator it = palavras.begin(); it != palavras.end(); it++)
                {
                    concatenar << *(it);
                    if (it != palavras.end() - 1)
                        concatenar << " "; // Assim não é adicionado um ultimo espaço na ultima palavra
                }

                nome = concatenar.str();

                if (nome.empty())
                    throw std::runtime_error(linha + " - ERRO: Nome invalido");

                palavras.clear();
                novo_cliente = new Cliente(cpf, nome, data_nascimento);

                this->inserirCliente(novo_cliente);
                total_lidos++;
            }
            catch (const std::exception &e)
            {
                log << e.what() << std::endl;
                total_erros++;
            }
        }

        log.close();
        arquivo.close();

        if (total_lidos)
            std::cout << total_lidos << " clientes cadastrados com sucesso" << std::endl;
        if (total_erros)
            std::cout << total_erros << " clientes geraram erro" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Implementa o destrutor
CadastroClientes::~CadastroClientes()
{
    this->salvarDados(true);
}
