#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third-party/doctest.h"
#include "../include/Sistema.hpp"
#include <sstream>
#include <iostream>


TEST_CASE("LER ARQUIVO 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("C\n data\\Clientes\\clientes\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("ERRO: nao foi possível criar o arquivo") == std::string::npos);

}


TEST_CASE("LER ARQUIVO 2") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("C\n data\\Filmes\\filmes\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("ERRO: arquivo inexistente") == std::string::npos);
    
}


TEST_CASE("LER ARQUIVO 3") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("C\n data\\Filmes\\filmes\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("ERRO: arquivo inexistente") == std::string::npos);
    
}


TEST_CASE("LER ARQUIVO 4") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("C\n data\\Filmes\\x\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("ERRO: arquivo inexistente") == std::string::npos);
    
}

TEST_CASE("CADASTRAR FILME 1") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("10000.7836\n -167\n 13456\n D\n -167\n 6741.6253\n 156\n 01346\n FilmeTeste\n Estoque\n E\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.cadastrarFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);
}


TEST_CASE("CADASTRAR FILME 2") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("Teste\n -167\n 1678.12\n F\n -167\n sag.6253\n 1\n 256\n Teste1\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.cadastrarFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);
}

TEST_CASE("REMOVER FILME 1") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("256\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.removerFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("removido") != std::string::npos);
}


TEST_CASE("REMOVER FILME 2") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("01346\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.removerFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("removido") != std::string::npos);
}

TEST_CASE("LISTAR FILMES 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("N\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.listarClientesOrdenados();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("inexistente") == std::string::npos);
}


TEST_CASE("LISTAR FILMES 2") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("J\n CANCELAR\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.listarFilmesOrdenados();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("inexistente") != std::string::npos);
}


TEST_CASE("CADASTRAR CLIENTE 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("14567254309\n 145.672.543-09\n \n Carol\n 08102004\n 08/10/2004\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.cadastrarCliente();

        // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);

}

TEST_CASE("REMOVER CLIENTE 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("-567\n teste\n 14567254309\n 145.672.543-09\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.removerCliente();

        // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);   
}

TEST_CASE("ALUGAR FILME 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("safsdwajdsa\n 124322\n -5393503\n 124.678.124-35\n 677332\n -57575\n soi\n 19.9\n 1456\n 2468\n 13\n PARAR\n -10\n 8\n 5\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.alugarFilmes();

        // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("aprovado") != std::string::npos);   
}

TEST_CASE("DEVOLVER FILME 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("safsdwajdsa\n 124322\n -5393503\n 124.678.124-35\n -100\n teste\n 90\n 6773\n -57575\n soi\n 19.9\n 1456\n 2468\n 13\n PARAR\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.devolverFilmes();

        // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);   
}