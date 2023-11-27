#include "Sistema.hpp"
#include "Funcoes.hpp"

void Sistema::lerArquivo() {
    char tipo;
    std::string diretorio;

    std::cout << "Filmes ou Clientes (F/C)? ";
    while (true) {
        std::cin >> tipo;
        if(tipo != ARQUIVO_CLIENTES && tipo != ARQUIVO_FILMES) std::cout << "Erro : Tipo de leitura inválido" << std::endl;
        else break;
    }
    
    std::cout << "\nDigite o caminho para o arquivo: ";
    std::cin >> diretorio;
    this->estoque.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme() {
    char tipo;
    while(true) {
        std::cout << "\nDigite o tipo do filme\n[D] - dvd\n[F] - fita\n\nEscolha: ";
        std::cin >> tipo;
        if(!isTipoValido(tipo)) std::cout << "Erro : Tipo invalido, digite novamente" << std::endl;
        else break;
    }

    int unidades, identificador;
    while (true) {
        std::cout << "\nInsira a quantidade: ";
        std::cin >> unidades;

        if(!isUnidadesValido) std::cout << "Erro : Quantidades invalida, digite novamente" << std::endl;
        else break;
    }

    while(true) {     
        std::cout << "\nInsira o identificador: ";
        std::cin >> identificador;

        if(!isIdentificadorValido) std::cout << "Erro : Identificador invalido, digite novamente" << std::endl;
        else if(this->estoque.filmeExiste(identificador)) std::cout << "ERRO: identificador repetido" << std::endl; 
        
        else break;
    }

    std::string titulo;
    std::cout << "\nDigite o nome do filme: ";
    std::cin.ignore();
    std::getline(std::cin,titulo);

    Filme *filme;            

    if(tipo == Tipo_Filme.at(TIPO_DVD)) {

        char categoria;
        int indice_categoria;

        while(true) {
            std::cout << "\nDigite a categoria do filme\n[E] - Estoque\n[L] - Lancamento\n[P] - Promocao\n";
            std::cout << "\nEscolha: ";
            std::cin >> categoria;
            indice_categoria = isCategoriaValido(categoria);
            if(indice_categoria < 0) std::cout << "Erro : Categoria invalida, digite novamente" << std::endl;
            else break;
        }
            
        filme = new DVD(unidades,identificador,titulo,indice_categoria);
    }

    else if(tipo == 'F') filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());

    this->estoque.inserirFilme(filme);

    std::cout << "\nFilme " << identificador << " cadastrado com sucesso" << std::endl;
}

void Sistema::removerFilme() {
    int identificador;
    std::cout << "\nDigite o identificador: ";
    std::cin >> identificador;
    this->estoque.removerFilme(identificador);
}

void Sistema::listarFilmesOrdenados() const {
    std::string ordenacao;
    std::cout << "Digite o critério de ordenação\n[C] - por identificador\n[U] - por quantidade\n[N] - por nome\n";
    std::cout << "\nEscolha: ";
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
    std::cout << "\nDigite o CPF do cliente: ";
    std::cin >> cpf;
    if(isCPFValido(cpf)) this->clientes.removerCliente(cpf);
    else std::cout << "ERRO: Formato inválido de CPF" << std::endl;

}

void Sistema::alugarFilmes() {

    int id, dias, quantidade;

    std::string cpf;
    std::cout << "\nDigite CPF no formato ""XXX.XXX.XXX-XX"": ";
    std::cin.ignore();
    std::getline(std::cin, cpf);

    std::vector<Filme*> filmes;

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    std::cout << "Digite a quantidade de filmes: ";
    std::cin >> quantidade;

    for(int i=0; i<quantidade; i++) {   
        std::cout << "\nDigite o id do filme " << i+1 << ": ";
        std::cin >> id;
        Filme *filme = this->estoque.filmeValido(id);
        if(filme != nullptr) filmes.push_back(filme);
    }

    while (true) {
        std::cout << "\nDigite o n° de dias do aluguel (entre 1 e 7): ";
        std::cin >> dias;
        if(dias > 0 || dias <= 7) break;
        else std::cout << "ERRO: N° de dias invalido" << std::endl;
    }

    this->locacao.alugar(cpf,filmes,dias);    
}

void Sistema::devolverFilmes() {
    
    int id, dias, qtdTotal, qtdDanificado, qtdNaoRebobinado;
    int valorDaMulta = 0;
    
    std::vector<Filme*> filmes;

    std::string cpf;
    std::cout << "\nDigite CPF no formato ""XXX.XXX.XXX-XX"": ";
    std::cin >> cpf;

    if(!this->clientes.clienteExiste(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }
    std::cout << "\nDigite a quantidade de filmes a serem devolvidos: ";
    std::cin >> qtdTotal;

    std::cout << "\nDigite o n° de dias decorridos desde o aluguel: ";
    std::cin >> dias;
    
    std::vector<int> ids;

    for(int i=0; i<qtdTotal; i++) { 
        std::cout << "\nDigite o id do filme " << i+1 << ": ";  
        std::cin >> id;

        Filme *filme = this->estoque.filmeValido(id);
        if(filme != nullptr) {
            bool isDanificado;
            std::cout << "O filme " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta danificado?\n[0] - Nao\n[1] - Sim\nEscolha: ";
            std::cin >> isDanificado;

            if(filme->getTipo() == 1) { // Se o filme é fita, precisamos verificar se está rebobinado
                bool isRebobinado;
                std::cout << "A fita " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta rebobinada?\n[0] - Nao\n[1] - Sim\nEscolha: ";
                std::cin >> isRebobinado;
                if(!isRebobinado) valorDaMulta += 2;
            }

            valorDaMulta += this->locacao.devolucao(cpf, filme, dias, isDanificado);
        }
    }

    std::cout << "\n\nDevolucoes realizadas com sucesso, valor de multas a serem liquidadas: " << valorDaMulta << std::endl;
}

void Sistema::listarLogLocacoes() {
    this->locacao.historicoLocacoes();
}

void Sistema::limparTerminal() {
    std::system("clear");
}

void Sistema::mostrarOpcoes() {
    std::cout << "\nOpções disponíveis:\n";
    std::cout << " - LA: Ler Arquivo\n";
    std::cout << " - CA: Cadastrar Filme\n";
    std::cout << " - RF: Remover Filme\n";
    std::cout << " - CC: Cadastrar Cliente\n";
    std::cout << " - LF: Listar Filmes\n";
    std::cout << " - RC: Remover Clientes\n";
    std::cout << " - LC: Listar Clientes\n";
    std::cout << " - AL: Alugar Filme\n";
    std::cout << " - DV: Devolver Filme\n";
    std::cout << " - LL: Listar Log Locações\n";
    std::cout << " - CL: Limpar Terminal\n";
    std::cout << " - MO: Mostrar Opções\n";
    std::cout << " - FS: Finalizar Sistema\n\n";
    std::cout << "========================================================\n";
}