#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "persona.h"

void crearLista(Nodo **cabeza)
{
    *cabeza = NULL;
    printf("Lista doblemente enlazada creada.\n");
}

void insertarEnLista(Nodo **cabeza, Persona *p)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo)
    {
        printf("No se pudo asignar memoria para el nodo.\n");
        return;
    }

    nuevo->persona = p;
    nuevo->anterior = NULL;
    nuevo->siguiente = *cabeza;

    if (*cabeza != NULL)
        (*cabeza)->anterior = nuevo;

    *cabeza = nuevo;

    printf("Persona con ID %d insertada en la lista.\n", p->id);
}

void mostrarLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    int i = 1;
    while (actual != NULL)
    {
        printf("Nodo %d:\n", i);
        mostrarPersona(actual->persona, i - 1);
        actual = actual->siguiente;
        i++;
    }
}

void liberarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    while (actual != NULL)
    {
        Nodo *siguiente = actual->siguiente;
        free(actual->persona);
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
    printf("Lista liberada.\n");
}
