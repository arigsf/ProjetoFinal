#ifndef FUNCOES_H
#define FUNCOES_H

#include "Filme.hpp"
#include <string>

// Função de aleatoridade em fitas
const bool retornaVerdadeiroFalso();

bool isTipoValido(const char);
bool isUnidadesValido(const int);
bool isIdentificadorValido(const int);
int isCategoriaValido(char);
// Nota, bug presente, que afirma que não há referencia definida para esta função abaixo
bool isCPFValido(std::string &);
bool isDataNascimentoValido(std::string &);

#endif