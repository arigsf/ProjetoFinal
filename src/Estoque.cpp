#include "../include/Estoque.hpp"
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <sstream>

/**
 * @file Estoque.cpp
 * @brief Implementação da classe Estoque.
 */

Estoque::Estoque() {}

Estoque::~Estoque()
{
    salvarDados(true);
}

void Estoque::lerArquivo(const std::string diretorio)
{
    std::ifstream arquivo(diretorio, std::ios::in);

    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    
    char tipo;
    int total = 0;
    Filme *novo_filme;
    std::string titulo, linha;
    int unidades, identificador;
    

    while (std::getline(arquivo, linha))
    {
        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
        std::istringstream iss(linha);
        novo_filme = nullptr;
        // é um stream de input baseado em uma string

        iss >> tipo >> unidades >> identificador;

        if(tipo == Tipo_Filme.at(TIPO_FITA)) {
            std::getline(iss >> std::ws, titulo);
            novo_filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
        }


        else if(tipo == Tipo_Filme.at(TIPO_DVD)) {

            std::string palavra;
            std::vector<std::string> palavras;
            while (iss >> palavra) palavras.push_back(palavra); // As palavras são separadas em um arranjo

            // A ultima palavra corresponde a categoria do DVD
            int indice_categoria = -1;
            for (std::map<int,std::string>::const_iterator it = Categorias.begin(); it != Categorias.end();it++)
                if(it->second == palavras.back()) {
                    indice_categoria = it->first;
                    break;
                } 
            
            if(indice_categoria != -1) palavras.pop_back();

            titulo = std::accumulate(palavras.begin(), palavras.end(), std::string());
            palavras.clear();

            novo_filme = new DVD(unidades,identificador,titulo,indice_categoria);
        }

        if (this->inserirFilme(novo_filme))
            total++;
    }

    arquivo.close();
    std::cout << total << " Filmes cadastrados com sucesso" << std::endl;
    this->diretorio = diretorio;
}

bool Estoque::inserirFilme(Filme *novoFilme)
{
    bool erro = false;
    // Verifica se os dados inseridos são válidos de acordo com o tipo do filme
    if (novoFilme->getIdentificador() <= 0 || novoFilme->getTitulo() == "")
    {
        std::cout << "ERRO: dados incorretos" << std::endl;
        erro = true;
    }

    // Verifica se o código já é usado em outro filme
    
    else if(this->filmeExiste(novoFilme->getIdentificador()) != nullptr) {
        std::cout << "ERRO: identificador repetido" << std::endl;
        erro = true;
    }

    else if (novoFilme->getTipo() == TIPO_DVD)
    {
        DVD *dvd = dynamic_cast<DVD *>(novoFilme);
        if (Categorias.find(dvd->getCategoria()) == Categorias.end())
        {
            std::cout << "ERRO: categoria inválida" << std::endl;
            erro = true;
        }
    }

    if(erro) {
        delete novoFilme;
        return false;
    }

    this->estoque.push_back(novoFilme);
    std::cout << "Filme " << novoFilme->getIdentificador() << " cadastrado com sucesso" << std::endl;
    return true;
}

void Estoque::removerFilme(const int identificador)
{
    // Percorre o estoque a procura do filme
    std::vector<Filme*>::iterator it = std::remove_if(this->estoque.begin(), this->estoque.end(), [identificador](Filme *filme)
                             { return filme->getIdentificador() == identificador; });

    // Se existir um filme com o código associado, é excluído
    if (it != this->estoque.end())
    {
        delete *it;
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
    // Lista todos os filmes que tem o identificador informado pelo usuário
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
    // Lista todos os filmes que tem o título ou parte dele informado pelo usuário
    for (Filme *filme : this->estoque)
    {
        std::string tituloFilme = filme->getTitulo();
        std::transform(tituloFilme.begin(), tituloFilme.end(), tituloFilme.begin(), ::tolower);
        std::string tituloDesejado = titulo;
        std::transform(tituloDesejado.begin(), tituloDesejado.end(), tituloDesejado.begin(), ::tolower);

        // Verifica se a substring está contida no título do filme
        if (tituloFilme.find(tituloDesejado) != std::string::npos)
        {
            filme->listarInformacoes();
            std::cout << std::endl;
        }
    }
}

void Estoque::listarFilmesOrdenados(const std::string ordenacao) const
{

    if (COMPARADORES_FILME.find(ordenacao) != COMPARADORES_FILME.end())
    {
        std::vector<Filme *> filmes_ordenados = this->estoque;
        std::sort(filmes_ordenados.begin(), filmes_ordenados.end(), COMPARADORES_FILME.at(ordenacao));

        for (Filme *filme : filmes_ordenados)
        {
            std::cout << filme->getIdentificador() << " " << filme->getTitulo()
                      << " " << filme->getUnidades() << " " << Tipo_Filme.at(filme->getTipo()) << " ";

            if (filme->getTipo() == TIPO_DVD)
            {
                DVD *dvd = dynamic_cast<DVD *>(filme);
                std::cout << Categorias.at(dvd->getCategoria());
                // Downcasting para usar a função getCategoria
            }

            std::cout << std::endl;
        }
    }
    else
        std::cout << "Erro: opção inexistente" << std::endl;
}

Filme* Estoque::filmeExiste(const int identificador) const {
    for (Filme *filme : this->estoque) {
        if(filme->getIdentificador() == identificador) return filme;
    }

    return nullptr;
}

Filme *Estoque::filmeValido(const int identificador) const
{
    Filme* filme = filmeExiste(identificador);

    if(filme != nullptr) {
        if(filme->getUnidades() > 0) return filme;

        else { 
            std::cout << "Filme: " << filme->getTitulo() << "nao disponivel." << std::endl;
            return nullptr;
        }
    } 

    std::cout << "ERRO: Id inválido" << std::endl; 
    return nullptr;
}

void Estoque::salvarDados(const bool limparDados) // O parametro limpardados decide, se após dos dados serem salvos eles devem ser desalocados
{
    // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
    std::ofstream arquivo(this->diretorio, std::ios::out | std::ios::trunc);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: não foi possível criar o arquivo" << std::endl;
        return;
    }

    if(limparDados) {
        
        for (Filme *filme : estoque) {
            arquivo << filme->listarInformacoes() << std::endl;
            delete filme;
        }

        this->estoque.clear();
    }

    // Percorre a lista de filmes e adiciona no arquivo
    else
        for (Filme *filme : this->estoque)
            arquivo << filme->listarInformacoes() << std::endl;

    arquivo.close();
}