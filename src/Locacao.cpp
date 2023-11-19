#include "../include/Locacao.hpp"

int Locacao::numeroLocacoes = 0;

void Locacao::removeLocacao(int posNoVetorLocacoes){
    locacoes.erase(locacoes.begin() + posNoVetorLocacoes);
}

void Locacao::alugar(std::string CPF, std::vector<Filme*> &filmes){
    if(!verificarCPF(CPF)){

        this->locacoes.push_back(std::pair<std::string, std::vector<Filme*>> (CPF, filmes));
        this->numeroLocacoes++;

        std::cout << "Aluguel aprovado para o CPF: " << CPF << std::endl;

    } else std::cout << "Tal CPF ja esta com uma locacao pendente." << std::endl;
}

bool Locacao::verificarCPF(std::string CPF){ // Verifica se o CPF já está com alguma locação pendente
    for(std::pair<std::string, std::vector<Filme*>> i : this->locacoes) if(i.first == CPF) return true;
    return false;
}

int Locacao::devolucao(std::string CPF, int dias){
    if(verificarCPF(CPF)){
        int somaPrecos = 0;

        for(int i = 0; i < this->numeroLocacoes; i++){
            if(locacoes[i].first == CPF){
                for(Filme *filme : locacoes[i].second){
                    somaPrecos += filme->calculoPrecoLocacao(dias);
                }

                this->removeLocacao(i);
            }
        }


        std::cout << "Devolucao realizada com sucesso, apenas eh necessario o pagamento de " << somaPrecos << " reais." << std::endl;
        return somaPrecos;

    } 
    
    std::cout << "Tal CPF nao possui pendencias com o nosso sistema." << std::endl;
    return 0;
}

void Locacao::relatorio(){
    std::cout << "Imprimindo relatorio das locacoes pendentes...\n\n"; 

    for(std::pair<std::string, std::vector<Filme*>> locacao : locacoes){
        std::cout << locacao.first << " pendencias:\n";
        for(Filme *filme : locacao.second) std::cout << "\t" << filme->getIdentificador() << " " << filme->getTitulo() << ";\n";
    }
}