#include "Sistema.hpp"

Sistema::Sistema(){
    _locacao.associarPtrEstoque(&_estoque); // Para funções próprias da locação
}

void Sistema::lerArquivo()
{
    char tipo;
    std::string diretorio;

    std::cout << "Filmes ou Clientes (F/C)? ";
    while (true)
    {
        std::cin >> tipo;
        if (tipo != ARQUIVO_CLIENTES && tipo != ARQUIVO_FILMES) std::cout << "Erro : Tipo de leitura inválido" << std::endl;
        else break;
    }

    std::cout << "\nDigite o caminho para o arquivo: ";
    std::cin >> diretorio;

    if(ARQUIVO_FILMES) this->_estoque.lerArquivo(diretorio);
    else if (ARQUIVO_CLIENTES) this->_clientes.lerArquivo(diretorio);
}

void Sistema::cadastrarFilme()
{
    char tipo;
    while (true)
    {
        std::cout << "\nDigite o tipo do filme\n[D] - dvd\n[F] - fita\n\nEscolha (Digite 0 se deseja cancelar): ";
        std::cin >> tipo;
        if(tipo == '0') return;
        else if(!isTipoValido(tipo)) std::cout << "ERRO: Tipo invalido, digite novamente" << std::endl;
        else break;
    }

    int unidades, identificador;
    while (true)
    {
        std::cout << "\nInsira a quantidade (Digite -1 se deseja cancelar): ";
        std::cin >> unidades;
        if(unidades == -1) return;
        else if(!isUnidadesValido(unidades)) std::cout << "ERRO: Quantidades invalida, digite novamente" << std::endl;
        else break;
    }

    while (true)
    {
        std::cout << "\nInsira o identificador (Digite 0 se deseja cancelar): ";
        std::cin >> identificador;
        if(identificador == 0) return;
        else if(!isIdentificadorValido(identificador)) std::cout << "ERRO: Identificador invalido, digite novamente" << std::endl;
        else if(this->_estoque.filmeExiste(identificador)) std::cout << "ERRO: identificador repetido" << std::endl; 
        
        else break;
    }

    std::string titulo;

    while (true)
    {
        std::cout << "Digite o nome do filme (Digte CANCELAR se deseja cancelar): ";
        std::cin.ignore();
        std::getline(std::cin, titulo);
        if(titulo == "CANCELAR") return;
        else if(titulo.empty()) std::cout << "ERRO: nome titulo, digite novamente" << std::endl;
        else break;;

    }

    Filme *filme;

    if (tipo == Tipo_Filme.at(TIPO_DVD))
    {

        char categoria;
        int indice_categoria;

        while (true)
        {
            std::cout << "\nDigite a categoria do filme\n[E] - Estoque\n[L] - Lancamento\n[P] - Promocao\n";
            std::cout << "\nEscolha (Digite 0 se deseja cancelar): ";
            std::cin >> categoria;
            if(categoria == '0') return;
            indice_categoria = isCategoriaValido(categoria);

            if (indice_categoria < 0)
                std::cout << "Erro : Categoria invalida, digite novamente" << std::endl;
            else
                break;
        }

        filme = new DVD(unidades, identificador, titulo, indice_categoria);
    }

    else if (tipo == 'F')
        filme = new FITA(unidades, identificador, titulo, retornaVerdadeiroFalso());

    this->_estoque.inserirFilme(filme);

    std::cout << "\nFilme " << identificador << " cadastrado com sucesso" << std::endl;
}

void Sistema::removerFilme()
{
    int identificador;
    while (true)
    {   
        std::cout << "Digite o identificador (Digite 0 se deseja cancelar): ";
        std::cin >> identificador;

        if(identificador == 0) return;
        else if (isIdentificadorValido(identificador)) std::cout << "ERRO: identificador invalido, digite novamente" << std::endl;
        else if (!this->_estoque.filmeExiste(identificador)) std::cout << "ERRO: identificador inexistente, digite novamente" << std::endl;
        else if (this->_locacao.verificarFilmeAlugado(identificador)) std::cout << "ERRO: filme com aluguel pendente, nao pode ser removido" << std::endl;
        else break;
    }
    

    this->_estoque.removerFilme(identificador);
    std::cout << "Filme " << identificador << " removido com sucesso" << std::endl;    
}

