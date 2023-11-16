#include "../include/Estoque.hpp"
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

Estoque::Estoque()
{
}

Estoque::~Estoque()
{
    for (Filme *filme : estoque)
    {
        delete filme;
    }

    estoque.clear();
}

void Estoque::lerArquivo(const std::string diretorio)
{
    std::ifstream arquivo(diretorio, std::ios::in);

    if (!arquivo.is_open()) {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    int total = 0;
    char tipo;
    std::string titulo, linha;
    int unidades, identificador;

    while(std::getline(arquivo,linha)) {
    
        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo

        std::istringstream iss(linha);
        // é um stream de input baseado em uma string

        if(!(iss >> tipo >> unidades >> identificador)) continue; // caso a ordem não tenha sido respeitada, ou tenha dado erro
        if(!(std::getline(iss >> std::ws, titulo))) continue;

        Filme *novo_filme = nullptr;

        if (tipo == 'F') novo_filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
        
        else if(tipo == 'D') {
            int categoria = separarTituloCategoria(titulo);
            if(categoria == -1) continue;// Caso alguma categoria tenha sido encontrada
            removerEspacosDireitaEsquerda(titulo);
            novo_filme = new DVD(unidades,identificador,titulo,categoria);
        
            
        }

        if(this->inserirFilme(novo_filme,false)) total++;

    }
    
    
    arquivo.close();
    std::cout << total << " Filmes cadastrados com sucesso" << std::endl;
    this->diretorio = diretorio;
}

bool Estoque::inserirFilme(Filme *novoFilme, bool mensagens)
{   
    // Verifica se os dados inseridos são válidos de acordo com o tipo do filme
    if (novoFilme->getIdentificador() <= 0 || novoFilme->getTitulo() == "")
    {
        if(mensagens) std::cout << "ERRO: dados incorretos" << std::endl;
        return false;
    }

    // Verifica se o código já é usado em outro filme
    for (Filme *filme : this->estoque)
    {
        if (filme->getIdentificador() == novoFilme->getIdentificador())
        {
            if(mensagens) std::cout << "ERRO: identificador repetido" << std::endl;
            return false;
        }
    }

    this->estoque.push_back(novoFilme);
    if(mensagens) std::cout << "Filme " << novoFilme->getIdentificador() << " cadastrado com sucesso" << std::endl;
    return true;
}

void Estoque::removerFilme(const int identificador)
{
    // Percorre o estoque a procura do filme
    auto it = std::remove_if(this->estoque.begin(), this->estoque.end(), [identificador](Filme *filme)
                             { return filme->getIdentificador() == identificador; });

    // Se existir um filme com o código associado, é excluído
    if (it != this->estoque.end())
    {
        this->estoque.erase(it, this->estoque.end());
        std::cout << "Filme " << identificador << " removido com sucesso" << std::endl;
    }
    // Caso contrário, aparece mensagem de erro
    else
    {
        std::cout << "ERRO: identificador inexistente" << std::endl;
    }
}

void Estoque::pesquisarFilmesCodigo(const int identificador) const
{
    // Lista todos os filmes que tem o código informado pelo usuário
    for (Filme *filme : this->estoque)
    {
        if (filme->getIdentificador() == identificador)
        {
            filme->listarInformacoes();
            std::cout << std::endl;
        }
    }
}

void Estoque::pesquisarFilmesTitulo(const std::string titulo) const
{
    // Lista todos os filmes que tem o título informado pelo usuário
    for (Filme *filme : this->estoque)
    {
        if (filme->getTitulo() == titulo)
        {
            filme->listarInformacoes();
            std::cout << std::endl;
        }
    }
}

void Estoque::salvarDados() const
{
    // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
    std::ofstream arquivo(this->diretorio, std::ios::out | std::ios::trunc);
    

    if (!arquivo.is_open()) {
        std::cout << "Erro: não foi possível criar o arquivo" << std::endl;
        return;
    }

    // Percorre a lista de filmes e adiciona no arquivo
    for (Filme *filme : this->estoque)
        arquivo << filme->listarInformacoes() << std::endl;
    

    arquivo.close();
}