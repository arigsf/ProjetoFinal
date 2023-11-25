#include "Funcoes.hpp"
#include <iterator>
#include <random>
#include <regex> //Validar cpf e data de nascimento
#include <map>
#include <string>


const bool retornaVerdadeiroFalso() {
    // Cria um gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd()); // Pode escolher um outro algoritmo se desejar

    // Define a faixa de valores possíveis (0 ou 1)
    std::uniform_int_distribution<> dis(0, 1);

    // Gera um número aleatório (0 ou 1) e retorna true caso for igual a 1, e falso caso seja 0
    return  1 == dis(gen);

}

bool isTipoValido(const char tipo) { // Verifica se o tipo de Filme é valido

    for (std::map<int,char>::const_iterator it = Tipo_Filme.begin(); it != Tipo_Filme.end(); it++)
        if(it->second == tipo) return true;
    
    return false;

}

bool isUnidadesValido(const int unidades) { //Verifica se unidades é um valor maior que zero   
    return unidades > 0;
}

bool isIdentificadorValido(const int identificador) { // Verifica se o id é valido
    return identificador > 0;
}


int isCategoriaValido(char categoria) {
    for (std::map<int,char>::const_iterator it = Categorias.begin(); it != Categorias.end();it++)
        if(it->second == categoria) {
            return it->first;
        } 

    return -1;
}

bool isCPFValido(std::string &cpf) {
    //Expressão regular para validar o formato do CPF
    std::regex regexCPF(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");
    if (!std::regex_match(cpf, regexCPF)) return false;
    return true;
    
}


bool isDataNascimentoValido(std::string &data) {
    //Expressão regular para validar o formato da data de nascimento
    std::regex regexDataNascimento(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(data, regexDataNascimento)) return false;
    return true;
}