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
    if (categoria == 0) return 20 * dias;
    
    else if (categoria == 1) return 10 * dias;
    
    else if (categoria == 2) return 10;

    //Retorna -1 caso a categoria não seja válida
    else {
        std::cout << "Categoria inválida" << std::endl; 
        return -1;
    }
}

int FITA::calculaPreco (int dias) {
    return estaRebobinado ? 5 : 7; // R$5,00 se a fita estiver rebobinada, caso contrário há uma adição de R$2,00
}

