#include "Pelicula.h"

Pelicula::Pelicula(){
    _id = 0;
    _clasificacionEdad = 0;
    strcpy(_titulo, "Sin título");
    strcpy(_sinopsis, "Sin sinopsis");
    strcpy(_genero, "Sin género");
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
    int opcionGenero;
    cout << "CARGAR NUEVA PELÍCULA" << endl;
    cout << "TÍTULO: ";
    cin.getline(_titulo, sizeof(_titulo));
    cout << "SINOPSIS: ";
    cin.getline(_sinopsis, sizeof(_sinopsis));
    cout << "GÉNERO\n1. Accion\n2. Ciencia Ficcion\n3. Animacion\n4. Fantasia\n5. Drama\n6. Comedia\n7. Terror\n8. Aventura\n\nOPCIÓN: ";
    cin >> opcionGenero;
    switch(opcionGenero){
    case 1:
        strcpy(_genero, "Accion");
        break;
    case 2:
        strcpy(_genero, "Ciencia Ficcion");
        break;
    case 3:
        strcpy(_genero, "Animacion");
        break;
    case 4:
        strcpy(_genero, "Fantasia");
        break;
    case 5:
        strcpy(_genero, "Drama");
        break;
    case 6:
        strcpy(_genero, "Comedia");
        break;
    case 7:
        strcpy(_genero, "Terror");
        break;
    case 8:
        strcpy(_genero, "Aventura");
        break;
    default:
        strcpy(_genero, "Sin Genero");
        break;
    }
    cout << "CALIFICACIÓN: ";
    cin >> _calificacion;
    cin.ignore();
    cout << "FECHA DE ESTRENO" << endl;
    _fechaEstreno.Cargar();
    cout << "DURACIÓN" << endl;
    _duracion.Cargar();
    cout << "CLASIFICACIÓN DE EDAD: ";
    cin >> _clasificacionEdad;
    cin.ignore();
}

void Pelicula::Mostrar(){
    cout << "ID: " << _id << endl;
    cout << "TÍTULO: " << _titulo << endl;
    cout << "SINOPSIS: " << _sinopsis << endl;
    cout << "GÉNERO: " << _genero << endl;
    cout << "CLASIFICACIÓN DE EDAD: " << _clasificacionEdad << endl;
    cout << "CALIFICACIÓN (0-10): " << _calificacion << endl;
    cout << "FECHA DE ESTRENO: " << _fechaEstreno.toStringFecha() << endl;
    cout << "DURACIÓN: " << _duracion.toString() << endl;
}

bool Pelicula::Modificar(){
    int opcion;
    while(true){
        system("cls");
        Mostrar();
        cout << endl << "1. Título\n2. Sinopsis\n3. Género\n4. Clasificación de edad\n5. Calificación\n6. Fecha de estreno\n7. Duración\n\n0. Guardar y salir\n-1 Cancelar modificación" << endl << endl;
        cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCIÓN A MODIFICAR: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            char titulo[100];
            cout << endl << "NUEVO TÍTULO: ";
            cin.getline(titulo, sizeof(titulo));
            setTitulo(titulo);
            break;
        case 2:
            char sinopsis[500];
            cout << endl << "NUEVA SINOPSIS: ";
            cin.getline(sinopsis, sizeof(sinopsis));
            setSinopsis(sinopsis);
            break;
        case 3:
            char genero[20];
            cout << endl << "NUEVO GÉNERO: ";
            cin.getline(genero, sizeof(genero));
            setGenero(genero);
            break;
        case 4:
            int clasificacionEdad;
            cout << endl << "NUEVA CLASIFICACIÓN DE EDAD: ";
            cin >> clasificacionEdad;
            setClasificacionEdad(clasificacionEdad);
            break;
        case 5:
            float calificacion;
            cout << endl << "NUEVA CALIFICACIÓN (1-10): ";
            cin >> calificacion;
            setCalificacion(calificacion);
            break;
        case 6:
            cout << "NUEVA FECHA DE ESTRENO \n";
            _fechaEstreno.Cargar();
            break;
        case 7:
            cout << "NUEVA DURACIÓN \n";
            _duracion.Cargar();
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
