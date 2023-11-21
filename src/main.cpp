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
    
    while (true) {        
        std::cin >> comando;

        if(comando == LER_ARQUIVO) {
            std::string diretorio;
            std::cin >> diretorio;
            sistema_principal.lerArquivo(diretorio);
        }
        
        else if(comando == CADASTRAR_FILME) {
            char tipo;
            std::string titulo;
            Filme *filme;
            int unidades, identificador;

            std::cin >> tipo >> unidades >> identificador;
            std::cin.ignore();
            std::getline(std::cin,titulo);

            if(tipo == 'D') {
                std::string categoria;
                std::cin >> categoria;

                int indice_categoria = -1;
                for (std::map<int,std::string>::const_iterator it = Categorias.begin(); it != Categorias.end();it++)
                    if(it->second == categoria) indice_categoria = it->first;

                filme = new DVD(unidades,identificador,titulo,indice_categoria);
            }

            else if(tipo == 'F') filme = new FITA(unidades,identificador,titulo,retornaVerdadeiroFalso());
            
            sistema_principal.cadastrarFilme(filme);
            
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

        else if(comando == CADASTRAR_CLIENTE) {
            std::string cpf, nome, data_nascimento;
            std::cin >> cpf >> nome >> data_nascimento;
            Cliente* novo_cliente = new Cliente(cpf,nome,data_nascimento);
            sistema_principal.cadastrarCliente(novo_cliente);
        }

        else if(comando == LISTAR_CLIENTES) {
            std::string ordenacao;
            std::cin >> ordenacao;
            sistema_principal.listarClientesOrdenados(ordenacao);
        }

        else if(comando == REMOVER_ClIENTES) {
            std::string cpf;
            std::cin >> cpf;
            sistema_principal.removerCliente(cpf);
        }


        else if(comando == ALUGAR_FILME) {
            
            int id;
            std::string cpf;
            std::cin >> cpf;
            std::vector<int> ids;

            
            while (true) {   

                std::cin >> id;
                if(id  <= 0) break;
                ids.push_back(id);
            }

            sistema_principal.alugarFilmes(cpf, ids);
            
            
        }

        else if(comando == DEVOLVER_FILME) {

            int dias;
            std::string cpf;
            std::cin >> cpf, dias;
            sistema_principal.devolverFilmes(cpf,dias);
            
        }

        
        else if(comando == FINALIZAR_SISTEMA) {
            sistema_principal.finalizarSistema();
            break;
        }
                
    }
    
}