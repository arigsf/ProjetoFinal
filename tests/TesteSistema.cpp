#include "doctest.h"
#include "Sistema.hpp"
#include <sstream>
#include <iostream>


TEST_CASE("LER ARQUIVO") {
    Sistema sistema;

    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    std::istringstream buffer("2 3\n"); 
    std::streambuf* oldCin = std::cin.rdbuf(buffer.rdbuf());


    sistema.lerArquivo();
    


 

    // Restaura a saída padrão
    std::cout.rdbuf(oldCout);

    // Restaura a entrada padrão
    std::cin.rdbuf(oldCin);

    // Verifica a saída usando doctest
    CHECK(buffer.str() == "");
}