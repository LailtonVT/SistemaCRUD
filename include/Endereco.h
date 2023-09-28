#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>
#include <string>

using namespace std;

class Endereco
{
    public:
        Endereco();
        void lerEndereco();
        void exibirEndereco();
        string getCidade();
        string getEstado();
        string getBairro();
        string getRua();
        int getNumero();
        void setCidade(string c);
        void setEstado(string e);
        void setBairro(string b);
        void setRua(string r);
        void setNumero(int n);

    private:
        string cidade, estado, bairro, rua;
        int numero;
};

#endif // ENDERECO_H
