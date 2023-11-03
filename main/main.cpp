#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#define LER_ARQUIVO "LA"
#define CADASTRAR_FILME "CA"
#define REMOVER_FILME "RF"
#define CADASTRAR_CLIENTE "CC"
#define LISTAR_FILMES "LF"
#define REMOVER_ClIENTES "RC"
#define LISTAR_CLIENTES "LC"
#define ALUGAR_FILME "AL"
#define DEVOLVER_FILME "DV"
#define FINALIZAR_SISTEMA "FS"


using namespace std;

// classe feita apenas para fins de teste
class Filme
{
    
public:
    char tipo;
    int quantidade, codigo;
    string nome, dvd_tipo;
    Filme(char tipo, int quantidade, int codigo, string nome, string dvd_tipo);
    void Imprimir();
};

Filme::Filme(char tipo, int quantidade, int codigo, string nome, string dvd_tipo): tipo(tipo),
quantidade(quantidade), codigo(codigo), nome(nome), dvd_tipo(dvd_tipo)
{
}


void Filme::Imprimir() {
    cout <<  codigo << " " << tipo << " " << quantidade << " " << nome << " " << dvd_tipo << endl;
}


void removerEspacosDireitaEsquerda(string &linha)  {
    
    linha.erase(0,linha.find_first_not_of(' ')); 
    // remove os espaços a direita, a função find_first_not_of retorna o primeiro caracter que não é um espaço
    linha.erase(linha.find_last_not_of(' ')+1); // remove os espaços a esquerda, a função find_last_not_of retorna o ultimo caracter que não é um espaço
}

void lerArquivo(vector<Filme> &filmes) {

    string nome_arquivo;
    cin >> nome_arquivo;

    ifstream arquivo_filmes(nome_arquivo, ios::in);
    // O Arquivo é aberto em modo de leitura

    if(!arquivo_filmes.is_open()) {
        cout << "Erro: arquivos inexistente" << endl;
        return;
        // Caso o arquivo não exista, uma mensagem de erro é exibida e a função é encerrada
    }


    char tipo_item;
    int quantidade_cada_filme, codigo_item, total_filmes_unicos = 0;
    vector <string> categorias_dvd = {"Lançamento", "Promoção", "Estoque"};
    string titulo_item, categoria_dvd, linha;
    

    while (arquivo_filmes >> tipo_item >> quantidade_cada_filme >> codigo_item)
    {
        total_filmes_unicos++;
        // Os valores tipo(char), quantidade (int) e codigo(int) são lido separadamente
        getline(arquivo_filmes,linha);
        // Como não sabemos se o nome do filme tem mais de uma palavra, faremos uma analise posteriormente para separar a categoria do nome
        

        if(tipo_item == 'D') {
            // Caso o tipo de mídia seja Dvd, então ele terá obrigatóriamente uma categoria
            for (string categoria : categorias_dvd) // O foreach procurará na linha todos os tipos de categoria
            {
                size_t pos = linha.find(categoria); // A função find() retorna a primeira instancia da substring desejada
                if(pos != string::npos) { // se pos for diferende do valor falso esperado, encontramos a categoria certa
                    categoria_dvd = categoria;
                    linha.erase(pos,categoria.length()); // a função erase remove a substring da linha
                    removerEspacosDireitaEsquerda(linha);
                    titulo_item = linha; 
                    // Assim o restante da linha será o nome do filme
                    break;
                }

                
                
            }
            
        }

        else {
            // Caso a mídia seja do tipo fita, então ela não terá categoria, e então a propria linha sera o nome do filme
            categoria_dvd = "None";
            titulo_item = linha;
        }

        Filme filme(tipo_item,quantidade_cada_filme,codigo_item,titulo_item,categoria_dvd);
        filmes.push_back(filme);
        // Uma nova instancia de filme é criada e armazenada
        
    } 
    cout << total_filmes_unicos << " Filmes cadastrados com sucesso" << endl;
    arquivo_filmes.close();
}

void salvarDados(vector<Filme> &filmes) {
    ofstream arquivo_filmes("../backups/filmes_backup",ios::out | ios::trunc);

    if(!arquivo_filmes.is_open()) {
        cout << "Erro: não foi possível criar o arquivo" << endl;
        return;
        // Caso o arquivo não seja criado, uma mensagem de erro é exibida e a função é encerrada
    }

    for(Filme &filme : filmes) 
        arquivo_filmes << filme.tipo  << " " << filme.codigo << " " << filme.quantidade << 
        " " << filme.codigo << " " << filme.nome << " " << filme.dvd_tipo << endl;

    arquivo_filmes.close();

}




int main() {

    string comando;
    vector<Filme> filmes;
    
    while (true)
    {
        cin >> comando;
        
        if(comando == LER_ARQUIVO) lerArquivo(filmes);

        else if(comando == "LS") {
            // comando teste 

            for( vector<Filme>::iterator it = filmes.begin(); it!= filmes.end(); it++){
                it->Imprimir();
            }

        }

        else if(comando == FINALIZAR_SISTEMA) {
            salvarDados(filmes);
            break;
        }
            
        
        
    }
    

    
    



}