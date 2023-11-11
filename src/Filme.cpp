#include "Filme.hpp"

Filme::Filme(int _unidades, int _identificador, std::string _titulo) : unidades(_unidades), identificador(_identificador), titulo(_titulo) {}

Filme::~Filme() {}

DVD::DVD(int _unidades, int _identificador, std::string _titulo, int _categoria) : Filme(_unidades, _identificador, _titulo)
{
    this->categoria = _categoria;
    this->tipo = TIPO_DVD;
    std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;
}

FITA::FITA(int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado) : Filme(_unidades, _identificador, _titulo)
{
    this->estaRebobinado = _estaRebobinado;
    this->tipo = TIPO_FITA;
    std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;
}

int Filme::getIdentificador() { return this->identificador; }

int Filme::getUnidades() { return this->unidades; }

std::string Filme::getTitulo() { return this->titulo; }

int Filme::getTipo() { return this->tipo; }

int DVD::getCategoria() { return this->categoria; }

int DVD::calculoPrecoLocacao(int dias)
{
    if (this->getCategoria() == LANCAMENTO)
        return 20 * dias;

    else if (this->getCategoria() == ESTOQUE)
        return 10 * dias;

    else if (this->getCategoria() == PROMOCAO)
        return 10;

    return -1;
    // Implementar tratamento de erro
}

bool FITA::isRebobinado() { return this->estaRebobinado; }

int FITA::calculoPrecoLocacao(int dias)
{
    return (this->isRebobinado() == true) ? 5 : 7;
}

std::string Filme::listarInformacoes()
{
    return std::to_string(unidades) + " " + std::to_string(identificador) + " " + titulo + " ";
}

std::string DVD::listarInformacoes()
{
    return "D " + Filme::listarInformacoes() + " " + std::to_string(DVD::getCategoria());
}

std::string FITA::listarInformacoes()
{
    return "F " + Filme::listarInformacoes();
}

bool Filme::validarDados()
{
    return !(identificador <= 0 || titulo == ""); // Retorna true se os dados forem válidos, e false caso contrário
}

bool DVD::validarDados()
{
    return Filme::validarDados() && !(categoria < 0 || categoria > 2); // Retorna true se os dados forem válidos, e false caso contrário
}
