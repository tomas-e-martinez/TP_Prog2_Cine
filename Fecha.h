#pragma once
#include <string>
#include <iomanip>

class Fecha{
private:
    int _dia, _mes, _anio, _hora, _minutos;
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha(int dia, int mes, int anio, int hora, int minutos);

    void Cargar();
    std::string toStringFecha();
    std::string toStringHora();

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinutos();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setHora(int hora);
    void setMinutos(int minutos);
};
