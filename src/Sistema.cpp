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

void Sistema::alugarFilmes(std::string cpf, std::vector<int> &ids) {

    if(!this->clientes.clienteExiste(cpf)) std::cout << "ERRO: CPF inexistente" << std::endl;
    
    std::vector<Filme*> filmes;
    for (int &i : ids)
    {
        Filme *filme = this->estoque.filmeExiste(i);
        if(filme != nullptr) filmes.push_back(filme);
    }

    this->locacao.alugar(cpf,filmes);
    

}

void Sistema::devolverFilmes(std::string cpf, int dias) {

    if(!this->clientes.clienteExiste(cpf)) std::cout << "ERRO: CPF inexistente" << std::endl;
    this->locacao.devolucao(cpf, dias);

}
