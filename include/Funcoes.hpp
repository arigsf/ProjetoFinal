#ifndef FUNCOES_H
#define FUNCOES_H

#include "Filme.hpp"
#include <string>

// Função de aleatoridade em fitas
const bool retornaVerdadeiroFalso();

bool isTipoValido(const char tipo);
bool isUnidadesValido(const int unidades);
bool isIdentificadorValido(const int identificador);
int isCategoriaValido(char categoria);
// Nota, bug presente, que afirma que não há referencia definida para esta função abaixo
bool isCPFValido(std::string &cpf);
bool isDataNascimentoValido(std::string &data);
bool isDiasValido(const int dias);
bool isDiasDecorridosValido(const int dias);
bool isNumeroValido(const std::string& s);
std::string toUpperCase(const std::string& s);
bool isApenasEspaco(const std::string& s);

#endif