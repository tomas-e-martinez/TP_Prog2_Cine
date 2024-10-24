#include "Fecha.h"

Fecha::Fecha(){
    _dia = _mes = _anio = _hora = _minutos = 0;
}

int Fecha::getDia(){
    return _dia;
}

std::string Fecha::toStringFecha(){
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << _dia << "/"
        << std::setw(2) << std::setfill('0') << _mes << "/"
        << std::setw(4) << std::setfill('0') << _anio;
    return oss.str();
}

std::string Fecha::toStringHora(){
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << _hora << ":"
        << std::setw(2) << std::setfill('0') << _minutos;
    return oss.str();
}

void Fecha::Cargar(){
    cout << "DÍA: ";
    cin >> _dia;
    cout << "MES: ";
    cin >> _mes;
    cout << "AÑO: ";
    cin >> _anio;
}
