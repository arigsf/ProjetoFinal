#ifndef FILME_H
#define FILME_H

#include <string>

class Filme {

protected:
    int identificador;
    int unidades;
    std::string nome;    
};

class DVD : private Filme {

private:
    int categoria; // 0 - Lançamento, 1 - Estoque, 2 - Promoção
    
public:
    // Construtores
    DVD(int, int, std::string, int);
    DVD();

    int calculaPreco(int);
};

class FITA: private Filme {

private:
    bool estaRebobinado;

public:
    // Construtores
    FITA(int, int, std::string, bool);
    FITA();
    
    int calculaValor(int);
};



#endif