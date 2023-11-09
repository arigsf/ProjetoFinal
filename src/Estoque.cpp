#include "../include/Estoque.hpp"
#include "Estoque.hpp"
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

void Estoque::lerArquivo(std::string diretorio)
{
    std::ifstream arquivo(diretorio, std::ios::in);

    // Verifica se o arquivo existe
    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    std::vector<Filme *> filmes;
    char tipo;
    int quantidade, codigo, total = 0;
    std::vector<std::string> categorias_dvd = {"Lançamento", "Promoção", "Estoque"};
    std::string titulo, categoria_dvd, linha;

    // Grava os dados na variável
    while (arquivo >> tipo >> quantidade >> codigo)
    {
        total++;

        getline(arquivo, linha);

        if (tipo == 'D')
        {
            for (std::string categoria : categorias_dvd)
            {
                size_t pos = linha.find(categoria);
                if (pos != std::string::npos)
                {
                    categoria_dvd = categoria;
                    linha.erase(pos, categoria.length());
                    linha.erase(0, linha.find_first_not_of(' '));
                    linha.erase(linha.find_last_not_of(' ') + 1);
                    titulo = linha;
                    break;
                }
            }

            DVD *filme = new DVD(quantidade, codigo, titulo, 1);
            filmes.push_back(filme);
        }

        else
        {
            categoria_dvd = nullptr;
            titulo = linha;

            FITA *filme = new FITA(quantidade, codigo, titulo, 1);
            filmes.push_back(filme);
        }
    }
    std::cout << total << " Filmes cadastrados com sucesso" << std::endl;
    arquivo.close();

    this->estoque = filmes;
    this->diretorio = diretorio;
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

std::vector<Filme *> Estoque::pesquisarFilmesCodigo(int codigo)
{
    // Lista todos os filmes que tem o código informado pelo usuário
    for (Filme* filme : this->estoque)
    {
        if (filme->getIdentificador() == codigo)
        {
            filme->imprimir();
            std::cout << std::endl;
        }
    }
}

std::vector<Filme *> Estoque::pesquisarFilmesTitulo(std::string titulo)
{
    // Lista todos os filmes que tem o título informado pelo usuário
    for (Filme* filme : this->estoque)
    {
        if (filme->getTitulo() == titulo)
        {
            filme->imprimir();
            std::cout << std::endl;
        }
    }
}