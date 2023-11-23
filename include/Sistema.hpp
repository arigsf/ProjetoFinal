#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estoque.hpp"
#include "Locacao.hpp"
#include "cadastro_clientes.hpp"
#include <iterator>

class Sistema {

    private:
        Estoque estoque;
        Locacao locacao;
        CadastroClientes clientes;
        
    public:
        void lerArquivo(const std::string);
        void cadastrarFilme(Filme *);
        void removerFilme(const int);
        void listarFilmesOrdenados(const std::string) const;
        void cadastrarCliente(Cliente *);
        void listarClientesOrdenados(const std::string) const;
        void removerCliente(const std::string);
        void alugarFilmes(std::string, std::vector<int> &const, const int);
        void devolverFilmes(std::string, int);
        

};


#endif