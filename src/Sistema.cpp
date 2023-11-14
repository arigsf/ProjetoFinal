#include "../include/Sistema.hpp"

void Sistema::lerArquivo() {
    std::string diretorio;
    std::cin >> diretorio;
    this->estoque.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme() {
    
    char tipo;
    std::string titulo;
    int unidades, identificador;
    std::cin >> tipo >> unidades >> identificador >> titulo;

    if(tipo == 'D') {
        std::string categoria;
        std::cin >> categoria;
        DVD *novo_dvd = new DVD(unidades,identificador,titulo,getCategoria(categoria));
        this->estoque.inserirFilme(novo_dvd);

    }

    else if(tipo == 'F') {
        FITA *nova_fita = new FITA(unidades,identificador,titulo,true);
        this->estoque.inserirFilme(nova_fita);
    }
}

void Sistema::removerFilme() {
    int identificador;
    std::cin >> identificador;
    this->estoque.removerFilme(identificador);
}

void Sistema::listarFIlmes() {
    // char ordem;
    // std::cin >> ordem;

}


void Sistema::finalizarSistema() {
    this->estoque.salvarDados();
    
}