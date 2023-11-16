#include "../include/Sistema.hpp"

void Sistema::lerArquivo(const std::string diretorio) {
    this->estoque.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme(Filme *novo_filme) {
    this->estoque.inserirFilme(novo_filme, true);
}

void Sistema::removerFilme(const int identificador) {
    this->estoque.removerFilme(identificador);
}

void Sistema::listarFilmesOrdenados(bool porIndentificador) const {
    this->estoque.listarFilmesOrdenados(porIndentificador);
}


void Sistema::finalizarSistema() {
    this->estoque.salvarDados();
    
}