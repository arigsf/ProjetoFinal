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
            std::string nome_arquivo;
            std::cin >> nome_arquivo;
            sistema_principal.lerArquivo(nome_arquivo);
        }

        else if(comando == FINALIZAR_SISTEMA) {
            sistema_principal.salvarDados();
            break;
        }
                
    }
    
}