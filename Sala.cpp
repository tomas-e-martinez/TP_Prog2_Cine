#include "Sala.h"

Sala::Sala(){
    _idSala = 0;
    _capacidad = 0;
    strcpy(_tipo, "Sin tipo");
}

Sala::Sala(int idSala, int capacidad, const char* tipo){
    _idSala = idSala;
    _capacidad = capacidad;
    strcpy(_tipo,tipo);

}

void Sala::Cargar(){
    system("cls");
    cout << "CARGAR SALA" << endl;
    cout << "ID DE LA SALA: ";
    cin >> _idSala;
    cout << "TIPO: ";
    cin.getline(_tipo, sizeof(_tipo));
    cout << "CAPACIDAD: ";
    cin >> _capacidad;

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


