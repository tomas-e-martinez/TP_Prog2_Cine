#include <iostream>
#include <locale.h>
#include <string>

#include "Fecha.h"
#include "Tiempo.h"
#include "Pelicula.h"
#include "Cliente.h"
#include "Sala.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "Spanish");
    int opcion;

    //Prueba sala
    Sala sala1;
    sala1.Mostrar();
    system("pause");

    /*prueba caracteres especiales
    char palabra[10] = {"añáñé"};
    cout << palabra << endl;
    cin >> palabra;
    cout << palabra << endl;
    system("pause");*/

    Pelicula pelicula1;
    pelicula1.Cargar();
    pelicula1.Mostrar();

    //Fecha fecha1(32, 13, 2015, 24, 60);
    //cout << fecha1.toStringFecha() << endl;
    //cout << fecha1.toStringHora() << endl;

    while(false){
        system("cls");
        cout << "1." << endl;
        cout << "0. Salir" << endl << endl;

        cin >> opcion;

        switch(opcion){
        case 1:
            break;
        case 0:
            return 0;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
