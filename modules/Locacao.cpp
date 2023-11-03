#include "Locacao.hpp"

#include <vector>
#include <string>

Locacao::Locacao() this->numeroLocacoes=0;

void Locacao::alugar(std::string CPF, std::vector<std::string> codigos){
    if(verificarCPF(CPF) == 1){

        this->locacoes.push_back(std::pair<std::string, std::vector<std::string>> (CPF, codigos));
        this->numeroLocacoes++;

        std::cout << "Aluguel aprovado para o CPF: " << CPF << std::endl;

    } else std::cout << "Tal CPF ja esta com uma locacao pendente." << std::endl;
}

int Locacao::verificarCPF(std::string CPF){ // Verifica se o CPF já está com alguma locação pendente
    for(auto i : this->locacoes) if(i.first == CPF) return 0;
    return 1;
}

int Locacao::devolucao(std::string CPF, int dias){
    if(verificarCPF(CPF) == 1){
        int valor = 0;

        for(int i = 0; i<this->numeroLocacoes; i++){
            if(locacoes[i].first == CPF){
                for(auto codigo : locacoes[i].second){
                    // Depende do tipo
                }
            }
        }

    } else std::cout << "Tal CPF nao possui pendencias com o nosso sistema." << std::endl;

    return 0;
}

int Locacao::devolucao(std::string CPF, int dias, int rebobinado){
    int multa = (rebobinado == 1) ? 0 : 2;

    return this->devolucao(CPF, dias) + multa;
}