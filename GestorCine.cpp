#include "GestorCine.h"

void GestorCine::AgregarCliente(){
    Cliente cliente;
    ArchivoClientes archivo;
    int dni;
    system("cls");
    cout << "CARGAR NUEVO CLIENTE" << endl;
    cout << "DNI: ";
    cin >> dni;
    if(archivo.BuscarDni(dni) != -1){
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR: YA EXISTE UN CLIENTE CON EL DNI INGRESADO." << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
        return;
    }
    cliente.Cargar(dni);
    if(archivo.Guardar(cliente)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "CLIENTE AGREGADO CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR AL AGREGAR CLIENTE." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    system("pause");
}

void GestorCine::AgregarFuncion(){
    Funcion funcion;
    ArchivoFunciones archivo;
    funcion.Cargar();
    if(archivo.Guardar(funcion)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "FUNCI�N AGREGADA CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR AL AGREGAR LA FUNCI�N." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    system("pause");
}

void GestorCine::AgregarPelicula(){
    Pelicula pelicula;
    ArchivoPeliculas archivo;
    pelicula.Cargar();
    if(archivo.Guardar(pelicula)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "PEL�CULA AGREGADA CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR AL AGREGAR LA PEL�CULA." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    system("pause");
}

void GestorCine::AgregarSala(){
    Sala sala;
    ArchivoSalas archivo;
    sala.Cargar();
    if(archivo.Guardar(sala)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "SALA AGREGADA CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR AL AGREGAR LA SALA." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    system("pause");
}

void GestorCine::AgregarVenta(){ ///PRUEBA
    Venta venta;
    ArchivoVentas archivo;
    venta.Cargar();
    if(archivo.Guardar(venta)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "VENTA AGREGADA CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    else{
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "ERROR AL AGREGAR LA VENTA." << endl;
        rlutil::setColor(rlutil::GREY);
    }
    system("pause");
}

void GestorCine::ProcesarVenta(){
    int idSelec, opcionSelec, posicion, cantidadEntradas, entradasDisponibles, dni, posicionCliente;
    float valorEntrada;
    ArchivoFunciones archivoFunciones;
    system("cls");
    cout << "PROCESAR VENTA\nSELECCIONAR FECHA APROXIMADA DE LA FUNCI�N" << endl;
    Fecha fechaFuncion;
    fechaFuncion.Cargar();
    Reporte reporte;
    while(true){
        reporte.ListarFuncionesFecha(fechaFuncion-10, fechaFuncion+10);
        cout << endl << "1. Seleccionar funci�n\n0. Volver" << endl << endl;
        cout << "OPCI�N: ";
        cin >> opcionSelec;
        if(opcionSelec != 1)
            return;
        cout << "ID: ";
        cin >> idSelec;
        posicion = archivoFunciones.BuscarID(idSelec, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::YELLOW);
            cout << "No se encontr� una funci�n con el ID ingresado." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            continue;
        }
        break;
    }
    system("cls");
    Funcion funcion = archivoFunciones.LeerRegistro(posicion);
    valorEntrada = CalcularPrecioEntrada(funcion);
    entradasDisponibles = AsientosLibres(funcion);
    if(entradasDisponibles == 0){
        rlutil::setColor(rlutil::YELLOW);
        cout << "No hay entradas disponibles para la funci�n seleccionada." << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
        return;
    }
    while(true){
        cout << "HAY " << entradasDisponibles << " ENTRADAS DISPONIBLES PARA LA FUNCI�N SELECCIONADA" << endl;
        cout << "CANTIDAD DE ENTRADAS: ";
        cin >> cantidadEntradas;
        if(cantidadEntradas > AsientosLibres(funcion)){
            rlutil::setColor(rlutil::YELLOW);
            cout << "ERROR: La cantidad de entradas solicitadas supera la capacidad disponible." << endl;
            rlutil::setColor(rlutil::GREY);
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
    if(!cliente.getActivo()){
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR: EL DNI INGRESADO PERTENECE A UN CLIENTE DADO DE BAJA." << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
        return;
    }
    if(posicionCliente != -1){
        rlutil::setColor(rlutil::YELLOW);
        cout << "CLIENTE ENCONTRADO: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
        cout << "�DESEA CONTINUAR? 1.S� 2.NO\n";
        rlutil::setColor(rlutil::GREY);
        cin >> opcionSelec;
        if(opcionSelec != 1)
            return;
    }
    else{
        rlutil::setColor(rlutil::YELLOW);
        cout << "NO SE ENCONTR� UN CLIENTE CON ESE DNI, POR FAVOR CARGAR NUEVO CLIENTE" << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
        system("cls");
        cliente.Cargar(dni);
        if(archivoClientes.Guardar(cliente)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "NUEVO CLIENTE CARGADO CORRECTAMENTE." << endl;
            rlutil::setColor(rlutil::GREY);
            posicionCliente = archivoClientes.BuscarDni(dni);
            int idCliente = archivoClientes.LeerRegistro(posicionCliente).getId();
            cliente.setId(idCliente);
        }
        else{
            rlutil::setColor(rlutil::YELLOW);
            cout << "VENTA CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }
    }

    cout << "FECHA Y HORA DE LA VENTA\n";
    Fecha fechaVenta;
    fechaVenta.CargarHora();

    //VER Y CONFIRMAR COMPRA
    reporte.VentaDetalle(funcion, cantidadEntradas, fechaVenta, cliente, valorEntrada);
    rlutil::setColor(rlutil::YELLOW);
    cout << endl << "�CONFIRMAR VENTA? 1.S� 2.NO\n";
    rlutil::setColor(rlutil::GREY);
    cin >> opcionSelec;
    if(opcionSelec != 1)
        return;


    //EJECUTAR
    float totalVenta = cantidadEntradas * valorEntrada;
    Venta venta(cliente.getId(), funcion.getIdFuncion(), cantidadEntradas, fechaVenta, totalVenta);
    ArchivoVentas archivoVentas;
    if(archivoVentas.Guardar(venta)){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "VENTA REALIZADA CON �XITO." << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "ERROR: NO SE PUDO REALIZAR LA VENTA." << endl;
        rlutil::setColor(rlutil::GREY);
        system("pause");
    }
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
            posicion = archivo.BuscarID(id, false);
            if(posicion == -1){
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL ID INGRESADO." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                continue;
            }
            break;
        case 2:
            int dni;
            cout << "DNI: ";
            cin >> dni;
            posicion = archivo.BuscarDni(dni, false);
            if(posicion == -1){
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL DNI INGRESADO." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                continue;
            }
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            break;
        }

        cliente = archivo.LeerRegistro(posicion);
        if(!cliente.Modificar()){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "MODIFICACI�N CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        if(archivo.Guardar(cliente, posicion)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << endl << "CLIENTE MODIFICADO CON �XITO." << endl;
            rlutil::setColor(rlutil::GREY);
        }
        else{
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR EL CLIENTE." << endl;
            rlutil::setColor(rlutil::GREY);
        }

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
        cout << "MODIFICAR FUNCI�N" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA FUNCI�N CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        funcion = archivo.LeerRegistro(posicion);
        if(!funcion.Modificar()){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "MODIFICACI�N CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        if(archivo.Guardar(funcion, posicion)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << endl << "FUNCI�N MODIFICADA CON �XITO." << endl;
            rlutil::setColor(rlutil::GREY);
        }
        else{
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA FUNCI�N." << endl;
            rlutil::setColor(rlutil::GREY);
        }

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
        int id;
        cout << "MODIFICAR PEL�CULA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA PEL�CULA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        pelicula = archivo.LeerRegistro(posicion);
        if(!pelicula.Modificar()){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "MODIFICACI�N CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        if(archivo.Guardar(pelicula, posicion)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << endl << "PEL�CULA MODIFICADA CON �XITO." << endl;
            rlutil::setColor(rlutil::GREY);
        }
        else{
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA PEL�CULA." << endl;
            rlutil::setColor(rlutil::GREY);
        }

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
        int id;
        cout << "MODIFICAR SALA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA SALA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }
        sala = archivo.LeerRegistro(posicion);
        if(!sala.Modificar()){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "MODIFICACI�N CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        if(archivo.Guardar(sala, posicion)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << endl << "SALA MODIFICADA CON �XITO." << endl;
            rlutil::setColor(rlutil::GREY);
        }
        else{
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA SALA." << endl;
            rlutil::setColor(rlutil::GREY);
        }

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
        int id;
        cout << "MODIFICAR VENTA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA VENTA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        venta = archivo.LeerRegistro(posicion);
        if(!venta.Modificar()){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "MODIFICACI�N CANCELADA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        if(archivo.Guardar(venta, posicion)){
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << endl << "VENTA MODIFICADA CON �XITO." << endl;
            rlutil::setColor(rlutil::GREY);
        }
        else{
            rlutil::setColor(rlutil::LIGHTRED);
            cout << endl << "ERROR: NO SE PUEDO MODIFICAR LA VENTA." << endl;
            rlutil::setColor(rlutil::GREY);
        }

        system("pause");
        return;
    }
}

void GestorCine::BajaCliente(){
    ArchivoClientes archivo;
    Cliente cliente;
    int posicion;
    while(true){
        system("cls");
        int opcionEliminar;
        cout << "ELIMINAR CLIENTE - M�TODO DE B�SQUEDA\n1. ID\n2. DNI\n\n0. Cancelar" << endl << endl;
        cout << "INGRESAR OPCI�N: ";
        cin >> opcionEliminar;
        switch(opcionEliminar){
        case 1:
            int id;
            cout << "ID: ";
            cin >> id;
            posicion = archivo.BuscarID(id, false);
            if(posicion == -1){
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL ID INGRESADO." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                continue;
            }
            break;
        case 2:
            int dni;
            cout << "DNI: ";
            cin >> dni;
            posicion = archivo.BuscarDni(dni, false);
            if(posicion == -1){
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "ERROR: NO SE ENCONTR� UN CLIENTE CON EL DNI INGRESADO." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                continue;
            }
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            break;
        }

        cliente = archivo.LeerRegistro(posicion);
        while(true){
            system("cls");
            cliente.Mostrar();
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "�CONFIRMAR BAJA?\n1. S�\n2. No\n\n";
            rlutil::setColor(rlutil::GREY);
            cout << "OPCI�N: ";
            int opcion;
            cin >> opcion;
            switch(opcion){
            case 1:
                cliente.setActivo(false);
                if(archivo.Guardar(cliente, posicion)){
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << endl << "CLIENTE ELIMINADO CON �XITO." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                else{
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "ERROR: NO SE PUDO ELIMINAR EL CLIENTE." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                system("pause");
                return;
            case 2:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "BAJA CANCELADA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                return;
            default:
                rlutil::setColor(rlutil::YELLOW);
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                break;
            }
        }
    }
}

void GestorCine::BajaFuncion(){
    ArchivoFunciones archivo;
    Funcion funcion;
    int posicion;
    while(true){
        system("cls");
        int id;
        cout << "ELIMINAR FUNCI�N" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA FUNCI�N CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        funcion = archivo.LeerRegistro(posicion);

        while(true){
            system("cls");
            funcion.Mostrar();
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "�CONFIRMAR BAJA?\n1. S�\n2. No\n\n";
            rlutil::setColor(rlutil::GREY);
            cout << "OPCI�N: ";
            int opcion;
            cin >> opcion;
            switch(opcion){
            case 1:
                funcion.setActivo(false);
                if(archivo.Guardar(funcion, posicion)){
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << endl << "FUNCI�N ELIMINADA CON �XITO." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                else{
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "ERROR: NO SE PUDO ELIMINAR LA FUNCI�N." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                system("pause");
                return;
            case 2:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "BAJA CANCELADA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                return;
            default:
                rlutil::setColor(rlutil::YELLOW);
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                break;
            }
        }
    }
}

void GestorCine::BajaPelicula(){
    ArchivoPeliculas archivo;
    Pelicula pelicula;
    int posicion;
    while(true){
        system("cls");
        int id;
        cout << "ELIMINAR PEL�CULA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA PEL�CULA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        pelicula = archivo.LeerRegistro(posicion);

        while(true){
            system("cls");
            pelicula.Mostrar();
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "�CONFIRMAR BAJA?\n1. S�\n2. No\n\n";
            rlutil::setColor(rlutil::GREY);
            cout << "OPCI�N: ";
            int opcion;
            cin >> opcion;
            switch(opcion){
            case 1:
                pelicula.setActivo(false);
                if(archivo.Guardar(pelicula, posicion)){
                    rlutil::setColor(rlutil::GREY);
                    cout << endl << "PEL�CULA ELIMINADA CON �XITO." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                else{
                    rlutil::setColor(rlutil::GREY);
                    cout << endl << "ERROR: NO SE PUDO ELIMINAR LA PEL�CULA." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                system("pause");
                return;
            case 2:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "BAJA CANCELADA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                return;
            default:
                rlutil::setColor(rlutil::YELLOW);
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                break;
            }
        }
    }
}

void GestorCine::BajaSala(){
    ArchivoSalas archivo;
    Sala sala;
    int posicion;
    while(true){
        system("cls");
        int id;
        cout << "ELIMINAR SALA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA SALA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        sala = archivo.LeerRegistro(posicion);

        while(true){
            system("cls");
            sala.Mostrar();
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "�CONFIRMAR BAJA?\n1. S�\n2. No\n\n";
            rlutil::setColor(rlutil::GREY);
            cout << "OPCI�N: ";
            int opcion;
            cin >> opcion;
            switch(opcion){
            case 1:
                sala.setActivo(false);
                if(archivo.Guardar(sala, posicion)){
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << endl << "SALA ELIMINADA CON �XITO." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                else{
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "ERROR: NO SE PUDO ELIMINAR LA SALA." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                system("pause");
                return;
            case 2:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "BAJA CANCELADA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                return;
            default:
                rlutil::setColor(rlutil::YELLOW);
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                break;
            }
        }
    }
}

void GestorCine::BajaVenta(){
    ArchivoVentas archivo;
    Venta venta;
    int posicion;
    while(true){
        system("cls");
        int id;
        cout << "ELIMINAR VENTA" << endl << endl;
        cout << "INGRESAR ID: ";
        cin >> id;
        posicion = archivo.BuscarID(id, false);
        if(posicion == -1){
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "ERROR: NO SE ENCONTR� UNA VENTA CON EL ID INGRESADO." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            return;
        }

        venta = archivo.LeerRegistro(posicion);

        while(true){
            system("cls");
            venta.Mostrar();
            rlutil::setColor(rlutil::YELLOW);
            cout << endl << "�CONFIRMAR BAJA?\n1. S�\n2. No\n\n";
            rlutil::setColor(rlutil::GREY);
            cout << "OPCI�N: ";
            int opcion;
            cin >> opcion;
            switch(opcion){
            case 1:
                venta.setActivo(false);
                if(archivo.Guardar(venta, posicion)){
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << endl << "VENTA ELIMINADA CON �XITO." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                else{
                    rlutil::setColor(rlutil::LIGHTRED);
                    cout << endl << "ERROR: NO SE PUDO ELIMINAR LA VENTA." << endl;
                    rlutil::setColor(rlutil::GREY);
                }
                system("pause");
                return;
            case 2:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "BAJA CANCELADA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                return;
            default:
                rlutil::setColor(rlutil::YELLOW);
                cout << "ERROR: INGRESE UNA OPCI�N V�LIDA." << endl;
                rlutil::setColor(rlutil::GREY);
                system("pause");
                break;
            }
        }
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
        if(venta.getIdFuncion() == idFuncion && venta.getActivo()){
            ocupados += venta.getCantidadEntradas();
        }
    }

    return capacidad - ocupados;
}
