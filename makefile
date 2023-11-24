output: main.o Cadastro_clientes.o Clientes.o Estoque.o Filme.o Funcoes.o Locacao.o Sistema.o
	g++ main.o Cadastro_clientes.o Clientes.o Estoque.o Filme.o Funcoes.o Locacao.o Sistema.o -o output

Cadastro_clientes.o: ./src/Cadastro_clientes.cpp
	g++ -I ./include -c ./src/Cadastro_clientes.cpp

Clientes.o: ./src/Clientes.cpp
	g++ -I ./include -c ./src/Clientes.cpp

Estoque.o: ./src/Estoque.cpp
	g++ -I ./include -c ./src/Estoque.cpp

Filme.o: ./src/Filme.cpp
	g++ -I ./include -c ./src/Filme.cpp

Funcoes.o: ./src/Funcoes.cpp
	g++ -I ./include -c ./src/Funcoes.cpp

Locacao.o: ./src/Locacao.cpp
	g++ -I ./include -c ./src/Locacao.cpp

Sistema.o: ./src/Sistema.cpp
	g++ -I ./include -c ./src/Sistema.cpp

main.o: ./src/main.cpp
	g++ -I ./include -c ./src/main.cpp

clean:
	rm *.o