#include "Cliente.h"

Cliente::Cliente() : Usuario(1) // CLIENTE É DO TIPO 1
{

}

//MENU DO CLIENTE
void Cliente::menuCliente()
{
    //MÉTODO DA SUPERCLASSE
    cabecalhoUsuario();

    //MENU
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "\n1. Listar todos os fornecedores" << endl;
    cout << "2. Montar Marmita (Tenha o Indice do fornecedor)" << endl;
    cout << "3. Cancelar por nome ou indice do fornecedor" << endl;
    cout << "4. Pedidos" << endl;
    cout << "5. Avaliar" << endl;
    cout << "0. Sair" << endl;
    cout << "\nDigite uma opção: ";
}

//EXIBIR TODOS OS PEDIDOS
void Cliente::exibirClientes(){
    cout << "Indice: " << indice << " | Nome: " << nomeCompleto << " | Telefone: " << telefone << endl;
    endereco.exibirEndereco();
    cout << endl;
}
