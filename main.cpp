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
    pelicula1.Mostrar();

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
