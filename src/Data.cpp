#include "Data.h"
#include <time.h>

Data::Data()
{

}

int Data::getDia(){
    return dia;
}
int Data::getMes(){
    return mes;
}
int Data::getAno(){
    return ano;
}

void Data::setDia(int d){
    dia = d;
}
void Data::setMes(int m){
    mes = m;
}
void Data::setAno(int a){
    ano = a;
}

void Data::setHora(int h){
    hora = h;
}

void Data::pegarHoraAtual(){
    struct tm *horaAtual;
    time_t horasSistema;
    time(&horasSistema);
    horaAtual = localtime(&horasSistema);

    hora = horaAtual->tm_hour;
}

int Data::getHrs(){
    pegarHoraAtual();
    return hora;
}

void Data::atribuirDataHoje(){
    struct tm *dataHoje;
    time_t dataSistema;
    time(&dataSistema);

    dataHoje = localtime(&dataSistema);
    dia = dataHoje->tm_mday;
    mes = dataHoje->tm_mon+1;
    ano = dataHoje->tm_year+1900;

}

void Data::exibirData(){
    string diaAtual = (dia > 9 ? to_string(dia) : "0" + to_string(dia));
    string mesAtual = (mes > 9 ?  to_string(mes) : "0" + to_string(mes));
    cout << diaAtual << "/" << mesAtual << "/" << ano << endl;
}

bool Data::dataSeguinte(){
    int diaSeguinte, mesSeguinte, anoSeguinte;

    struct tm *dataHoje;
    time_t dataSistema;
    time(&dataSistema);

    dataHoje = localtime(&dataSistema);
    diaSeguinte = dataHoje->tm_mday;
    mesSeguinte = dataHoje->tm_mon+1;
    anoSeguinte = dataHoje->tm_year+1900;

    if(anoSeguinte>ano){
        return true;
    }else{
        if(mesSeguinte>mes){
            return true;
        }else {
            if(diaSeguinte>dia){
                return true;
            }else{
                return false;
            }
        }
    }

}
