#ifndef SISTEMA_H
#define SISTEMA_H

#include "Funcoes.hpp"
#include "Estoque.hpp"
#include <iterator>

class Sistema {

    private:
        Estoque estoque;
        
    public:
        void lerArquivo(const std::string);
        void cadastrarFilme(Filme *);
        void removerFilme(const int);
        void listarFIlmes();
        void finalizarSistema();
        

};


#endif