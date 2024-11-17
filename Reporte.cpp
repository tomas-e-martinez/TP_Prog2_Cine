#include "Reporte.h"

void Reporte::ListarPeliculas(const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(!registro.getActivo())
            continue;
        cout << left
             << setw(5)  << registro.getId()
             << setw(40) << registro.getTitulo()
             << setw(20) << registro.getGenero()
             << setw(20) << registro.getFechaEstreno().toStringFecha()
             << setw(10) << registro.getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << registro.getCalificacion()
             << setw(5)  << (to_string(registro.getClasificacionedad()) + "+") << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasOrdenGenero(const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    Pelicula* peliculas = new Pelicula[cantidadRegistros];

    //ALMACENAR REGISTROS PARA ORDENAR DESPUÉS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        peliculas[i] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < cantidadRegistros - 1; i++){
        for(int j = 0; j < cantidadRegistros - 1; j++){
            if(strcmp(peliculas[j].getGenero(), peliculas[j+1].getGenero()) > 0){
                Pelicula aux = peliculas[j];
                peliculas[j] = peliculas[j+1];
                peliculas[j+1] = aux;
            }
        }
    }

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        if(!peliculas[i].getActivo())
            continue;
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasOrdenCalificacion(const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    Pelicula* peliculas = new Pelicula[cantidadRegistros];

    //ALMACENAR REGISTROS PARA ORDENAR DESPUÉS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        peliculas[i] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < cantidadRegistros - 1; i++){
        for(int j = 0; j < cantidadRegistros - 1; j++){
            if(peliculas[j].getCalificacion() > peliculas[j+1].getCalificacion()){
                Pelicula aux = peliculas[j];
                peliculas[j] = peliculas[j+1];
                peliculas[j+1] = aux;
            }
        }
    }

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        if(!peliculas[i].getActivo())
            continue;
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasGenero(int opcionGenero, const char* nombreArchivo){
    char genero[20];
    switch(opcionGenero){
    case 1:
        strcpy(genero, "Accion");
        break;
    case 2:
        strcpy(genero, "Ciencia Ficcion");
        break;
    case 3:
        strcpy(genero, "Animacion");
        break;
    case 4:
        strcpy(genero, "Fantasia");
        break;
    case 5:
        strcpy(genero, "Drama");
        break;
    case 6:
        strcpy(genero, "Comedia");
        break;
    case 7:
        strcpy(genero, "Terror");
        break;
    case 8:
        strcpy(genero, "Aventura");
        break;
    case 0:
        return;
    default:
        cout << "ERROR: LA OPCIÓN INGRESADA NO ES VÁLIDA." << endl;
        system("pause");
        return;
    }

    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    Pelicula* peliculas = new Pelicula[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS QUE COINCIDAN CON EL GÉNERO Y ESTÉN ACTIVAS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(strcmp(registro.getGenero(), genero) == 0 && registro.getActivo())
            peliculas[indice++] = registro;
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    cout << "PELÍCULAS ENCONTRADAS: " << indice << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << "Se encontraron " << indice << " películas del género \"" << genero << "\"." << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasCalificacion(float minCalificacion, float maxCalificacion, const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    Pelicula* peliculas = new Pelicula[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS QUE ESTÉN EN EL RANGO DE CALIFICACIONES Y ESTÉN ACTIVOS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(registro.getCalificacion() >= minCalificacion && registro.getCalificacion() <= maxCalificacion && registro.getActivo())
            peliculas[indice++] = registro;
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    cout << "PELÍCULAS ENCONTRADAS: " << indice << endl;
    system("pause");
    system("cls");

    //ORDENAR REGISTROS
    for(int i = 0; i < indice - 1; i++){
        for(int j = 0; j < indice - 1; j++){
            if(peliculas[j].getCalificacion() > peliculas[j+1].getCalificacion()){
                Pelicula aux = peliculas[j];
                peliculas[j] = peliculas[j+1];
                peliculas[j+1] = aux;
            }
        }
    }

    // ENCABEZADO
    cout << "Se encontraron " << indice << " películas calificadas entre " << minCalificacion << " y " << maxCalificacion << "." << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasTitulo(const char* titulo, const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    int posicion = archivo.BuscarTitulo(titulo, false);

    if(posicion == -1){
        cout << "No se encontro ninguna película con el título ingresado." << endl;
        system("pause");
        return;
    }

    Pelicula registro = archivo.LeerRegistro(posicion);
    system("cls");
    registro.Mostrar();
    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasEdad(int edadMax, const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    Pelicula* peliculas = new Pelicula[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS QUE ESTÉN DEBAJO DEL LÍMITE DE EDAD Y ESTÉN ACTIVOS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(registro.getClasificacionedad() <= edadMax && registro.getActivo())
            peliculas[indice++] = registro;
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE PELÍCULAS: " << cantidadRegistros << endl;
    cout << "PELÍCULAS ENCONTRADAS: " << indice << endl;
    system("pause");
    system("cls");

    //ORDENAR REGISTROS
    for(int i = 0; i < indice - 1; i++){
        for(int j = 0; j < indice - 1; j++){
            if(peliculas[j].getClasificacionedad() > peliculas[j+1].getClasificacionedad()){
                Pelicula aux = peliculas[j];
                peliculas[j] = peliculas[j+1];
                peliculas[j+1] = aux;
            }
        }
    }

    // ENCABEZADO
    cout << "Se encontraron " << indice << " películas para una edad máxima de " << edadMax << "." << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(15) << "CALIFICACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << fixed << setprecision(2) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarClientes(const char* nombreArchivo){
    ArchivoClientes archivo(nombreArchivo);
    Cliente registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE CLIENTES: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "DNI"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(20) << "TELÉFONO"
         << setw(15) << "FECHA DE NACIMIENTO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        if(!registro.getActivo())
            continue;
        cout << left
             << setw(5)  << registro.getId()
             << setw(10) << registro.getDni()
             << setw(30) << registro.getNombre()
             << setw(30) << registro.getApellido()
             << setw(20) << registro.getTelefono()
             << setw(15) << registro.getFechaNacimiento().toStringFecha() << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::ListarClientesEdad(int minimo, int maximo, const char* nombreArchivo){
    ArchivoClientes archivo(nombreArchivo);
    Cliente registro;
    int edad;

    int cantidadRegistros = archivo.ContarRegistros();

    Cliente* clientes = new Cliente[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS EN RANGO DE EDAD QUE ESTÉN ACTIVOS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        edad = 2024 - registro.getFechaNacimiento().getAnio();
        if(edad >= minimo && edad <= maximo && registro.getActivo())
            clientes[indice++] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < indice - 1; i++){
        for(int j = 0; j < indice - 1; j++){
            int edadA = 2024 - clientes[j].getFechaNacimiento().getAnio();
            int edadB = 2024 - clientes[j+1].getFechaNacimiento().getAnio();
            if(edadA > edadB){
                Cliente aux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux;
            }
        }
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE CLIENTES: " << cantidadRegistros << endl;
    cout << "CLIENTES ENCONTRADOS: " << indice << endl;
    system("pause");
    system("cls");


    // ENCABEZADO
    cout << indice << " Clientes con edad entre " << minimo << " Y " << maximo << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "DNI"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(20) << "TELÉFONO"
         << setw(15) << "FECHA DE NAC."
         << setw(10) << "EDAD" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        edad = 2024 - clientes[i].getFechaNacimiento().getAnio();
        cout << left
             << setw(5)  << clientes[i].getId()
             << setw(10) << clientes[i].getDni()
             << setw(30) << clientes[i].getNombre()
             << setw(30) << clientes[i].getApellido()
             << setw(20) << clientes[i].getTelefono()
             << setw(15) << clientes[i].getFechaNacimiento().toStringFecha()
             << setw(10) << edad << endl;
    }

    delete[] clientes;

    cout << endl;
    system("pause");
}

void Reporte::ListarClientesApellido(const char* nombreArchivo){
    ArchivoClientes archivo(nombreArchivo);
    Cliente registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE CLIENTES: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    Cliente* clientes = new Cliente[cantidadRegistros];

    //ALMACENAR REGISTROS PARA ORDENAR DESPUÉS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        clientes[i] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < cantidadRegistros - 1; i++){
        for(int j = 0; j < cantidadRegistros - 1; j++){
            if(strcmp(clientes[j].getApellido(), clientes[j+1].getApellido()) > 0){
                Cliente aux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = aux;
            }
        }
    }

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "DNI"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(20) << "TELÉFONO"
         << setw(15) << "FECHA DE NACIMIENTO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        if(!clientes[i].getActivo())
            continue;
        cout << left
             << setw(5)  << clientes[i].getId()
             << setw(10) << clientes[i].getDni()
             << setw(30) << clientes[i].getNombre()
             << setw(30) << clientes[i].getApellido()
             << setw(20) << clientes[i].getTelefono()
             << setw(15) << clientes[i].getFechaNacimiento().toStringFecha() << endl;
    }

    delete[] clientes;

    cout << endl;
    system("pause");
}

void Reporte::ListarClientesDNI(int dni, const char* nombreArchivo){
    ArchivoClientes archivo(nombreArchivo);
    int posicion = archivo.BuscarDni(dni, false);

    if(posicion == -1){
        cout << "No se encontró ningún cliente con el DNI ingresado. " << endl;
        system("pause");
        return;
    }

    Cliente registro = archivo.LeerRegistro(posicion);

    system("cls");
    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "DNI"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(20) << "TELÉFONO"
         << setw(15) << "FECHA DE NACIMIENTO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left
         << setw(5)  << registro.getId()
         << setw(10) << registro.getDni()
         << setw(30) << registro.getNombre()
         << setw(30) << registro.getApellido()
         << setw(20) << registro.getTelefono()
         << setw(15) << registro.getFechaNacimiento().toStringFecha() << endl;

    cout << endl;
    system("pause");
}

void Reporte::ListarFunciones(const char* nombreArchivo){
    ArchivoPeliculas archivoPeliculas;
    ArchivoSalas archivoSalas;
    ArchivoFunciones archivo(nombreArchivo);
    Funcion registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE FUNCIONES: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "PELÍCULA"
         << setw(15) << "DURACIÓN"
         << setw(10) << "EDAD"
         << setw(10) << "SALA"
         << setw(10) << "TIPO"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        if(!registro.getActivo())
            continue;
        Pelicula pelicula = archivoPeliculas.LeerRegistro(registro.getIdPelicula());
        Sala sala = archivoSalas.LeerRegistro(registro.getIdSala());
        cout << left
             << setw(5)  << registro.getIdFuncion()
             << setw(40) << pelicula.getTitulo()
             << setw(15) << pelicula.getDuracion().toString()
             << setw(10) << (to_string(pelicula.getClasificacionedad()) + "+")
             << setw(10) << ("N°" + to_string(registro.getIdSala()))
             << setw(10) << sala.getTipo()
             << setw(20) << registro.getFecha().toStringFecha()
             << setw(10) << registro.getFecha().toStringHora() << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::ListarFuncionesFecha(const Fecha& minimo,const Fecha& maximo, const char* nombreArchivo){
    ArchivoPeliculas archivoPeliculas;
    ArchivoSalas archivoSalas;
    ArchivoFunciones archivo(nombreArchivo);
    Funcion registro;

    int cantidadRegistros = archivo.ContarRegistros();

    Funcion* funciones = new Funcion[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS EN RANGO DE FECHAS
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(registro.getFecha() >= minimo && registro.getFecha() <= maximo && registro.getActivo())
            funciones[indice++] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < indice - 1; i++){
        for(int j = 0; j < indice - 1; j++){
            if(funciones[j].getFecha() > funciones[j+1].getFecha()){
                Funcion aux = funciones[j];
                funciones[j] = funciones[j+1];
                funciones[j+1] = aux;
            }
        }
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE FUNCIONES: " << cantidadRegistros << endl;
    cout << "FUNCIONES ENCONTRADAS: " << indice << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << "Se encontraron " << indice << " funciones entre " << minimo.toStringFecha() << " y " << maximo.toStringFecha() << "." << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "PELÍCULA"
         << setw(15) << "DURACIÓN"
         << setw(10) << "EDAD"
         << setw(10) << "SALA"
         << setw(10) << "TIPO"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        registro = funciones[i];
        Pelicula pelicula = archivoPeliculas.LeerRegistro(registro.getIdPelicula());
        Sala sala = archivoSalas.LeerRegistro(registro.getIdSala());
        cout << left
             << setw(5)  << registro.getIdFuncion()
             << setw(40) << pelicula.getTitulo()
             << setw(15) << pelicula.getDuracion().toString()
             << setw(10) << (to_string(pelicula.getClasificacionedad()) + "+")
             << setw(10) << ("N°" + to_string(registro.getIdSala()))
             << setw(10) << sala.getTipo()
             << setw(20) << registro.getFecha().toStringFecha()
             << setw(10) << registro.getFecha().toStringHora() << endl;
    }

    delete[] funciones;

    cout << endl;
    system("pause");
    return;
}

void Reporte::ListarFuncionesSala(int tipo, const char* nombreArchivo){
    char tipoSala[5];
    switch(tipo){
    case 1:
        strcpy(tipoSala, "2D");
        break;
    case 2:
        strcpy(tipoSala, "3D");
        break;
    case 3:
        strcpy(tipoSala, "IMAX");
        break;
    case 0:
        return;
    default:
        cout << "ERROR: OPCIÓN INVÁLIDA." << endl;
        system("pause");
        return;
    }

    ArchivoPeliculas archivoPeliculas;
    ArchivoSalas archivoSalas;
    ArchivoFunciones archivoFunciones(nombreArchivo);
    Funcion registro;
    Sala sala;
    Pelicula pelicula;

    int cantidadRegistros = archivoFunciones.ContarRegistros();

    Funcion* funciones = new Funcion[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS QUE COINCIDAN CON EL TIPO DE SALA
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivoFunciones.LeerRegistro(i);
        sala = archivoSalas.LeerRegistro(registro.getIdSala());
        if(strcmp(sala.getTipo(), tipoSala) == 0 && registro.getActivo())
            funciones[indice++] = registro;
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE FUNCIONES: " << cantidadRegistros << endl;
    cout << "FUNCIONES ENCONTRADAS: " << indice << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << "Se encontraron " << indice << " funciones en salas de tipo " << tipoSala << "." << endl;
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "PELÍCULA"
         << setw(15) << "DURACIÓN"
         << setw(10) << "EDAD"
         << setw(10) << "SALA"
         << setw(10) << "TIPO"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < indice; i++) {
        registro = funciones[i];
        pelicula = archivoPeliculas.LeerRegistro(registro.getIdPelicula());
        sala = archivoSalas.LeerRegistro(registro.getIdSala());
        cout << left
             << setw(5)  << registro.getIdFuncion()
             << setw(40) << pelicula.getTitulo()
             << setw(15) << pelicula.getDuracion().toString()
             << setw(10) << (to_string(pelicula.getClasificacionedad()) + "+")
             << setw(10) << ("N°" + to_string(registro.getIdSala()))
             << setw(10) << sala.getTipo()
             << setw(20) << registro.getFecha().toStringFecha()
             << setw(10) << registro.getFecha().toStringHora() << endl;
    }

    delete[] funciones;

    cout << endl;
    system("pause");
    return;
}

void Reporte::VentaDetalle(Funcion& funcion, int cantEntradas, Fecha& fecha, Cliente& cliente, float valorEntrada, const char* nombreArchivo){
    ArchivoPeliculas archivoPeliculas;
    int posicionPelicula = archivoPeliculas.BuscarID(funcion.getIdPelicula());
    Pelicula pelicula = archivoPeliculas.LeerRegistro(posicionPelicula);
    ArchivoSalas archivoSalas;
    int posicionSala = archivoSalas.BuscarID(funcion.getIdSala());
    Sala sala = archivoSalas.LeerRegistro(posicionSala);

    system("cls");
    cout << "Película: " << pelicula.getTitulo() << endl;
    cout << "Fecha: "    << funcion.getFecha().toStringFecha() << endl;
    cout << "Hora: "     << funcion.getFecha().toStringHora() << endl;
    cout << "Tipo: "     << sala.getTipo() << endl;
    cout << "Sala N°"    << sala.getIdSala() << endl;
    cout << "Duración: " << pelicula.getDuracion().toString() << endl;
    cout << "Cliente: "  << cliente.getNombre() << " " << cliente.getApellido() << endl;
    cout << "Teléfono del cliente: " << cliente.getTelefono() << endl;
    cout << "N° de entradas: " << cantEntradas << endl;
    cout << "Valor por entrada: $" << valorEntrada << endl;
    cout << "Fecha de la venta: " << fecha.toStringFecha() << endl;
    cout << "Hora de la venta: " << fecha.toStringHora() << endl;
    cout << endl << "Total: $" << cantEntradas * valorEntrada << endl;
}

void Reporte::ListarVentas(const char* nombreArchivo){
    ArchivoVentas archivo(nombreArchivo);
    Venta registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "Cantidad de ventas: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "ID FUNCIÓN"
         << setw(15) << "ID CLIENTE"
         << setw(20) << "CANT. ENTRADAS"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        if(!registro.getActivo())
            continue;
        cout << left
             << setw(5)  << registro.getIdVenta()
             << setw(15) << registro.getIdFuncion()
             << setw(15) << registro.getIdCliente()
             << setw(20) << registro.getCantidadEntradas()
             << setw(20) << registro.getFecha().toStringFecha()
             << setw(10) << registro.getFecha().toStringHora() << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::ListarVentasOrdenFecha(const char* nombreArchivo){
    ArchivoVentas archivo;
    Venta registro;

    int cantidadRegistros = archivo.ContarRegistros();

    Venta* ventas = new Venta[cantidadRegistros];
    int indice = 0;

    //ALMACENAR REGISTROS PARA ORDENAR POR FECHA
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        ventas[indice++] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i < indice - 1; i++){
        for(int j = 0; j < indice - 1; j++){
            if(ventas[j].getFecha() > ventas[j+1].getFecha()){
                Venta aux = ventas[j];
                ventas[j] = ventas[j+1];
                ventas[j+1] = aux;
            }
        }
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE VENTAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "ID FUNCIÓN"
         << setw(15) << "ID CLIENTE"
         << setw(20) << "CANT. ENTRADAS"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        if(!ventas[i].getActivo())
            continue;
        cout << left
             << setw(5)  << ventas[i].getIdVenta()
             << setw(15) << ventas[i].getIdFuncion()
             << setw(15) << ventas[i].getIdCliente()
             << setw(20) << ventas[i].getCantidadEntradas()
             << setw(20) << ventas[i].getFecha().toStringFecha()
             << setw(10) << ventas[i].getFecha().toStringHora() << endl;
    }

    delete[] ventas;

    cout << endl;
    system("pause");
}

void Reporte::ListarSalas(const char* nombreArchivo){
    ArchivoSalas archivo(nombreArchivo);
    Sala registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "CANTIDAD TOTAL DE SALAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "CAPACIDAD"
         << setw(10) << "TIPO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        if(!registro.getActivo())
            continue;
        cout << left
             << setw(5)  << registro.getIdSala()
             << setw(15) << registro.getCapacidad()
             << setw(10) << registro.getTipo() << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::ListarSalasTipo(const char* nombreArchivo){
    ArchivoSalas archivo(nombreArchivo);
    Sala registro;

    int cantidadRegistros = archivo.ContarRegistros();
    Sala* salas = new Sala[cantidadRegistros];

    //ALMACENAR REGISTROS PARA ORDENAR POR TIPO
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        salas[i] = registro;
    }

    //ORDENAR REGISTROS
    for(int i = 0; i <  cantidadRegistros - 1; i++){
        for(int j = 0; j < cantidadRegistros - 1; j++){
            if(strcmp(salas[j].getTipo(), salas[j+1].getTipo()) > 0){
                Sala aux = salas[j];
                salas[j] = salas[j+1];
                salas[j+1] = aux;
            }
        }
    }

    system("cls");
    cout << "CANTIDAD TOTAL DE SALAS: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "CAPACIDAD"
         << setw(10) << "TIPO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        if(!salas[i].getActivo())
            continue;
        cout << left
             << setw(5)  << salas[i].getIdSala()
             << setw(15) << salas[i].getCapacidad()
             << setw(10) << salas[i].getTipo() << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::RecaudacionAnual(Reporte& reporte){
    int anio, idFuncion, posFuncion;
    float recaudacionAnualMeses[12] = {0};
    float valorEntrada, totalVenta;
    char meses[12][11] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    GestorCine gestor;
    Funcion funcion;
    Venta venta;
    ArchivoFunciones archivoFunciones;
    ArchivoVentas archivoVentas;

    int cantidadVentas = archivoVentas.ContarRegistros();
    if(cantidadVentas < 1){
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << "INGRESE EL AÑO A CONSULTAR: ";
    cin >> anio;
    cout << "RECAUDACIÓN DEL " << anio << endl;
    cout << "-----------------------------------------" << endl;

    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getFecha().getAnio() == anio && venta.getActivo()){
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);
            valorEntrada = gestor.CalcularPrecioEntrada(funcion);
            totalVenta = valorEntrada * venta.getCantidadEntradas();
            recaudacionAnualMeses[venta.getFecha().getMes() - 1] += totalVenta;
        }
    }

    // ENCABEZADO
    cout << left
         << setw(30) << "MES"
         << setw(30) << "RECAUDACIÓN" << endl;

    for (int i = 0; i < 12; i++) {
        cout << left
             << setw(30) << meses[i]
             << setw(1) << "$" << fixed << setprecision(2) << setw(29) << recaudacionAnualMeses[i] << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::RecaudacionTipoSala(Reporte& reporte){
    int idFuncion, posFuncion, opcion, idSala, posSala;
    float recaudacionTipos[3] = {0};
    char tipos[3][5] = {"2D", "3D", "IMAX"};
    float valorEntrada, totalVenta;

    GestorCine gestor;
    Funcion funcion;
    Venta venta;
    Sala sala;
    ArchivoFunciones archivoFunciones;
    ArchivoVentas archivoVentas;
    ArchivoSalas archivoSalas;

    int cantidadVentas = archivoVentas.ContarRegistros();
    if(cantidadVentas < 1){
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    Fecha fechaMin;
    Fecha fechaMax;

    while(true){
        system("cls");
        cout << "RECAUDACIÓN POR TIPO DE SALA\n1. Ingresar rango de fechas\n2. Año actual\n\n0. Cancelar\n\nOPCIÓN: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "RECAUDACIÓN DESDE" << endl;
            fechaMin.Cargar();
            cout << endl << "HASTA" << endl;
            fechaMax.Cargar();
            break;
        case 2:
            fechaMin.setDia(1);
            fechaMin.setMes(1);
            fechaMin.setAnio(2024);
            fechaMax.setDia(1);
            fechaMax.setMes(1);
            fechaMax.setAnio(2025);
            break;
        case 0:
            return;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA" << endl;
            system("pause");
            continue;
        }
        break;
    }

    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << "RECAUDACIÓN POR TIPO DE SALA " << endl;
    cout << "DESDE " << fechaMin.toStringFecha() << endl;
    cout << "HASTA " << fechaMax.toStringFecha() << endl;
    cout << "-----------------------------------------" << endl;

    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getFecha() >= fechaMin && venta.getFecha() <= fechaMax && venta.getActivo()){
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);

            idSala = funcion.getIdSala();
            posSala = archivoSalas.BuscarID(idSala);
            sala = archivoSalas.LeerRegistro(posSala);

            valorEntrada = gestor.CalcularPrecioEntrada(funcion);
            totalVenta = valorEntrada * venta.getCantidadEntradas();

            int indice = 0;
            while(strcmp(sala.getTipo(), tipos[indice]) != 0){
                indice++;
            }

            recaudacionTipos[indice] += totalVenta;
        }
    }

    // ENCABEZADO
    cout << left
         << setw(30) << "TIPO"
         << setw(30) << "RECAUDACIÓN" << endl;

    for (int i = 0; i < 3; i++) {
        cout << left
             << setw(30) << tipos[i]
             << setw(1) << "$" << fixed << setprecision(2) << setw(29) << recaudacionTipos[i] << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::RecaudacionTitulo(Reporte& reporte){
    int opcion, idPelicula, posPelicula, idFuncion, posFuncion;
    float precioEntrada;

    GestorCine gestor;
    Pelicula pelicula;
    Venta venta;
    Funcion funcion;
    ArchivoPeliculas archivoPeliculas;
    ArchivoVentas archivoVentas;
    ArchivoFunciones archivoFunciones;

    int cantidadPeliculas = archivoPeliculas.ContarRegistros();
    if(cantidadPeliculas < 1){
        cout << "ERROR: NO SE ENCONTRARON PELÍCULAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }
    float* recaudacionPeliculas= new float[cantidadPeliculas]();

    int cantidadVentas = archivoVentas.ContarRegistros();
    if(cantidadVentas < 1){
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    Fecha fechaMin;
    Fecha fechaMax;

    while(true){
        system("cls");
        cout << "RECAUDACIÓN POR PELÍCULA\n1. Ingresar rango de fechas\n2. Año actual\n\n0. Cancelar\n\nOPCIÓN: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "RECAUDACIÓN DESDE" << endl;
            fechaMin.Cargar();
            cout << endl << "HASTA" << endl;
            fechaMax.Cargar();
            break;
        case 2:
            fechaMin.setDia(1);
            fechaMin.setMes(1);
            fechaMin.setAnio(2024);
            fechaMax.setDia(1);
            fechaMax.setMes(1);
            fechaMax.setAnio(2025);
            break;
        case 0:
            return;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA" << endl;
            system("pause");
            continue;
        }
        break;
    }

    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "RECAUDACIÓN POR PELÍCULA" << endl;
    cout << "DESDE " << fechaMin.toStringFecha() << endl;
    cout << "HASTA " << fechaMax.toStringFecha() << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getFecha() >= fechaMin && venta.getFecha() <= fechaMax && venta.getActivo()){
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);

            precioEntrada = gestor.CalcularPrecioEntrada(funcion);
            idPelicula = funcion.getIdPelicula();

            recaudacionPeliculas[idPelicula] += precioEntrada * venta.getCantidadEntradas();
        }
    }

    // ENCABEZADO
    cout << left
         << setw(50) << "PELÍCULA"
         << setw(30) << "RECAUDACIÓN" << endl;

    for (int i = 0; i < cantidadPeliculas; i++) {
        posPelicula = archivoPeliculas.BuscarID(i);
        pelicula = archivoPeliculas.LeerRegistro(posPelicula);
        cout << left
             << setw(50) << pelicula.getTitulo()
             << setw(1) << "$" << fixed << setprecision(2) << setw(29) << recaudacionPeliculas[i] << endl;
    }


    delete[] recaudacionPeliculas;

    cout << endl;
    system("pause");
}

void Reporte::RecaudacionGenero(Reporte& reporte){
    char generos[9][20] = {"Accion", "Ciencia Ficcion", "Animacion", "Fantasia", "Drama", "Comedia", "Terror", "Aventura", "Sin Genero"};
    float recaudacionGeneros[9] = {0};
    int opcion, idPelicula, posPelicula, idFuncion, posFuncion;
    float precioEntrada;

    GestorCine gestor;
    Pelicula pelicula;
    Venta venta;
    Funcion funcion;
    ArchivoPeliculas archivoPeliculas;
    ArchivoVentas archivoVentas;
    ArchivoFunciones archivoFunciones;

    int cantidadVentas = archivoVentas.ContarRegistros();
    if(cantidadVentas < 1){
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    Fecha fechaMin;
    Fecha fechaMax;

    while(true){
        system("cls");
        cout << "RECAUDACIÓN POR GÉNERO\n1. Ingresar rango de fechas\n2. Año actual\n\n0. Cancelar\n\nOPCIÓN: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "RECAUDACIÓN DESDE" << endl;
            fechaMin.Cargar();
            cout << endl << "HASTA" << endl;
            fechaMax.Cargar();
            break;
        case 2:
            fechaMin.setDia(1);
            fechaMin.setMes(1);
            fechaMin.setAnio(2024);
            fechaMax.setDia(1);
            fechaMax.setMes(1);
            fechaMax.setAnio(2025);
            break;
        case 0:
            return;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA" << endl;
            system("pause");
            continue;
        }
        break;
    }

    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "RECAUDACIÓN POR GÉNERO" << endl;
    cout << "DESDE " << fechaMin.toStringFecha() << endl;
    cout << "HASTA " << fechaMax.toStringFecha() << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getFecha() >= fechaMin && venta.getFecha() <= fechaMax && venta.getActivo()){
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);

            idPelicula = funcion.getIdPelicula();
            posPelicula = archivoPeliculas.BuscarID(idPelicula);
            pelicula = archivoPeliculas.LeerRegistro(posPelicula);

            int indiceGenero = 0;
            while(indiceGenero < 8){
                if(strcmp(pelicula.getGenero(), generos[indiceGenero]) == 0)
                    break;
                indiceGenero++;
            }
            precioEntrada = gestor.CalcularPrecioEntrada(funcion);

            recaudacionGeneros[indiceGenero] += precioEntrada * venta.getCantidadEntradas();
        }
    }

    // ENCABEZADO
    cout << left
         << setw(30) << "GÉNERO"
         << setw(30) << "RECAUDACIÓN" << endl;

    for (int i = 0; i < 9; i++) {
        posPelicula = archivoPeliculas.BuscarID(i);
        pelicula = archivoPeliculas.LeerRegistro(posPelicula);
        cout << left
             << setw(30) << generos[i]
             << setw(1) << "$" << fixed << setprecision(2) << setw(29) << recaudacionGeneros[i] << endl;
    }

    cout << endl;
    system("pause");
}

void Reporte::EntradasVendidasPorPelicula(Reporte& reporte){
    int opcion, idPelicula, posPelicula, idFuncion, posFuncion;

    Pelicula pelicula;
    Venta venta;
    Funcion funcion;
    ArchivoPeliculas archivoPeliculas;
    ArchivoVentas archivoVentas;
    ArchivoFunciones archivoFunciones;

    int cantidadPeliculas = archivoPeliculas.ContarRegistros();
    if(cantidadPeliculas < 1){
        cout << "ERROR: NO SE ENCONTRARON PELÍCULAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }
    int* acuEntradasPelicula = new int[cantidadPeliculas]();

    int cantidadVentas = archivoVentas.ContarRegistros();
    if(cantidadVentas < 1){
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    Fecha fechaMin;
    Fecha fechaMax;

    while(true){
        system("cls");
        cout << "CANTIDAD DE ENTRADAS VENDIDAS POR PELÍCULA\n1. Ingresar rango de fechas\n2. Año actual\n\n0. Cancelar\n\nOPCIÓN: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "VENTAS DESDE" << endl;
            fechaMin.Cargar();
            cout << endl << "HASTA" << endl;
            fechaMax.Cargar();
            break;
        case 2:
            fechaMin.setDia(1);
            fechaMin.setMes(1);
            fechaMin.setAnio(2024);
            fechaMax.setDia(1);
            fechaMax.setMes(1);
            fechaMax.setAnio(2025);
            break;
        case 0:
            return;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA" << endl;
            system("pause");
            continue;
        }
        break;
    }

    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "CANTIDAD DE ENTRADAS VENDIDAS POR PELÍCULA" << endl;
    cout << "DESDE " << fechaMin.toStringFecha() << endl;
    cout << "HASTA " << fechaMax.toStringFecha() << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getFecha() >= fechaMin && venta.getFecha() <= fechaMax && venta.getActivo()){
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);

            idPelicula = funcion.getIdPelicula();

            acuEntradasPelicula[idPelicula] += venta.getCantidadEntradas();
        }
    }

    // ENCABEZADO
    cout << left
         << setw(50) << "PELÍCULA"
         << setw(30) << "ENTRADAS VENDIDAS" << endl;

    for (int i = 0; i < cantidadPeliculas; i++) {
        posPelicula = archivoPeliculas.BuscarID(i);
        pelicula = archivoPeliculas.LeerRegistro(posPelicula);
        cout << left
             << setw(50) << pelicula.getTitulo()
             << setw(30) << acuEntradasPelicula[i] << endl;
    }


    delete[] acuEntradasPelicula;

    cout << endl;
    system("pause");
}

