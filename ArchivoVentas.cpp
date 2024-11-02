#include "ArchivoVentas.h"

ArchivoVentas::ArchivoVentas(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoVentas::ContarRegistros(){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int cantidad = ftell(p)/sizeof(Venta);
    fclose(p);
    return cantidad;
}

int ArchivoVentas::BuscarID(int id){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Venta venta;
    int i = 0;
    while(fread(&venta, sizeof(Venta), 1, p)){
        if(venta.getIdVenta() == id){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Venta ArchivoVentas::LeerRegistro(int pos){
    FILE* p = fopen(_nombre, "rb");
    Venta venta;
    if(p == NULL){
        return venta;
    }
    fseek(p, sizeof(Venta) * pos, 0);
    fread(&venta, sizeof(Venta), 1, p);
    fclose(p);
    return venta;
}

bool ArchivoVentas::Guardar(Venta venta){
    int idActual = 0;

    while(BuscarID(idActual) != -1)
        idActual++;

    venta.setIdVenta(idActual);

    FILE* p = fopen(_nombre, "ab");
    if(p == NULL){
        return false;
    }

    bool escribio = fwrite(&venta, sizeof(Venta), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoVentas::Guardar(Venta venta, int pos){
    FILE* p = fopen(_nombre, "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Venta) * pos, 0);
    bool escribio = fwrite(&venta, sizeof(Venta), 1, p);
    fclose(p);
    return escribio;
}
