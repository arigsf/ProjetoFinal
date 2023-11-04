#include "Filme.hpp"

Filme::Filme (int _unidades, int _identificador, std::string _titulo) : 
    unidades(_unidades), identificador(_identificador), titulo(_titulo) {}


DVD::DVD (int _unidades, int _identificador, std::string _titulo, int _categoria) : 
    Filme (_unidades, _identificador, _titulo) {
        this->categoria = _categoria;
    }

FITA::FITA (int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado):
    Filme (_unidades, _identificador, _titulo) {
        this->estaRebobinado = _estaRebobinado;
        this->categoria = 3;
        std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;  
    }

int Filme::getIdentificador(){ return this->identificador; }

std::string Filme::getTitulo(){ return this->titulo; }

int DVD::getCategoria(){ return this->categoria; }

int FITA::getCategoria(){ return this->categoria; }

bool FITA::isRebobinado(){ return this->estaRebobinado; }

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
