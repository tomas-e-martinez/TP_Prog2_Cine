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
                cout << "NUEVA FECHA DE NACIMIENTO \n";
                cliente.getFechaNacimiento().Cargar();
                break;
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

void GestorCine::ModificarFuncion(){
    ArchivoFunciones archivo;
    Funcion funcion;
    int posicion;
    while(true){
        system("cls");
        int opcionModificar;
        int id;
        cout << "MODIFICAR FUNCI�N" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTR� UNA FUNCI�N CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }
        while(true){
            system("cls");
            funcion = archivo.LeerRegistro(posicion);
            funcion.Mostrar();
            cout << endl << "1. ID Pel�cula\n2. ID Sala\n3. Fecha\n\n0. Cancelar" << endl << endl;
            cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCI�N A MODIFICAR: ";
            cin >> opcionModificar;
            cin.ignore();
            switch(opcionModificar){
            case 1:
                int idPelicula;
                cout << endl << "NUEVO ID PEL�CULA: ";
                cin >> idPelicula;
                funcion.setIdPelicula(idPelicula);
                break;
            case 2:
                int idSala;
                cout << endl << "NUEVO ID SALA: ";
                cin >> idSala;
                funcion.setIdSala(idSala);
                break;
            case 3:
                cout << endl << "NUEVA FECHA \n";
                funcion.getFecha().CargarHora();
                break;
            case 0:
                return;
            default:
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                system("pause");
                continue;
            }

            if(archivo.Guardar(funcion, posicion))
                cout << endl << "FUNCI�N MODIFICADA CON �XITO." << endl;
            else
                cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA FUNCI�N." << endl;

            system("pause");
            break;
        }
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
        cout << "MODIFICAR PEL�CULA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id);
        if(posicion == -1){
            cout << "ERROR: NO SE ENCONTR� UNA PEL�CULA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }
        while(true){
            system("cls");
            pelicula = archivo.LeerRegistro(posicion);
            pelicula.Mostrar();
            cout << endl << "1. T�tulo\n2. Sinopsis\n3. G�nero\n4. Clasificaci�n de edad\n5. Calificaci�n\n6. Fecha de estreno\n7. Duraci�n\n\n0. Cancelar" << endl << endl;
            cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCI�N A MODIFICAR: ";
            cin >> opcionModificar;
            cin.ignore();
            switch(opcionModificar){
            case 1:
                char titulo[100];
                cout << endl << "NUEVO T�TULO: ";
                cin.getline(titulo, sizeof(titulo));
                pelicula.setTitulo(titulo);
                break;
            case 2:
                char sinopsis[500];
                cout << endl << "NUEVA SINOPSIS: ";
                cin.getline(sinopsis, sizeof(sinopsis));
                pelicula.setSinopsis(sinopsis);
                break;
            case 3:
                char genero[20];
                cout << endl << "NUEVO G�NERO: ";
                cin.getline(genero, sizeof(genero));
                pelicula.setGenero(genero);
                break;
            case 4:
                int clasificacionEdad;
                cout << endl << "NUEVA CLASIFICACI�N DE EDAD: ";
                cin >> clasificacionEdad;
                pelicula.setClasificacionEdad(clasificacionEdad);
                break;
            case 5:
                float calificacion;
                cout << endl << "NUEVA CALIFICACI�N (1-10): ";
                cin >> calificacion;
                pelicula.setCalificacion(calificacion);
                break;
            case 6:
                cout << "NUEVA FECHA DE ESTRENO \n";
                pelicula.getFechaEstreno().Cargar();
                break;
            case 7:
                cout << "NUEVA DURACI�N \n";
                pelicula.getDuracion().Cargar();
                break;
            case 0:
                return;
            default:
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                system("pause");
                continue;
            }

            if(archivo.Guardar(pelicula, posicion))
                cout << endl << "PEL�CULA MODIFICADA CON �XITO." << endl;
            else
                cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA PEL�CULA." << endl;

            system("pause");
            break;
        }
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
            cout << "ERROR: NO SE ENCONTR� UNA SALA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }
        while(true){
            system("cls");
            sala = archivo.LeerRegistro(posicion);
            sala.Mostrar();
            cout << endl << "1. Capacidad\n2. Tipo\n\n0. Cancelar" << endl << endl;
            cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCI�N A MODIFICAR: ";
            cin >> opcionModificar;
            cin.ignore();
            switch(opcionModificar){
            case 1:
                int capacidad;
                cout << endl << "NUEVA CAPACIDAD: ";
                cin >> capacidad;
                sala.setCapacidad(capacidad);
                break;
            case 2:
                char tipo[5];
                cout << endl << "NUEVO TIPO: ";
                cin.getline(tipo, sizeof(tipo));
                sala.setTipo(tipo);
                break;
            case 0:
                return;
            default:
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                system("pause");
                continue;
            }

            if(archivo.Guardar(sala, posicion))
                cout << endl << "SALA MODIFICADA CON �XITO." << endl;
            else
                cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA SALA." << endl;

            system("pause");
            break;
        }
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
            cout << "ERROR: NO SE ENCONTR� UNA VENTA CON EL ID INGRESADO." << endl;
            system("pause");
            continue;
        }
        while(true){
            system("cls");
            venta = archivo.LeerRegistro(posicion);
            venta.Mostrar();
            cout << endl << "1. ID Cliente\n2. ID Funci�n\n3. Cantidad de entradas\n4. Fecha\n\n0. Cancelar" << endl << endl;
            cout << "ADVERTENCIA: INGRESAR UN VALOR DEL MISMO TIPO\nINGRESAR OPCI�N A MODIFICAR: ";
            cin >> opcionModificar;
            cin.ignore();
            switch(opcionModificar){
            case 1:
                int idCliente;
                cout << endl << "NUEVO ID CLIENTE: ";
                cin >> idCliente;
                venta.setIdCliente(idCliente);
                break;
            case 2:
                int idFuncion;
                cout << endl << "NUEVO ID FUNCI�N: ";
                cin >> idFuncion;
                venta.setIdFuncion(idFuncion);
                break;
            case 3:
                int cantidadEntradas;
                cout << endl << "NUEVA CANTIDAD DE ENTRADAS:";
                cin >> cantidadEntradas;
                venta.setCantidadEntradas(cantidadEntradas);
                break;
            case 4:
                cout << endl << "NUEVA FECHA \n";
                venta.getFecha().CargarHora();
                break;
            case 0:
                return;
            default:
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                system("pause");
                continue;
            }

            if(archivo.Guardar(venta, posicion))
                cout << endl << "VENTA MODIFICADA CON �XITO." << endl;
            else
                cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA VENTA." << endl;

            system("pause");
            break;
        }
        return;
    }
}
