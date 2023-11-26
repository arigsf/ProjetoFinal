#include "Locacao.hpp"

int Locacao::numeroLocacoes = 0;

const std::string DIRETORIO_HISTORICO_LOCACOES = "./data/Locacoes/historico_Locacoes";

Locacao::Locacao(){}

// Metodos privados da classe

void Locacao::removeLocacao(int posNoVetorLocacoes){
    locacoes.erase(locacoes.begin() + posNoVetorLocacoes);
}

int Locacao::getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme*, int>> locacao){
    for(int i = 0; i<locacoes.size(); i++){
        if(&(this->locacoes[i]) == &locacao) return i;
    }
    return -1;
}

std::pair<std::string, std::pair<Filme*, int>> Locacao::getLocacao(std::string CPF, Filme* filme){
    for(auto i : this->locacoes) if(i.first == CPF && i.second.first->getIdentificador() == filme->getIdentificador()) return i;
    // Implementar tratamento de erro.....
    return std::pair<std::string, std::pair<Filme*, int>> ("AAAAA", std::pair<Filme*, int>(filme, 0)); // Momentaneo (a ser removido do projeto)
}

// Log Locações

void Locacao::salvarLocacaoLog(Filme* filme, std::string CPF, int dias, int valorMultas){

}

std::vector<std::pair<std::vector<std::string>, std::vector<int>>> Locacao::leituraLocacaoLog(){
    std::ifstream arquivo(DIRETORIO_HISTORICO_LOCACOES, std::ios::in);

    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> logLocacoes;

    if (!arquivo.is_open())
    {
        std::cout << "ERRO: arquivo de historico de locações inexistente" << std::endl;
        return logLocacoes;
    }

    std::string linha, palavra, CPFCliente, nomeFilme;
    std::vector<std::string> palavras;
    int identificadorFilme, dias, multaPaga, total;

    while (getline(arquivo,linha)) {
        // Formato (par) par1 -> (nomeFilme, CPFCliente); par2 -> (identificadorFilme, dias, multaPaga)
        std::pair<std::vector<std::string>, std::vector<int>> parLeitura;

        // retorna nullpointer caso houve falha na leitura da linha, ou caso seja o final do arquivo
        std::istringstream iss(linha);

        // é um stream de input baseado em uma string
        iss >> identificadorFilme;
        while (iss >> palavra) palavras.push_back(palavra); // Todas as palavras pós cpf são separadas em um vetor,
        // devido ao fato de não sabermos a quantidade de palavras do nome
        multaPaga = std::stoi(palavras.back()); palavras.pop_back();
        dias = std::stoi(palavras.back()); palavras.pop_back();
        CPFCliente = palavras.back(); palavras.pop_back();
        nomeFilme = std::accumulate(palavras.begin(), palavras.end(), std::string(), [](const std::string& texto, const std::string& palavra) {
            return texto + (texto.empty() ? "" : " ") + palavra;
        }); // União das palavras do nome do filme, com a adição do espaço entre as palavras    
        palavras.clear();
        
        parLeitura.first.push_back(nomeFilme);
        parLeitura.first.push_back(CPFCliente);
        parLeitura.second.push_back(identificadorFilme);
        parLeitura.second.push_back(dias);
        parLeitura.second.push_back(multaPaga);

        logLocacoes.push_back(parLeitura);

        total++;
    }

    arquivo.close();
    if(total) std::cout << total << " logs de locacoes lidos com sucesso" << std::endl;

    return logLocacoes;
}

// Metodos publicos da classe

int Locacao::getLocacoesPorCliente(std::string CPF){
    int soma = 0;
    for(auto i : this->locacoes) if(i.first == CPF) soma++;
    return soma;
}

void Locacao::alugar(std::string CPF, std::vector<Filme*>filmes, int dias) {
    if(!verificarCPFmaxFilmes(CPF, size(filmes))){
        float valorAluguel = 0;

        for(Filme* f : filmes){
            f->removerUnidades();
            // Implementar tratamento de erro (se não há filmes)
            this->locacoes.push_back(std::pair<std::string, std::pair<Filme*, int>> (CPF, std::pair<Filme*, int> (f, dias)));
            this->numeroLocacoes++;
            valorAluguel += f->calculoPrecoLocacao(dias);
        }

        std::cout << "Aluguel de " << dias << " dias foi aprovado para o CPF: " << CPF << std::endl;
        std::cout << "Valor a ser cobrado: " << std::setprecision(2) << std::fixed << valorAluguel << std::endl;

    } else std::cout << "Tal CPF ultrapassara o limite de 10 locacoes pendentes." << std::endl;
}

bool Locacao::verificarCPFmaxFilmes(std::string CPF, int qtdFilmes){ // Verifica se o CPF pode alugar mais itens (qtdFilmes), sem que ultrapasse o limite de 10 locações
    if(qtdFilmes+getLocacoesPorCliente(CPF)>=10) return true;
    return false;
}

int Locacao::devolucao(std::string CPF, Filme* filme, int dias, bool isDanificado){
    int valorMultas = 0;

    auto locacao = this->getLocacao(CPF, filme);
    // Implementar tratamento erro
    int diasAlugados = locacao.second.second;
    if(diasAlugados < dias){ // Multa por atraso (calculo linear da multa)
        valorMultas += (diasAlugados-dias)*2;
    }

    if(isDanificado == true) valorMultas+=20; // Multa por danificação do produto

    // Salvando log
    //this->salvarLocacaoLog(filme, CPF, dias, valorMultas);

    filme->adicionarUnidades();
    this->removeLocacao(getPosicaoLocacaoVetorLocacoes(locacao));

    return valorMultas;
}

void Locacao::relatorio(){
    std::cout << "Imprimindo relatorio das locacoes pendentes...\n\n"; 

    for(std::pair<std::string, std::pair<Filme*, int>> locacao : this->locacoes){
        std::cout << "\t" << locacao.first << " - " << locacao.second.first->getIdentificador() << " " << locacao.second.first->getTitulo() << ";\n";
    }
}

void Locacao::historicoLocacoes(){
    std::vector<std::pair<std::vector<std::string>, std::vector<int>>> logLocacoes = this->leituraLocacaoLog();
    for(auto locacao : logLocacoes){
        std::cout << "\t" << locacao.second[0] << " - " << locacao.first[0] << " - " << locacao.first[1] << " - " << locacao.second[1] << " - " << locacao.second[2] << std::endl;
    }
}