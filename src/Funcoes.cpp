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
    
    // Nenhuma Categoria foi encontrada
    return -1;

}

// Funções usadas na classe Sistema
