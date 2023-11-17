#include "../include/Funcoes.hpp"


const bool retornaVerdadeiroFalso() {
    // Cria um gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd()); // Pode escolher um outro algoritmo se desejar

    // Define a faixa de valores possíveis (0 ou 1)
    std::uniform_int_distribution<> dis(0, 1);

    // Gera um número aleatório (0 ou 1) e retorna true caso for igual a 1, e falso caso seja 0
    return  1 == dis(gen);

}



void removerEspacosDireitaEsquerda(std::string &linha)  {
    
    linha.erase(0,linha.find_first_not_of(' ')); 
    // remove os espaços a direita, a função find_first_not_of retorna o primeiro caracter que não é um espaço
    linha.erase(linha.find_last_not_of(' ')+1); // remove os espaços a esquerda, a função find_last_not_of retorna o ultimo caracter que não é um espaço
}


const int separarTituloCategoria(std::string &titulo) {

    for (std::map<int, std::string>::const_iterator categoria = Categorias.begin(); categoria != Categorias.end(); categoria++) {
        size_t pos = titulo.find(categoria->second); // A função find() retorna a primeira instancia da substring desejada
        if(pos != std::string::npos) { 
            // se pos for diferende do valor falso esperado, encontramos a categoria certa
            titulo.erase(pos,categoria->second.length()); // a função erase remove a substring que contem a categoria da linha
            removerEspacosDireitaEsquerda(titulo);
            return categoria->first;
        }
            
    }
    
    // tratamento de erro
    return -1;

}

// Funções usadas na classe Sistema

Filme* lerFilme() {

    char tipo;
    std::string titulo;
    int unidades, identificador;

    std::cin >> tipo >> unidades >> identificador;
    std::cin.ignore();
    std::getline(std::cin,titulo);

    Filme *filme = nullptr;

    if(tipo == 'D') {
        std::string categoria;
        std::cin >> categoria;
        std::map<int,std::string>::const_iterator it;

        for (it = Categorias.begin(); it != Categorias.end();it++)
            if(it->second == categoria) break;
        
        filme = new DVD(unidades,identificador,titulo,it->first);
    }

    else if(tipo == 'F') filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
    


    // if(!(std::cin >> tipo >> unidades >> identificador)) return nullptr; // Retorna nulo caso a ordem não seja respeitada
    // std::cin.ignore();
    // if(!(std::getline(std::cin,titulo))) return nullptr; // retorna nulo caso haja algum erro na leitura da linha

    // Filme *novo_filme = nullptr;

    // if (tipo == 'F') novo_filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
    
    // else if(tipo == 'D') {
    //     int categoria = separarTituloCategoria(titulo);
    //     if(categoria == -1) return nullptr; // Retorna nulo caso não haja uma categoria especificada
    //     removerEspacosDireitaEsquerda(titulo);
    //     novo_filme = new DVD(unidades,identificador,titulo,categoria);
    // }
    
    return filme;
}