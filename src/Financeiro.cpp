#include "Financeiro.hpp"

Financeiro::Financeiro() {
    std::ifstream arquivo(DIRETORIO_HISTORICO_FINANCEIRO, std::ios::in);

    if(!arquivo.is_open()) {
        std::cout << "Arquivo de histórico financeiro não encontrado.\nFavor inserir o saldo manualmente: R$";
        float saldo; std::cin >> saldo;

        while(saldo < 0) {
            std::cout << "\nSaldo inválido, favor inserir novamente: R$";
            std::cin >> saldo;
        } 
    }
    std::string linha;

    std::getline(arquivo, linha);
    std::istringstream iss(linha);
    iss >> this->saldo; // inicializa o saldo com a primeira linha do arquivo;

    while(std::getline(arquivo, linha)) {
        Data d; char delimiter;

        std::istringstream iss(linha);
        iss >> d.dia >> delimiter >>  d.mes >> delimiter >> d.ano;

        char tipo; iss >> tipo;
        int valor; iss >> valor;
        int saldo_final; iss >> saldo_final;
        this->transacoes.push_back(Transacao(d, tipo, valor, saldo_final));
    }
    
    arquivo.close();
}

Financeiro::~Financeiro() {
    this->salvarDados();
}

bool Financeiro::deposito(float valor) {
    if (valor > 0) {
        Data data;
        this->saldo += valor;
        Transacao transacao(data, 'D', valor, saldo);

        transacoes.push_front(transacao);

        return true;
    } 
        
    std::cout << "ERRO: Valor inválido" << std::endl;
    return false;
    
}

bool Financeiro::saque(float valor) {
    if (valor <= 0) {
        std::cout << "ERRO: Valor inválido" << std::endl;
        return false;
    }

    if (valor > saldo) {
        std::cout << std::fixed << std::setprecision(2) <<  "\nValor indisponível, saldo atual de R$" << saldo << std::endl; 
        return false;
    }
    
    Data data;
    this->saldo -= valor;
    Transacao transacao(data, 'S', valor, saldo);

    transacoes.push_front(transacao);

    std::cout << std::fixed << std::setprecision(2) <<  "Saque de R$" << valor << " realizado com sucesso!\nSaldo atual: R$" << saldo << std::endl;

    return true; 
}

float Financeiro::getSaldo() {
    return this->saldo;
}

void Financeiro::historicoTransacoes() {
    char escolha; std::cout << "\nSelecione o intervalo desejado para visualizar o histórico de transações!\n[D] - Dia atual\n[M] - Mês\n[T] - Total\n\nEscolha: ";
    std::cin >> escolha;

    Data d;

    if(escolha == 'D') {
        if(this->transacoes[0].data.dia != d.dia) {// Se a transação mais recente não for do dia atual, então não há nenhuma transação no dia atual
            std::cout << "\nNão há nenhuma transação referente ao dia de hoje" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|     Data     |   Tipo  |      Valor       |    Saldo Final  |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for(auto t : transacoes) {
            if( t.data.dia != d.dia) break;
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
        return;
    }
    if(escolha == 'M') {
        if(this->transacoes[0].data.mes != d.mes) {// Se a transação mais recente não for do mes atual, então não há nenhuma transação no mes atual
            std::cout << "\nNão há nenhuma transação referente ao mes de hoje" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|     Data     |   Tipo  |      Valor       |    Saldo Final  |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for(auto t : transacoes) {
            if( t.data.mes != d.mes) break;
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
        return;
    }
    if(escolha == 'T') {
        if(!this->transacoes.size()) {
            std::cout << "Não há nenhuma transação a ser mostrada" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|    Data     |   Tipo  |      Valor       |    Saldo Final   |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for(auto t : transacoes) {
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
    }
}

void Financeiro::salvarDados() {
    std::ofstream arquivo(DIRETORIO_HISTORICO_FINANCEIRO, std::ios::out | std::ios::trunc);

    if(!arquivo.is_open()) {
        std::cout << "Erro: não foi possível criar/encontrar o arquivo para salvar o histórico financeiro" << std::endl;
        return;
    }

    arquivo << this->saldo << std::endl;
    for(auto t : transacoes){
        if(t.data.dia < 10) arquivo << '0';

        arquivo << t.data.dia << '/' << t.data.mes << '/' << t.data.ano << ' ' << t.tipo << ' ' << t.valor << ' ' << t.saldo_final << std::endl;
    } 
    
    arquivo.close();
}

Transacao::Transacao(Data _data, char _tipo, float _valor, float _saldo_final) : 
    data(_data), tipo(_tipo), valor(_valor), saldo_final(_saldo_final) {}


void Transacao::imprimeTransacao() {
        std::stringstream ss1, ss2; 
        ss1 << std::fixed << std::setprecision(2) << this->valor;
        ss2 << std::fixed << std::setprecision(2) << this->saldo_final;

        std::string valorString = ss1.str();
        std::string saldoString = ss2.str();

        std::cout << "| ";
        if(data.dia < 10) std::cout << '0';
        std::cout << data.dia << '/' << data.mes << '/' << data.ano << ' ' << " |";
        std::cout << "    " << tipo << "    |";
        std::cout << "     " << valorString;
        for(auto i=0; i<13-(int)valorString.size(); i++) std::cout << ' ';
        std::cout << "|     " << saldoString;
        for(auto i=0; i<13-(int)saldoString.size(); i++) std::cout << ' ';
        std::cout << '|';
        
}