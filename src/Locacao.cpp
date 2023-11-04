#include "Locacao.hpp"
#include "Filme.hpp"


Locacao::Locacao() {this->numeroLocacoes=0;}

void Locacao::alugar(std::string CPF, std::vector<Filme> filmes){
    if(verificarCPF(CPF) == 1){

        this->locacoes.push_back(std::pair<std::string, std::vector<Filme>> (CPF, filmes));
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
        int somaPrecos = 0;

        for(int i = 0; i<this->numeroLocacoes; i++){
            if(locacoes[i].first == CPF){
                for(auto filme : locacoes[i].second){
                    somaPrecos += calculoPreco(dias, filme);
                }
            }
        }

        std::cout << "Devolucao realizada com sucesso, apenas eh necessario o pagamento de " << somaPrecos << " reais." << std::endl;

        return somaPrecos;

    } else std::cout << "Tal CPF nao possui pendencias com o nosso sistema." << std::endl;

    return 0;
}


int Locacao::calculoPreco (int dias, Filme filme){
    if (filme.getCategoria() == 0) return 20 * dias;
    
    else if (filme.getCategoria() == 1) return 10 * dias;

    else if (filme.getCategoria() == 2) return 10;

    else if (filme.getCategoria() == 3) return (filme.isRebobinado()) ? 5 : 7;
}

void Locacao::relatorio(){
    std::cout << "Imprimindo relatorio das locacoes pendentes...\n\n"; 

    for(auto locacao : locacoes){
        std::cout << locacao.first << " pendencias:\n";
        for(auto filme : locacao.second) std::cout << "\t" << filme.getIdentificador() << " " << filme.getTitulo() << ";\n";
    }
}