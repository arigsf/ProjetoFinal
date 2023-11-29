CC=g++
CFLAGS=-std=c++11 -Wall
TARGET =output

ifdef DEBUG

endif

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include


${${BUILD_DIR}_DIR}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/Sistema.o ${BUILD_DIR}/Funcoes.o ${BUILD_DIR}/Estoque.o ${BUILD_DIR}/Filme.o ${BUILD_DIR}/Cadastro_Clientes.o ${BUILD_DIR}/Clientes.o ${BUILD_DIR}/Locacao.o ${BUILD_DIR}/Financeiro.o 
	${CC} ${CFLAGS} -g ${BUILD_DIR}/*.o -o ./${BUILD_DIR}/${TARGET}

${BUILD_DIR}/main.o: ./${SRC_DIR}/main.cpp ./${INCLUDE_DIR}/Sistema.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Sistema.o: ./${SRC_DIR}/Sistema.cpp ./${INCLUDE_DIR}/Sistema.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Sistema.cpp -o ${BUILD_DIR}/Sistema.o

${BUILD_DIR}/Funcoes.o: ./${SRC_DIR}/Funcoes.cpp ./${INCLUDE_DIR}/Funcoes.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Funcoes.cpp -o ${BUILD_DIR}/Funcoes.o

${BUILD_DIR}/Estoque.o: ./${SRC_DIR}/Estoque.cpp ./${INCLUDE_DIR}/Estoque.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Estoque.cpp -o ${BUILD_DIR}/Estoque.o

${BUILD_DIR}/Filme.o: ./${SRC_DIR}/Filme.cpp ./${INCLUDE_DIR}/Filme.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Filme.cpp -o ${BUILD_DIR}/Filme.o

${BUILD_DIR}/Cadastro_Clientes.o: ./${SRC_DIR}/Cadastro_Clientes.cpp ./${INCLUDE_DIR}/Cadastro_Clientes.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Cadastro_Clientes.cpp -o ${BUILD_DIR}/Cadastro_Clientes.o

${BUILD_DIR}/Clientes.o: ./${SRC_DIR}/Clientes.cpp ./${INCLUDE_DIR}/Clientes.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Clientes.cpp -o ${BUILD_DIR}/Clientes.o

${BUILD_DIR}/Locacao.o: ./${SRC_DIR}/Locacao.cpp ./${INCLUDE_DIR}/Locacao.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Locacao.cpp -o ${BUILD_DIR}/Locacao.o

${BUILD_DIR}/Financeiro.o: ./${SRC_DIR}/Financeiro.cpp ./${INCLUDE_DIR}/Financeiro.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c -g ./${SRC_DIR}/Financeiro.cpp -o ${BUILD_DIR}/Financeiro.o

clean:
	rm ${BUILD_DIR}/*