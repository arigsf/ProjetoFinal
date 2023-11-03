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
        std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;  
    }

int DVD::calculaPreco (int dias){
    if (categoria == LANCAMENTO) return 20 * dias;
    
    else if (categoria == ESTOQUE) return 10 * dias;

    else if (categoria == PROMOCAO) return 10;

    //Elaborar tratamento de erro futuramente;
}

// Define um valor padrão para o número de dias, pois isso não tem influência no cálculo do preço da fita;

int FITA::calculaPreco (int dias = 0) { 
    return estaRebobinado ? 5 : 7; // R$5,00 se a fita estiver rebobinada, caso contrário há uma adição de R$2,00;
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
