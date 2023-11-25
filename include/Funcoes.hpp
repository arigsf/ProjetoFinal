#ifndef FUNCOES_H
#define FUNCOES_H

// Função de aleatoridade em fitas
const bool retornaVerdadeiroFalso();

bool isTipoValido(char);
bool isUnidadesValido(int);
bool isIdentificadorValido(int);
int isCategoriaValido(std::string &);
bool isCPFValido(std::string);
bool isDataNascimentoValido(std::string);

#endif