void Sistema::listarFilmesOrdenados() const
{
    std::string ordenacao;
    std::cout << "Digite o critério de ordenação\n[C] - por identificador\n[U] - por quantidade\n[N] - por nome\n\n";

    while (true)
    {
        std::cout << "Escolha (Digite CANCELAR se deseja cancelar): ";
        std::cin >> ordenacao;
        if(ordenacao == "CANCELAR") return;
        else if (COMPARADORES_FILME.find(ordenacao) == COMPARADORES_FILME.end()) std::cout << "Erro: opção inexistente, digite novamente" << std::endl;
        else break;
    }
    
    
    
    this->_estoque.listarFilmesOrdenados(ordenacao);
}

void Sistema::cadastrarCliente()
{
    std::string cpf, nome, data_nascimento;

    while (true)
    {
        std::cout << "\nDigite o CPF no formato "
                     "XXX.XXX.XXX-XX"
                     "(Digite CANCELAR se deseja cancelar): ";
        std::cin >> cpf;

        if(cpf == "CANCELAR") return;
        else if (!isCPFValido(cpf)) std::cout << "\nERRO: Formato inválido de CPF" << std::endl;
        else if (this->_clientes.clienteExiste(cpf)) std::cout << "\nERRO: CPF repetido" << std::endl;
        else break;
    }


    

    while (true)
    {
        std::cin.ignore();
        std::cout << "\nDigite o nome do cliente (Digte CANCELAR se deseja cancelar): ";
        std::getline(std::cin, nome);
        if(nome == "CANCELAR") return;
        else if(nome.empty()) std::cout << "ERRO: nome invalido, digite novamente" << std::endl; 
        else break;;

    }
    
    

    while (true)
    {
        std::cout << "\nDigite a data de nascimento no formato DD/MM/AAAA (Digte CANCELAR se deseja cancelar): ";
        std::cin >> data_nascimento;
        if(data_nascimento == "CANCELAR") return;
        else if (!isDataNascimentoValido(data_nascimento))
            std::cout << "\nERRO: Formato inválido de data de nascimento\n"
                      << std::endl;
        else
            break;
    }

    Cliente* novo_cliente = new Cliente(cpf,nome,data_nascimento);
    this->_clientes.inserirCliente(novo_cliente);
    std::cout << "\nCliente de CPF: " << cpf << " cadastrado com sucesso" << std::endl;
}

void Sistema::listarClientesOrdenados() const
{
    this->_clientes.listarClientesOrdenados();
}

void Sistema::removerCliente()
{
    std::string cpf;
    
    while(true) {
        std::cout << "\nDigite o CPF do cliente (Digte CANCELAR se deseja cancelar): ";
        std::cin >> cpf;
        if(cpf == "CANCELAR") return;
        else if (!isCPFValido(cpf)) std::cout << "ERRO: Formato inválido de CPF" << std::endl;
        else break;
        
    }

    this->_clientes.removerCliente(cpf);
    
}