void Reporte::EntradasVendidasPorGenero(Reporte& reporte){
    char generos[9][20] = {"Accion", "Ciencia Ficcion", "Animacion", "Fantasia", "Drama", "Comedia", "Terror", "Aventura", "Sin Genero"};
    int ventasGeneros[9] = {0};
    int opcion, idPelicula, posPelicula, idFuncion, posFuncion, cantEntradasVendidas;

    GestorCine gestor;
    Pelicula pelicula;
    Venta venta;
    Funcion funcion;
    ArchivoPeliculas archivoPeliculas;
    ArchivoVentas archivoVentas;
    ArchivoFunciones archivoFunciones;

    /// CONTAMOS LAS VENTAS
    int cantidadVentas = archivoVentas.ContarRegistros();
    if (cantidadVentas < 1) {
        cout << "ERROR: NO SE ENCONTRARON VENTAS EN EL ARCHIVO." << endl;
        system("pause");
        return;
    }

    Fecha fechaMin;
    Fecha fechaMax;

    /// SELECCIONAMOS EL RANGO DE LAS FECHAS
    while (true) {
        system("cls");
        cout << "CANTIDAD DE ENTRADAS VENDIDAS POR GÉNERO\n1. Ingresar rango de fechas\n2. Año actual\n\n0. Cancelar\n\nOPCIÓN: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "ENTRADAS VENDIDAS DESDE" << endl;
            fechaMin.Cargar();
            cout << endl << "HASTA" << endl;
            fechaMax.Cargar();
            break;
        case 2:
            fechaMin.setDia(1);
            fechaMin.setMes(1);
            fechaMin.setAnio(2024);
            fechaMax.setDia(1);
            fechaMax.setMes(1);
            fechaMax.setAnio(2025);
            break;
        case 0:
            return;
        default:
            cout << "ERROR: INGRESE UNA OPCIÓN VÁLIDA" << endl;
            system("pause");
            continue;
        }
        break;
    }

    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "CANTIDAD DE ENTRADAS VENDIDA POR GÉNERO" << endl;
    cout << "DESDE " << fechaMin.toStringFecha() << endl;
    cout << "HASTA " << fechaMax.toStringFecha() << endl;
    cout << "-------------------------------------------------------------------" << endl;

    /// PROCESAMOS LAS VENTAS
    for (int i = 0; i < cantidadVentas; i++) {
        venta = archivoVentas.LeerRegistro(i);
        if (venta.getFecha() >= fechaMin && venta.getFecha() <= fechaMax && venta.getActivo()) {
            idFuncion = venta.getIdFuncion();
            posFuncion = archivoFunciones.BuscarID(idFuncion);
            funcion = archivoFunciones.LeerRegistro(posFuncion);

            idPelicula = funcion.getIdPelicula();
            posPelicula = archivoPeliculas.BuscarID(idPelicula);
            pelicula = archivoPeliculas.LeerRegistro(posPelicula);

            /// BUSCAMOS EL GENERO DE LA PELICULA
            int indiceGenero = 0;
            while (indiceGenero < 8) {
                if (strcmp(pelicula.getGenero(), generos[indiceGenero]) == 0) {
                    break;
                }
                indiceGenero++;
            }
            ventasGeneros[indiceGenero] += venta.getCantidadEntradas();
        }
    }

    cout << left
         << setw(30) << "GÉNERO"
         << setw(20) << "ENTRADAS VENDIDAS" << endl;
    for (int i = 0; i < 9; i++) {
        cout << left
             << setw(30) << generos[i]
             << setw(20) << ventasGeneros[i] << endl;
    }

    cout << endl;
    system("pause");
}
