#include "Fornecedor.h"

Fornecedor::Fornecedor() : Usuario(2)
{
    valor = 0;
    qtdAlimentos = 0;
}

//MÉTODOS GET E SET

float Fornecedor::getValor(){
    return valor;
}
float Fornecedor::getPeso(){
    return peso;
}

void Fornecedor::setCardapio(string a, int qtd){
    cardapio[qtd] = a;
}

string Fornecedor::getCardapio(int qtd){
    return cardapio[qtd];
}

string Fornecedor::getTelefone(){
    return telefone;
}

Horario Fornecedor::getHoraEntrega(){
    return horaEntrega;
}

//LISTAR TODOS OS ALIMENTOS DO CARDÁPIO
void listarCardapio(int qtd, string cardapio[]){
    for(int i=0;i<qtd;i++){
        cout << "   " << i+1 << " - " << cardapio[i] << endl;
    }
}

//MENU FORNECEDOR
void Fornecedor::menuFornecedor()
{
        //CADASTRO DE MARMITA NO PRIMEIRO ACESSO
        cadastroMarmita();

        //MÉTODO DA SUPERCLASSE
        cabecalhoUsuario();

        //INFORMAÇÕES DA MARMITA
        cout << "------------------ MARMITA -------------------" << endl;
        cout << "Quantidade de alimentos: " << qtdAlimentos << endl;
        cout << "Horario de Entrega: ";
        horaEntrega.exibirHorario();
        cout << fixed << setprecision(2) << "Valor: R$ " << valor << endl;
        if(peso>=1000){
            cout << fixed << setprecision(0) << "Peso: " << peso/1000 << "kg" << endl;
        }else{
            cout << fixed << setprecision(0) << "Peso: " << peso << "g" << endl;
        }

        //MENU
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "\n1. Cardápio do Dia" << endl;
        cout << "2. Alterar Horário" << endl;
        cout << "3. Meus Clientes" << endl;
        cout << "4. Remover pedido por indice de cliente" << endl;
        cout << "5. Alterar Valor" << endl;
        cout << "6. Alterar Peso" << endl;
        cout << "0. Sair" << endl;
}

//EXIBE AS INFORMAÇÕES DO FORNECEDOR
void Fornecedor::exibirFornecedores(){
    cout << "Indice: " << indice << " | Nome: " << nomeCompleto << " | Telefone: " << telefone << endl;
    cout << fixed << setprecision(2) << "Valor: R$ " << valor;
    if(peso>=1000){
        cout << fixed << setprecision(0) << " | Peso: " << peso/1000 << "kg";
    }else{
        cout << fixed << setprecision(0) << " | Peso: " << peso << "g";
    }
    cout << " | Quantidade de Alimentos: " << qtdAlimentos << endl;
    cout << "\nCardápio\n";
    listarCardapio(qtdAlimentos, cardapio);

}

//CADASTRO DE MARMITA NO PRIMEIRO ACESSO DO FORNECEDOR AO SISTEMA
void Fornecedor::cadastroMarmita()
{
    int minut, hors;
    if(valor==0){
        cardapio[0] = "VAZIO";
        cout << "\nAgora vamos para o cadastro da marmita\n\n";
        cout << "Valor R$ ";
        cin >> valor;
        cout << "Peso (Gramas): ";
        cin >> peso;
        cout << "\nHorario de Entrega:\n\n";
        cout << "Hora: ";
        cin >> hors;
        cout << "Minutos: ";
        cin >> minut;
        system("cls");

        horaEntrega.setHora(hors);
        horaEntrega.setMinutos(minut);

        ofstream arquivoMarmita("marmitasFornecedor.txt", ios::app);
            salvarMarmita(arquivoMarmita);
        arquivoMarmita.close();
    }
}

//SALVAR AS CONFIGURAÇÕES DA MARMITA NO SISTEMA
void Fornecedor::salvarMarmita(ofstream& arquivo){
    arquivo << indice << ",";
    arquivo << peso << ",";
    arquivo << valor << ",";
    arquivo << horaEntrega.getHora() << ",";
    arquivo << horaEntrega.getMinutos() << endl;
}

//CARREGAR AS INFORMAÇÕES DA MARMITA CONTIDAS NO ARQUIVO E ARMAZENANDO NO OBJETO FORNECEDOR
void Fornecedor::carregarMarmita(string l){
    istringstream iss(l);
    string token;
    int h, m;
    int contador = 0;
    while (getline(iss, token, ',')) {
        switch (contador) {
            case 0:; break;
            case 1: peso = stof(token); break;
            case 2: valor = stof(token); break;
            case 3: h = stoi(token); break;
            case 4: m = stoi(token); break;
        }
        contador++;
    }
    horaEntrega.setHora(h);
    horaEntrega.setMinutos(m);
}

//MENU PARA ADICIONAR CARDAPIO
void Fornecedor::adicionarCardapio(){
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "   Cardápio - " << nomeCompleto << endl;
    cout << "------------------------------------------------------------------------------------------\n" << endl;
    listarCardapio(qtdAlimentos, cardapio);
    if(qtdAlimentos==0){
        cout << "\n--------NENHUM ALIMENTO ADICIONADO!--------\n" << endl;
    }

    cout << "\nAdicionar mais alimentos? (1) SIM (0) NÃO -> ";
}

//CARREGAR CARDAPIO
void Fornecedor::carregarCardapio(string l){
    istringstream iss(l);
    string token;
    int contador = 0;
    while (getline(iss, token, ',')) {
        if(contador==0){
            qtdAlimentos = stoi(token);
        }else{
            cardapio[contador-1] = token;
        }
        contador++;
    }
}

//FUNÇÃO PARA ALTERAR HORÁRIO
void Fornecedor::alterarHorario(){
    int h, m;
    cout << "\nNovo Horario: \n\n";
    cout << "Hora: ";
    cin >> h;
    cout << "Minuto: ";
    cin >> m;
    horaEntrega.setHora(h);
    horaEntrega.setMinutos(m);
}

//FUNÇÃO PARA ALTERAR VALOR
void Fornecedor::alterarValor(){
    cout << "\nNovo Valor: \n\n";
    cout << "Valor: ";
    cin >> valor;
}

//FUNÇÃO PARA ALTERAR PESO
void Fornecedor::alterarPeso(){
    cout << "\nNovo Peso: \n\n";
    cout << "Peso: ";
    cin >> peso;
}
