#include "../include/Filme.hpp"

Filme::Filme (int _unidades, int _identificador, std::string _titulo) : 
    unidades(_unidades), identificador(_identificador), titulo(_titulo) {}


DVD::DVD (int _unidades, int _identificador, std::string _titulo, int _categoria) : 
    Filme (_unidades, _identificador, _titulo) {
        this->categoria = _categoria;
        this->tipo = TIPO_DVD;
        std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl; 
    }

FITA::FITA (int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado):
    Filme (_unidades, _identificador, _titulo) {
        this->estaRebobinado = _estaRebobinado;
        this->tipo = TIPO_FITA;
        std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;  
    }

int Filme::getIdentificador(){ return this->identificador; }

int Filme::getUnidades(){ return this->unidades; }

std::string Filme::getTitulo(){ return this->titulo; }

int Filme::getTipo() { return this->tipo; }

int DVD::getCategoria(){ return this->categoria; }

int DVD::calculoPrecoLocacao(int dias){
    if (this->getCategoria() == LANCAMENTO) return 20 * dias;

    else if (this->getCategoria() == ESTOQUE) return 10 * dias;

    else if (this->getCategoria() == PROMOCAO) return 10;

    // Tratamento de erro
    return -1;
    
}

bool FITA::isRebobinado(){ return this->estaRebobinado; }

int FITA::calculoPrecoLocacao(int dias){
    return (this->isRebobinado() == true) ? 5 : 7;
}

void Filme::imprimir() {
    std::cout << identificador << ' ' << titulo << ' ' << unidades << ' ';
}

void DVD::imprimir() {
    Filme::imprimir();
    std::cout << "DVD" << std::endl;
}

void FITA::imprimir() {
    Filme::imprimir();
    std::cout << "FITA" << std::endl;
}


std::string Filme::listarInformacoes() {
    return Tipo_Filme[this->getTipo()] + " " + std::to_string(this->getUnidades()) + " " + std::to_string(this->getIdentificador()) + " " + this->getTitulo() + " ";
}

std::string DVD::listarInformacoes() {
    return this->Filme::listarInformacoes() + " " + Categorias[this->getCategoria()];
}