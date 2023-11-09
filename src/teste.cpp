#include <iostream>
#include "Filme.hpp"
#include <vector>
#include "Estoque.hpp"

int main() {
    std::string filename, comando;
    std::vector<Filme*> filmes;
    Estoque* estoque = new Estoque();
    
    while (true)
    {
        std::cin >> comando;
        
        if(comando == "LA") {
            estoque->lerArquivo("../data/movies");            
        }

        else if(comando == "FS") break;
    }
}