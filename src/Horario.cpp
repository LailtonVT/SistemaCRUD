#include "Horario.h"
#include <iostream>
#include <string>

Horario::Horario()
{

}

int Horario::getHora(){
    return hora;
}
int Horario::getMinutos(){
    return minuto;
}
void Horario::setHora(int h){
    if(h>=24){
        h=h-24;
    }
    hora = h;
}
void Horario::setMinutos(int m){
    if(m>=60){
        hora+=m/60;
        m=m%60;
    }
    minuto = m;
}

void Horario::exibirHorario(){
    std::string m;
    m = minuto>10 ? std::to_string(minuto) : "0" + std::to_string(minuto);
    std::cout << hora << "h" << m << std::endl;
}
