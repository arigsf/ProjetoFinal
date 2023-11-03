#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

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

void lerArquivo(string file, vector<Filme> &filmes) {


    ifstream movies(file, ios::in);
    // O Arquivo é aberto em modo de leitura

    if(!movies.is_open()) {
        cout << "Erro: arquivos inexistente" << endl;
        return;
        // Caso o arquivo não exista, uma mensagem de erro é exibida e a função é encerrada
    }


    char tipo;
    int quantidade, codigo, total = 0;
    vector <string> categorias_dvd = {"Lançamento", "Promoção", "Estoque"};
    string nome, categoria_dvd, linha;
    

    while (movies >> tipo >> quantidade >> codigo)
    {
        total++;
        // Os valores tipo(char), quantidade (int) e codigo(int) são lido separadamente
        getline(movies,linha);
        // Como não sabemos se o nome do filme tem mais de uma palavra, faremos uma analise posteriormente para separar a categoria do nome
        

        if(tipo == 'D') {
            // Caso o tipo de mídia seja Dvd, então ele terá obrigatóriamente uma categoria
            for (string categoria : categorias_dvd) // O foreach procurará na linha todos os tipos de categoria
            {
                size_t pos = linha.find(categoria); // A função find() retorna a primeira instancia da substring desejada
                if(pos != string::npos) { // se pos for diferende do valor falso esperado, encontramos a categoria certa
                    categoria_dvd = categoria;
                    linha.erase(pos,categoria.length()); // a função erase remove a substring da linha
                    removerEspacosDireitaEsquerda(linha);
                    nome = linha; 
                    // Assim o restante da linha será o nome do filme
                    break;
                }

                
                
            }
            
        }

        else {
            // Caso a mídia seja do tipo fita, então ela não terá categoria, e então a propria linha sera o nome do filme
            categoria_dvd = "None";
            nome = linha;
        }

        Filme filme(tipo,quantidade,codigo,nome,categoria_dvd);
        filmes.push_back(filme);
        // Uma nova instancia de filme é criada e armazenada
        
    } 
    cout << total << " Filmes cadastrados com sucesso" << endl;
    movies.close();
}






int main() {


    string filename, comando;
    vector<Filme> filmes;
    
    while (true)
    {

        cin >> comando;
        
        if(comando == "LA") {

            cin >> filename;
            lerArquivo(filename,filmes);

            
        }

        else if(comando == "LS") {
            // comando teste 

            for( vector<Filme>::iterator it = filmes.begin(); it!= filmes.end(); it++){
                it->Imprimir();
            }

        }

        else if(comando == "FS") break;
        
        
    }
    

    
    



}