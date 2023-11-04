#include "../include/Sistema.hpp"



void Sistema::lerArquivo(std::string nome_do_arquivo) {

   
    std::ifstream arquivo_filmes(nome_do_arquivo, std::ios::in);
    // O Arquivo é aberto em modo de leitura

    if(!arquivo_filmes.is_open()) {
        std::cout << "Erro: arquivos inexistente" << std::endl;
        return;
        // Caso o arquivo não exista, uma mensagem de erro é exibida e a função é encerrada
    }


    char tipo_item;
    int unidades_item, categoria_dvd, codigo_item, total = 0;
    std::string titulo_item;
    

    while (arquivo_filmes >> tipo_item >> unidades_item >> codigo_item)
    {
        total++; // Os valores tipo(char), quantidade (int) e codigo(int) são lido separadamente
        std::getline(arquivo_filmes,titulo_item); // Como não sabemos se o nome do filme tem mais de uma palavra, faremos uma analise posteriormente para separar a categoria do nome

        if(tipo_item == 'D') {
            categoria_dvd = separarTituloCategoria(titulo_item);
            DVD * novo_dvd = new DVD(unidades_item,codigo_item,titulo_item,categoria_dvd);
            lista_Filmes.push_back(novo_dvd);

        }

        else if(tipo_item == 'F') {
            FITA * nova_fita = new FITA(unidades_item,codigo_item,titulo_item,true);
            lista_Filmes.push_back(nova_fita);
        }
    } 

    std::cout << total<< " Filmes cadastrados com sucesso" << std::endl;
    arquivo_filmes.close();
}


void Sistema::adcionarFilme(Filme *filme) {
    this->lista_Filmes.push_back(filme);
}



void Sistema::salvarDados() {
    std::ofstream arquivo_filmes("../backups/filmes_backup",std::ios::out | std::ios::trunc);

    if(!arquivo_filmes.is_open()) {
        std::cout << "Erro: não foi possível criar o arquivo" << std::endl;
        return;
    }


    for (Filme *filme : this->lista_Filmes)
    {
        arquivo_filmes << filme->listarInformacoes() << std::endl;
        delete filme;
    }
    

    arquivo_filmes.close();

    
}
