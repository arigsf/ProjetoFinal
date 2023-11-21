#include "../include/Filme.hpp"

Filme::Filme(int _unidades, int _identificador, std::string _titulo, int _tipo) : unidades(_unidades), identificador(_identificador), titulo(_titulo), tipo(_tipo) {}

Filme::~Filme() {}

DVD::DVD(int _unidades, int _identificador, std::string _titulo, int _categoria) : Filme(_unidades, _identificador, _titulo, TIPO_DVD), categoria(_categoria) {}

FITA::FITA(int _unidades, int _identificador, std::string _titulo, bool _estaRebobinado) : Filme(_unidades, _identificador, _titulo, TIPO_FITA), estaRebobinado(_estaRebobinado) {}

const int Filme::getIdentificador() const { return this->identificador; }

const int Filme::getUnidades() const { return this->unidades; }

const std::string Filme::getTitulo() const { return this->titulo; }

const int Filme::getTipo() const { return this->tipo; }

void Filme::adicionarUnidades(int valor) {
    if(valor > 0)
        this->unidades += valor;
    else
        std::cout << "Valor inválido a ser adicionado às unidades do filme: " << this->getTitulo() << std::endl;
}

void Filme::removerUnidades(int valor) {
    if(valor > 0 && this->unidades >= valor) 
        this->unidades -= valor;

    else
        std::cout << "Valor inválido a ser removido das unidades do filme: " << this->getTitulo() << std::endl;
}

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
    return std::to_string(unidades) + " " + std::to_string(identificador) + " " + titulo;
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
