#include "Pedido.h"

Pedido::Pedido()
{

}

//MÉTODOS GET E SET

Data Pedido::getData(){
    return dataPedido;
}

void Pedido::setFornecedor(int in){
    idFornecedor = in;
    dataPedido.atribuirDataHoje();
}

void Pedido::setCliente(int ic){
    idCliente = ic;
}
int Pedido::getFornecedor(){
    return idFornecedor;
}
int Pedido::getCliente(){
    return idCliente;
}

string Pedido::getAlimentoPedido(int po){
    return alimentos[po];
}

//CARREGAR PEDIDOS DO ARQUIVO
void Pedido::carregarPedido(string l){
    istringstream iss(l);
    string token;
    int contador = 0;
    int ano, mes, dia;
    while (getline(iss, token, ',')) {
        switch (contador) {
            case 0: idFornecedor = stoi(token); break;
            case 1: idCliente = stoi(token); break;
            case 2: ano = stoi(token); break;
            case 3: mes = stoi(token); break;
            case 4: dia = stoi(token); break;
            case 5: alimentos[0] = token; break;
            case 6: alimentos[1] = token; break;
            case 7: alimentos[2] = token; break;
            case 8: alimentos[3] = token; break;
            case 9: alimentos[4] = token; break;
        }
        contador++;
    }
    dataPedido.setAno(ano);
    dataPedido.setMes(mes);
    dataPedido.setDia(dia);
}

//SALVAR INFORMAÇÕES DA CLASSE PEDIDO NO ARQUIVO
void Pedido::salvarPedido(ofstream& arquivoPedido){
    arquivoPedido << idFornecedor << ",";
    arquivoPedido << idCliente << ",";
    arquivoPedido << dataPedido.getAno() << ",";
    arquivoPedido << dataPedido.getMes() << ",";
    arquivoPedido << dataPedido.getDia() << ",";
    arquivoPedido << alimentos[0] << ",";
    arquivoPedido << alimentos[1] << ",";
    arquivoPedido << alimentos[2] << ",";
    arquivoPedido << alimentos[3] << ",";
    arquivoPedido << alimentos[4] << endl;
}

//INICIAR O ARQUIVO PEDIDO ADICIONANDO NA ÚLTIMA LINHA
void Pedido::salvarPedidos(){
    ofstream arquivoPedido("pedidos.txt", ios::app);
        salvarPedido(arquivoPedido);
    arquivoPedido.close();
}

//ADICIONAR ALIMENTOS
void Pedido::adicionarAlimentos(int pos, string a){
    alimentos[pos]=a;
}
