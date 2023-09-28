#include "App.h"

//CABEÇALHO DO SISTEMA
//CONDICAO 1 - CABECALHO
//CONDICAO 2 - LINHA
void cabecalho(string mensagem, int condicao) {
  if(condicao==1){
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------" << mensagem << "-------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
  }else if(condicao==2){
    cout << "------------------------------------------------------------------------------------------" << endl;
  }
}

//DECLARAÇÃO DOS OBJETOS DE CLIENTE E FORNECEDOR
Cliente* clientes[200];
Fornecedor* fornecedores[200];
Pedido pedidos[200];
Avaliacao avaliacoes[200];

//VARIÁVEIS DE USUÁRIO LOGADO NO MOMENTO
int clientAtual = -1;
int fornecedorAtual = -1;

//VARIÁVEIS DE CONTROLE DE QUANTIDADE DOS USUÁRIOS
int qtdFornecedores = 0;
int qtdClientes = 0;
int qtdPedidos = 0;
int qtdAvaliacoes = 0;

//VARIÁVEIS DE AUTENTICAÇÃO AO LOGIN
string usuarioLogin;
string senhaLogin;

//INTERFACE DE LOGIN
void login() {
  cout << "Usuário: ";
  cin >> usuarioLogin;
  cout << "Senha: ";
  cin >> senhaLogin;
  cin.ignore();
}

//MÉTODO PARA AUTENTICAR LOGIN DE CLIENTE
bool autenticarCliente() {
  for (int i = 0; i < qtdClientes; i++) {
     if(clientes[i]->getUsuario()==usuarioLogin && clientes[i]->getSenha()==senhaLogin){
        clientAtual = i;
        return true;
     }
  }
  return false;
}

//MÉTODO PARA AUTENTICAR LOGIN DE FORNECEDOR
bool autenticarFornecedor() {
  for (int i = 0; i < qtdFornecedores; i++){
     if(fornecedores[i]->getUsuario()==usuarioLogin && fornecedores[i]->getSenha()==senhaLogin){
        fornecedorAtual = i;
        return true;
     }
  }
  return false;
}

//CARREGAR OS ARQUIVOS
void carregarDadosSistema(){
    //QUANTIDADE DE CLIENTES E FORNECEDORES DO SISTEMA
    ifstream qtdUsuariosArquivo("qtdUsuarios.txt");
    string lQtd;
    int c=0;
    while(getline(qtdUsuariosArquivo, lQtd)){
        if (c == 0){
            qtdClientes = stoi(lQtd);
        }else{
            qtdFornecedores = stoi(lQtd);
        }
        c++;
    }
    qtdUsuariosArquivo.close();

    //TODOS OS CLIENTES DO SISTEMA
    ifstream arquivoCliente("clientes.txt");
    for (int i = 0; i < qtdClientes; i++) {
        string linha;
        if (getline(arquivoCliente, linha)){
            clientes[i] = new Cliente();
            clientes[i]->carregarDados(linha);
        }
    }
    arquivoCliente.close();

    //TODOS OS FORNECEDORES DO SISTEMA
    ifstream arquivoFornecedor("fornecedores.txt");
    for (int i = 0; i < qtdFornecedores; i++) {
        string linha;
        if (getline(arquivoFornecedor, linha)){
            fornecedores[i] = new Fornecedor();
            fornecedores[i]->carregarDados(linha);
        }
    }
    arquivoFornecedor.close();

    //CARREGAR AS CONFIGURAÇÕES DE MARMITA DOS FORNECEDORES
    ifstream arquivoMarmita("marmitasFornecedor.txt");
    for (int i = 0; i < qtdFornecedores; i++) {
        string linha;
        if (getline(arquivoMarmita, linha)){
            fornecedores[i]->carregarMarmita(linha);
        }
    }
    arquivoMarmita.close();

    //CARREGAR CARDAPIO DOS FORNECEDORES
    ifstream arquivoCardapio("cardapio.txt");
    for (int i = 0; i < qtdFornecedores; i++) {
        string linha;
        if (getline(arquivoCardapio, linha)){
            fornecedores[i]->carregarCardapio(linha);
        }
    }
    arquivoCardapio.close();

    //QUANTIDADE DE PEDIDOS
    ifstream qtdPedidosArquivo("qtdPedidos.txt");
        qtdPedidosArquivo >> qtdPedidos;
    qtdPedidosArquivo.close();

    //QUANTIDADE DE AVALIACOES
    ifstream qtdAvaliacoesArquivo("qtdAvaliacoes.txt");
        qtdAvaliacoesArquivo >> qtdAvaliacoes;
    qtdAvaliacoesArquivo.close();

    //CARREGAR TODOS OS PEDIDOS DO SISTEMA
    ifstream arquivoPedidos("pedidos.txt");
    for (int i = 0; i < qtdPedidos; i++) {
        string linha;
        if (getline(arquivoPedidos, linha)){
            pedidos[i].carregarPedido(linha);
        }
    }
    arquivoPedidos.close();

    //CARREGAR TODAS AS AVALIAÇÕES DO SISTEMA
    ifstream AvaliacoesArquivo("avaliacoes.txt");
    for (int i = 0; i < qtdAvaliacoes; i++) {
        string linha;
        if (getline(AvaliacoesArquivo, linha)){
            avaliacoes[i].carregarAvaliacao(linha);
        }
    }
    AvaliacoesArquivo.close();

}

