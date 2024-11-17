#include "Sala.h"

Sala::Sala(){
    _idSala = 0;
    _capacidad = 0;
    strcpy(_tipo, "NULO");
    _activo = true;
}

Sala::Sala(int capacidad, int tipo){
    _idSala = 0;
    _capacidad = capacidad;
    setTipo(tipo);
    _activo = true;
}

void Sala::Cargar(){
    system("cls");
    int opcion;
    cout << "CARGAR NUEVA SALA" << endl;
    cout << "TIPO\n 1.2D\n 2.3D\n 3.IMAX" << endl;
    cout << "OPCIÓN: ";
    cin >> opcion;
    setTipo(opcion);
    cout << "CAPACIDAD: ";
    cin >> _capacidad;
    cin.ignore();
}

void Sala::Mostrar(){
    cout << "ID: " << _idSala << endl;
    cout << "TIPO: " << _tipo << endl;
    cout << "CAPACIDAD: " << _capacidad<< endl;
}

bool Sala::Modificar(){
    int opcion;
    while(true){
        system("cls");
        Mostrar();
        cout << endl << "1. Capacidad\n2. Tipo\n\n0. Guardar y salir\n-1. Cancelar modificación" << endl << endl;
        cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCIÓN A MODIFICAR: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            int capacidad;
            cout << endl << "NUEVA CAPACIDAD: ";
            cin >> capacidad;
            setCapacidad(capacidad);
            break;
        case 2:
            int opcionTipo;
            cout << endl << "NUEVO TIPO\n1. 2D\n2. 3D\n3. IMAX\n\n";
            cout << "INGRESAR OPCIÓN: ";
            cin >> opcionTipo;
            setTipo(opcionTipo);
            break;
        case 0:
            return true;
        case -1:
            return false;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA." << endl;
            system("pause");
            continue;
        }
    }
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

bool Sala::getActivo(){
    return _activo;
}


void Sala::setIdSala(int idSala){
    _idSala = idSala;
}

void Sala::setTipo(int tipo){
    switch(tipo){
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
}

void Sala::setCapacidad(int capacidad){
    _capacidad = capacidad;
}

void Sala::setActivo(bool activo){
    _activo = activo;
}
