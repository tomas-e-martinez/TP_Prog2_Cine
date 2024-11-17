#include "CargarAleatorio.h"

int CargarAleatorio::DNI(){
    int dni = 0;
    int digitosDNI[8];
    for(int i = 0; i < 8; i++){ ///GENERAR DNI
            if(i == 0)
                digitosDNI[i] = rand() % 7 + 1;
            else
                digitosDNI[i] = rand() % 10;
            dni = dni * 10 + digitosDNI[i];
        }
    return dni;
}

void CargarAleatorio::CargarClientes(int cantidad){
    Cliente registro;
    ArchivoClientes archivo;
    for(int i = 0; i < cantidad; i++){
        registro = GenerarCliente();
        if(!archivo.Guardar(registro)){
            cout << "ERROR AL AGREGAR REGISTRO." << endl;
            break;
        }
    }
        cout << "CLIENTES AGREGADOS: " << cantidad << endl;
        system("pause");
}

Cliente CargarAleatorio::GenerarCliente(){
    int dni = DNI(); ///GENERAR DNI
    char nombre[30], apellido[30], telefono[20];

    ///GENERAR FECHA DE NACIMIENTO
    int mesNac = rand() % 12 + 1;
    int anioNac = 2024 - 12 - rand() % 87;
    int diaNac;
    if(mesNac == 1 || mesNac == 3 || mesNac == 5 || mesNac == 7 || mesNac == 8 || mesNac == 10 || mesNac == 12)
        diaNac = rand() % 31 + 1;
    else if (mesNac == 2)
        diaNac = rand() % 28 + 1;
    else
        diaNac = rand() % 30 + 1;
    Fecha fechaNac(diaNac, mesNac, anioNac);

    ///GENERAR TELEFONO
    for(int i = 0; i < 10; i++){
        telefono[i] = '0' + rand() % 10;
    }
    telefono[10] = '\0';

    char nombres[40][30] = {
        "Juan", "María", "Carlos", "Ana", "Luis",
        "Pedro", "Marta", "José", "Laura", "Ricardo",
        "Sandra", "David", "Carmen", "Felipe", "Elena",
        "Jorge", "Isabel", "Raúl", "Pablo", "Eva",
        "Fernando", "Antonio", "Rosa", "Beatriz", "Mónica",
        "Gabriel", "Raquel", "Esteban", "Alba", "Julián",
        "Verónica", "Victoria", "Sergio", "Paula", "Martín",
        "Estela", "Simón", "Adriana", "Natalia", "Daniel"
    };

    char apellidos[40][30] = {
        "Gómez", "Pérez", "Rodríguez", "López", "Martínez",
        "Sánchez", "Fernández", "García", "Hernández", "Lozano",
        "Vázquez", "Ramírez", "Álvarez", "Mendoza", "Romero",
        "Cruz", "Torres", "Jiménez", "Díaz", "Moreno",
        "Morales", "Ortiz", "González", "Ruiz", "Salazar",
        "Serrano", "Castro", "Ramos", "Pacheco", "Cardenas",
        "Valencia", "Ruiz", "Gutiérrez", "Carrillo", "Escobar",
        "Figueroa", "Serrano", "Chávez", "Reyes", "García"
    };


    strcpy(nombre, nombres[rand() % 40]);
    strcpy(apellido, apellidos[rand() % 40]);

    Cliente cliente(dni, nombre, apellido, telefono, fechaNac);
    return cliente;
}

Funcion CargarAleatorio::GenerarFuncion(){
    ArchivoPeliculas archivoPeliculas;
    int cantidadPeliculas = archivoPeliculas.ContarRegistros();
    int idPelicula;
    while(true){
        idPelicula = rand() % cantidadPeliculas;
        if(archivoPeliculas.BuscarID(idPelicula, false) != 1)
            break;
    }
    bool activo = true;

    ArchivoSalas archivoSalas;
    int cantidadSalas = archivoSalas.ContarRegistros();
    int idSala;
    while(true){
        idSala = rand() % cantidadSalas;
        if(archivoSalas.BuscarID(idSala, false) != 1)
            break;
    }

    int anio = 2024 - rand() % 4;
    int dia;
    int mes = rand() % 12 + 1;
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        dia = rand() % 31 + 1;
    else if (mes == 2)
        dia = rand() % 28 + 1;
    else
        dia = rand() % 30 + 1;

    int hora = 23 - rand() % 15;
    int minutos = (rand() % 12) * 5;
    Fecha fechaFuncion(dia, mes, anio, hora, minutos);




    Funcion funcion(idPelicula, idSala, fechaFuncion);
    funcion.setActivo(activo);
    return funcion;
}

