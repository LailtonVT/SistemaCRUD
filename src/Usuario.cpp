#include "Usuario.h"

Usuario::Usuario(int tipo) {
    this->tipo = tipo;
}

//MÉTODOS GET DOS ATRIBUTOS PRIVADOS

string Usuario::getNome(){
  return nomeCompleto;
}

string Usuario::getUsuario(){
  return usuario;
}
string Usuario::getSenha(){
  return senha;
}

int Usuario::getIndice(){
    return indice;
}

//CABEÇALHO DE CADA USUÁRIO LOGADO
void Usuario::cabecalhoUsuario(){
    //ABREVIACÃO DO NOME
    string nome;
    int pos = nomeCompleto.find(' ');
    if (pos != string::npos) {
        nome = nomeCompleto.substr(0, pos);
    }else{
        nome = nomeCompleto;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Olá, " << nome << "!" << endl;
    cout << endl;
    cout << "---------------- Meu Endereco ----------------" << endl;
    endereco.exibirEndereco();
}

//CADASTRAR USUARIO
void Usuario::cadastrar(int id) {
  indice = id+2023000;
  cout << "Nome Completo: ";
  getline(cin, nomeCompleto);
  cout << "Telefone: ";
  getline(cin, telefone);
  endereco.lerEndereco();
  cout << "Usuário: ";
  getline(cin, usuario);
  cout << "Senha: ";
  getline(cin, senha);
  string diretorio;
    if(tipo == 1){
        diretorio = "clientes.txt";
        cout << "\nCADASTRO DE CLIENTE REALIZADO COM SUCESSO!\n\n";
        getchar();
    }else{
        diretorio = "fornecedores.txt";
        cout << "\nCADASTRO DE FORNECEDOR REALIZADO COM SUCESSO!\n\n";
        getchar();
    }

    //APÓS CADASTRO SALVAR NO ARQUIVO INSERINDO AO ÚLTIMO
    ofstream arquivo(diretorio, ios::app);
    arquivo << indice << ",";
    arquivo << nomeCompleto << ",";
    arquivo << telefone << ",";
    arquivo << endereco.getCidade() << ",";
    arquivo << endereco.getEstado() << ",";
    arquivo << endereco.getBairro() << ",";
    arquivo << endereco.getRua() << ",";
    arquivo << endereco.getNumero() << ",";
    arquivo << usuario << ",";
    arquivo << senha << endl;
    arquivo.close();
}

//CARREGAR DADOS DO USUÁRIO CONTIDOS NO ARQUIVO E ARMAZENANDO NO OBJETO
void Usuario::carregarDados(string linha){
    istringstream iss(linha);
    string token;
    string nome, tel, c, e, b, r, s, u;
    int id, n;
    int contador = 0;
    while (getline(iss, token, ',')) {
        switch (contador) {
            case 0: id = stoi(token); break;
            case 1: nome = token; break;
            case 2: tel = token; break;
            case 3: c = token; break;
            case 4: e = token; break;
            case 5: b = token; break;
            case 6: r = token; break;
            case 7: n = stoi(token); break;
            case 8: u = token; break;
            case 9: s = token; break;
        }
        contador++;
    }
    indice = id;
    nomeCompleto = nome;
    telefone = tel;
    usuario = u;
    senha = s;
    endereco.setCidade(c);
    endereco.setEstado(e);
    endereco.setBairro(b);
    endereco.setRua(r);
    endereco.setNumero(n);
}
