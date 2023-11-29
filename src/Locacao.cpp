#include "Locacao.hpp"

int Locacao::_numeroLocacoes = 0;

Locacao::Locacao() {}

// Metodos privados da classe

void Locacao::removeLocacao(int posNoVetorLocacoes)
{
    _locacoes.erase(_locacoes.begin() + posNoVetorLocacoes);
}

int Locacao::getPosicaoLocacaoVetorLocacoes(LocacaoData* locacao)
{
    for (std::vector<LocacaoData>::size_type i = 0; i < _locacoes.size(); i++)
    {
        if (&this->_locacoes[i] == locacao)
            return i;
    }
    return -1;
}

LocacaoData Locacao::getLocacao(std::string CPF, Filme *filme)
{
    for (LocacaoData i : this->_locacoes)
        if (i._CPFCliente == CPF && i._filme->getIdentificador() == filme->getIdentificador())
            return i;
    throw std::runtime_error("\nERRO: este filme nao esta alugado por tal cliente"); // Erro

}

// Métodos para arquivos

void Locacao::salvarLocacaoPendentes()                                          // Atualiza arquivo locações pendentes para o estado atual do sistema
{

    // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
    std::ofstream arquivo(DIRETORIO_LOCACOES_PENDENTES, std::ios::out | std::ios::trunc);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: nao foi possivel criar/encontrar o arquivo para salvar locacao" << std::endl;
        return;
    }

    for (LocacaoData locacao : this->_locacoes){
        arquivo << locacao._filme->getIdentificador() << " " << locacao._filme->getTitulo() << " " << locacao._CPFCliente << " " << locacao._diasAlugados << std::endl;
    }

    arquivo.close();
}

void Locacao::salvarLocacaoLog(Filme *filme, std::string CPF, int dias, int valorMultas)
{
    std::vector<LocacaoLogData> logLocacoes = this->leituraLocacaoLog();
    LocacaoLogData novaLocacao;
    novaLocacao._nomeFilme = filme->getTitulo();
    novaLocacao._CPFCliente = CPF;
    novaLocacao._identificadorFilme = filme->getIdentificador();
    novaLocacao._diasAlugados = dias;
    novaLocacao._multaPaga = valorMultas;

    logLocacoes.push_back(novaLocacao);

    // Abre o arquivo em modo de escrita e limpo de qualquer frase que continha
    std::ofstream arquivo(DIRETORIO_HISTORICO_LOCACOES, std::ios::out | std::ios::trunc);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: nao foi possivel criar/encontrar o arquivo para salvar locacao finalizada" << std::endl;
        return;
    }

    for (auto locacao : logLocacoes)
        arquivo << locacao._identificadorFilme << " " << locacao._nomeFilme << " " << locacao._CPFCliente << " " << locacao._diasAlugados << " " << locacao._multaPaga << std::endl;
    
    arquivo.close();
}

std::vector<LocacaoData> Locacao::leituraLocacoesPendentes(){
    std::ifstream arquivo(DIRETORIO_LOCACOES_PENDENTES, std::ios::in);

    std::vector<LocacaoData> locacoesPendentes;

    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo de locacoes pendentes inexistente" << std::endl;
    }

    std::string linha, palavra, CPFCliente, nomeFilme;
    std::vector<std::string> palavras;
    int identificadorFilme, dias;
    int total = 0;

    while (std::getline(arquivo, linha))
    {

        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
        std::istringstream iss(linha);

        // é um stream de input baseado em uma string
        iss >> identificadorFilme;
        while (iss >> palavra)
            palavras.push_back(palavra); // Todas as palavras pós cpf são separadas em um vetor,
        // devido ao fato de não sabermos a quantidade de palavras do nome
        dias = std::stoi(palavras.back());
        palavras.pop_back();
        CPFCliente = palavras.back();
        palavras.pop_back();
        nomeFilme = std::accumulate(palavras.begin(), palavras.end(), std::string(), [](const std::string &texto, const std::string &palavra)
                                    { return texto + (texto.empty() ? "" : " ") + palavra; }); // União das palavras do nome do filme, com a adição do espaço entre as palavras
        palavras.clear();

        LocacaoData loc;
        loc._CPFCliente = CPFCliente;
        loc._filme = _estoque->filmeExiste(identificadorFilme);
        loc._diasAlugados = dias;

        locacoesPendentes.push_back(loc);

        total++;
    }

    arquivo.close();
    if (total)
        std::cout << total << " locacoes pendentes lidas com sucesso" << std::endl;

    return locacoesPendentes;
}

