#include "Sistema.hpp"

const std::string LER_ARQUIVO = "LA";
const std::string CADASTRAR_FILME = "CA";
const std::string REMOVER_FILME = "RF";
const std::string CADASTRAR_CLIENTE = "CC";
const std::string LISTAR_FILMES = "LF";
const std::string REMOVER_CLIENTES = "RC";
const std::string LISTAR_CLIENTES = "LC";
const std::string ALUGAR_FILME = "AL";
const std::string DEVOLVER_FILME = "DV";
const std::string FINALIZAR_SISTEMA = "FS";


int main() {
    std::cout << "Lendo arquivos" << std::flush;

    for (int i=0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "." << std::flush;
            usleep(700000);
        }
        std::cout << "\b\b\b   \b\b\b";
    }
    std::cout << "\n\n";

    std::string comando;
    Sistema sistema_principal;

    sleep(2);
    std::cout << "\n\n========================================================\n";
    std::cout << "   _______            ___    __                       __\n";
    std::cout << "  / ____(_)___  ___  /   |  / /_  ______ ___  _____  / /\n";
    std::cout << " / /   / / __ \\/ _ \\/ /| | / / / / / __ `/ / / / _ \\/ / \n";
    std::cout << "/ /___/ / / / /  __/ ___ |/ / /_/ / /_/ / /_/ /  __/ /  \n";
    std::cout << "\\____/_/_/ /_/\\___/_/  |_/_/\\__,_/\\__, /\\__,_/\\___/_/   \n";
    std::cout << "                                 /____/                 \n";
    std::cout << "========================================================\n\n";

    std::cout << "Opções disponíveis:\n";
    std::cout << " - " << LER_ARQUIVO << ": Ler Arquivo\n";
    std::cout << " - " << CADASTRAR_FILME << ": Cadastrar Filme\n";
    std::cout << " - " << REMOVER_FILME << ": Remover Filme\n";
    std::cout << " - " << CADASTRAR_CLIENTE << ": Cadastrar Cliente\n";
    std::cout << " - " << LISTAR_FILMES << ": Listar Filmes\n";
    std::cout << " - " << REMOVER_CLIENTES << ": Remover Clientes\n";
    std::cout << " - " << LISTAR_CLIENTES << ": Listar Clientes\n";
    std::cout << " - " << ALUGAR_FILME << ": Alugar Filme\n";
    std::cout << " - " << DEVOLVER_FILME << ": Devolver Filme\n";
    std::cout << " - " << FINALIZAR_SISTEMA << ": Finalizar Sistema\n\n";
    std::cout << "========================================================\n";
    
    while (true) {
        std::cout << "\nComando: ";
        std::cin >> comando;

        if(comando == LER_ARQUIVO) sistema_principal.lerArquivo();
        else if(comando == CADASTRAR_FILME) sistema_principal.cadastrarFilme();
        else if(comando == REMOVER_FILME) sistema_principal.removerFilme();
        else if(comando == LISTAR_FILMES) sistema_principal.listarFilmesOrdenados();
        else if(comando == CADASTRAR_CLIENTE) sistema_principal.cadastrarCliente();
        else if(comando == REMOVER_CLIENTES) sistema_principal.removerCliente();
        else if(comando == LISTAR_CLIENTES) sistema_principal.listarClientesOrdenados();
        else if(comando == ALUGAR_FILME) sistema_principal.alugarFilmes();
        else if(comando == DEVOLVER_FILME) sistema_principal.devolverFilmes();
        else if(comando == FINALIZAR_SISTEMA) break;
                
    }
    
}