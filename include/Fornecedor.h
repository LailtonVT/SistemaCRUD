#ifndef FORNECEDOR_H
#define FORNECEDOR_H

//BIBLIOTECAS
#include <iomanip>

//CLASSES USUÁRIO
#include "App.h"
#include "Horario.h"

class Fornecedor : public Usuario
{
    public:
      Fornecedor();

      string getCardapio(int qtd);
      Horario getHoraEntrega();
      float getValor();
      float getPeso();
      string getTelefone();
      void setCardapio(string a, int qtd);

      int qtdAlimentos;

      void menuFornecedor();
      void cadastroMarmita();
      void exibirFornecedores();
      void salvarMarmita(ofstream& arquivo);
      void carregarMarmita(string l);
      void carregarCardapio(string l);
      void adicionarCardapio();
      void alterarHorario();
      void alterarValor();
      void alterarPeso();

    private:
      int idFornecedor;
      string cardapio[100];
      float valor;
      float peso;
      Horario horaEntrega;
};

#endif // FORNECEDOR_H
