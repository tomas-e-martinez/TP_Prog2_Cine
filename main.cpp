#include <iostream>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_CTYPE, "spanish");
    int opcion;

    while(true){
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
            cout << "Opci�n inv�lida. Intente de nuevo." << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
