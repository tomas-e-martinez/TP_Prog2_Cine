#include "Pelicula.h"

Pelicula::Pelicula(){
    _id = 0;
    _clasificacionEdad = 0;
    strcpy(_titulo, "Sin titulo");
    strcpy(_sinopsis, "Sin sinopsis");
    strcpy(_genero, "Sin genero");
    _calificacion = 0.0f;
}

Pelicula::Pelicula(int id, int clasificacionEdad, const char* titulo, const char* sinopsis, const char* genero, float calificacion, Fecha fechaEstreno, Tiempo duracion){
    _id = id;
    _clasificacionEdad = clasificacionEdad;
    strcpy(_titulo, titulo);
    strcpy(_sinopsis, sinopsis);
    strcpy(_genero, genero);
    _calificacion = calificacion;
    _fechaEstreno = fechaEstreno;
    _duracion = duracion;
}

void Pelicula::Cargar(){
    system("cls");
    cout << "CARGAR NUEVA PEL�CULA" << endl;
    cout << "ID: ";
    cin >> _id;
    cout << "CLASIFICACI�N DE EDAD: ";
    cin >> _clasificacionEdad;
    cin.ignore();
    cout << "T�TULO: ";
    cin.getline(_titulo, sizeof(_titulo));
    cout << "SINOPSIS: ";
    cin.getline(_sinopsis, sizeof(_sinopsis));
    cout << "G�NERO: ";
    cin.getline(_genero, sizeof(_genero));
    cout << "CALIFICACI�N: ";
    cin >> _calificacion;
    cout << "FECHA DE ESTRENO" << endl;
    _fechaEstreno.Cargar();
    cout << "DURACI�N" << endl;
    _duracion.Cargar();
}

void Pelicula::Mostrar(){
    cout << _id << endl;
    cout << _titulo << endl;
    cout << _sinopsis << endl;
    cout << _genero << endl;
    cout << _clasificacionEdad << "+" << endl;
    cout << _calificacion << endl;
    cout << _fechaEstreno.toStringFecha() << endl;
    cout << _duracion.toString() << endl;
}
