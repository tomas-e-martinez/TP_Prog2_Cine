#include "Menu.h"

void Menu::Principal(){
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
            Clientes();
            break;
        case 2:
            Funciones();
            break;
        case 3:
            Peliculas();
            break;
        case 4:
            Salas();
            break;
        case 5:
            Ventas();
            break;
        case 6:
            Reportes();
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

void Menu::Clientes(){
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

void Menu::Funciones(){
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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

void Menu::Peliculas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ PELÍCULAS" << endl << endl;
        cout << "1. Agregar Película" << endl;
        cout << "2. Modificar Película" << endl;
        cout << "3. Listado ordenado por título" << endl;
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
        case 7:
            break;
        case 8:
            break;
        case 9:
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

void Menu::Salas(){
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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

void Menu::Ventas(){
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
            break;
        case 2:
            break;
        case 3:
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

void Menu::Reportes(){
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
