#include <iostream>
#include <locale.h>
#include <string>

#include "Fecha.h"
#include "Tiempo.h"
#include "Pelicula.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "spanish");
    int opcion;


    Pelicula pelicula1;
    //pelicula1.Cargar();
    Fecha fecha1(32, 13, 2015, 24, 60);
    cout << fecha1.toStringFecha() << endl;
    cout << fecha1.toStringHora() << endl;

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
