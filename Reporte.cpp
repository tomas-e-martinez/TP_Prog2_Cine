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
        cout << left
             << setw(5)  << registro.getId()
             << setw(40) << registro.getTitulo()
             << setw(20) << registro.getGenero()
             << setw(20) << registro.getFechaEstreno().toStringFecha()
             << setw(10) << registro.getDuracion().toString()
             << setw(15) << registro.getCalificacion()
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
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << peliculas[i].getCalificacion()
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
        cout << left
             << setw(5)  << peliculas[i].getId()
             << setw(40) << peliculas[i].getTitulo()
             << setw(20) << peliculas[i].getGenero()
             << setw(20) << peliculas[i].getFechaEstreno().toStringFecha()
             << setw(10) << peliculas[i].getDuracion().toString()
             << setw(15) << peliculas[i].getCalificacion()
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

    //ALMACENAR REGISTROS QUE COINCIDAN CON EL GÉNERO
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(strcmp(registro.getGenero(), genero) == 0)
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
             << setw(15) << peliculas[i].getCalificacion()
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

    //ALMACENAR REGISTROS QUE ESTÉN EN EL RANGO DE CALIFICACIONES
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(registro.getCalificacion() >= minCalificacion && registro.getCalificacion() <= maxCalificacion)
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
             << setw(15) << peliculas[i].getCalificacion()
             << setw(5)  << (to_string(peliculas[i].getClasificacionedad()) + "+") << endl;
    }

    delete[] peliculas;

    cout << endl;
    system("pause");
}

void Reporte::ListarPeliculasTitulo(const char* titulo, const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    int posicion = archivo.BuscarTitulo(titulo);

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

    //ALMACENAR REGISTROS QUE ESTÉN DEBAJO DEL LÍMITE DE EDAD
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        if(registro.getClasificacionedad() <= edadMax)
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
             << setw(15) << peliculas[i].getCalificacion()
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

    //ALMACENAR REGISTROS EN RANGO DE EDAD
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        edad = 2024 - registro.getFechaNacimiento().getAnio();
        if(edad >= minimo && edad <= maximo)
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
    int posicion = archivo.BuscarDni(dni);

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

void Reporte::ListarFuncionesFecha(Fecha& minimo, Fecha& maximo, const char* nombreArchivo){
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
        if(registro.getFecha() >= minimo && registro.getFecha() <= maximo)
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
        if(strcmp(sala.getTipo(), tipoSala) == 0)
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
        cout << left
             << setw(5)  << salas[i].getIdSala()
             << setw(15) << salas[i].getCapacidad()
             << setw(10) << salas[i].getTipo() << endl;
    }

    cout << endl;
    system("pause");
}
