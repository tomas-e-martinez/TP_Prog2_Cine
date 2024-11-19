#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>

#include "rlutil.h"

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

#include <ctime> ///GENERAR REGISTROS PROVISORIOS
#include "CargarAleatorio.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "Spanish");

    ///CARGAR ALEATORIOS
    /*srand(time(0));
    CargarAleatorio cargar;
    cargar.CargarFunciones(20);
    Reporte prueba;
    prueba.ListarFunciones();
    return 2;*/


    ///CARGAR PELICULAS
    /*while(true){
        Pelicula pelicula;
        ArchivoPeliculas archivo;
        pelicula.Cargar();
        if(archivo.Guardar(pelicula))
            cout << "PELICULA CARGADA CORRECTAMENTE." << endl;
        cout << "CANT. PELICULAS: " << archivo.ContarRegistros() << endl;
        system("pause");
    }*/

    Menu menu;
    GestorCine gestor;
    Reporte reporte;

    menu.Principal(gestor, reporte);

    return 0;
}
