#pragma once

#include <iostream>
#include <string>

using namespace std;

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
