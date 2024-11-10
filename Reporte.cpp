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
    system("cls");
    cout << "Cantidad de clientes: " << cantidadRegistros << endl;
    system("pause");
    system("cls");

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

    // ENCABEZADO
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
        if(edad >= minimo && edad <= maximo){
        cout << left
             << setw(5)  << clientes[i].getId()
             << setw(10) << clientes[i].getDni()
             << setw(30) << clientes[i].getNombre()
             << setw(30) << clientes[i].getApellido()
             << setw(20) << clientes[i].getTelefono()
             << setw(15) << clientes[i].getFechaNacimiento().toStringFecha()
             << setw(10) << edad << endl;
        }
    }

    delete[] clientes;

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
         << setw(40) << "PELÍCULA"
         << setw(15) << "DURACIÓN"
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
