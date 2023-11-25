#include "Sistema.hpp"
#include "Funcoes.hpp"

void Sistema::lerArquivo() {
    std::string diretorio;
    std::cin >> diretorio;
    this->estoque.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme() {
    
    
    char tipo;
    while(true) {
        std::cin >> tipo;

        if(!isTipoValido(tipo)) std::cout << "Erro : Tipo invalido, digite novamente" << std::endl;
        else break;
    }

    int unidades, identificador;
    while (true) {
        std::cin >> unidades;

        if(!isUnidadesValido) std::cout << "Erro : Quantidades invalida, digite novamente" << std::endl;
        else break;
    }

    while(true) {     
        std::cin >> identificador;

        if(!isIdentificadorValido) std::cout << "Erro : Identificador invalido, digite novamente" << std::endl;
        else if(!this->estoque.filmeExiste(identificador)) std::cout << "ERRO: identificador repetido" << std::endl; 
        
        else break;
    }

    std::string titulo;
    std::cin.ignore();
    std::getline(std::cin,titulo);

    Filme *filme;            

    if(tipo == Tipo_Filme.at(TIPO_DVD)) {

        std::string categoria;
        int indice_categoria;

        while(true) {

            std::cin >> categoria;
            indice_categoria = isCategoriaValido(categoria);
            if(indice_categoria < 0) std::cout << "Erro : Categoria invalida, digite novamente" << std::endl;
            else break;
        }
            
        filme = new DVD(unidades,identificador,titulo,indice_categoria);
    }

    else if(tipo == 'F') filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());

    this->estoque.inserirFilme(filme);

    std::cout << "Filme " << identificador << " cadastrado com sucesso" << std::endl;
}

void Sistema::removerFilme() {
    int identificador;
    std::cin >> identificador;
    this->estoque.removerFilme(identificador);
}

void Sistema::listarFilmesOrdenados() const {
    std::string ordenacao;
    std::cin >> ordenacao;
    this->estoque.listarFilmesOrdenados(ordenacao);
}

void Sistema::cadastrarCliente() {
    std::string cpf, nome, data_nascimento;
    
    while(true) {
        std::cout << "\nDigite o CPF no formato ""XXX.XXX.XXX-XX"": ";
        std::cin >> cpf;

        if(!isCPFValido(cpf)) std::cout << "\nERRO: Formato inválido de CPF\n" << std::endl;
        else if (this->clientes.clienteExiste(cpf)) std::cout << "\nERRO: CPF repetido\n" << std::endl;
        else break;
    }

    std::cout << "\nDigite o nome do cliente: ";
    std::cin.ignore();
    std::getline(std::cin,nome);

    while(true) {
        std::cout << "\nDigite a data de nascimento no formato DD/MM/AAAA: ";
        std::cin >> data_nascimento;
        if(!isDataNascimentoValido(data_nascimento)) std::cout << "\nERRO: Formato inválido de data de nascimento\n" << std::endl;
        else break;
    }

    Cliente* novo_cliente = new Cliente(cpf,nome,data_nascimento);
    clientes.inserirCliente(novo_cliente);

    std::cout << "\nCliente de CPF: " << cpf << " cadastrado com sucesso" << std::endl;
}

void Sistema::listarClientesOrdenados() const {
    this->clientes.listarClientesOrdenados();
}

void  Sistema::removerCliente() {
    std::string cpf;
    std::cin >> cpf;
    if(isCPFValido(cpf)) this->clientes.removerCliente(cpf);
    else std::cout << "ERRO: Formato inválido de CPF" << std::endl;

}

void Sistema::alugarFilmes() {

    int id, dias;
    std::string cpf;
    std::cin >> cpf;
    std::vector<int> ids;

    
    while (true) {   

        std::cin >> id;
        if(id  <= 0) break;
        ids.push_back(id);
    }

    while (true) {
        
        std::cin >> dias;
        if(dias > 0 || dias <= 7) break;
    }

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    std::vector<Filme*> filmes;
    for (int &i : ids)
    {
        Filme *filme = this->estoque.filmeValido(i);
        if(filme != nullptr) filmes.push_back(filme);
    }

    this->locacao.alugar(cpf,filmes,dias);
    

}

void Sistema::devolverFilmes() {

    int id, dias, qtdDanificado, qtdNaoRebobinado;
    std::string cpf;
    std::cin >> cpf, dias;
    std::vector<int> ids;

    while (true) {   
        std::cin >> id;
        if(id  <= 0) break;
        ids.push_back(id);
    }

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    int valorDaMulta = 0;
    std::vector<Filme*> filmes;
    for (int &i : ids)
    {
        Filme *filme = this->estoque.filmeValido(i);
        if(filme != nullptr){
            bool isDanificado;
            std::cout << "O filme " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta danificado?"<< std::endl;
            std::cin >> isDanificado;
            if(filme->getTipo() == 1) { // Se o filme é fita, precisamos verificar se está rebobinado
                bool isRebobinado;
                std::cout << "A fita " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta rebobinado?"<< std::endl;
                std::cin >> isRebobinado;
                if(!isRebobinado) valorDaMulta += 2;
            }
            valorDaMulta += this->locacao.devolucao(cpf, filme, dias, isDanificado);
            // Implementar tratamento de exceção (se filme não estiver locado)
        }
    }    
    std::cout << "\n\nDevolucoes realizadas com sucesso, valor de multas a serem liquidadas: " << valorDaMulta << std::endl;

}

