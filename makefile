output: build/main.o build/Sistema.o build/Funcoes.o build/Estoque.o build/Filme.o build/Cadastro_Clientes.o build/Clientes.o build/Locacao.o 
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

build/Cadastro_Clientes.o: ./src/Cadastro_Clientes.cpp ./include/Cadastro_Clientes.hpp
	g++ -I ./include -c -g ./src/Cadastro_Clientes.cpp -o build/Cadastro_Clientes.o

${BUILD_DIR}/Clientes.o: ./${SRC_DIR}/Clientes.cpp ./${INCLUDE_DIR}/Clientes.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Clientes.cpp -o ${BUILD_DIR}/Clientes.o

${BUILD_DIR}/Locacao.o: ./${SRC_DIR}/Locacao.cpp ./${INCLUDE_DIR}/Locacao.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Locacao.cpp -o ${BUILD_DIR}/Locacao.o

build/Financeiro.o: ./src/Financeiro.cpp ./include/Financeiro.hpp
	g++ -I ./include -c -g ./src/Financeiro.cpp -o build/Financeiro.o

clean:
	rm ${BUILD_DIR}/*