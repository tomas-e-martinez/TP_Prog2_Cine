#pragma once
#include <string>

class Tiempo{
private:
    int _minutos;
public:
    Tiempo();
    Tiempo(int minutos);

    void Cargar();
    std::string toString();

    int getMinutos();

    void setMinutos(int minutos);
};