void Sistema::alugarFilmes()
{

    int id, dias;
    std::string cpf;

    while (true)
    {
        std::cout << "\nDigite o CPF no formato "
                     "XXX.XXX.XXX-XX"
                     "(Digite CANCELAR se deseja cancelar): ";
        std::cin >> cpf;

        if(cpf == "CANCELAR") return;
        else if (!isCPFValido(cpf)) std::cout << "\nERRO: Formato inválido de CPF" << std::endl;
        else if (!this->_clientes.clienteExiste(cpf)) std::cout << "\nERRO: CPF Inexistente na lista de clientes " << std::endl;
        else break;
    }

    
    int alugados = this->_locacao.getLocacoesPorCliente(cpf);
    std::cout << "Digite o id dos filmes desejados, você pode alugar até 10 filmes " << std::endl;
    std::cout << "Você já alugou " << alugados << " filmes" << std::endl;

    
    std::vector<Filme *> filmes;

    
    while (alugados <= QTD_MAXIMO_FILMES_ALUGADOS)
    {
        std::cout << "\nDigite o id do " << alugados + 1 << "° filme (Digite 0 se deseja cancelar, -1 se está satisfeito com os filmes alugados): ";
        std::cin >> id;

        if(id == 0) return;
        else if(id == -1) break;

        Filme *filme = this->_estoque.filmeValido(id);
        if (!filme){
            std::cout << "ERRO: não existe filme com indentificador " << id << ", digite novamente" << std::endl;
            continue;
        }

        if(!this->_estoque.filmeValido(id)) {
            std::cout << "Infelizmente o filme com indentificador " << id <<
            " não se encontra disponivel, por favor escolha outro filme" << std::endl;
            continue;
        } 

        filmes.push_back(filme);
        alugados++;
    }

    
    while (true)
    {
        std::cout << "\nDigite o n° de dias do aluguel (entre 1 e 7, ou 0 se deseja cancelar): ";
        std::cin >> dias;
        if(dias == 0) return;
        else if (!isDiasValido(dias)) std::cout << "ERRO: N° de dias invalido, digite novamente" << std::endl;
        else break;
            
    }

    this->_locacao.alugar(cpf, filmes, dias);
}

void Sistema::devolverFilmes()
{

    int id, dias, qtdTotal;
    int valorDaMulta = 0;

    std::vector<Filme *> filmes;

    std::string cpf;
    std::cout << "\nDigite CPF no formato "
                 "XXX.XXX.XXX-XX"
                 ": ";
    std::cin >> cpf;

    if (!this->_clientes.clienteExiste(cpf))
    {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }
    std::cout << "\nDigite a quantidade de filmes a serem devolvidos: ";
    std::cin >> qtdTotal;

    std::cout << "\nDigite o n° de dias decorridos desde o aluguel: ";
    std::cin >> dias;

    std::vector<int> ids;

    for (int i = 0; i < qtdTotal; i++)
    {
        std::cout << "\nDigite o id do filme " << i + 1 << ": ";
        std::cin >> id;

        Filme *filme = this->_estoque.filmeValido(id);
        if (filme != nullptr)
        {
            bool isDanificado;
            std::cout << "O filme " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta danificado?\n[0] - Nao\n[1] - Sim\nEscolha: ";
            std::cin >> isDanificado;

            if (filme->getTipo() == 1)
            { // Se o filme é fita, precisamos verificar se está rebobinado
                bool isRebobinado;
                std::cout << "A fita " << filme->getTitulo() << " - " << filme->getIdentificador() << " esta rebobinada?\n[0] - Nao\n[1] - Sim\nEscolha: ";
                std::cin >> isRebobinado;
                if (!isRebobinado)
                    valorDaMulta += 2;
            }

            valorDaMulta += this->_locacao.devolucao(cpf, filme, dias, isDanificado);
        }
    }

    std::cout << "\n\nDevolucoes realizadas com sucesso, valor de multas a serem liquidadas: " << valorDaMulta << std::endl;
}

void Sistema::listarLogLocacoes()
{
    this->_locacao.historicoLocacoes();
}

void Sistema::listarLocacoes()
{
    this->_locacao.relatorio();
}

void Sistema::limparTerminal()
{
    std::system("clear");
}

void Sistema::mostrarOpcoes()
{
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
    std::cout << " - LL: Listar Locações\n";
    std::cout << " - LH: Listar Historico Locações\n";
    std::cout << " - CL: Limpar Terminal\n";
    std::cout << " - MO: Mostrar Opções\n";
    std::cout << " - FS: Finalizar Sistema\n\n";
    std::cout << "========================================================\n";
}