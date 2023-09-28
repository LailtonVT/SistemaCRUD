#ifndef MARMITA_H
#define MARMITA_H
#include <iostream>

using namespace std;

class Marmita
{
    public:
        Marmita();
        int getIdfornecedor();
        string getAlimentos(int idAlimento);
        void setIdfornecedor(int idForn);
        void adicionarAlimentos();
    private:
        int idFornecedor;
        string alimentos[5];
};

#endif // MARMITA_H
