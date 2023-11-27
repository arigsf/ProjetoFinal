#include "Filme.hpp"

Filme::Filme(int unidades, int identificador, std::string titulo, int tipo) : _unidades(unidades), _identificador(identificador), _titulo(titulo), _tipo(tipo) {}

Filme::~Filme() {}

DVD::DVD(int unidades, int identificador, std::string titulo, int categoria) : Filme(unidades, identificador, titulo, TIPO_DVD), _categoria(categoria) {}

FITA::FITA(int unidades, int identificador, std::string titulo, bool estaRebobinado) : Filme(unidades, identificador, titulo, TIPO_FITA), _estaRebobinado(estaRebobinado) {}

const int Filme::getIdentificador() const { return this->_identificador; }

const int Filme::getUnidades() const { return this->_unidades; }

const std::string Filme::getTitulo() const { return this->_titulo; }

const int Filme::getTipo() const { return this->_tipo; }

void Filme::adicionarUnidades()
{
    this->_unidades++;
}

void Filme::removerUnidades()
{
    if (this->_unidades >= 1)
    {
        this->_unidades--;
    }
    else
    {
        std::cout << "ERRO: Filme: " << this->getTitulo() << " nao disponivel no momento." << std::endl;
    }
}

int DVD::getCategoria() { return this->_categoria; }

float DVD::calculoPrecoLocacao(int dias) // Cálculo simulado a preços reais
{
    if (this->getCategoria() == LANCAMENTO)
        return std::log2(dias * dias) + 8 + 2 * dias;

    else if (this->getCategoria() == ESTOQUE)
        return std::log2(dias * dias) + 4 + dias;

    else if (this->getCategoria() == PROMOCAO)
        return 5;

    return -1;
    // Implementar tratamento de erro
}

bool FITA::isRebobinado() { return this->_estaRebobinado; }

float FITA::calculoPrecoLocacao(int dias)
{
    return 5;
}

std::string Filme::listarInformacoes()
{
    return std::to_string(_unidades) + " " + std::to_string(_identificador) + " " + _titulo;
}

std::string DVD::listarInformacoes()
{
    return "D " + Filme::listarInformacoes() + " " + aux_Categorias.at(this->getCategoria());
}

std::string FITA::listarInformacoes()
{
    return "F " + Filme::listarInformacoes();
}

bool Filme::validarDados()
{
    return !(_identificador <= 0 || _titulo == ""); // Retorna true se os dados forem válidos, e false caso contrário
}

bool DVD::validarDados()
{
    return Filme::validarDados() && !(_categoria < 0 || _categoria > 2); // Retorna true se os dados forem válidos, e false caso contrário
}
