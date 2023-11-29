#include "Estoque.hpp"
#include <iostream>
#include <iterator>
#include <fstream> // Operações com arquivos
#include <algorithm>
#include <numeric>
#include <sstream> // Operações com leitura de linha

Estoque::Estoque()
{
    this->lerArquivo(DIRETORIO_PADRAO_FILMES);
}

Estoque::~Estoque()
{
    salvarDados(true);
}

void Estoque::lerArquivo(const std::string diretorio)
{
    try {


        std::ifstream arquivo(diretorio, std::ios::in);
        std::ofstream log (DIRETORIO_LOG_FILMES,std::ios::app);

        if (!arquivo.is_open()) throw std::runtime_error("ERRO: arquivo inexistente");
            
        if (!log.is_open()) throw std::runtime_error("ERRO: não foi possivel encontrar ou criar o arquivo");

        char tipo;
        int total_lidos = 0, total_erros = 0;
        Filme *novo_filme;
        std::string titulo, linha;
        int unidades, identificador;

        while (std::getline(arquivo, linha)) {

            // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
            std::istringstream iss(linha);
            novo_filme = nullptr;
            // é um stream de input baseado em uma string

            iss >> tipo >> unidades >> identificador;

            if(!isTipoValido(tipo)){
                
                log << linha << " - ERRO: tipo inválido" << std::endl;
                total_erros++;
                continue;
            }
            if(!isUnidadesValido(unidades)) {
                log << linha << " - ERRO: unidades inválido" << std::endl;
                total_erros++;
                continue;
            }
                
            if(!isIdentificadorValido(identificador)) {
                log << linha << " - ERRO: Identificador invalido" << std::endl;
                total_erros++;
                continue;
            }
                
            if(this->filmeExiste(identificador)) {
                log << linha << " - ERRO: Identificador repetido" << std::endl;
                total_erros++;
                continue;
            }

            if(tipo == Tipo_Filme.at(TIPO_FITA)) {
                std::getline(iss >> std::ws, titulo);

                if(titulo.empty()) {
                    log << linha << " - ERRO: Nome vazio" << std::endl;
                    total_erros++;
                    continue;
                }

                novo_filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
            }

            else if (tipo == Tipo_Filme.at(TIPO_DVD))
            {

                std::string palavra;
                std::vector<std::string> palavras;
                while (iss >> palavra)
                    palavras.push_back(palavra); // As palavras são separadas em um arranjo

                // A ultima palavra corresponde a categoria do DVD
                int indiceCategoria = isCategoriaValido(palavras.back()[0]);
                if(indiceCategoria == -1) {
                    log << linha << " - ERRO: categoria invalida" << std::endl;
                    total_erros++;
                    continue;
                }
                
                palavras.pop_back();
                
                std::ostringstream concatenar;
                for (std::vector<std::string>::iterator it = palavras.begin(); it != palavras.end(); it++) {
                    concatenar << *(it);
                    if(it != palavras.end()-1) concatenar << " "; // Assim não é adicionado um ultimo espaço na ultima palavra
                } 


                titulo = concatenar.str();
                
                if(titulo.empty()) {
                    log << linha << " - ERRO: Nome vazio" << std::endl;
                    total_erros++;
                    continue;
                }
                
                palavras.clear();

                novo_filme = new DVD(unidades, identificador, titulo, indiceCategoria);
            }

            this->inserirFilme(novo_filme);
            total_lidos++;
        }

        log.close();
        arquivo.close();

        if(total_lidos) std::cout << total_lidos << " Filmes cadastrados com sucesso" << std::endl;
        if(total_erros) std::cout << total_erros << " Filmes geraram erro" << std::endl;

     
    } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
    } 
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

    else if (this->filmeExiste(novoFilme->getIdentificador()) != nullptr)
    {
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

    if (erro)
    {
        delete novoFilme;
        return false;
    }

    this->_estoque.push_back(novoFilme);
    return true;
}

void Estoque::removerFilme(const int identificador)
{
    // Percorre o estoque a procura do filme
    std::vector<Filme *>::iterator it = std::remove_if(this->_estoque.begin(), this->_estoque.end(), [identificador](Filme *filme)
                                                       { return filme->getIdentificador() == identificador; });
    delete *it;
    this->_estoque.erase(it, this->_estoque.end());
        
    
    
}

void Estoque::pesquisarFilmesCodigo(const int identificador) const
{
    // Lista todos os filmes que tem o identificador informado pelo usuário
    for (Filme *filme : this->_estoque)
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
    for (Filme *filme : this->_estoque)
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

void Estoque::listarFilmesOrdenados(const std::string ordenacao) const {
    std::vector<Filme *> filmes_ordenados = this->_estoque;
    std::sort(filmes_ordenados.begin(), filmes_ordenados.end(), COMPARADORES_FILME.at(ordenacao));

    for (Filme *filme : filmes_ordenados)
    {
        std::cout << filme->getIdentificador() << " " << filme->getTitulo()
                    << " " << filme->getUnidades() << " " << Tipo_Filme.at(filme->getTipo()) << " ";

        if (filme->getTipo() == TIPO_DVD)
        {
            DVD *dvd = dynamic_cast<DVD *>(filme);
            std::cout << aux_Categorias.at(dvd->getCategoria());
            // Downcasting para usar a função getCategoria
        }

        std::cout << std::endl;
    }

}

Filme *Estoque::filmeExiste(const int identificador) const
{
    for (Filme *filme : this->_estoque)
    {
        if (filme->getIdentificador() == identificador)
            return filme;
    }

    return nullptr;
}

Filme *Estoque::filmeValido(const int identificador) const
{
    Filme *filme = filmeExiste(identificador);

    if (filme != nullptr)
    {
        if (filme->getUnidades() > 0)
            return filme;

        else
        {
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
    try {
    
        std::ofstream arquivo(DIRETORIO_PADRAO_FILMES, std::ios::out | std::ios::trunc);

        if (!arquivo.is_open()) throw std::runtime_error("Erro: não foi possível criar o arquivo");

        std::chrono::system_clock::time_point agora = std::chrono::system_clock::now();
        std::time_t tempo = std::chrono::system_clock::to_time_t(agora);

        // Cria uma estrutura de tempo local
        std::tm *horaLocal = std::localtime(&tempo);

        // Formata a data e a hora como uma string
        std::ostringstream oss;
        oss << std::put_time(horaLocal, "%d-%m-%Y %H_%M_%S");

        std::string caminho_copia = DIRETORIO_HISTORICO_FILMES + "filmes " + oss.str();
        std::ofstream copia(caminho_copia, std::ios::out | std::ios::trunc);
        // Cria um arquivo com o nome sendo a data atual

        if (!copia.is_open()) throw std::runtime_error("ERRO: não foi possivel criar o arquivo copia");

        if (limparDados)
        {

            for (Filme *filme : _estoque)
            {
                arquivo << filme->listarInformacoes() << std::endl;
                copia << filme->listarInformacoes() << std::endl;
                delete filme;
            }

            this->_estoque.clear();
        }

        // Percorre a lista de filmes e adiciona no arquivo
        else
            for (Filme *filme : this->_estoque) {
                arquivo << filme->listarInformacoes() << std::endl;
                copia << filme->listarInformacoes() << std::endl;
            }
                

        arquivo.close();
        copia.close();

    } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
    }

}
