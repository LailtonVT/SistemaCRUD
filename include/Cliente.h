#ifndef CLIENTE_H
#define CLIENTE_H

//BIBLIOTECAS
#include "Usuario.h"
#include <iostream>

//CLASSES PRINCIPAL E HORÁRIO
#include "App.h"
#include "Horario.h"

class Cliente : public Usuario
{
    public:
      Cliente();
      void menuCliente();
      void exibirClientes();

    protected:
      int idCliente;

    private:
};

#endif // CLIENTE_H
