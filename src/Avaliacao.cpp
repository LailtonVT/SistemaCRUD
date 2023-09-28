#include "Avaliacao.h"

Avaliacao::Avaliacao()
{
    soma = 0;
    media = 0;
}

int Avaliacao::getIfFornecedor(){
    return idFornecedor;
}
int Avaliacao::getQtdClientes(){
    return qtdClientesAva;
}
int Avaliacao::getSoma(){
    return soma;
}
float Avaliacao::getMedia(){
    return soma/static_cast<float>(qtdClientesAva);
}
void Avaliacao::setIfFornecedor(int idf){
    idFornecedor = idf;
}
void Avaliacao::setQtdClientes(int qtdCl){
    qtdClientesAva = qtdCl;
}
void Avaliacao::setSoma(int s){
    soma = s;
}

void Avaliacao::salvarAvaliacao(ofstream& arquivo){
    arquivo << idFornecedor << ",";
    arquivo << qtdClientesAva << ",";
    arquivo << soma << endl;
}

void Avaliacao::carregarAvaliacao(string linha){
    istringstream iss(linha);
    string token;
    int h, m;
    int contador = 0;
    while (getline(iss, token, ',')) {
        switch (contador) {
            case 0: idFornecedor = stoi(token); break;
            case 1: qtdClientesAva = stoi(token); break;
            case 2: soma = stoi(token); break;
        }
        contador++;
    }
}
