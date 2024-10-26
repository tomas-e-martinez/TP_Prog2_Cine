#include <iostream>
#include <iomanip>
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
    system("cls");

    //ENCABEZADO
    cout << left
         << setw(5)  << "ID"
         << setw(30) << "TÍTULO"
         << setw(20) << "GÉNERO"
         << setw(20) << "FECHA DE ESTRENO"
         << setw(10) << "DURACIÓN"
         << setw(5)  << "EDAD" << endl;


    cout << "------------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.LeerRegistro(i);
        cout << left
             << setw(5)  << registro.getId()
             << setw(30) << registro.getTitulo()
             << setw(20) << registro.getGenero()
             << setw(20) << registro.getFechaEstreno().toStringFecha()
             << setw(10) << registro.getDuracion().toString()
             << setw(5)  << (to_string(registro.getClasificacionedad()) + "+") << endl;
    }

    cout << endl;
    system("pause");
}

int main(){
    setlocale(LC_CTYPE, "Spanish");
    int opcion;




    /*prueba caracteres especiales
    char palabra[10] = {"añáñé"};
    cout << palabra << endl;
    cin >> palabra;
    cout << palabra << endl;
    system("pause");*/
    listarPeliculas();
    ArchivoPeliculas archivo;
    while(true){
        Pelicula pelicula1;
        pelicula1.Cargar();
        archivo.Guardar(pelicula1);
        listarPeliculas();
    }
    //pelicula1.Mostrar();
    //system("pause");
    //ArchivoPeliculas archivo;
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
