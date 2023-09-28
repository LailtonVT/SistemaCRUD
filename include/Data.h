#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>

using namespace std;

class Data
{
    public:
        Data();
        int getDia();
        int getMes();
        int getAno();
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);
        void setHora(int h);
        void atribuirDataHoje();
        void pegarHoraAtual();
        int getHrs();
        void exibirData();
        bool dataSeguinte();
    private:
        int dia, mes, ano, hora;
};

#endif // DATA_H
