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
        cout << "0. Salir" << endl << endl;

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
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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

void Menu::Peliculas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ PELÍCULAS" << endl << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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

void Menu::Salas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ SALAS" << endl << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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

void Menu::Ventas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ VENTAS" << endl << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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

void Menu::Reportes(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTIÓN DE CINE" << endl;
        cout << "SUBMENÚ REPORTES" << endl << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "0. Salir" << endl << endl;

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
