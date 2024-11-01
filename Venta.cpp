#include "Venta.h"

Venta::Venta(){
    _idVenta = 0;
    _dniCliente = 0;
   _idFuncion = 0;
   _cantidadEntradas = 0;
}

Venta::Venta(int idVenta, int dniCliente, int idFuncion, int cantidadEntradas, Fecha fecha){
    _idVenta = idVenta;
    _dniCliente = dniCliente;
    _idFuncion = idFuncion;
    _cantidadEntradas = cantidadEntradas;
    _fecha = fecha;
}


void Venta::Cargar(){
    system("cls");
    cout << "ID FUNCIÓN: ";
    cin >> _idFuncion;
    cout << "DNI CLIENTE: ";
    cin >> _dniCliente;
    cout << "CANTIDAD DE ENTRADAS: ";
    cin >> _cantidadEntradas;
    cout << "FECHA: " << endl;
    _fecha.CargarHora();
}

void Venta::Mostrar() {
        cout << "ID VENTA: " << _idVenta << endl;
        cout << "DNI CLIENTE: " << _dniCliente << endl;
        cout << "ID FUNCION: " << _idFuncion << endl;
        cout << "CANTIDAD DE ENTRADAS: " << _cantidadEntradas << endl;
        cout << "FECHA DE LA VENTA: " << _fecha.toStringFecha() << endl;
        cout << "HORA: " << _fecha.toStringHora() << endl;
    }


int Venta::getIdVenta(){
    return _idVenta;
}

int Venta::getDniCliente(){
    return _dniCliente;
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

void Venta::setDniCliente(int dniCliente){
    _dniCliente = dniCliente;
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
