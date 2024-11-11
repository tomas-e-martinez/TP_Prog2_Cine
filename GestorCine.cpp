#include "GestorCine.h"

void GestorCine::AgregarCliente(){
    Cliente cliente;
    ArchivoClientes archivo;
    cliente.Cargar();
    if(archivo.Guardar(cliente))
        cout << "CLIENTE AGREGADO CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR CLIENTE." << endl;
    system("pause");
}

void GestorCine::AgregarFuncion(){
    Funcion funcion;
    ArchivoFunciones archivo;
    funcion.Cargar();
    if(archivo.Guardar(funcion))
        cout << "FUNCIÓN AGREGADA CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA FUNCIÓN." << endl;
    system("pause");
}

void GestorCine::AgregarPelicula(){
    Pelicula pelicula;
    ArchivoPeliculas archivo;
    pelicula.Cargar();
    if(archivo.Guardar(pelicula))
        cout << "PELÍCULA AGREGADA CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA PELÍCULA." << endl;
    system("pause");
}

void GestorCine::AgregarSala(){
    Sala sala;
    ArchivoSalas archivo;
    sala.Cargar();
    if(archivo.Guardar(sala))
        cout << "SALA AGREGADA CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA SALA." << endl;
    system("pause");
}

void GestorCine::AgregarVenta(){ ///PRUEBA
    Venta venta;
    ArchivoVentas archivo;
    venta.Cargar();
    if(archivo.Guardar(venta))
        cout << "VENTA AGREGADA CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA VENTA." << endl;
    system("pause");
}

void GestorCine::ProcesarVenta(){
    int idSelec, opcionSelec, posicion, cantidadEntradas, entradasDisponibles, dni, posicionCliente;
    float valorEntrada;
    ArchivoFunciones archivoFunciones;
    system("cls");
    cout << "PROCESAR VENTA\nSELECCIONAR FECHA APROXIMADA DE LA FUNCIÓN" << endl;
    Fecha fechaFuncion;
    fechaFuncion.Cargar();
    Reporte reporte;
    while(true){
        reporte.ListarFuncionesFecha(fechaFuncion-10, fechaFuncion+10);
        cout << endl << "1. Seleccionar función\n0. Volver" << endl << endl;
        cout << "OPCIÓN: ";
        cin >> opcionSelec;
        if(opcionSelec != 1)
            return;
        cout << "ID: ";
        cin >> idSelec;
        posicion = archivoFunciones.BuscarID(idSelec);
        if(posicion == -1){
            cout << "No se encontró una función con el ID ingresado." << endl;
            system("pause");
            continue;
        }
        break;
    }
    Funcion funcion = archivoFunciones.LeerRegistro(posicion);
    valorEntrada = CalcularPrecioEntrada(funcion);
    entradasDisponibles = AsientosLibres(funcion);
    if(entradasDisponibles == 0){
        cout << "No hay entradas disponibles para la función seleccionada." << endl;
        system("pause");
        return;
    }
    while(true){
        cout << "HAY " << entradasDisponibles << " ENTRADAS DISPONIBLES PARA LA FUNCIÓN SELECCIONADA" << endl;
        cout << "CANTIDAD DE ENTRADAS: ";
        cin >> cantidadEntradas;
        if(cantidadEntradas > AsientosLibres(funcion)){
            cout << "ERROR: La cantidad de entradas solicitadas supera la capacidad disponible." << endl;
            system("pause");
            system("cls");
        }
        break;
    }
    ArchivoClientes archivoClientes;
    cout << "DNI DEL CLIENTE: ";
    cin >> dni;
    posicionCliente = archivoClientes.BuscarDni(dni);
    Cliente cliente = archivoClientes.LeerRegistro(posicionCliente);
    if(posicionCliente != -1){
        cout << "CLIENTE ENCONTRADO: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
        cout << "¿DESEA CONTINUAR? 1.SÍ 2.NO\n";
        cin >> opcionSelec;
        if(opcionSelec != 1)
            return;
    }
    else{
        cout << "NO SE ENCONTRÓ UN CLIENTE CON ESE DNI, POR FAVOR CARGAR NUEVO CLIENTE" << endl;
        system("pause");
        system("cls");
        cliente.Cargar();
        if(archivoClientes.Guardar(cliente)){
            cout << "NUEVO CLIENTE CARGADO CORRECTAMENTE." << endl;
            posicionCliente = archivoClientes.BuscarDni(dni);
            int idCliente = archivoClientes.LeerRegistro(posicionCliente).getId();
            cliente.setId(idCliente);
        }
        else{
            cout << "VENTA CANCELADA." << endl;
            system("pause");
            return;
        }
    }

    cout << "FECHA Y HORA DE LA VENTA\n";
    Fecha fechaVenta;
    fechaVenta.CargarHora();

    //VER Y CONFIRMAR COMPRA
    reporte.VentaDetalle(funcion, cantidadEntradas, fechaVenta, cliente, valorEntrada);
    cout << endl << "¿CONFIRMAR VENTA? 1.SÍ 2.NO\n";
    cin >> opcionSelec;
    if(opcionSelec != 1)
        return;


    //EJECUTAR
    Venta venta(cliente.getId(), funcion.getIdFuncion(), cantidadEntradas, fechaVenta);
    ArchivoVentas archivoVentas;
    if(archivoVentas.Guardar(venta)){
        cout << "VENTA REALIZADA CON ÉXITO." << endl;
        system("pause");
    }
    else{
        cout << "ERROR: NO SE PUDO REALIZAR LA VENTA." << endl;
        system("pause");
    }


    ///EN DESARROLLO
}

