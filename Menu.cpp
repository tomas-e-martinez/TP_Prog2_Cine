#include "Menu.h"

void Menu::Principal(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "MENÚ PRINCIPAL" << endl << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Funciones" << endl;
        cout << "3. Películas" << endl;
        cout << "4. Salas" << endl;
        cout << "5. Ventas" << endl;
        cout << "6. Reportes" << endl;
        cout << endl << "0. Salir" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            Clientes(gestor, reporte);
            break;
        case 2:
            Funciones(gestor, reporte);
            break;
        case 3:
            Peliculas(gestor, reporte);
            break;
        case 4:
            Salas(gestor, reporte);
            break;
        case 5:
            Ventas(gestor, reporte);
            break;
        case 6:
            Reportes(reporte);
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Clientes(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ CLIENTES" << endl << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Modificar Cliente" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Listado ordenado por apellido" << endl;
        cout << "5. Buscar por DNI" << endl;
        cout << "6. Buscar por rango de edad" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.AgregarCliente();
            break;
        case 2:
            gestor.ModificarCliente();
            break;
        case 3:
            reporte.ListarClientes();
            break;
        case 4:
            reporte.ListarClientesApellido();
            break;
        case 5:
            system("cls");
            int dni;
            cout << "BUSCAR CLIENTE POR DNI\n\nIngrese el N° de DNI: ";
            cin >> dni;
            reporte.ListarClientesDNI(dni);
            break;
        case 6:
            system("cls");
            int minimo, maximo;
            cout << "BUSCAR CLIENTES POR RANGO DE EDAD\n\nIngrese edad mínima: ";
            cin >> minimo;
            cout << "Ingrese edad máxima: ";
            cin >> maximo;
            reporte.ListarClientesEdad(minimo, maximo);
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Funciones(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ FUNCIONES" << endl << endl;
        cout << "1. Agregar Función" << endl;
        cout << "2. Modificar Función" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Buscar por fecha" << endl;
        cout << "5. Buscar por tipo de sala" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.AgregarFuncion();
            break;
        case 2:
            gestor.ModificarFuncion();
            break;
        case 3:
            reporte.ListarFunciones();
            break;
        case 4: {
            system("cls");
            int minimo, maximo;
            cout << "BUSCAR FUNCIONES POR FECHA\n\nDESDE\n";
            Fecha fecha1;
            fecha1.Cargar();
            cout << "\nHASTA\n";
            Fecha fecha2;
            fecha2.Cargar();
            reporte.ListarFuncionesFecha(fecha1, fecha2);
            break;
        }
        case 5:
            system("cls");
            int opcionTipo;
            cout << "BUSCAR FUNCIONES POR TIPO DE SALA\n1. 2D\n2. 3D\n3. IMAX\n\n0. Cancelar" << endl << endl;
            cout << "INGRESAR OPCIÓN: ";
            cin >> opcionTipo;
            reporte.ListarFuncionesSala(opcionTipo);
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Peliculas(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ PELÍCULAS" << endl << endl;
        cout << "1. Agregar Película" << endl;
        cout << "2. Modificar Película" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Listado ordenado por género" << endl;
        cout << "5. Listado ordenado por puntuación" << endl;
        cout << "6. Buscar por género" << endl;
        cout << "7. Buscar por puntuación" << endl;
        cout << "8. Buscar por título" << endl;
        cout << "9. Buscar por clasificación de edad" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.AgregarPelicula();
        case 2:
            gestor.ModificarPelicula();
            break;
        case 3:
            reporte.ListarPeliculas();
            break;
        case 4:
            reporte.ListarPeliculasOrdenGenero();
            break;
        case 5:
            reporte.ListarPeliculasOrdenCalificacion();
            break;
        case 6:
            //reporte.ListarPeliculasGenero();
            break;
        case 7:
            //reporte.ListarPeliculasCalificacion();
            break;
        case 8:
            //reporte.ListarPeliculasTitulo();
            break;
        case 9:
            //reporte.ListarPeliculasEdad();
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Salas(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ SALAS" << endl << endl;
        cout << "1. Agregar Sala" << endl;
        cout << "2. Modificar Sala" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Listado ordenado por tipo de sala" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.AgregarSala();
            break;
        case 2:
            gestor.ModificarSala();
            break;
        case 3:
            reporte.ListarSalas();
            break;
        case 4:
            reporte.ListarSalasTipo();
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Ventas(GestorCine& gestor, Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ VENTAS" << endl << endl;
        cout << "1. Agregar Venta" << endl;
        cout << "2. Modificar Venta" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.AgregarVenta();
            break;
        case 2:
            gestor.ModificarVenta();
            break;
        case 3:
            reporte.ListarVentas();
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Reportes(Reporte& reporte){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ REPORTES" << endl << endl;
        cout << "1. Recaudación anual" << endl;
        cout << "2. Recaudación por tipo de sala" << endl;
        cout << "3. Recaudación por título" << endl;
        cout << "4. Recaudación por género" << endl;
        cout << "5. Cantidad de entradas vendidas por película" << endl;
        cout << "6. Cantidad de entradas vendidas por género" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}
