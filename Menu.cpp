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
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
        cout << "3. Eliminar Cliente" << endl;
        cout << "4. Listado ordenado por ID" << endl;
        cout << "5. Listado ordenado por apellido" << endl;
        cout << "6. Buscar por DNI" << endl;
        cout << "7. Buscar por rango de edad" << endl;
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
            gestor.BajaCliente();
            break;
        case 4:
            reporte.ListarClientes();
            break;
        case 5:
            reporte.ListarClientesApellido();
            break;
        case 6:
            system("cls");
            int dni;
            cout << "BUSCAR CLIENTE POR DNI\n\nIngrese el N° de DNI: ";
            cin >> dni;
            reporte.ListarClientesDNI(dni);
            break;
        case 7:
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
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
        cout << "3. Eliminar Función" << endl;
        cout << "4. Listado ordenado por ID" << endl;
        cout << "5. Buscar por fecha" << endl;
        cout << "6. Buscar por tipo de sala" << endl;
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
            gestor.BajaFuncion();
            break;
        case 4:
            reporte.ListarFunciones();
            break;
        case 5: {
            system("cls");
            cout << "BUSCAR FUNCIONES POR FECHA\n\nDESDE\n";
            Fecha fecha1;
            fecha1.Cargar();
            cout << "\nHASTA\n";
            Fecha fecha2;
            fecha2.Cargar();
            reporte.ListarFuncionesFecha(fecha1, fecha2);
            break;
        }
        case 6:
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
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
        cout << "3. Eliminar Película" << endl;
        cout << "4. Listado ordenado por ID" << endl;
        cout << "5. Listado ordenado por género" << endl;
        cout << "6. Listado ordenado por puntuación" << endl;
        cout << "7. Buscar por género" << endl;
        cout << "8. Buscar por puntuación" << endl;
        cout << "9. Buscar por título" << endl;
        cout << "10. Buscar por clasificación de edad" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;
        cin.ignore();

        switch(_opcion){
        case 1:
            gestor.AgregarPelicula();
            break;
        case 2:
            gestor.ModificarPelicula();
            break;
        case 3:
            gestor.BajaPelicula();
            break;
        case 4:
            reporte.ListarPeliculas();
            break;
        case 5:
            reporte.ListarPeliculasOrdenGenero();
            break;
        case 6:
            reporte.ListarPeliculasOrdenCalificacion();
            break;
        case 7:
            system("cls");
            int opcionGenero;
            cout << "BUSCAR PELÍCULAS POR GÉNERO\n1. Accion\n2. Ciencia Ficcion\n3. Animacion\n4. Fantasia\n5. Drama\n6. Comedia\n7. Terror\n8. Aventura\n\n0. Cancelar" << endl << endl;
            cout << "INGRESAR OPCIÓN: ";
            cin >> opcionGenero;
            reporte.ListarPeliculasGenero(opcionGenero);
            break;
        case 8:
            system("cls");
            float minimo, maximo;
            cout << "BUSCAR PELÍCULAS POR CALIFICACIÓN (0.00/10.00)\nMÍNIMO: ";
            cin >> minimo;
            cout << "MÁXIMO:";
            cin >> maximo;
            reporte.ListarPeliculasCalificacion(minimo, maximo);
            break;
        case 9:
            system("cls");
            char titulo[100];
            cout << "BUSCAR PELÍCULA POR TÍTULO\nIngrese el título: ";
            cin.getline(titulo, sizeof(titulo));
            reporte.ListarPeliculasTitulo(titulo);
            break;
        case 10:
            system("cls");
            int edadMax;
            cout << "BUSCAR PELÍCULAS POR CLASIFICACIÓN DE EDAD\nIngrese la edad límite: ";
            cin >> edadMax;
            reporte.ListarPeliculasEdad(edadMax);
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
        cout << "3. Eliminar Sala" << endl;
        cout << "4. Listado ordenado por ID" << endl;
        cout << "5. Listado ordenado por tipo de sala" << endl;
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
            gestor.BajaSala();
            break;
        case 4:
            reporte.ListarSalas();
            break;
        case 5:
            reporte.ListarSalasTipo();
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
        cout << "1. Procesar Venta" << endl;
        cout << "2. Modificar Venta" << endl;
        cout << "3. Eliminar Venta" << endl;
        cout << "4. Listado ordenado por ID" << endl;
        cout << "5. Listado ordenado por fecha" << endl;
        cout << endl << "0. Volver al menú principal" << endl << endl;

        cout << "Ingresar opción: ";
        cin >> _opcion;

        switch(_opcion){
        case 1:
            gestor.ProcesarVenta();
            break;
        case 2:
            gestor.ModificarVenta();
            break;
        case 3:
            gestor.BajaVenta();
            break;
        case 4:
            reporte.ListarVentas();
            break;
        case 5:
            reporte.ListarVentasOrdenFecha();
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
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
            reporte.RecaudacionAnual(reporte);
            break;
        case 2:
            reporte.RecaudacionTipoSala(reporte);
            break;
        case 3:
            reporte.RecaudacionTitulo(reporte);
            break;
        case 4:
            reporte.RecaudacionGenero(reporte);
            break;
        case 5:
            reporte.EntradasVendidasPorPelicula(reporte);
            break;
        case 6:
            reporte.EntradasVendidasPorGenero(reporte);
            break;
        case 0:
            return;
        default:
            rlutil::setColor(rlutil::YELLOW);
            cout << "Opción inválida. Intente de nuevo." << endl;
            rlutil::setColor(rlutil::GREY);
            system("pause");
            break;
        }
    }
}
