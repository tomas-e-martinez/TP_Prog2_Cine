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
    cout << "DÍA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "AÑO: ";
    cin >> anio;
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::CargarHora(){
    int dia, mes, anio, hora, minutos;
    cout << "DÍA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "AÑO: ";
    cin >> anio;
    cout << "HORA: ";
    cin >> hora;
    cout << "MINUTOS: ";
    cin >> minutos;
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(hora);
    setMinutos(minutos);
}

std::string Fecha::toStringFecha() const{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << _dia << "/"
        << std::setw(2) << std::setfill('0') << _mes << "/"
        << std::setw(4) << std::setfill('0') << _anio;
    return oss.str();
}

std::string Fecha::toStringHora() const{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << _hora << ":"
        << std::setw(2) << std::setfill('0') << _minutos;
    return oss.str();
}

void Fecha::AjustarFecha(){
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(EsBisiesto(_anio))
        diasPorMes[1] = 29;
    else
        diasPorMes[1] = 28;

    while (_dia > diasPorMes[_mes - 1]) {
        _dia -= diasPorMes[_mes - 1];
        _mes++;
        if (_mes > 12) {
            _mes = 1;
            _anio++;
        }
    }

    while (_dia <= 0) {
        _mes--;
        if (_mes < 1) {
            _mes = 12;
            _anio--;
        }
        _dia += diasPorMes[_mes - 1];
    }
}

bool Fecha::EsBisiesto(int anio) const{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
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
    if(anio > 0 && anio < 100)
        _anio = anio + 2000;
    else
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

bool Fecha::operator==(const Fecha& otra) const {
    return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio &&
           _hora == otra._hora && _minutos == otra._minutos;
}

bool Fecha::operator!=(const Fecha& otra) const {
    return !(*this == otra);
}

bool Fecha::operator<(const Fecha& otra) const {
    if (_anio < otra._anio) return true;
    if (_anio > otra._anio) return false;
    if (_mes < otra._mes) return true;
    if (_mes > otra._mes) return false;
    if (_dia < otra._dia) return true;
    if (_dia > otra._dia) return false;
    if (_hora < otra._hora) return true;
    if (_hora > otra._hora) return false;
    return _minutos < otra._minutos;
}

bool Fecha::operator<=(const Fecha& otra) const {
    return *this < otra || *this == otra;
}

bool Fecha::operator>(const Fecha& otra) const {
    return !(*this <= otra);
}

bool Fecha::operator>=(const Fecha& otra) const {
    return !(*this < otra);
}

Fecha Fecha::operator+(int dias) const {
    Fecha nuevaFecha = *this;
    nuevaFecha._dia += dias;
    nuevaFecha.AjustarFecha();
    return nuevaFecha;
}

Fecha Fecha::operator-(int dias) const {
    Fecha nuevaFecha = *this;
    nuevaFecha._dia -= dias;
    nuevaFecha.AjustarFecha();
    return nuevaFecha;
}
