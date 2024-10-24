#include "Fecha.h"

Fecha::Fecha(){
    _dia = _mes = _anio = _hora = _minutos = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    _hora = _minutos = 0;
}

Fecha::Fecha(int dia, int mes, int anio, int hora, int minutos){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(hora);
    setMinutos(minutos);
}

void Fecha::Cargar(){
    int dia, mes, anio;
    cout << "D�A: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "A�O: ";
    cin >> anio;
    setDia(dia);
    setMes(mes);
    setAnio(anio);
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

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

int Fecha::getHora(){
    return _hora;
}

int Fecha::getMinutos(){
    return _minutos;
}

void Fecha::setDia(int dia){
    if(dia > 0 && dia <= 31)
        _dia = dia;
    else
        _dia = 0;
}

void Fecha::setMes(int mes){
    if(mes > 0 && mes <= 12)
        _mes = mes;
    else
        _mes = 0;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

void Fecha::setHora(int hora){
    if(hora >= 0 && hora <= 23)
        _hora = hora;
    else
        _hora = -1;
}

void Fecha::setMinutos(int minutos){
    if(minutos >= 0 && minutos <= 59)
        _minutos = minutos;
    else
        _minutos = -1;
}





