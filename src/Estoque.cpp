#include "Estoque.hpp"
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

    char tipo_item;
    int unidades_item, categoria_dvd, identificador_item, total = 0;
    std::string titulo_item;

    while (arquivo >> tipo_item >> unidades_item >> identificador_item) {
        total++;
        getline(arquivo, titulo_item);

        if (tipo_item == 'D') {

            categoria_dvd = separarTituloCategoria(titulo_item);
            DVD *novo_dvd = new DVD(unidades_item,identificador_item,titulo_item,categoria_dvd);
            this->estoque.push_back(novo_dvd);

            
        }
        else if(tipo_item == 'F') {
            FITA *nova_fita = new FITA(unidades_item,identificador_item,titulo_item, true);
            this->estoque.push_back(nova_fita);
        }

    }
    
    arquivo.close();
    std::cout << total << " Filmes cadastrados com sucesso" << std::endl;
    this->diretorio = diretorio;
}

void Estoque::inserirFilme(Filme *novoFilme)
{
    // Verifica se os dados inseridos são válidos de acordo com o tipo do filme
    if (novoFilme->getIdentificador() <= 0 || novoFilme->getTitulo() == "")
    {
        std::cout << "ERRO: dados incorretos" << std::endl;
        return;
    }

    // Verifica se o código já é usado em outro filme
    for (Filme *filme : this->estoque)
    {
        if (filme->getIdentificador() == novoFilme->getIdentificador())
        {
            std::cout << "ERRO: identificador repetido" << std::endl;
            return;
        }
    }

    this->estoque.push_back(novoFilme);
    std::cout << "Filme " << novoFilme->getIdentificador() << " cadastrado com sucesso" << std::endl;
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