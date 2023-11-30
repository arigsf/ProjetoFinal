#include "doctest.h"
#include "Estoque.hpp"

TEST_CASE("Inserir filme") {
    Estoque estoque;

    // Criar um filme para ser inserido
    Filme *novoFilme = new FITA(10, 1, "Lua Crescente", true);

    // Inserir o filme no estoque
    REQUIRE(estoque.inserirFilme(novoFilme) == true);

    // Verificar se o filme existe no estoque
    REQUIRE(estoque.filmeExiste(1) != nullptr);
}

TEST_CASE("Remover filme") {
    Estoque estoque;
    
    // Verificar se o filme existe no estoque
    REQUIRE(estoque.filmeExiste(1) != nullptr);

    // Remover o filme do estoque
    estoque.removerFilme(1);

    // Verificar se o filme foi removido
    REQUIRE(estoque.filmeExiste(1) == nullptr);
}