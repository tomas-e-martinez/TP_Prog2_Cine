#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>

#include "Menu.h"
#include "Fecha.h"
#include "Tiempo.h"
#include "Pelicula.h"
#include "Cliente.h"
#include "Sala.h"
#include "Funcion.h"
#include "Venta.h"
#include "Reporte.h"
#include "GestorCine.h"

#include "ArchivoPeliculas.h"
#include "ArchivoClientes.h"
#include "ArchivoSalas.h"
#include "ArchivoFunciones.h"
#include "ArchivoVentas.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "Spanish");

    GestorCine gestor;
    Reporte reporte;



    /* PRUEBA DE CARACTERES ESPECIALES
    char palabra[10] = {"aραρι"};
    cout << palabra << endl;
    cin >> palabra;
    cout << palabra << endl;
    system("pause");*/



    /// PRUEBA DE ARCHIVOS
    /*Reporte reporte1;
    reporte1.ListarSalas();
    reporte1.ListarVentas();
    reporte1.ListarFunciones();
    reporte1.ListarClientes();
    reporte1.ListarPeliculas();
    ArchivoFunciones archivo;
    while(true){
        Funcion funcion1;
        funcion1.Cargar();
        archivo.Guardar(funcion1);
        reporte1.ListarFunciones();
    }*/

    /*PRUEBA DE CLASE
    Funcion funcion1;
    funcion1.Cargar();
    funcion1.Mostrar();
    system("pause");*/

    //pelicula1.Mostrar();
    //system("pause");
    //ArchivoPeliculas archivo;
    //system("pause");
    //system("cls");
    //listarPeliculas();
    //system("pause");

    //Fecha fecha1(32, 13, 2015, 24, 60);
    //cout << fecha1.toStringFecha() << endl;
    //cout << fecha1.toStringHora() << endl;

    Menu menu;
    menu.Principal(gestor, reporte);

    return 0;
}
