#include "../include/Estoque.hpp"
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

void Estoque::inserirFilme(Filme *novoFilme)
{
    // Verifica se os dados inseridos são válidos de acordo com o tipo do filme
    if (novoFilme->getTipo() == TIPO_DVD)
    {
        if (novoFilme->getIdentificador() <= 0 || novoFilme->getTitulo() == "")
        {
            std::cout << "ERRO: dados incorretos" << std::endl;
            return;
        }
    }

    // Verifica se o código já é usado em outro filme
    for (Filme *filme : this->estoque)
    {
        if (filme->getIdentificador() == novoFilme->getIdentificador())
        {
            std::cout << "ERRO: codigo repetido" << std::endl;
            return;
        }
    }

    this->estoque.push_back(novoFilme);
    std::cout << "Filme " << novoFilme->getIdentificador() << " cadastrado com sucesso" << std::endl;
}

void Estoque::removerFilme(int codigo)
{
    // Percorre o estoque a procura do filme
    auto it = std::remove_if(this->estoque.begin(), this->estoque.end(), [codigo](Filme *filme)
                             { return filme->getIdentificador() == codigo; });

    // Se existir um filme com o código associado, é excluído
    if (it != this->estoque.end())
    {
        this->estoque.erase(it, this->estoque.end());
        std::cout << "Filme " << codigo << " removido com sucesso" << std::endl;
    }
    // Caso contrário, aparece mensagem de erro
    else
    {
        std::cout << "ERRO: codigo inexistente" << std::endl;
    }
}

void Estoque::pesquisarFilmesCodigo(int codigo)
{
    // Lista todos os filmes que tem o código informado pelo usuário
    for (Filme *filme : this->estoque)
    {
        if (filme->getIdentificador() == codigo)
        {
            filme->imprimir();
            std::cout << std::endl;
        }
    }
}

void Estoque::pesquisarFilmesTitulo(std::string titulo)
{
    // Lista todos os filmes que tem o título informado pelo usuário
    for (Filme *filme : this->estoque)
    {
        if (filme->getTitulo() == titulo)
        {
            filme->imprimir();
            std::cout << std::endl;
        }
    }
}