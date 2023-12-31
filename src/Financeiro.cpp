#include "Financeiro.hpp"

/**
 * @file Financeiro.cpp
 * @brief Implementação da classe Financeiro.
 */

Financeiro::Financeiro()
{
    std::ifstream arquivo(DIRETORIO_HISTORICO_FINANCEIRO, std::ios::in);

    if (!arquivo.is_open())
    {
        std::cout << "Arquivo de historico financeiro nao encontrado.\nFavor inserir o saldo manualmente: R$";
        float saldo;
        std::cin >> saldo;

        while (saldo < 0)
        {
            std::cout << "\nSaldo invalido, favor inserir novamente: R$";
            std::cin >> saldo;
        }
    }
    std::string linha;

    std::getline(arquivo, linha);
    std::istringstream iss(linha);
    iss >> this->saldo; // inicializa o saldo com a primeira linha do arquivo;

    while (std::getline(arquivo, linha))
    {
        Data d;
        char delimiter;

        std::istringstream iss(linha);
        iss >> d.dia >> delimiter >> d.mes >> delimiter >> d.ano;

        char tipo;
        iss >> tipo;
        float valor;
        iss >> valor;
        float saldo_final;
        iss >> saldo_final;
        this->transacoes.push_back(Transacao(d, tipo, valor, saldo_final));
    }

    arquivo.close();
}

Financeiro::~Financeiro()
{
    this->salvarDados();
}

bool Financeiro::deposito(float valor)
{
    if (valor > 0)
    {
        Data data;
        this->saldo += valor;
        Transacao transacao(data, 'D', valor, saldo);

        transacoes.push_front(transacao);

        return true;
    }

    std::cout << "ERRO: Valor invalido" << std::endl;
    return false;
}

bool Financeiro::saque(float valor)
{
    if (valor <= 0)
    {
        std::cout << "ERRO: Valor invalido" << std::endl;
        return false;
    }

    if (valor > saldo)
    {
        std::cout << std::fixed << std::setprecision(2) << "\nValor indisponivel, saldo atual de R$" << saldo << std::endl;
        return false;
    }

    Data data;
    this->saldo -= valor;
    Transacao transacao(data, 'S', valor, saldo);

    transacoes.push_front(transacao);

    std::cout << std::fixed << std::setprecision(2) << "Saque de R$" << valor << " realizado com sucesso!\nSaldo atual: R$" << saldo << std::endl;

    return true;
}

float Financeiro::getSaldo()
{
    return this->saldo;
}

void Financeiro::historicoTransacoes()
{
    std::string escolha;
    
    while (true)
    {   
        std::cout << "\nSelecione o intervalo desejado para visualizar o historico de transacoes!\n[D] - Dia atual\n[M] - Mês\n[T] - Total\n\nEscolha (Digite CANCELAR se deseja cancelar): ";
        std::cin >> escolha;
        escolha = toUpperCase(escolha);
        if(escolha == "CANCELAR")
            return;
        else if((escolha[0] != DIA && escolha[0] != MES && escolha[0] != TOTAL) || escolha.size() > 1)
            std::cout << "Erro : Categoria invalida, digite novamente" << std::endl;
        else 
            break;
    }
    
    

    Data d;

    if (escolha[0] == DIA)
    {
        if (this->transacoes[0].data.dia != d.dia)
        { // Se a transação mais recente não for do dia atual, então não há nenhuma transação no dia atual
            std::cout << "\nNao ha nenhuma transacao referente ao dia de hoje" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|     Data     |   Tipo  |      Valor       |    Saldo Final  |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for (auto t : transacoes)
        {
            if (t.data.dia != d.dia)
                break;
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
        return;
    }
    if (escolha[0] == MES)
    {
        if (this->transacoes[0].data.mes != d.mes)
        { // Se a transação mais recente não for do mes atual, então não há nenhuma transação no mes atual
            std::cout << "\nNao ha nenhuma transacao referente ao mes de hoje" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|     Data     |   Tipo  |      Valor       |    Saldo Final  |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for (auto t : transacoes)
        {
            if (t.data.mes != d.mes)
                break;
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
        return;
    }
    if (escolha[0] == TOTAL)
    {
        if (!this->transacoes.size())
        {
            std::cout << "Nao ha nenhuma transcao a ser mostrada" << std::endl;
            return;
        }
        std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        std::cout << "|    Data     |   Tipo  |      Valor       |    Saldo Final   |" << std::endl;
        std::cout << "|-------------------------------------------------------------|" << std::endl;
        for (auto t : transacoes)
        {
            t.imprimeTransacao();
            std::cout << "\n|-------------------------------------------------------------|" << std::endl;
        }
    }
}

void Financeiro::salvarDados()
{
    std::ofstream arquivo(DIRETORIO_HISTORICO_FINANCEIRO, std::ios::out | std::ios::trunc);

    if (!arquivo.is_open())
    {
        std::cout << "Erro: nao foi possivel criar/encontrar o arquivo para salvar o historico financeiro" << std::endl;
        return;
    }

    arquivo << this->saldo << std::endl;
    for (auto t : transacoes)
    {
        if (t.data.dia < 10)
            arquivo << '0';

        arquivo << t.data.dia << '/' << t.data.mes << '/' << t.data.ano << ' ' << t.tipo << ' ' << t.valor << ' ' << t.saldo_final << std::endl;
    }

    arquivo.close();
}

void Financeiro::cancelarUltimaTransacao()
{
    if (transacoes[0].tipo == 'D')
        saldo -= transacoes[0].valor;
    else if (transacoes[0].tipo == 'S')
        saldo += transacoes[0].valor;
    else
    {
        std::cout << "ERRO: Nao foi possivel cancelar a ultima transacao" << std::endl;
        return;
    }

    this->transacoes.pop_front();
    std::cout << "\nTransacao cancelada com sucesso" << std::endl;
}

Transacao::Transacao(Data _data, char _tipo, float _valor, float _saldo_final) : data(_data), tipo(_tipo), valor(_valor), saldo_final(_saldo_final) {}

void Transacao::imprimeTransacao()
{
    std::stringstream ss1, ss2;
    ss1 << std::fixed << std::setprecision(2) << this->valor;
    ss2 << std::fixed << std::setprecision(2) << this->saldo_final;

    std::string valorString = ss1.str();
    std::string saldoString = ss2.str();

    std::cout << "| ";
    if (data.dia < 10)
        std::cout << '0';
    std::cout << data.dia << '/' << data.mes << '/' << data.ano << ' ' << " |";
    std::cout << "    " << tipo << "    |";
    std::cout << "     " << valorString;
    for (auto i = 0; i < 13 - (int)valorString.size(); i++)
        std::cout << ' ';
    std::cout << "|     " << saldoString;
    for (auto i = 0; i < 13 - (int)saldoString.size(); i++)
        std::cout << ' ';
    std::cout << '|';
}