#include "Tiempo.h"

Tiempo::Tiempo(){
    _minutos = 0;
}

Tiempo::Tiempo(int minutos){
    _minutos = minutos;
}

std::string Tiempo::toString(){
    int horas = _minutos / 60;
    int minutos = _minutos % 60;

    return std::to_string(horas) + "h " + std::to_string(minutos) + "m";
}
