#ifndef USUARIO_H
#define USUARIO_H

//BIBLIOTECAS
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//CLASSE ENDERECO
#include "Endereco.h"

using namespace std;

class Usuario
{
    public:
        Usuario(int tipo);
        string getNome();
        int getIndice();
        string getUsuario();
        string getSenha();

        void cabecalhoUsuario();
        void cadastrar(int id);
        void alterarCadastro();
        void removerCadastro();
        void carregarDados(string linha);

    protected:
        int tipo;
        int indice;
        string nomeCompleto;
        string telefone;
        Endereco endereco;
        string usuario;
        string senha;
};

#endif // USUARIO_H
