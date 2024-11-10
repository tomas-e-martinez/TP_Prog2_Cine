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

void GestorCine::AgregarVenta(){
    Venta venta;
    ArchivoVentas archivo;
    venta.Cargar();
    if(archivo.Guardar(venta))
        cout << "VENTA AGREGADA CON ÉXITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA VENTA." << endl;
    system("pause");
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
        int opcionModificar;
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