//SALVAR CARDÁPIO
void salvarCardapio(){
    ofstream arquivoCardapio("cardapio.txt");
        for(int i=0;i<qtdFornecedores;i++){
            arquivoCardapio << fornecedores[i]->qtdAlimentos << ",";
                if(fornecedores[i]->qtdAlimentos==0){
                    arquivoCardapio << "\n";
                }
                for(int j=0;j<fornecedores[i]->qtdAlimentos;j++){
                    if((j+1)==fornecedores[i]->qtdAlimentos){
                        arquivoCardapio << fornecedores[i]->getCardapio(j) << endl;
                    }else{
                        arquivoCardapio << fornecedores[i]->getCardapio(j) << ",";
                    }
                }
        }
    arquivoCardapio.close();
}

//SALVAR QUANTIDADE DE USUARIOS CADASTRADOS NO SISTEMA
void salvarQuantidade(){
    ofstream qtdUsuariosArquivo("qtdUsuarios.txt");
        qtdUsuariosArquivo << qtdClientes << endl;
        qtdUsuariosArquivo << qtdFornecedores;
    qtdUsuariosArquivo.close();
}

//SALVAR QUANTIDADE DE PEDIDOS
void salvarQuantidadePedidos(){
    ofstream qtdUsuariosArquivo("qtdPedidos.txt");
        qtdUsuariosArquivo << qtdPedidos << endl;
    qtdUsuariosArquivo.close();
}

//ATUALIZAR DADOS DE TODOS OS FORNECEDORES (NECESSÁRIO APÓS ALTERAR ALGUM DADO ESPECÍFICO)
void atualizarFornecedores(){
    ofstream arquivoMarmita("marmitasFornecedor.txt");
    for(int i=0;i<qtdFornecedores;i++){
        fornecedores[i]->salvarMarmita(arquivoMarmita);
    }
    arquivoMarmita.close();
}

//ATUALIZAR DADOS DE TODOS OS PEDIDOS (NECESSÁRIO APÓS ALTERAR ALGUM DADO ESPECÍFICO)
void atualizarPedidos(){
    int quant=0;
    ofstream arquivoPedidos("pedidos.txt");
    for(int i=0;i<qtdPedidos;i++){
        if(pedidos[i].getCliente()==0){
            quant++;
        }else{
            pedidos[i].salvarPedido(arquivoPedidos);
        }
    }
    arquivoPedidos.close();
    qtdPedidos = qtdPedidos - quant;
    ofstream qtdUsuariosArquivo("qtdPedidos.txt");
        qtdUsuariosArquivo << qtdPedidos << endl;
    qtdUsuariosArquivo.close();

    carregarDadosSistema();

}

