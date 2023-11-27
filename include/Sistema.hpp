#ifndef SISTEMA_H
#define SISTEMA_H

const char ARQUIVO_FILMES = 'F';
const char ARQUIVO_CLIENTES = 'C';


#include "Estoque.hpp"
#include "Locacao.hpp"
#include "Cadastro_Clientes.hpp"
#include <iterator>
#include <unistd.h>

class Sistema
{

private:
    Estoque _estoque;
    Locacao _locacao;
    CadastroClientes _clientes;

public:
    Sistema();

    void lerArquivo();
    void cadastrarFilme();
    void removerFilme();
    void listarFilmesOrdenados() const;
    void cadastrarCliente();
    void listarClientesOrdenados() const;
    void removerCliente();
    void alugarFilmes();
    void devolverFilmes(); // CPF, Filmes por ID, dias
    void listarLogLocacoes();
    void listarLocacoes();
    void limparTerminal();
    void mostrarOpcoes();
};

#endif