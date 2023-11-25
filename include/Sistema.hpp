#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estoque.hpp"
#include "Locacao.hpp"
#include "cadastro_clientes.hpp"
#include <iterator>
#include <unistd.h>

class Sistema {

    private:
        Estoque estoque;
        Locacao locacao;
        CadastroClientes clientes;
        
    public:
        void lerArquivo();
        void cadastrarFilme();
        void removerFilme();
        void listarFilmesOrdenados() const;
        void cadastrarCliente();
        void listarClientesOrdenados() const;
        void removerCliente();
        void alugarFilmes();
        void devolverFilmes(); // CPF, Filmes por ID, dias
        void limparTerminal();
        void mostrarOpcoes();
};


#endif