#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream arquivo("seuarquivo.txt"); // Substitua "seuarquivo.txt" pelo nome do seu arquivo

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    char tipo;
    int quantidade, codigo;
    string titulo, categoria;

    while (arquivo >> tipo >> quantidade >> codigo >> ws) {  // "ws" consome os espaços em branco após o código
        getline(arquivo, titulo);

        cout << "Tipo: " << tipo << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Código: " << codigo << endl;
        cout << "Título: " << titulo << endl;

        if (tipo == 'D') {
            arquivo >> ws;  // Consumir espaços em branco antes de ler a categoria
            getline(arquivo, categoria);
            cout << "Categoria: " << categoria << endl;
        }
    }

    arquivo.close();

    return 0;
}
