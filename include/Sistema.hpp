#ifndef SISTEMA_H
#define SISTEMA_H

#include "Funcoes.hpp"
#include "Estoque.hpp"
#include "Locacao.hpp"
#include <iterator>

class Sistema {

    private:
        Estoque estoque;
        Locacao locacao;
        
    public:
        void lerArquivo(const std::string);
        void cadastrarFilme(Filme *);
        void removerFilme(const int);
        void listarFilmesOrdenados(bool ) const;
        void finalizarSistema();
        

};


#endif