#include "Menu.h"

void Menu::Principal(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "MEN� PRINCIPAL" << endl << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Funciones" << endl;
        cout << "3. Pel�culas" << endl;
        cout << "4. Salas" << endl;
        cout << "5. Ventas" << endl;
        cout << "6. Reportes" << endl;
        cout << endl << "0. Salir" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Clientes(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� CLIENTES" << endl << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Modificar Cliente" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Listado ordenado por apellido" << endl;
        cout << "5. Buscar por DNI" << endl;
        cout << "6. Buscar por rango de edad" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Funciones(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� FUNCIONES" << endl << endl;
        cout << "1. Agregar Funci�n" << endl;
        cout << "2. Modificar Funci�n" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Buscar por fecha" << endl;
        cout << "5. Buscar por tipo de sala" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Peliculas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� PEL�CULAS" << endl << endl;
        cout << "1. Agregar Pel�cula" << endl;
        cout << "2. Modificar Pel�cula" << endl;
        cout << "3. Listado ordenado por t�tulo" << endl;
        cout << "4. Listado ordenado por g�nero" << endl;
        cout << "5. Listado ordenado por puntuaci�n" << endl;
        cout << "6. Buscar por g�nero" << endl;
        cout << "7. Buscar por puntuaci�n" << endl;
        cout << "8. Buscar por t�tulo" << endl;
        cout << "9. Buscar por clasificaci�n de edad" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Salas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� SALAS" << endl << endl;
        cout << "1. Agregar Sala" << endl;
        cout << "2. Modificar Sala" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << "4. Listado ordenado por tipo de sala" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Ventas(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� VENTAS" << endl << endl;
        cout << "1. Agregar Venta" << endl;
        cout << "2. Modificar Venta" << endl;
        cout << "3. Listado ordenado por ID" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}

void Menu::Reportes(){
    while(true){
        system("cls");
        cout << "SISTEMA DE GESTI�N DE CINE" << endl;
        cout << "SUBMEN� REPORTES" << endl << endl;
        cout << "1. Recaudaci�n anual" << endl;
        cout << "2. Recaudaci�n por tipo de sala" << endl;
        cout << "3. Recaudaci�n por t�tulo" << endl;
        cout << "4. Recaudaci�n por g�nero" << endl;
        cout << "5. Cantidad de entradas vendidas por pel�cula" << endl;
        cout << "6. Cantidad de entradas vendidas por g�nero" << endl;
        cout << endl << "0. Volver al men� principal" << endl << endl;

        cout << "Ingresar opci�n: ";
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }
}
