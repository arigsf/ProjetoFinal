#include "Filme.hpp"

Filme::Filme (int _unidades, int _identificador, std::string _titulo) : 
    unidades(_unidades), identificador(_identificador), titulo(_titulo) {}

int Filme::getIdentificador(){ return this->identificador; }

DVD::DVD (int _unidades, int _identificador, std::string _titulo, int _categoria) : 
    Filme (_unidades, _identificador, _titulo) {
        this->categoria = _categoria;
    }

FITA::FITA (int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado):
    Filme (_unidades, _identificador, _titulo) {
        this->estaRebobinado = _estaRebobinado;
        std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;  
    }

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
