#include "../include/Sistema.hpp"

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
    
    while (true)
    {        
        std::cin >> comando;
        
        if(comando == LER_ARQUIVO) {
            std::string diretorio;
            std::cin >> diretorio;
            sistema_principal.lerArquivo(diretorio);
        }
        
        else if(comando == CADASTRAR_FILME) {
            Filme* novo_filme = lerFilme();
            if(novo_filme) sistema_principal.cadastrarFilme(novo_filme); // Se novo_filme não for nulo
            else {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Dados inválidos, por favor tente novamente" << std::endl;
            } 
        }
        else if(comando == REMOVER_FILME) {
            int identificador;
            std::cin >> identificador;
            sistema_principal.removerFilme(identificador);
        } 
        else if(comando == LISTAR_FILMES) {
            char codigo_titulo;
            std::cin >> codigo_titulo;

            if(codigo_titulo == 'C') sistema_principal.listarFilmesOrdenados(true);
            else if(codigo_titulo == 'T') sistema_principal.listarFilmesOrdenados(false);
            
            
        }
        
        else if(comando == FINALIZAR_SISTEMA) {
            
            break;
        }
                
    }
    
}