void GestorCine::ModificarCliente(){
    ArchivoClientes archivo;
    Cliente cliente;
    int posicion;
    while(true){
        system("cls");
        int opcionModificar;
        cout << "MODIFICAR CLIENTE - MÉTODO DE BÚSQUEDA\n1. ID\n2. DNI\n\n0. Cancelar" << endl << endl;
        cout << "INGRESAR OPCIÓN: ";
        cin >> opcionModificar;
        switch(opcionModificar){
        case 1:
            int id;
            cout << "ID: ";
            cin >> id;
            posicion = archivo.BuscarID(id);
            if(posicion == -1){
                cout << "ERROR: NO SE ENCONTRÓ UN CLIENTE CON EL ID INGRESADO." << endl;
                system("pause");
                continue;
            }
            break;
        case 2:
            int dni;
            cout << "DNI: ";
            cin >> dni;
            posicion = archivo.BuscarDni(dni);
            if(posicion == -1){
                cout << "ERROR: NO SE ENCONTRÓ UN CLIENTE CON EL DNI INGRESADO." << endl;
                system("pause");
                continue;
            }
            break;
        case 0:
            return;
        default:
            cout << endl << "ERROR: INGRESE UNA OPCIÓN VÁLIDA." << endl;
            system("pause");
            break;
        }

        cliente = archivo.LeerRegistro(posicion);
        if(!cliente.Modificar()){
            cout << endl << "MODIFICACIÓN CANCELADA." << endl;
            system("pause");
            return;
        }

        if(archivo.Guardar(cliente, posicion))
            cout << endl << "CLIENTE MODIFICADO CON ÉXITO." << endl;
        else
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR EL CLIENTE." << endl;

        system("pause");
        return;
    }
}

void GestorCine::ModificarFuncion(){
    ArchivoFunciones archivo;
    Funcion funcion;
    int posicion;
    while(true){
        system("cls");
        int id;
        cout << "MODIFICAR FUNCIÓN" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTRÓ UNA FUNCIÓN CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }

        funcion = archivo.LeerRegistro(posicion);
        if(!funcion.Modificar()){
            cout << endl << "MODIFICACIÓN CANCELADA." << endl;
            system("pause");
            return;
        }

        if(archivo.Guardar(funcion, posicion))
            cout << endl << "FUNCIÓN MODIFICADA CON ÉXITO." << endl;
        else
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA FUNCIÓN." << endl;

        system("pause");
        return;
    }
}