void CargarAleatorio::CargarFunciones(int cantidad){
    Funcion registro;
    ArchivoFunciones archivo;
    int contadorTotal = 0;
    for(int i = 0; i < cantidad; i++){
        registro = GenerarFuncion();
        if(!archivo.Guardar(registro)){
            cout << "ERROR AL AGREGAR REGISTRO." << endl;
            break;
        }
        contadorTotal++;

        system("cls");
        cout << "GENERANDO " << cantidad << " FUNCIONES..." << endl;
        cout << contadorTotal << "/" << cantidad << endl;
    }
        cout << "FUNCIONES AGREGADAS: " << cantidad << endl;
        system("pause");
}

Sala CargarAleatorio::GenerarSala(){
    int capacidad = (rand() % 150 + 51) * 5;
    int opcionTipo = rand() % 100 + 1;
    if(opcionTipo <= 75)
        opcionTipo = 1;
    else if(opcionTipo <= 95)
        opcionTipo = 2;
    else if(opcionTipo <= 100)
        opcionTipo = 3;
    bool activo = true;

    Sala sala(capacidad, opcionTipo);
    sala.setActivo(activo);
    return sala;
}

void CargarAleatorio::CargarSalas(int cantidad){
    Sala registro;
    ArchivoSalas archivo;
    for(int i = 0; i < cantidad; i++){
        registro = GenerarSala();
        if(!archivo.Guardar(registro)){
            cout << "ERROR AL AGREGAR REGISTRO." << endl;
            break;
        }
    }

    cout << "SALAS AGREGADAS: " << cantidad << endl;
    system("pause");
}

Venta CargarAleatorio::GenerarVenta(){
    ArchivoFunciones archivoFunciones;
    ArchivoClientes archivoClientes;

    int cantClientes = archivoClientes.ContarRegistros();
    if(cantClientes < 1){
        Venta venta;
        cout << "ERROR: No se encontraron clientes en el archivo." << endl;
        system("pause");
        return venta;
    }
    int idCliente;
    while(true){
        idCliente = rand() % cantClientes;
        if(archivoClientes.BuscarID(idCliente) != -1)
            break;
    }

    int cantFunciones = archivoFunciones.ContarRegistros();
    if(cantFunciones < 1){
        Venta venta;
        cout << "ERROR: No se encontraron funciones en el archivo." << endl;
        system("pause");
        return venta;
    }
    int idFuncion;
    while(true){
        idFuncion = rand() % cantFunciones;
        if(archivoFunciones.BuscarID(idFuncion, false) != -1)
            break;
    }

    int cantidadEntradas = rand() % 10 + 1;

    ///GENERAR FECHA Y HORA DE VENTA
    int mes = rand() % 12 + 1;
    int anio = 2024 - rand() % 4;
    int dia;
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        dia = rand() % 31 + 1;
    else if (mes == 2)
        dia = rand() % 28 + 1;
    else
        dia = rand() % 30 + 1;

    int hora = 23 - rand() % 15;
    int minutos = rand() % 60;

    Fecha fechaVenta(dia, mes, anio, hora, minutos);

    Venta venta(idCliente, idFuncion, cantidadEntradas, fechaVenta);
    return venta;
}

void CargarAleatorio::CargarVentas(int cantidad){
    ArchivoClientes archivoClientes;
    ArchivoVentas archivoVentas;
    Cliente cliente;
    Venta venta;
    int posCliente;

    int contadorVentasTotal = 0;
    int contadorVentasCliente = 0;



    while(contadorVentasTotal < cantidad){
        int cantidadVentasCliente = rand() % 5 + 1;
        cliente = GenerarCliente();
        if(!archivoClientes.Guardar(cliente)){
            cout << "ERROR AL AGREGAR CLIENTE." << endl;
            system("pause");
            return;
        }

        posCliente = archivoClientes.BuscarDni(cliente.getDni());
        cliente = archivoClientes.LeerRegistro(posCliente);

        contadorVentasCliente = 0;
        while(contadorVentasCliente < cantidadVentasCliente && contadorVentasTotal < cantidad){
            venta = GenerarVenta();
            venta.setIdCliente(cliente.getId());
            if(!archivoVentas.Guardar(venta)){
                cout << "ERROR AL AGREGAR LA VENTA." << endl;
                system("pause");
                return;
            }
            contadorVentasCliente++;
            contadorVentasTotal++;

            system("cls");
            cout << "GENERANDO " << cantidad << " VENTAS..." << endl;
            cout << contadorVentasTotal << "/" << cantidad << endl;
        }
    }

    cout << "SE AGREGARON " << contadorVentasTotal << " VENTAS." << endl;
    system("pause");
}
