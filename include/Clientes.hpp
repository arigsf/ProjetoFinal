#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <ctime>

//FORMATO CPF: xxx.xxx.xxx-xx
//FORMATO Data de Nascimento: dd/mm/yyyy

class Cliente {
public:
    //Construtor da classe Cliente
    Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento /*const std::string endereco*/);

    //Métodos das informações dos clientes
    const std::string getCPF() const;
    const std::string getNome() const;
    const std::string getDataNascimento() const;
    // const std::string getEndereco() const;
    //Método que obtém idade por meio da data de nascimento
    int getIdade() const;

private:
    //Atributos da classe Cliente
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
    /*std::string endereco;*/
};

#endif