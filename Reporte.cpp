#include "Reporte.h"

void Reporte::ListarPeliculas(const char* nombreArchivo){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    system("cls");
    cout << "Cantidad de películas: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(30) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        cout << left
             << setw(5)  << registro.getId()
             << setw(30) << registro.getTitulo()
             << setw(20) << registro.getGenero()
             << setw(20) << registro.getFechaEstreno().toStringFecha()
             << setw(10) << registro.getDuracion().toString()
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
         << setw(20) << "TELEFONO"
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
         << setw(15) << "ID PELÍCULA"
         << setw(10) << "ID SALA"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        cout << left
             << setw(5)  << registro.getIdFuncion()
             << setw(15) << registro.getIdPelicula()
             << setw(10) << registro.getIdSala()
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
         << setw(15) << "ID FUNCIÓN"
         << setw(15) << "DNI CLIENTE"
         << setw(20) << "CANT. ENTRADAS"
         << setw(20) << "FECHA"
         << setw(10) << "HORA" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = archivo.LeerRegistro(i);
        cout << left
             << setw(5)  << registro.getIdVenta()
             << setw(15) << registro.getIdFuncion()
             << setw(15) << registro.getDniCliente()
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
