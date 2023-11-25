#ifndef FUNCOES_H
#define FUNCOES_H

#include <string>

// Função de aleatoridade em fitas
const bool retornaVerdadeiroFalso();

bool isTipoValido(char);
bool isUnidadesValido(int);
bool isIdentificadorValido(int);
int isCategoriaValido(std::string &);
// Nota, bug presente, que afirma que não há referencia definida para esta função abaixo
bool isCPFValido(std::string &);
bool isDataNascimentoValido(std::string &);

#endif