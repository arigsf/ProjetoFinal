#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Cadastro_Clientes.hpp"

#include "doctest.h"
#include "Cadastro_Clientes.hpp"

TEST_CASE("Cliente") {
    Cliente cliente("400.289.220-00", "Ari Pai", "11/09/2000");
    
    CHECK(cliente.getCPF() == "400.289.220-00");
    CHECK(cliente.getNome() == "Ari Pai");
    CHECK(cliente.getDataNascimento() == "11/09/2000");
    CHECK(cliente.getIdade() == 23);
}


TEST_CASE("Inserir cliente") {
    CadastroClientes clientes;

    Cliente *novoCliente = new Cliente("400.289.220-00", "Ari Pai", "11/09/2000");

    clientes.inserirCliente(novoCliente);

    std::string cpf = "400.289.220-00";

    REQUIRE(clientes.clienteExiste(cpf) != nullptr);
}

TEST_CASE("Remover cliente") {
    CadastroClientes clientes;

    std::string cpf = "400.289.220-00";

    clientes.removerCliente(cpf);

    REQUIRE(clientes.clienteExiste(cpf) == nullptr);
}