void GestorCine::ModificarPelicula(){
    ArchivoPeliculas archivo;
    Pelicula pelicula;
    int posicion;
    while(true){
        system("cls");
        int opcionModificar;
        int id;
        cout << "MODIFICAR PELÍCULA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTRÓ UNA PELÍCULA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }

        pelicula = archivo.LeerRegistro(posicion);
        if(!pelicula.Modificar()){
            cout << endl << "MODIFICACIÓN CANCELADA." << endl;
            system("pause");
            return;
        }

        if(archivo.Guardar(pelicula, posicion))
            cout << endl << "PELÍCULA MODIFICADA CON ÉXITO." << endl;
        else
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA PELÍCULA." << endl;

        system("pause");
        return;
    }
}

void GestorCine::ModificarSala(){
    ArchivoSalas archivo;
    Sala sala;
    int posicion;
    while(true){
        system("cls");
        int opcionModificar;
        int id;
        cout << "MODIFICAR SALA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTRÓ UNA SALA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }
        sala = archivo.LeerRegistro(posicion);
        if(!sala.Modificar()){
            cout << endl << "MODIFICACIÓN CANCELADA." << endl;
            system("pause");
            return;
        }

        if(archivo.Guardar(sala, posicion))
            cout << endl << "SALA MODIFICADA CON ÉXITO." << endl;
        else
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA SALA." << endl;

        system("pause");
        return;
    }
}

void GestorCine::ModificarVenta(){
    ArchivoVentas archivo;
    Venta venta;
    int posicion;
    while(true){
        system("cls");
        int opcionModificar;
        int id;
        cout << "MODIFICAR VENTA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTRÓ UNA VENTA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }

        venta = archivo.LeerRegistro(posicion);
        if(!venta.Modificar()){
            cout << endl << "MODIFICACIÓN CANCELADA." << endl;
            system("pause");
            return;
        }

        if(archivo.Guardar(venta, posicion))
            cout << endl << "VENTA MODIFICADA CON ÉXITO." << endl;
        else
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA VENTA." << endl;

        system("pause");
        return;
    }
}

float GestorCine::CalcularPrecioEntrada(Funcion funcion){
    ArchivoSalas archivoSalas;
    int posSala = archivoSalas.BuscarID(funcion.getIdSala());
    Sala sala = archivoSalas.LeerRegistro(posSala);
    float precioBase = 6000;

    float multiplicadorTipo = 1;
    if(strcmp(sala.getTipo(), "3D") == 0)
        multiplicadorTipo = 1.5;
    if(strcmp(sala.getTipo(), "IMAX") == 0)
        multiplicadorTipo = 2;

    float multiplicadorCapacidad = 1;
    if(sala.getCapacidad() > 500)
        multiplicadorCapacidad = 1.2;
    if(sala.getCapacidad() < 250)
        multiplicadorCapacidad = 0.8;

    return precioBase * multiplicadorTipo * multiplicadorCapacidad;
}

int GestorCine::AsientosLibres(Funcion funcion){
    ArchivoVentas archivoVentas;
    ArchivoSalas archivoSalas;

    int idSala, posSala, idFuncion, capacidad, ocupados = 0;
    idSala = funcion.getIdSala();
    idFuncion = funcion.getIdFuncion();

    posSala = archivoSalas.BuscarID(idSala);
    Sala sala = archivoSalas.LeerRegistro(posSala);
    capacidad = sala.getCapacidad();

    int cantidadVentas = archivoVentas.ContarRegistros();
    Venta venta;
    for(int i = 0; i < cantidadVentas; i++){
        venta = archivoVentas.LeerRegistro(i);
        if(venta.getIdFuncion() == idFuncion){
            ocupados += venta.getCantidadEntradas();
        }
    }

    return capacidad - ocupados;
}
