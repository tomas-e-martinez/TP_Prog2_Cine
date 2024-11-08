#include "Sala.h"

Sala::Sala(){
    _idSala = 0;
    _capacidad = 0;
    strcpy(_tipo, "NULO");
}

Sala::Sala(int idSala, int capacidad, const char* tipo){
    _idSala = idSala;
    _capacidad = capacidad;
    strcpy(_tipo,tipo);

}

void Sala::Cargar(){
    system("cls");
    int opcion;
    cout << "CARGAR NUEVA SALA" << endl;
    cout << "TIPO\n 1.2D\n 2.3D\n 3.IMAX" << endl;
    cout << "OPCIÓN: ";
    cin >> opcion;
    switch(opcion){
    case 1:
        strcpy(_tipo, "2D");
        break;
    case 2:
        strcpy(_tipo, "3D");
        break;
    case 3:
        strcpy(_tipo, "IMAX");
        break;
    default:
        strcpy(_tipo, "NULO");
        break;
    }
    cout << "CAPACIDAD: ";
    cin >> _capacidad;
    cin.ignore();
}

void Sala::Mostrar(){
    cout << _idSala << endl;
    cout << _tipo << endl;
    cout << _capacidad<< endl;
}

int Sala::getIdSala(){
    return _idSala;
}

const char* Sala::getTipo(){
    return _tipo;
}

int Sala::getCapacidad(){
    return _capacidad;
}


void Sala::setIdSala(int idSala){
    _idSala = idSala;
}

void Sala::setTipo(const char* tipo){
    strcpy(_tipo, tipo);
}

void Sala::setCapacidad(int capacidad){
    _capacidad = capacidad;
}


