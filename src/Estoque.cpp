#include "./Estoque.hpp"
#include "Estoque.hpp"
#include <iostream>
#include <iterator>
#include <fstream>

void Estoque::lerArquivo(std::string diretorio)
{
    std::ifstream arquivo(diretorio, std::ios::in);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: arquivos inexistente" << std::endl;
        return;
    }

    std::vector<Filme> filmes;
    char tipo;
    int quantidade, codigo, total = 0;
    std::vector<std::string> categorias_dvd = {"Lançamento", "Promoção", "Estoque"};
    std::string titulo, categoria_dvd, linha;

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
        }

        else
        {
            categoria_dvd = nullptr;
            titulo = linha;
        }

        Filme filme(tipo, quantidade, codigo, titulo, categoria_dvd);
        filmes.push_back(filme);
    }
    std::cout << total << " Filmes cadastrados com sucesso" << std::endl;
    arquivo.close();

    this->estoque = filmes;
}

void Estoque::inserirFilme(Filme filme)
{
}

void Estoque::removerFilme(int codigo)
{
}

std::vector<Filme> Estoque::pesquisarFilmes(std::string filtro)
{
}

void Estoque::imprimirRelatiorio()
{
}