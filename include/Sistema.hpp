#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include "Locacao.hpp"
#include "Funcoes.hpp"
#include <iterator>

class Sistema {

    private:
        // A classe sistema armazenara uma classe do tipo estoque
        
    public:
        void lerArquivo(std::string);
        void salvarDados();

};


#endif