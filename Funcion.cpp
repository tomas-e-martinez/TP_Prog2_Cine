#include "Funcion.h"

Funcion::Funcion(){
    _idFuncion = 0;
    _idPelicula = 0;
    _idSala = 0;
}

Funcion::Funcion(int idFuncion, int idPelicula, int idSala, Fecha fecha){
    _idFuncion = idFuncion;
    _idPelicula = idPelicula;
    _idSala = idSala;
    _fecha = fecha;
}

void Funcion::Cargar(){
    system("cls");
    cout << "ID DE LA PELÍCULA: ";
    cin >> _idPelicula;
    cout << "ID DE LA SALA: ";
    cin >> _idSala;
    cout << "FECHA DE LA FUNCIÓN" << endl;
    _fecha.CargarHora();
}

void Funcion::Mostrar(){
    cout << _idFuncion << endl;
    cout << _idPelicula << endl;
    cout << _idSala << endl;
    cout << _fecha.toStringHora() << endl;
}

int Funcion::getIdFuncion(){
    return _idFuncion;
}

int Funcion::getIdPelicula(){
    return _idPelicula;
}

int Funcion::getIdSala(){
    return _idSala;
}


Fecha Funcion::getFecha(){
    return _fecha;
}


void Funcion::setIdFuncion(int idFuncion){
    _idFuncion = idFuncion;
}

void Funcion::setIdPelicula(int idPelicula){
    _idPelicula = idPelicula;
}

void Funcion::setIdSala(int idSala){
    _idSala = idSala;
}
void Funcion::setFecha(Fecha fecha){
    _fecha = fecha;
}


