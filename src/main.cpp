#include "Sistema.hpp"

const std::string LER_ARQUIVO = "LA";
const std::string CADASTRAR_FILME = "CA";
const std::string REMOVER_FILME = "RF";
const std::string CADASTRAR_CLIENTE = "CC";
const std::string LISTAR_FILMES = "LF";
const std::string REMOVER_ClIENTES = "RC";
const std::string LISTAR_CLIENTES = "LC";
const std::string ALUGAR_FILME = "AL";
const std::string DEVOLVER_FILME = "DV";
const std::string FINALIZAR_SISTEMA = "FS";


int main() {

    std::string comando;
    Sistema sistema_principal;
    
    while (true) {        
        std::cin >> comando;

        if(comando == LER_ARQUIVO) sistema_principal.lerArquivo();
        else if(comando == CADASTRAR_FILME) sistema_principal.cadastrarFilme();
        else if(comando == REMOVER_FILME) sistema_principal.removerFilme();
        else if(comando == LISTAR_FILMES) sistema_principal.listarFilmesOrdenados();
        else if(comando == CADASTRAR_CLIENTE) sistema_principal.cadastrarCliente();
        else if(comando == REMOVER_ClIENTES) sistema_principal.removerCliente();
        else if(comando == LISTAR_CLIENTES) sistema_principal.listarClientesOrdenados();
        else if(comando == ALUGAR_FILME) sistema_principal.alugarFilmes();
        else if(comando == DEVOLVER_FILME) sistema_principal.devolverFilmes();
        else if(comando == FINALIZAR_SISTEMA) break;
                
    }
    
}