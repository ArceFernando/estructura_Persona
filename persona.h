#ifndef PERSONA_H
#define PERSONA_H

#define MAX_PERSONAS 5
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#define MAX_CARRERA 50
#define MAX_MATERIAS 5
#define MAX_MATERIA_NOMBRE 30

typedef struct
{
    int id;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int edad;
    char carrera[MAX_CARRERA];
    char materias[MAX_MATERIAS][MAX_MATERIA_NOMBRE];
} Persona;

extern int ultimoID;

Persona *crearPersona();
void modificarPersona(Persona *p);
void mostrarPersona(const Persona *p, int indice);

#endif
