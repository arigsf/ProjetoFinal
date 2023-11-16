#include "../include/Filme.hpp"

Filme::Filme(int _unidades, int _identificador, std::string _titulo) : unidades(_unidades), identificador(_identificador), titulo(_titulo) {}

Filme::~Filme() {}

DVD::DVD(int _unidades, int _identificador, std::string _titulo, int _categoria) : Filme(_unidades, _identificador, _titulo), categoria(_categoria) {
    this->tipo = TIPO_DVD;
}

FITA::FITA(int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado) : Filme(_unidades, _identificador, _titulo), estaRebobinado(_estaRebobinado) {
    this->tipo = TIPO_FITA;
}

const int Filme::getIdentificador() const { return this->identificador; }

const int Filme::getUnidades() const { return this->unidades; }

const std::string Filme::getTitulo() const { return this->titulo; }

const int Filme::getTipo() const { return this->tipo; }

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
    return "D " + Filme::listarInformacoes() + " " + Categorias.at(this->getCategoria());
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
