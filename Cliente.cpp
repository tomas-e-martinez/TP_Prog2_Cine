#include "Cliente.h"

Cliente::Cliente(){
    _id = 0;
    _dni = 0;
    strcpy(_nombre, "Sin nombre");
    strcpy(_apellido, "Sin apellido");
    strcpy(_telefono, "Sin telefono");
}

Cliente::Cliente(int dni, const char* nombre, const char* apellido, const char* telefono, Fecha fechaNacimiento){
    _id = 0;
    _dni = dni;
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    strcpy(_telefono,telefono);
    _fechaNacimiento = fechaNacimiento;
}

void Cliente::Cargar(int dni){
    if(dni == 0){
    system("cls");
    cout << "CARGAR NUEVO CLIENTE" << endl;
    cout << "DNI: ";
    cin >> _dni;
    }
    else
        setDni(dni);

    cin.ignore();
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
    cout << "DNI: " << _dni << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "APELLIDO: " << _apellido << endl;
    cout << "TELÉFONO: " << _telefono << endl;
    cout << "FECHA DE NACIMIENTO: " << _fechaNacimiento.toStringFecha() << endl;
}

bool Cliente::Modificar(){
    int opcion;
    while(true){
        system("cls");
        Mostrar();
        cout << endl << "1. DNI\n2. Nombre\n3. Apellido\n4. Teléfono\n5. Fecha de nacimiento\n\n0. Guardar y salir\n-1. Cancelar modificación" << endl << endl;
        cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCIÓN A MODIFICAR: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            int dni;
            cout << endl << "NUEVO DNI: ";
            cin >> dni;
            setDni(dni);
            break;
        case 2:
            char nombre[30];
            cout << endl << "NUEVO NOMBRE: ";
            cin.getline(nombre, sizeof(nombre));
            setNombre(nombre);
            break;
        case 3:
            char apellido[30];
            cout << endl << "NUEVO APELLIDO: ";
            cin.getline(apellido, sizeof(apellido));
            setApellido(apellido);
            break;
        case 4:
            char telefono[20];
            cout << endl << "NUEVO TELÉFONO: ";
            cin.getline(telefono, sizeof(telefono));
            setTelefono(telefono);
            break;
        case 5:
            cout << "NUEVA FECHA DE NACIMIENTO \n";
            _fechaNacimiento.Cargar();
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

Fecha& Cliente::getFechaNacimiento(){
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


