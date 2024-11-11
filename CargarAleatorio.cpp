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
    char digitosTel[10];
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
    int idPelicula = rand() % cantidadPeliculas;

    ArchivoSalas archivoSalas;
    int cantidadSalas = archivoSalas.ContarRegistros();
    int idSala = rand() % cantidadSalas;

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
    return funcion;
}

void CargarAleatorio::CargarFunciones(int cantidad){
    Funcion registro;
    ArchivoFunciones archivo;
    for(int i = 0; i < cantidad; i++){
        registro = GenerarFuncion();
        if(!archivo.Guardar(registro)){
            cout << "ERROR AL AGREGAR REGISTRO." << endl;
            break;
        }
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

    Sala sala(capacidad, opcionTipo);
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
