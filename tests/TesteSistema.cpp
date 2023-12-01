#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third-party/doctest.h"
#include "../include/Sistema.hpp"
#include <sstream>
#include <iostream>


TEST_CASE("LER ARQUIVO 1") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("J\n 0\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());

    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    // Verifica a saída usando doctest
    CHECK(outputbuffer.str() == "Filmes ou Clientes (F/C)? (Digite 0 se deseja cancelar) Erro : Tipo de leitura invalido\nFilmes ou Clientes (F/C)? (Digite 0 se deseja cancelar) ");
}


TEST_CASE("LER ARQUIVO 2") {
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

TEST_CASE("LER ARQUIVO 5") {
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("F\n data\\Filmes\\x\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.lerArquivo();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("ERRO: arquivo inexistente") == std::string::npos);
    
}


TEST_CASE("CADASTRAR FILME") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("F\n 10000000000000000000000\n 100000000000000000\n x\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.cadastrarFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);
}


TEST_CASE("CADASTRAR FILME") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("D\n 10000000100000000000000\n 100000010000000000\n Teste salve aahahah \n P\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.cadastrarFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);
}



TEST_CASE("CADASTRAR FILME") { 
    Sistema sistema;

    std::ostringstream outputbuffer;
    std::streambuf* oldCout = std::cout.rdbuf(outputbuffer.rdbuf());

    std::istringstream inputbuffer("1000\n Oi\n 106.7\n D\n salve\n 1.1\n ola\n 1\n Teste salve aahahah \n P\n");
    std::streambuf* oldCin = std::cin.rdbuf(inputbuffer.rdbuf());
    
    sistema.cadastrarFilme();

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    CHECK(outputbuffer.str().find("sucesso") != std::string::npos);
}