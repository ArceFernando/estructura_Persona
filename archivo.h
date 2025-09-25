#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "persona.h"

#define ARCHIVO_PERSONAS "personas.txt"

void guardarEnArchivo(Persona *personas[], int total);
void cargarDesdeArchivo(Persona *personas[], int total);

#endif
