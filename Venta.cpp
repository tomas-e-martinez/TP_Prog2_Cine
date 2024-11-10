#include "Venta.h"

Venta::Venta(){
    _idVenta = 0;
    _idCliente = 0;
   _idFuncion = 0;
   _cantidadEntradas = 0;
}

Venta::Venta(int idVenta, int idCliente, int idFuncion, int cantidadEntradas, Fecha fecha){
    _idVenta = idVenta;
    _idCliente = idCliente;
    _idFuncion = idFuncion;
    _cantidadEntradas = cantidadEntradas;
    _fecha = fecha;
}


void Venta::Cargar(){
    system("cls");
    cout << "CARGAR NUEVA VENTA" << endl;
    cout << "ID FUNCIÓN: ";
    cin >> _idFuncion;
    cout << "ID CLIENTE: ";
    cin >> _idCliente;
    cout << "CANTIDAD DE ENTRADAS: ";
    cin >> _cantidadEntradas;
    cout << "FECHA: " << endl;
    _fecha.CargarHora();
}

void Venta::Mostrar() {
        cout << "ID: " << _idVenta << endl;
        cout << "ID CLIENTE: " << _idCliente << endl;
        cout << "ID FUNCION: " << _idFuncion << endl;
        cout << "CANTIDAD DE ENTRADAS: " << _cantidadEntradas << endl;
        cout << "FECHA DE LA VENTA: " << _fecha.toStringFecha() << endl;
        cout << "HORA: " << _fecha.toStringHora() << endl;
    }


int Venta::getIdVenta(){
    return _idVenta;
}

int Venta::getIdCliente(){
    return _idCliente;
}

int Venta::getIdFuncion(){
    return _idFuncion;
}

Fecha Venta::getFecha(){
    return _fecha;
}

int Venta::getCantidadEntradas(){
    return _cantidadEntradas;
}


void Venta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}

void Venta::setIdCliente(int idCliente){
    _idCliente = idCliente;
}

void Venta::setIdFuncion(int idFuncion){
    _idFuncion = idFuncion;
}

void Venta::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Venta::setCantidadEntradas(int cantidadEntradas){
    _cantidadEntradas = cantidadEntradas;
}
