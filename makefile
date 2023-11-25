output: build/main.o build/Sistema.o build/Funcoes.o build/Estoque.o build/Filme.o build/cadastro_clientes.o build/clientes.o build/Locacao.o 
	g++ -g build/*.o -o ./build/output

build/main.o: ./src/main.cpp ./include/Sistema.hpp
	g++ -I ./include -c -g ./src/main.cpp -o build/main.o

build/Sistema.o: ./src/Sistema.cpp ./include/Sistema.hpp
	g++ -I ./include -c -g ./src/Sistema.cpp -o build/Sistema.o

build/Funcoes.o: ./src/Funcoes.cpp ./include/Funcoes.hpp
	g++ -I ./include -c -g ./src/Funcoes.cpp -o build/Funcoes.o


build/Estoque.o: ./src/Estoque.cpp ./include/Estoque.hpp
	g++ -I ./include -c -g ./src/Estoque.cpp -o build/Estoque.o

build/Filme.o: ./src/Filme.cpp ./include/Filme.hpp
	g++ -I ./include -c -g ./src/Filme.cpp -o build/Filme.o

build/cadastro_clientes.o: ./src/cadastro_clientes.cpp ./include/cadastro_clientes.hpp
	g++ -I ./include -c -g ./src/cadastro_clientes.cpp -o build/cadastro_clientes.o

build/clientes.o: ./src/clientes.cpp ./include/clientes.hpp
	g++ -I ./include -c -g ./src/clientes.cpp -o build/clientes.o

build/Locacao.o: ./src/Locacao.cpp ./include/Locacao.hpp
	g++ -I ./include -c -g ./src/Locacao.cpp -o build/Locacao.o

clean:
	rm build/*