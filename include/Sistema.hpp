#ifndef SISTEMA_H
#define SISTEMA_H

#include <fstream>
#include "Locacao.hpp"
#include "Funcoes.hpp"
#include <iterator>

class Sistema
{
private:
    std::vector<Filme *> lista_Filmes;
    
public:
    void lerArquivo(std::string);
    void salvarDados();
    void adcionarFilme(Filme *);

};



#endif