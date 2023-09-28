#ifndef APP_H
#define APP_H

//BIBLIOTECAS
#include <locale.h>
#include <string>
#include <fstream>
#include <stdlib.h>

//CLASSES
#include "Data.h"
#include "Endereco.h"
#include "Cliente.h"
#include "Fornecedor.h"
#include "Pedido.h"
#include "Avaliacao.h"

//DEFINIÇÃO DA CLASSE APP
class App
{
    public:
        void menu();
};

#endif // APP_H