//SALVAR TODAS AS AVALIAÇÕES (NECESSÁRIO APÓS ADICIONAR UMA NOVA ATUALIZAÇÃO)
void salvarAvaliacoes(){
    ofstream arquivoAvaliacao("avaliacoes.txt");
    for(int i=0;i<qtdAvaliacoes;i++){
        avaliacoes[i].salvarAvaliacao(arquivoAvaliacao);
    }
    arquivoAvaliacao.close();
    carregarDadosSistema();
}

//ESCOPO PRINCIPAL DO SISTEMA
void App::menu() {

  //VARIÁVEIS DE CONTROLE
  int op, opCliente, opFornecedor;
  string exibeCliente = "------ÁREA DE CLIENTE-------";
  string exibeFornecedor = "------ÁREA FORNECEDOR-------";

  //CARREGAR DADOS DO SISTEMA
  carregarDadosSistema();

  //LOOP MENU PRINCIPAL
  while (1) {
    system("cls");
    system("color F1");
    cabecalho("SISTEMA DE VENDA DE MARMITAS", 1);

    //MENU COM TIPO DE USUÁRIO
    cout << "1. Sou cliente" << endl;
    cout << "2. Sou fornecedor" << endl;
    cout << "0. Sair" << endl;
    cout << "\nDigite uma opção: ";
    cin >> op;

    //SAIR DO SISTEMA
    if (op == 0) {
      system("cls");
      system("color 4F");
      cout << "\n   Saindo do sistema..." << endl;
      break;
    }

    //SOU CLIENTE
    else if (op == 1) {
      system("cls");
      system("color B0");
      cabecalho(exibeCliente, 1);

      cout << "1. Login" << endl;
      cout << "2. Cadastro" << endl;
      cout << "0. Voltar" << endl;
      cout << "\nDigite uma opção: ";
      cin >> opCliente;
      cin.ignore();

      //LOGIN DO CLIENTE
      if (opCliente == 1) {
        system("cls");
        cabecalho(exibeCliente, 1);
        login();

        //USUÁRIO CLIENTE LOGADO NO SISTEMA
        if(autenticarCliente() && clientAtual!=-1){
            int opMenuCliente;

            //LOOP DO MENU CLIENTE
            while(1){
                system("cls");

                //INFORMAÇÕES DO MENU CLIENTE
                clientes[clientAtual]->menuCliente();
                cin >> opMenuCliente;

                //LISTAR TODOS OS FORNECEDORES
                if(opMenuCliente==1){
                    system("cls");
                    for(int i=0;i<qtdFornecedores;i++){
                        cabecalho("",2);
                        fornecedores[i]->exibirFornecedores();
                        for(int a=0;a<qtdAvaliacoes;a++){
                            if(avaliacoes[a].getIfFornecedor()==fornecedores[i]->getIndice()){
                                cout << fixed << setprecision(1) << "\n Avaliação deste fornecedor: " << avaliacoes[a].getMedia() << " | Quantidade de Avaliações: " << avaliacoes[a].getQtdClientes() << endl;
                            }
                        }
                    }
                    cout << "\n------------------------------------------------------------------------------------------" << endl;
                    cout << "\nPara montar sua marmita volte ao menu anterior e utilize o indice do fornecedor!\n";
                    getchar();
                    getchar();

                }

                //MONTAR MARMITA POR INDICE DO FORNECEDOR
                if(opMenuCliente==2){
                    system("cls");
                    int indice, tipoPedido;
                    bool verify=false;
                    cabecalho("",2);

                    cout << "MONTE AGORA SUA MARMITA!" << endl;
                    cabecalho("",2);
                    cout << "Digite o indice do fornecedor: ";
                    cin >> indice;

                    //LISTAR TODOS OS FORNECEDORES FILTRANDO APENAS O QUE POSSUI O INDICE INSERIDO
                    for(int i=0;i<qtdFornecedores;i++){
                        if(fornecedores[i]->getIndice()==indice){
                            cabecalho("",2);
                            fornecedores[i]->exibirFornecedores();
                            cout << "\n Montar marmita desse fornecedor? [1]SIM [0]NÃO: ";
                            cin >> tipoPedido;
                            if(tipoPedido==1){
                                int tipoAlimento;
                                system("cls");
                                fornecedores[i]->exibirFornecedores();
                                pedidos[qtdPedidos].setFornecedor(indice);
                                pedidos[qtdPedidos].setCliente(2023000+clientAtual);
                                for(int j=0;j<5;j++){
                                    cout << "Adicione alimento [" << j+1 << " de 5] = (DIGITE '0' PARA ENCERRRAR):  ";
                                    cin >> tipoAlimento;
                                    if(tipoAlimento==0&&j==0){
                                        cout << "\n!!VOCÊ PRECISA INSERIR PELO MENOS 1 ALIMENTO!!\n" << endl;
                                        j--;
                                    }else if(tipoAlimento==0&&j>0){
                                        for(int n=j;n<5;n++){
                                            pedidos[qtdPedidos].adicionarAlimentos(n, " ");
                                        }
                                        break;
                                    }else if (tipoAlimento>fornecedores[i]->qtdAlimentos){
                                        cout << "\n!!ESTE FORNECEDOR NÃO POSSUI ESSA OPÇÃO!!\n" << endl;
                                        j--;
                                    }else{
                                        for(int k=0;k<fornecedores[i]->qtdAlimentos;k++){
                                            if(k+1==tipoAlimento){
                                                pedidos[qtdPedidos].adicionarAlimentos(j, fornecedores[i]->getCardapio(k));
                                                cout << "       " << fornecedores[i]->getCardapio(k) << " adicionado!\n";
                                            }
                                        }
                                    }
                                }
                                pedidos[qtdPedidos].salvarPedidos();
                                qtdPedidos++;
                                salvarQuantidadePedidos();
                                cout << "\nMarmita pronta!" << endl;
                                cout << "Pressione qualquer tecla para prosseguir!" << endl;
                            }
                            verify=true;
                        }
                    }
                    if(!verify){
                        cout << "\nFornecedor não encontrado!" << endl;
                    }
                    getchar();
                    getchar();
                }
                //CANCELAR PEDIDO POR INDICE DE FORNECEDOR
                else if(opMenuCliente==3){
                    int indiceForn;
                    bool ePed=false;
                    system("cls");
                    cabecalho("",2);
                    cout << "       CANCELAR MARMITA!" << endl;
                    cabecalho("",2);
                    cout << "Digite o indice do fornecedor: ";
                    cin >> indiceForn;
                    for(int p=0;p<qtdPedidos;p++){
                        if(pedidos[p].getFornecedor()==indiceForn&&pedidos[p].getCliente()==clientAtual+2023000){
                            int removePedido;
                            ePed=true;
                            cabecalho("",2);
                            for(int f=0;f<qtdFornecedores;f++){
                                if(pedidos[p].getFornecedor()==fornecedores[f]->getIndice()){
                                    cout << "Indice: " << fornecedores[f]->getIndice() << " | Nome: " << fornecedores[f]->getNome() << " | Telefone: " << fornecedores[f]->getTelefone() << endl;
                                    cout << fixed << setprecision(2) << "Valor: R$ " << fornecedores[f]->getValor();
                                    if(fornecedores[f]->getPeso()>=1000){
                                        cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso()/1000 << "kg";
                                    }else{
                                        cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso() << "g";
                                    }
                                }
                            }
                            cout << "\n\n Data do Pedido: ";
                            pedidos[p].getData().exibirData();
                            cout << "\n Sua Marmita\n";
                            for(int m=0;m<5;m++){
                                if(pedidos[p].getAlimentoPedido(m)!=" "){
                                    cout << "       " << m+1 << ". " << pedidos[p].getAlimentoPedido(m) << "\n";
                                }
                            }
                            cout << "Cancelar pedido? SIM[1] NÃO[0]: ";
                            cin >> removePedido;
                            if(removePedido==1){
                                pedidos[p].setCliente(0);
                                pedidos[p].setFornecedor(0);
                                atualizarPedidos();
                                system("cls");
                                ePed=false;
                                break;
                            }
                        }
                    }
                    if(!ePed){
                        cout << "\n Nenhum pedido encontrado desse fornecedor!!\n";
                    }
                    cout << "\n Pressione qualquer tecla para retornar! ";
                    getchar();
                    getchar();
                }
                //PEDIDOS DO CLIENTE
                else if(opMenuCliente==4){
                    bool eP=false;
                    system("cls");
                    for(int p=0;p<qtdPedidos;p++){
                        if(pedidos[p].getCliente()==clientAtual+2023000){
                            eP=true;
                            cabecalho("",2);
                            for(int f=0;f<qtdFornecedores;f++){
                                if(pedidos[p].getFornecedor()==fornecedores[f]->getIndice()){
                                    cout << "Indice: " << fornecedores[f]->getIndice() << " | Nome: " << fornecedores[f]->getNome() << " | Telefone: " << fornecedores[f]->getTelefone() << endl;
                                    cout << fixed << setprecision(2) << "Valor: R$ " << fornecedores[f]->getValor();
                                    if(fornecedores[f]->getPeso()>=1000){
                                        cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso()/1000 << "kg";
                                    }else{
                                        cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso() << "g";
                                    }
                                        cout << " | Hora Entrega: " << fornecedores[f]->getHoraEntrega().getHora() << "h" << fornecedores[f]->getHoraEntrega().getMinutos();
                                }
                            }
                            cout << "\n\n Data do Pedido: ";
                            pedidos[p].getData().exibirData();
                            cout << "\n Sua Marmita\n";
                            for(int m=0;m<5;m++){
                                if(pedidos[p].getAlimentoPedido(m)!=" "){
                                    cout << "       " << m+1 << ". " << pedidos[p].getAlimentoPedido(m) << "\n";
                                }
                            }
                        }
                    }
                    if(!eP){
                        cout << "\n Nenhum pedido registrado até o momento!!\n";
                    }
                    cout << "\n Pressione qualquer tecla para retornar! ";
                    getchar();
                    getchar();
                }
                //AVALIAR FORNECEDOR APÓS O TÉRMINO DO HORÁRIO DE ENTREGA
                else if(opMenuCliente==5){
                    bool eP=false;
                    system("cls");
                    for(int p=0;p<qtdPedidos;p++){
                        if(pedidos[p].getCliente()==clientAtual+2023000){
                            cabecalho("",2);
                            cout << "\n   Faça a sua avaliação!" << endl;
                            for(int f=0;f<qtdFornecedores;f++){
                                if(pedidos[p].getFornecedor()==fornecedores[f]->getIndice()){
                                    if(pedidos[p].getData().getHrs()>fornecedores[f]->getHoraEntrega().getHora()+1){
                                        if(pedidos[p].getData().dataSeguinte()){
                                            eP=true;
                                            cout << "\nIndice: " << fornecedores[f]->getIndice() << " | Nome: " << fornecedores[f]->getNome() << " | Telefone: " << fornecedores[f]->getTelefone() << endl;
                                            cout << fixed << setprecision(2) << "Valor: R$ " << fornecedores[f]->getValor();
                                            if(fornecedores[f]->getPeso()>=1000){
                                                cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso()/1000 << "kg";
                                            }else{
                                                cout << fixed << setprecision(0) << " | Peso: " << fornecedores[f]->getPeso() << "g";
                                            }
                                            cout << " | Hora Entrega: " << fornecedores[f]->getHoraEntrega().getHora() << "h" << fornecedores[f]->getHoraEntrega().getMinutos();
                                            cout << "\n\n Data do Pedido: ";
                                            pedidos[p].getData().exibirData();
                                            cout << "\n Sua Marmita\n";
                                            for(int m=0;m<5;m++){
                                                if(pedidos[p].getAlimentoPedido(m)!=" "){
                                                    cout << "       " << m+1 << ". " << pedidos[p].getAlimentoPedido(m) << "\n";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(!eP){
                        cout << "\n Nenhum fornecedor para avaliar no momento!!\n";
                        cout << "\n Pressione qualquer tecla para retornar! ";
                    }else{
                        int opAvaliar, notaAvaliacao;
                        cout << "\n\n Insira o indice do fornecedor que você quer avaliar: ";
                        cin >> opAvaliar;
                        for(int p=0;p<qtdPedidos;p++){
                            if(pedidos[p].getCliente()==clientAtual+2023000){
                                for(int f=0;f<qtdFornecedores;f++){
                                    if(pedidos[p].getFornecedor()==fornecedores[f]->getIndice()){
                                        if(pedidos[p].getData().getHrs()>fornecedores[f]->getHoraEntrega().getHora()+1){
                                            if(pedidos[p].getData().dataSeguinte()){
                                                if(opAvaliar==fornecedores[f]->getIndice()){
                                                    bool eAva=false;
                                                    cout << "\n Avaliando a marmita do Sr(a). " << fornecedores[f]->getNome() << endl;
                                                    cout << "\n\n   Dê a sua nota!";
                                                    cout << "\n       1. Muito Insatisfeito";
                                                    cout << "\n       2. Insatisfeito";
                                                    cout << "\n       3. Indiferente";
                                                    cout << "\n       4. Satisfeito";
                                                    cout << "\n       5. Muito Satisfeito\n";
                                                    cout << "\n Qual a sua nota? ";
                                                    cin >> notaAvaliacao;

                                                    for(int av=0;av<qtdAvaliacoes;av++){
                                                        if(avaliacoes[av].getIfFornecedor()==opAvaliar){
                                                            eAva=true;
                                                            switch(notaAvaliacao){
                                                                case 1: avaliacoes[av].setSoma(avaliacoes[av].getSoma()+1); break;
                                                                case 2: avaliacoes[av].setSoma(avaliacoes[av].getSoma()+2); break;
                                                                case 3: avaliacoes[av].setSoma(avaliacoes[av].getSoma()+3); break;
                                                                case 4: avaliacoes[av].setSoma(avaliacoes[av].getSoma()+4); break;
                                                                case 5: avaliacoes[av].setSoma(avaliacoes[av].getSoma()+5); break;
                                                            }
                                                            avaliacoes[av].setQtdClientes(avaliacoes[av].getQtdClientes()+1);
                                                            salvarAvaliacoes();
                                                            pedidos[p].setCliente(0);
                                                            pedidos[p].setFornecedor(0);
                                                            atualizarPedidos();
                                                            cout << "\n Avaliação adicionada com sucesso!!";
                                                        }
                                                    }
                                                    if(!eAva){
                                                        avaliacoes[qtdAvaliacoes].setIfFornecedor(opAvaliar);
                                                        switch(notaAvaliacao){
                                                            case 1: avaliacoes[qtdAvaliacoes].setSoma(avaliacoes[qtdAvaliacoes].getSoma()+1); break;
                                                            case 2: avaliacoes[qtdAvaliacoes].setSoma(avaliacoes[qtdAvaliacoes].getSoma()+2); break;
                                                            case 3: avaliacoes[qtdAvaliacoes].setSoma(avaliacoes[qtdAvaliacoes].getSoma()+3); break;
                                                            case 4: avaliacoes[qtdAvaliacoes].setSoma(avaliacoes[qtdAvaliacoes].getSoma()+4); break;
                                                            case 5: avaliacoes[qtdAvaliacoes].setSoma(avaliacoes[qtdAvaliacoes].getSoma()+5); break;
                                                        }
                                                        avaliacoes[qtdAvaliacoes].setQtdClientes(avaliacoes[qtdAvaliacoes].getQtdClientes()+1);
                                                        qtdAvaliacoes++;
                                                        ofstream qtdAvaliacoesArquivo("qtdAvaliacoes.txt");
                                                            qtdAvaliacoesArquivo << qtdAvaliacoes << endl;
                                                        qtdAvaliacoesArquivo.close();
                                                        salvarAvaliacoes();
                                                        pedidos[p].setCliente(0);
                                                        pedidos[p].setFornecedor(0);
                                                        atualizarPedidos();
                                                        cout << "\n Avaliação adicionada com sucesso!!";
                                                    }
                                                }else{
                                                    cout << "\n Indice incorreto ou não existe pedido para esse fornecedor!!\n";
                                                    cout << "\n Pressione qualquer tecla para retornar! ";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    getchar();
                    getchar();
                }
                //SAIR DA CONTA
                else if(opMenuCliente==0){
                    clientAtual = -1;
                    break;
                }
            }
        }
        //USUÁRIO OU SENHA DE CLIENTE INCORRETO
        else{
            system("cls");
            cabecalho(exibeCliente, 1);
            cout << "\n!!!Usuário ou senha incorretos!!!\n" << endl;
            getchar();
        }
      }

      //CADASTRO CLIENTE
      else if (opCliente == 2) {
        system("cls");
        cabecalho(exibeCliente, 1);

        //CADASTRO DO CLIENTE
        clientes[qtdClientes] = new Cliente();
        clientes[qtdClientes]->cadastrar(qtdClientes);
        qtdClientes++;

        //SALVAR A QUANTIDADE DE USUARIOS CADASTRADOS
        salvarQuantidade();
      }
    }

    //SOU FORNECEDOR
    else if (op == 2){
      system("cls");
      system("color 8F");
      cabecalho(exibeFornecedor,1);
      cout << "1. Login" << endl;
      cout << "2. Cadastro" << endl;
      cout << "0. Voltar" << endl;
      cout << "\nDigite uma opção: ";
      cin >> opFornecedor;
      cin.ignore();

      //LOGIN FORNECEDOR
      if (opFornecedor == 1) {
        system("cls");
        cabecalho(exibeFornecedor,1);
        login();

        //USUÁRIO FORNECEDOR LOGADO NO SISTEMA
        if(autenticarFornecedor() && fornecedorAtual!=-1){
            int opMenuFornecedor;
            string alimento;
            while(1){
                system("cls");
                fornecedores[fornecedorAtual]->menuFornecedor();

                for(int a=0;a<qtdAvaliacoes;a++){
                    if(avaliacoes[a].getIfFornecedor()==fornecedores[fornecedorAtual]->getIndice()){
                        cout << fixed << setprecision(1) << "\n Sua Avaliação: " << avaliacoes[a].getMedia() << " | Quantidade de Avaliações: " << avaliacoes[a].getQtdClientes() << endl;
                    }
                }

                cout << "\n\nDigite uma opção: ";
                cin >> opMenuFornecedor;
                cin.ignore();

                //CARDÁPIO
                if(opMenuFornecedor==1){
                    while(1){
                        system("cls");
                        int opCardapio;
                        fornecedores[fornecedorAtual]->adicionarCardapio();
                        cin >> opCardapio;
                        cin.ignore();
                        if(opCardapio==1){
                            cout << "\n\n Qual alimento você quer adicionar? ";
                            getline(cin, alimento);
                            fornecedores[fornecedorAtual]->setCardapio(alimento, fornecedores[fornecedorAtual]->qtdAlimentos);
                            fornecedores[fornecedorAtual]->qtdAlimentos++;

                            //ATUALIZAR O CARDÁPIO DE TODOS OS FORNECEDORES
                            salvarCardapio();

                        }else if(opCardapio==0){
                            break;
                        }
                    }
                }
                //ALTERAR HORÁRIO
                else if(opMenuFornecedor==2){
                    system("cls");
                    int tipoHora;
                    cout << "HORÁRIO: ";
                    fornecedores[fornecedorAtual]->getHoraEntrega().exibirHorario();
                    cout << "\n\n Alterar horário? [1]SIM [0]NAO ";
                    cin >> tipoHora;
                    if(tipoHora==1){
                        fornecedores[fornecedorAtual]->alterarHorario();
                        atualizarFornecedores();
                    }
                }
                //LISTAR TODOS OS CLIENTES DO FUNCIONÁRIO
                if(opMenuFornecedor==3){
                    system("cls");
                    bool eCl = false;
                    for(int i=0;i<qtdPedidos;i++){
                        if(pedidos[i].getFornecedor()==fornecedorAtual+2023000){
                            for(int j=0;j<qtdClientes;j++){
                                if(pedidos[i].getCliente()==clientes[j]->getIndice()){
                                    cabecalho("",2);
                                    clientes[j]->exibirClientes();
                                    eCl = true;
                                }
                            }
                            cout << " Data do Pedido: ";
                            pedidos[i].getData().exibirData();
                            cout << "\nMarmita\n";
                            for(int m=0;m<5;m++){
                                if(pedidos[i].getAlimentoPedido(m)!=" "){
                                    cout << "       " << m+1 << ". " << pedidos[i].getAlimentoPedido(m) << "\n";
                                }
                            }
                        }
                    }
                    if(!eCl){
                        cout << "\n Nenhum cliente até o momento!" << endl;
                    }
                    cout << "\n Para cancelar um pedido volte ao menu anterior e utilize o indice do cliente!\n";
                    getchar();
                }
                //CANCELAR CLIENTE POR INDICE DO FUNCIONÁRIO
                if(opMenuFornecedor==4){
                    system("cls");
                    int indiceCli;
                    bool ePed=false;
                    system("cls");
                    cabecalho("",2);
                    cout << "       CANCELAR PEDIDO!" << endl;
                    cabecalho("",2);
                    cout << "Digite o indice do cliente: ";
                    cin >> indiceCli;
                    for(int p=0;p<qtdPedidos;p++){
                        if(pedidos[p].getFornecedor()==fornecedorAtual+2023000&&pedidos[p].getCliente()==indiceCli){
                            int removePedido;
                            ePed=true;
                            cabecalho("",2);
                            for(int j=0;j<qtdClientes;j++){
                                if(pedidos[p].getCliente()==clientes[j]->getIndice()){
                                    cabecalho("",2);
                                    clientes[j]->exibirClientes();
                                }
                            }
                            cout << "\n\n Data do Pedido: ";
                            pedidos[p].getData().exibirData();
                            cout << "\n Opções na Marmita\n";
                            for(int m=0;m<5;m++){
                                if(pedidos[p].getAlimentoPedido(m)!=" "){
                                    cout << "       " << m+1 << ". " << pedidos[p].getAlimentoPedido(m) << "\n";
                                }
                            }
                            cout << "Cancelar pedido? SIM[1] NÃO[0]: ";
                            cin >> removePedido;
                            if(removePedido==1){
                                pedidos[p].setCliente(0);
                                pedidos[p].setFornecedor(0);
                                atualizarPedidos();
                                system("cls");
                                ePed=false;
                                break;
                            }
                        }
                    }
                    if(!ePed){
                        cout << " \nNenhum pedido encontrado desse cliente!!\n";
                    }
                    cout << "\n Pressione qualquer tecla para retornar! ";
                    getchar();
                    getchar();


                }
                //ALTERAR VALOR
                else if(opMenuFornecedor==5){
                    system("cls");
                    int tipoValor;
                    cout << "Valor: R$ " << fornecedores[fornecedorAtual]->getValor();
                    cout << "\n\nAlterar valor? [1]SIM [0]NAO ";
                    cin >> tipoValor;
                    if(tipoValor==1){
                        fornecedores[fornecedorAtual]->alterarValor();
                        atualizarFornecedores();
                    }
                }
                //ALTERAR PESO
                else if(opMenuFornecedor==6){
                    system("cls");
                    int tipoPeso;
                    cout << "Peso: " << fornecedores[fornecedorAtual]->getPeso() << "g";
                    cout << "\n\nAlterar peso? [1]SIM [0]NAO ";
                    cin >> tipoPeso;
                    if(tipoPeso==1){
                        fornecedores[fornecedorAtual]->alterarPeso();
                        atualizarFornecedores();
                    }
                }
                //SAIR
                else if(opMenuFornecedor==0){
                    clientAtual = -1;
                    break;
                }
            }
        }

        //USUÁRIO OU SENHA DE USUÁRIO FORNECEDOR INCORRETO
        else{
            system("cls");
            cabecalho(exibeFornecedor,1);
            cout << "\n!!!Usuário ou senha incorretos!!!\n" << endl;
            getchar();
        }
      }

      //CADASTRO DO FORNECEDOR
      else if (opFornecedor == 2) {
        system("cls");
        cabecalho(exibeFornecedor,1);

        //CADASTRO DO CLIENTE
        fornecedores[qtdFornecedores] = new Fornecedor();
        fornecedores[qtdFornecedores]->cadastrar(qtdFornecedores);
        qtdFornecedores++;

        //SALVAR A QUANTIDADE DE USUARIOS CADASTRADOS
        salvarQuantidade();

        //SALVAR O CARDÁPIO ATRIBUINDO 0 A QUANTIDADE DE ALIMENTOS
        salvarCardapio();

      }
      if (opFornecedor == 0);
    }
  }
}
