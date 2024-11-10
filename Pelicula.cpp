#include "Pelicula.h"

Pelicula::Pelicula(){
    _id = 0;
    _clasificacionEdad = 0;
    strcpy(_titulo, "Sin t�tulo");
    strcpy(_sinopsis, "Sin sinopsis");
    strcpy(_genero, "Sin g�nero");
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
    cout << "T�TULO: ";
    cin.getline(_titulo, sizeof(_titulo));
    cout << "SINOPSIS: ";
    cin.getline(_sinopsis, sizeof(_sinopsis));
    cout << "G�NERO: ";
    cin.getline(_genero, sizeof(_genero));
    cout << "CALIFICACI�N: ";
    cin >> _calificacion;
    cin.ignore();
    cout << "FECHA DE ESTRENO" << endl;
    _fechaEstreno.Cargar();
    cout << "DURACI�N" << endl;
    _duracion.Cargar();
    cout << "CLASIFICACI�N DE EDAD: ";
    cin >> _clasificacionEdad;
    cin.ignore();
}

void Pelicula::Mostrar(){
    cout << "ID: " << _id << endl;
    cout << "T�TULO: " << _titulo << endl;
    cout << "SINOPSIS: " << _sinopsis << endl;
    cout << "G�NERO: " << _genero << endl;
    cout << "CLASIFICACI�N DE EDAD: " << _clasificacionEdad << endl;
    cout << "CALIFICACI�N (0-10): " << _calificacion << endl;
    cout << "FECHA DE ESTRENO: " << _fechaEstreno.toStringFecha() << endl;
    cout << "DURACI�N: " << _duracion.toString() << endl;
}

int Pelicula::getId(){
    return _id;
}

const char* Pelicula::getTitulo(){
    return _titulo;
}

const char* Pelicula::getSinopsis(){
    return _sinopsis;
}

const char* Pelicula::getGenero(){
    return _genero;
}

int Pelicula::getClasificacionedad(){
    return _clasificacionEdad;
}

float Pelicula::getCalificacion(){
    return _calificacion;
}

Fecha& Pelicula::getFechaEstreno(){
    return _fechaEstreno;
}

Tiempo& Pelicula::getDuracion(){
    return _duracion;
}

void Pelicula::setId(int id){
    _id = id;
}

void Pelicula::setTitulo(const char* titulo){
    strcpy(_titulo, titulo);
}

void Pelicula::setSinopsis(const char* sinopsis){
    strcpy(_sinopsis, sinopsis);
}

void Pelicula::setGenero(const char* genero){
    strcpy(_genero, genero);
}

void Pelicula::setClasificacionEdad(int clasificacionEdad){
    _clasificacionEdad = clasificacionEdad;
}

void Pelicula::setCalificacion(float calificacion){
    _calificacion = calificacion;
}

void Pelicula::setFechaEstreno(Fecha fechaEstreno){
    _fechaEstreno = fechaEstreno;
}

void Pelicula::setDuracion(Tiempo duracion){
    _duracion = duracion;
}
