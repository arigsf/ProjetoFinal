#include "../include/Locacao.hpp"

int Locacao::numeroLocacoes = 0;

void Locacao::removeLocacao(int posNoVetorLocacoes){
    locacoes.erase(locacoes.begin() + posNoVetorLocacoes);
}

int Locacao::getPosicaoLocacaoVetorLocacoes(std::pair<std::string, std::pair<Filme*, int>> locacao){
    for(int i = 0; i<locacoes.size(); i++){
        if(&(this->locacoes[i]) == &locacao) return i;
    }
}

std::pair<std::string, std::pair<Filme*, int>> Locacao::getLocacao(std::string CPF, Filme* filme){
    for(auto i : this->locacoes) if(i.first == CPF && i.second.first->getIdentificador() == filme->getIdentificador()) return i;
    // Implementar tratamento de erro.....
    return std::pair<std::string, std::pair<Filme*, int>> ("AAAAA", std::pair<Filme*, int>(filme, 0)); // Momentaneo (a ser removido do projeto)
}

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