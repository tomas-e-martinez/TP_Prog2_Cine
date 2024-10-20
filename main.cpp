#include <iostream>
#include <locale.h>

#include "Fecha.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "spanish");
    int opcion;

    Fecha fecha1;
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
