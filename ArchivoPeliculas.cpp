#include "ArchivoPeliculas.h"

ArchivoPeliculas::ArchivoPeliculas(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoPeliculas::ContarRegistros(){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int cantidad = ftell(p)/sizeof(Pelicula);
    fclose(p);
    return cantidad;
}

int ArchivoPeliculas::BuscarID(int id, bool todos){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Pelicula pelicula;
    int i = 0;
    while(fread(&pelicula, sizeof(Pelicula), 1, p)){
        if(pelicula.getId() == id){
            fclose(p);
            if(todos || pelicula.getActivo())
                return i;
            else
                return -1;
        }
        i++;
    }
    fclose(p);
    return -1;
}


int ArchivoPeliculas::BuscarTitulo(const char* titulo, bool todos){
    FILE* p = fopen(_nombre, "rb");
    if(p == NULL){
        return -1;
    }
    Pelicula pelicula;
    int i = 0;
    while(fread(&pelicula, sizeof(Pelicula), 1, p)){
        if(strcmp(pelicula.getTitulo(), titulo) == 0){
            fclose(p);
            if(todos || pelicula.getActivo())
                return i;
            else
                return -1;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Pelicula ArchivoPeliculas::LeerRegistro(int pos){
    FILE* p = fopen(_nombre, "rb");
    Pelicula pelicula;
    if(p == NULL){
        return pelicula;
    }
    fseek(p, sizeof(Pelicula) * pos, 0);
    fread(&pelicula, sizeof(Pelicula), 1, p);
    fclose(p);
    return pelicula;
}

bool ArchivoPeliculas::Guardar(Pelicula pelicula){
    int idActual = 0;

    while(BuscarID(idActual) != -1)
        idActual++;

    pelicula.setId(idActual);

    FILE* p = fopen(_nombre, "ab");
    if(p == NULL){
        return false;
    }

    bool escribio = fwrite(&pelicula, sizeof(Pelicula), 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoPeliculas::Guardar(Pelicula pelicula, int pos){
    FILE* p = fopen(_nombre, "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Pelicula) * pos, 0);
    bool escribio = fwrite(&pelicula, sizeof(Pelicula), 1, p);
    fclose(p);
    return escribio;
}





