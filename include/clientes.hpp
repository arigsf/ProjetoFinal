#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>

class Cliente {
public:
    //Construtor da classe Cliente
    Cliente(const std::string cpf, const std::string nome, const std::string dataNascimento);

    //Métodos das informações dos clientes
    const std::string getCPF() const;
    const std::string getNome() const;
    const std::string getDataNascimento() const;

private:
    //Atributos da classe Cliente
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
};

#endif
