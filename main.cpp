#include <iostream>
#include <locale.h>
#include <string>

#include "Fecha.h"
#include "Tiempo.h"
#include "Pelicula.h"
#include "Cliente.h"
#include "Sala.h"

#include "ArchivoPeliculas.h"

using namespace std;

void listarPeliculas(const char* nombreArchivo = "peliculas.dat"){
    ArchivoPeliculas archivo(nombreArchivo);
    Pelicula registro;

    int cantidadRegistros = archivo.ContarRegistros();
    cout << cantidadRegistros << endl;
    system("pause");
    cout << "TÍTULO\t\t\tGÉNERO\t\tDURACIÓN\t\tEDAD" << endl;
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        cout
        << registro.getTitulo() << "\t\t\t"
        << registro.getGenero() << "\t\t"
        << registro.getDuracion().toString() << "\t\t"
        << registro.getClasificacionedad() << "+" << endl;
    }
}

int main(){
    setlocale(LC_CTYPE, "Spanish");
    int opcion;

    ArchivoPeliculas archivo;
    Pelicula pelicula1 = archivo.LeerRegistro(2);
    cout << pelicula1.getGenero() << endl;
    system("pause");

    /*prueba caracteres especiales
    char palabra[10] = {"añáñé"};
    cout << palabra << endl;
    cin >> palabra;
    cout << palabra << endl;
    system("pause");*/

    //Pelicula pelicula1;
    pelicula1.Cargar();
    //pelicula1.Mostrar();
    //system("pause");
    //ArchivoPeliculas archivo;
    archivo.Guardar(pelicula1);
    //system("pause");
    system("cls");
    listarPeliculas();
    system("pause");

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
