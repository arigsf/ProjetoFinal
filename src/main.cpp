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
            sistema_principal.cadastrarFilme(novo_filme);
            
        }
        
        else if(comando == REMOVER_FILME) {
            int identificador;
            std::cin >> identificador;
            sistema_principal.removerFilme(identificador);
        } 

        else if(comando == LISTAR_FILMES) {
            std::string ordenacao;
            std::cin >> ordenacao;
            sistema_principal.listarFilmesOrdenados(ordenacao);

            
        }
        
        else if(comando == FINALIZAR_SISTEMA) {
            sistema_principal.finalizarSistema();
            break;
        }
                
    }
    
}