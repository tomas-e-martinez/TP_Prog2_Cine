#include "Cliente.h"

Cliente::Cliente(){
    _id = 0;
    _dni = 0;
    strcpy(_nombre, "Sin nombre");
    strcpy(_apellido, "Sin apellido");
    strcpy(_telefono, "Sin telefono");
}

Cliente::Cliente(int id, int dni, const char* nombre, const char* apellido, const char* telefono, Fecha fechaNacimiento){
    _id = id;
    _dni = dni;
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    strcpy(_telefono,telefono);
    _fechaNacimiento = fechaNacimiento;
}

void Cliente::Cargar(){
    system("cls");
    cout << "CARGAR NUEVO CLIENTE" << endl;
    cout << "DNI: ";
    cin >> _dni;
    cout << "NOMBRE: ";
    cin.getline(_nombre, sizeof(_nombre));
    cout << "APELLIDO: ";
    cin.getline(_apellido, sizeof(_apellido));
    cout << "TELEFONO: ";
    cin.getline(_telefono, sizeof(_telefono));
    cout << "FECHA DE NACIMIENTO" << endl;
    _fechaNacimiento.Cargar();

}

void Cliente::Mostrar(){
    cout << _dni << endl;
    cout << _nombre << endl;
    cout << _apellido << endl;
    cout << _telefono << endl;
    cout << _fechaNacimiento.toStringFecha() << endl;
}

int Cliente::getId(){
    return _id;
}

int Cliente::getDni(){
    return _dni;
}

const char* Cliente::getNombre(){
    return _nombre;
}

const char* Cliente::getApellido(){
    return _apellido;
}

const char* Cliente::getTelefono(){
    return _telefono;
}

Fecha Cliente::getFechaNacimiento(){
    return _fechaNacimiento;
}


void Cliente::setId(int id){
    _id = id;
}

void Cliente::setDni(int dni){
    _dni = dni;
}

void Cliente::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

void Cliente::setApellido(const char* apellido){
    strcpy(_apellido, apellido);
}

void Cliente::setTelefono(const char* telefono){
    strcpy(_telefono, telefono);
}

void Cliente::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}


