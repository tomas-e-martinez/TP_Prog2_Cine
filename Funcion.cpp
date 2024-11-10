#include "Funcion.h"

Funcion::Funcion(){
    _idFuncion = 0;
    _idPelicula = 0;
    _idSala = 0;
}

Funcion::Funcion(int idPelicula, int idSala, Fecha fecha){
    _idFuncion = 0;
    _idPelicula = idPelicula;
    _idSala = idSala;
    _fecha = fecha;
}

void Funcion::Cargar(){
    system("cls");
    cout << "CARGAR NUEVA FUNCIÓN" << endl;
    cout << "ID DE LA PELÍCULA: ";
    cin >> _idPelicula;
    cout << "ID DE LA SALA: ";
    cin >> _idSala;
    cout << "FECHA DE LA FUNCIÓN" << endl;
    _fecha.CargarHora();
}

void Funcion::Mostrar(){
    cout << "ID: " << _idFuncion << endl;
    cout << "ID PELÍCULA: " << _idPelicula << endl;
    cout << "ID SALA: " << _idSala << endl;
    cout << "FECHA: " << _fecha.toStringFecha() << endl;
    cout << "HORA: " << _fecha.toStringHora() << endl;
}

bool Funcion::Modificar(){
    int opcion;
    while(true){
        system("cls");
        Mostrar();
        cout << endl << "1. ID Película\n2. ID Sala\n3. Fecha\n\n0. Guardar y salir\n-1. Cancelar modificación" << endl << endl;
        cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCIÓN A MODIFICAR: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            int idPelicula;
            cout << endl << "NUEVO ID PELÍCULA: ";
            cin >> idPelicula;
            setIdPelicula(idPelicula);
            break;
        case 2:
            int idSala;
            cout << endl << "NUEVO ID SALA: ";
            cin >> idSala;
            setIdSala(idSala);
            break;
        case 3:
            cout << endl << "NUEVA FECHA \n";
            _fecha.CargarHora();
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

int Funcion::getIdFuncion(){
    return _idFuncion;
}

int Funcion::getIdPelicula(){
    return _idPelicula;
}

int Funcion::getIdSala(){
    return _idSala;
}


Fecha& Funcion::getFecha(){
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


