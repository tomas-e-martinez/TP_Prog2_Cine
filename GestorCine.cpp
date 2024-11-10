#include "GestorCine.h"

void GestorCine::AgregarCliente(){
    Cliente cliente;
    ArchivoClientes archivo;
    cliente.Cargar();
    if(archivo.Guardar(cliente))
        cout << "CLIENTE AGREGADO CON �XITO." << endl;
    else
        cout << "ERROR AL AGREGAR CLIENTE." << endl;
    system("pause");
}

void GestorCine::AgregarFuncion(){
    Funcion funcion;
    ArchivoFunciones archivo;
    funcion.Cargar();
    if(archivo.Guardar(funcion))
        cout << "FUNCI�N AGREGADA CON �XITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA FUNCI�N." << endl;
    system("pause");
}

void GestorCine::AgregarPelicula(){
    Pelicula pelicula;
    ArchivoPeliculas archivo;
    pelicula.Cargar();
    if(archivo.Guardar(pelicula))
        cout << "PEL�CULA AGREGADA CON �XITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA PEL�CULA." << endl;
    system("pause");
}

void GestorCine::AgregarSala(){
    Sala sala;
    ArchivoSalas archivo;
    sala.Cargar();
    if(archivo.Guardar(sala))
        cout << "SALA AGREGADA CON �XITO." << endl;
    else
        cout << "ERROR AL AGREGAR LA SALA." << endl;
    system("pause");
}

void GestorCine::AgregarVenta(){
    Venta venta;
    ArchivoVentas archivo;
    venta.Cargar();
    if(archivo.Guardar(venta))
        cout << "VENTA AGREGADA CON �XITO." << endl;
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
        cout << "MODIFICAR CLIENTE - M�TODO DE B�SQUEDA\n1. ID\n2. DNI\n\n0. Cancelar" << endl << endl;
        cout << "INGRESAR OPCI�N: ";
        cin >> opcionModificar;
        switch(opcionModificar){
        case 1:
            int id;
            cout << "ID: ";
            cin >> id;
            posicion = archivo.BuscarID(id);
            if(posicion == -1){
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL ID INGRESADO." << endl;
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
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL DNI INGRESADO." << endl;
                system("pause");
                continue;
            }
            break;
        case 0:
            return;
        default:
            cout << endl << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
            system("pause");
            break;
        }
        while(true){
            system("cls");
            cliente = archivo.LeerRegistro(posicion);
            cliente.Mostrar();
            cout << endl << "1. DNI\n2. Nombre\n3. Apellido\n4. Tel�fono\n5. Fecha de nacimiento\n\n0. Cancelar" << endl << endl;
            cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCI�N A MODIFICAR: ";
            cin >> opcionModificar;
            cin.ignore();
            switch(opcionModificar){
            case 1:
                int dni;
                cout << endl << "NUEVO DNI: ";
                cin >> dni;
                cliente.setDni(dni);
                break;
            case 2:
                char nombre[30];
                cout << endl << "NUEVO NOMBRE: ";
                cin.getline(nombre, sizeof(nombre));
                cliente.setNombre(nombre);
                break;
            case 3:
                char apellido[30];
                cout << endl << "NUEVO APELLIDO: ";
                cin.getline(apellido, sizeof(apellido));
                cliente.setApellido(apellido);
                break;
            case 4:
                char telefono[20];
                cout << endl << "NUEVO TEL�FONO: ";
                cin.getline(telefono, sizeof(telefono));
                cliente.setTelefono(telefono);
                break;
            case 5:
            {
                Fecha fechaNacimiento;
                cout << "NUEVA FECHA DE NACIMIENTO \n";
                fechaNacimiento.Cargar();
                cliente.setFechaNacimiento(fechaNacimiento);
                break;
            }
            case 0:
                return;
            default:
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                system("pause");
                continue;
            }

            if(archivo.Guardar(cliente, posicion))
                cout << endl << "CLIENTE MODIFICADO CON �XITO." << endl;
            else
                cout << endl << "ERROR: NO SE PUEDO MODIFICAR EL CLIENTE." << endl;

            system("pause");
            break;
        }
        return;
    }
}