std::vector<LocacaoLogData> Locacao::leituraLocacaoLog()
{
    std::ifstream arquivo(DIRETORIO_HISTORICO_LOCACOES, std::ios::in);

    std::vector<LocacaoLogData> logLocacoes;

    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo de historico de locacoes inexistente" << std::endl;
        return logLocacoes;
    }

    std::string linha, palavra, CPFCliente, nomeFilme;
    std::vector<std::string> palavras;
    int identificadorFilme, dias, multaPaga;

    while (std::getline(arquivo, linha))
    {
        LocacaoLogData leitura;

        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
        std::istringstream iss(linha);

        // é um stream de input baseado em uma string
        iss >> identificadorFilme;
        while (iss >> palavra)
            palavras.push_back(palavra); // Todas as palavras pós cpf são separadas em um vetor,
        // devido ao fato de não sabermos a quantidade de palavras do nome
        multaPaga = std::stoi(palavras.back());
        palavras.pop_back();
        dias = std::stoi(palavras.back());
        palavras.pop_back();
        CPFCliente = palavras.back();
        palavras.pop_back();
        nomeFilme = std::accumulate(palavras.begin(), palavras.end(), std::string(), [](const std::string &texto, const std::string &palavra)
                                    { return texto + (texto.empty() ? "" : " ") + palavra; }); // União das palavras do nome do filme, com a adição do espaço entre as palavras
        palavras.clear();

        leitura._nomeFilme = nomeFilme;
        leitura._CPFCliente = CPFCliente;
        leitura._identificadorFilme = identificadorFilme;
        leitura._diasAlugados = dias;
        leitura._multaPaga = multaPaga;

        logLocacoes.push_back(leitura);
    }

    arquivo.close();

    return logLocacoes;
}

// Metodos publicos da classe

void Locacao::associarPtrEstoque(Estoque* estoque){
    _estoque = estoque;
    _locacoes = this->leituraLocacoesPendentes();
}

int Locacao::getLocacoesPorCliente(std::string CPF)
{
    int soma = 0;
    for (LocacaoData i : this->_locacoes)
        if (i._CPFCliente == CPF)
            soma++;
    return soma;
}

float Locacao::alugar(std::string CPF, std::vector<Filme *> filmes, int dias)
{
    
    float valorAluguel = 0;

    for (Filme *f : filmes)
    {
        try{
            f->removerUnidades();
            LocacaoData loc;
            loc._CPFCliente = CPF;
            loc._filme = f;
            loc._diasAlugados = dias;
            this->_locacoes.push_back(loc);
            this->_numeroLocacoes++;
            valorAluguel += f->calculoPrecoLocacao(dias);
        } catch (const std::runtime_error& e){
            std::cout << "\nFilme: " << f->getTitulo() << " nao foi alugado" << std::endl; 
        }
        
    }

    this->salvarLocacaoPendentes(); // Atualizar arquivo

    std::cout << "Aluguel de " << dias << " dias foi aprovado para o CPF: " << CPF << std::endl;
    std::cout << "Valor a ser cobrado: " << std::setprecision(2) << std::fixed << valorAluguel << std::endl;

    return valorAluguel;
}

int Locacao::devolucao(std::string CPF, Filme *filme, int dias, bool isDanificado)
{
    int valorMultas = 0;
    try{
        LocacaoData locacao = this->getLocacao(CPF, filme);

        int diasAlugados = locacao._diasAlugados;
        if (diasAlugados < dias)
        { // Multa por atraso (calculo linear da multa)
            valorMultas += (dias - diasAlugados) * 2;
        }

        if (isDanificado == true)
            valorMultas += 20; // Multa por danificação do produto

        filme->adicionarUnidades();
        this->removeLocacao(getPosicaoLocacaoVetorLocacoes(&locacao));
        this->salvarLocacaoPendentes(); // Atualizar arquivo
        this->salvarLocacaoLog(filme, CPF, dias, valorMultas); // Salvando log

        return valorMultas;
    
    } catch(const std::runtime_error& e) {
        throw e;
    }
}

bool Locacao::verificarFilmeAlugado(int identificador)
{
    for(LocacaoData locacao : this->_locacoes)
        if(locacao._filme->getIdentificador() == identificador) return true;
    return false;
}

void Locacao::relatorio()
{
    std::cout << "Imprimindo relatorio das locacoes pendentes...\n\n";

    for (LocacaoData locacao : this->_locacoes)
    {
        std::cout << "\t" << locacao._CPFCliente << " - " << locacao._filme->getIdentificador() << " " << locacao._filme->getTitulo() << " dias: " << locacao._diasAlugados << std::endl;
    }
}

void Locacao::historicoLocacoes()
{
    std::vector<LocacaoLogData> logLocacoes = this->leituraLocacaoLog();
    for (LocacaoLogData locacao : logLocacoes)
    {
        std::cout << "\t" << locacao._identificadorFilme << " - " << locacao._CPFCliente << " - " << locacao._nomeFilme << " - dias: " << locacao._diasAlugados << " - multa paga: " << locacao._multaPaga << std::endl;
    }
}