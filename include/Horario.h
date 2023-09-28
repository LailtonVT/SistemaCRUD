#ifndef HORARIO_H
#define HORARIO_H

class Horario
{
    public:
        Horario();
        int getHora();
        int getMinutos();
        void setHora(int h);
        void setMinutos(int m);
        void exibirHorario();
    private:
        int hora, minuto;
};

#endif // HORARIO_H
