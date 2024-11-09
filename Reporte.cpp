#include "Reporte.h"

void Reporte::ListarPeliculas(const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "Cantidad de pel�culas: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "T�TULO"
         << setw(20) << "G�NERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACI�N"
         << setw(15) << "CALIFICACI�N"
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

void Reporte::ListarClientes(const char* nombreArchivo){
    ArchivoClientes archivo(nombreArchivo);
    Cliente registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "Cantidad de clientes: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "DNI"
         << setw(30) << "NOMBRE"
         << setw(30) << "APELLIDO"
         << setw(20) << "TEL�FONO"
         << setw(20) << "FECHA DE NACIMIENTO" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        cout << left
             << setw(5)  << registro.getId()
             << setw(10) << registro.getDni()
             << setw(30) << registro.getNombre()
             << setw(30) << registro.getApellido()
             << setw(20) << registro.getTelefono()
             << setw(20) << registro.getFechaNacimiento().toStringFecha() << endl;
    }

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
    cout << "Cantidad de funciones: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    // ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(40) << "PEL�CULA"
         << setw(15) << "DURACI�N"
         << setw(10)  << "EDAD"
         << setw(10) << "SALA"
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
             << setw(10)  << (to_string(pelicula.getClasificacionedad()) + "+")
             << setw(10) << sala.getTipo()
             << setw(20) << registro.getFecha().toStringFecha()
             << setw(10) << registro.getFecha().toStringHora() << endl;
    }

    cout << endl;
    system("pause");
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
         << setw(15) << "ID FUNCI�N"
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
    cout << "Cantidad de salas: " << cantidadRegistros << endl;
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
