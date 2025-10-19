#ifndef LISTA_H
#define LISTA_H

#include "persona.h"

typedef struct Nodo
{
    Persona *persona;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void crearLista(Nodo **cabeza);
void insertarEnLista(Nodo **cabeza, Persona *p);
void mostrarLista(Nodo *cabeza);
void liberarLista(Nodo **cabeza);
void eliminarDeListaPorID(Nodo **cabeza, int id);

#endif
