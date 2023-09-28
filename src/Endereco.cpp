#include "Endereco.h"

Endereco::Endereco()
{
}

void Endereco::lerEndereco(){
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "Estado: ";
    getline(cin, estado);
    cout << "Bairro: ";
    getline(cin, bairro);
    cout << "Rua: ";
    getline(cin, rua);
    cout << "N�mero: ";
    cin >> numero;
    cin.ignore();
}
void Endereco::exibirEndereco(){
    cout << cidade << " - " << estado << endl;
    cout << "Bairro: " << bairro << endl;
    cout << "Rua: " << rua << endl;
    cout << "N�mero: " << numero << endl;
}

string Endereco::getCidade(){
    return cidade;
}
string Endereco::getEstado(){
    return estado;
}
string Endereco::getBairro(){
    return bairro;
}
string Endereco::getRua(){
    return rua;
}
int Endereco::getNumero(){
    return numero;
}

void Endereco::setCidade(string c){
    cidade = c;
}
void Endereco::setEstado(string e){
    estado = e;
}
void Endereco::setBairro(string b){
    bairro = b;
}
void Endereco::setRua(string r){
    rua = r;
}
void Endereco::setNumero(int n){
    numero = n;
}
