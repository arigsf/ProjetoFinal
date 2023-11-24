#include "../include/Sistema.hpp"

void Sistema::lerArquivo(const std::string diretorio) {
    this->estoque.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme(Filme *novo_filme) {
    this->estoque.inserirFilme(novo_filme);
}

void Sistema::removerFilme(const int identificador) {
    this->estoque.removerFilme(identificador);
}

void Sistema::listarFilmesOrdenados(const std::string ordenacao) const {
    this->estoque.listarFilmesOrdenados(ordenacao);
}

void Sistema::cadastrarCliente(Cliente *cliente) {
    this->clientes.inserirCliente(cliente);
}

void Sistema::listarClientesOrdenados(const std::string ordenacao) const {
    bool ordem = ordenacao == "C" ;
    this->clientes.listarClientesOrdenados(ordem);
}

void  Sistema::removerCliente(const std::string cpf) {
    this->clientes.removerCliente(cpf);
}

void Sistema::alugarFilmes(std::string cpf, std::vector<int> &ids, const int dias) {

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    std::vector<Filme*> filmes;
    for (int &i : ids)
    {
        Filme *filme = this->estoque.filmeValido(i);
        if(filme != nullptr) filmes.push_back(filme);
    }

    this->locacao.alugar(cpf,filmes,dias);
    

}

void Sistema::devolverFilmes(std::string cpf, std::vector<int> &ids, const int dias) {

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    int valorDaMulta = 0;
    std::vector<Filme*> filmes;
    for (int &i : ids)
    {
        Filme *filme = this->estoque.filmeValido(i);
        if(filme != nullptr){
            bool isDanificado;
            std::cout << "O filme " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta danificado?"<< std::endl;
            std::cin >> isDanificado;
            if(filme->getTipo() == 1) { // Se o filme é fita, precisamos verificar se está rebobinado
                bool isRebobinado;
                std::cout << "A fita " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta rebobinado?"<< std::endl;
                std::cin >> isRebobinado;
                if(!isRebobinado) valorDaMulta += 2;
            }
            valorDaMulta += this->locacao.devolucao(cpf, filme, dias, isDanificado);
            // Implementar tratamento de exceção (se filme não estiver locado)
        }
    }    
    std::cout << "\n\nDevolucoes realizadas com sucesso, valor de multas a serem liquidadas: " << valorDaMulta << std::endl;

}

