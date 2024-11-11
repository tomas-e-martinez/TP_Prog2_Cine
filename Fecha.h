#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Fecha{
private:
    int _dia, _mes, _anio, _hora, _minutos;
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha(int dia, int mes, int anio, int hora, int minutos);

    void Cargar();
    void CargarHora();
    std::string toStringFecha() const;
    std::string toStringHora() const;
    void AjustarFecha();
    bool EsBisiesto(int anio) const;

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

    bool operator==(const Fecha& otra) const;
    bool operator!=(const Fecha& otra) const;
    bool operator<(const Fecha& otra) const;
    bool operator<=(const Fecha& otra) const;
    bool operator>(const Fecha& otra) const;
    bool operator>=(const Fecha& otra) const;
    Fecha operator+(int dias) const;
    Fecha operator-(int dias) const;
};
