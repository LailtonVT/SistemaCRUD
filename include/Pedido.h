#ifndef PEDIDO_H
#define PEDIDO_H
#include "Data.h"
#include <fstream>
#include <iomanip>

class Pedido
{
    public:
        Pedido();
        Data getData();
        void setFornecedor(int in);
        void setCliente(int ic);
        int getFornecedor();
        int getCliente();
        string getAlimentoPedido(int po);

        void salvarPedidos();
        void carregarPedido(string l);
        void adicionarAlimentos(int pos, string a);
        void salvarPedido(ofstream& arquivoPedido);
        void exibirPedidos();
    private:
        Data dataPedido;
        int idFornecedor;
        int idCliente;
        string alimentos[5];
};

#endif // PEDIDO_H
