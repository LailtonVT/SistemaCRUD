#ifndef AVALIACAO_H
#define AVALIACAO_H
#include "App.h"

class Avaliacao
{
    public:
        Avaliacao();
        int getIfFornecedor();
        int getQtdClientes();
        int getSoma();
        float getMedia();
        void setIfFornecedor(int idf);
        void setQtdClientes(int qtdCl);
        void setSoma(int s);
        void salvarAvaliacao(ofstream& arquivo);
        void carregarAvaliacao(string linha);
    private:
        int idFornecedor;
        int qtdClientesAva;
        int soma;
        float media;
};

#endif // AVALIACAO_H
