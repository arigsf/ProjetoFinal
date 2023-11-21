#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <ctime>

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

class Cliente {
public:
    //Construtor da classe Cliente
    Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento, const std::string endereco);

    //Métodos das informações dos clientes
    const std::string GetCPF() const;
    const std::string GetNome() const;
    const std::string GetDataNascimento() const;
    const std::string GetEndereco() const;
    //Método que obtém idade por meio da data de nascimento
    int GetIdade() const;

private:
    //Atributos da classe Cliente
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
    std::string endereco;
};

#endif