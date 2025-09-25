#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "validacion.h"

int ultimoID = 0;

Persona *crearPersona()
{
    Persona *p = malloc(sizeof(Persona));
    if (!p)
    {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    p->id = ++ultimoID;

    leerCadenaSoloLetras(p->nombre, MAX_NOMBRE, "Nombre: ");
    leerCadenaSoloLetras(p->apellido, MAX_APELLIDO, "Apellido: ");
    p->edad = leerEdad("Edad (0 - 120): ");
    leerCadenaSoloLetras(p->carrera, MAX_CARRERA, "Carrera: ");

    int n = leerEntero("¿Cuantas materias desea ingresar? (max 5): ");
    if (n < 0)
        n = 0;
    else if (n > MAX_MATERIAS)
        n = MAX_MATERIAS;

    for (int i = 0; i < n; i++)
    {
        char mat[MAX_MATERIA_NOMBRE];
        char msg[60];
        snprintf(msg, sizeof(msg), "Materia %d: ", i + 1);
        leerCadenaSoloLetras(mat, MAX_MATERIA_NOMBRE, msg);
        strncpy(p->materias[i], mat, MAX_MATERIA_NOMBRE - 1);
        p->materias[i][MAX_MATERIA_NOMBRE - 1] = '\0';
    }

    for (int i = n; i < MAX_MATERIAS; i++)
        p->materias[i][0] = '\0';

    return p;
}

void modificarPersona(Persona *p)
{
    if (!p)
    {
        printf("Persona no existe.\n");
        return;
    }

    printf("Modificando persona (ID %d):\n", p->id);

    char buffer[100];

    // Nombre
    while (1)
    {
        printf("Nombre actual: %s\n", p->nombre);
        printf("Nuevo nombre (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            // Mantener actual
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->nombre, buffer, MAX_NOMBRE - 1);
            p->nombre[MAX_NOMBRE - 1] = '\0';
            break;
        }
    }

    // Apellido
    while (1)
    {
        printf("Apellido actual: %s\n", p->apellido);
        printf("Nuevo apellido (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->apellido, buffer, MAX_APELLIDO - 1);
            p->apellido[MAX_APELLIDO - 1] = '\0';
            break;
        }
    }

    // Edad
    while (1)
    {
        printf("Edad actual: %d\n", p->edad);
        printf("Nueva edad (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (esNumeroEntero(buffer))
        {
            int edad = atoi(buffer);
            if (edad >= 0 && edad <= 120)
            {
                p->edad = edad;
                break;
            }
            else
                printf("Edad invalida. Debe estar entre 0 y 120.\n");
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }

    // Carrera
    while (1)
    {
        printf("Carrera actual: %s\n", p->carrera);
        printf("Nueva carrera (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->carrera, buffer, MAX_CARRERA - 1);
            p->carrera[MAX_CARRERA - 1] = '\0';
            break;
        }
    }

    // Materias
    printf("Materias actuales:\n");
    int materiasActuales = 0;
    for (int i = 0; i < MAX_MATERIAS; i++)
    {
        if (p->materias[i][0] != '\0')
        {
            printf("  %d. %s\n", i + 1, p->materias[i]);
            materiasActuales++;
        }
    }
    if (materiasActuales == 0)
        printf("  (Ninguna)\n");

    int n;
    while (1)
    {
        printf("Cuantas materias desea ingresar? (0 a %d, enter para mantener actuales): ", MAX_MATERIAS);
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            // Mantener actuales
            n = materiasActuales;
            break;
        }
        else if (esNumeroEntero(buffer))
        {
            n = atoi(buffer);
            if (n >= 0 && n <= MAX_MATERIAS)
                break;
            else
                printf("Numero invalido. Intente de nuevo.\n");
        }
        else
        {
            printf("Entrada invalida. Intente de nuevo.\n");
        }
    }

    if (strlen(buffer) != 0) // Si ingresó un nuevo número de materias, modificar
    {
        for (int i = 0; i < n; i++)
        {
            while (1)
            {
                char msg[60];
                snprintf(msg, sizeof(msg), "Materia %d: ", i + 1);
                printf("%s", msg);
                leerCadena(buffer, sizeof(buffer));
                if (strlen(buffer) == 0)
                {
                    printf("La materia no puede estar vacia.\n");
                    continue;
                }
                if (!esCadenaSoloLetras(buffer))
                {
                    printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
                    continue;
                }
                strncpy(p->materias[i], buffer, MAX_MATERIA_NOMBRE - 1);
                p->materias[i][MAX_MATERIA_NOMBRE - 1] = '\0';
                break;
            }
        }
        for (int i = n; i < MAX_MATERIAS; i++)
            p->materias[i][0] = '\0';
    }

    printf("Persona modificada.\n");
}

void mostrarPersona(const Persona *p, int indice)
{
    if (!p)
    {
        printf("Persona %d: [Vacia]\n", indice + 1);
        return;
    }

    printf("Persona %d:\n", indice + 1);
    printf("  ID: %d\n", p->id);
    printf("  Nombre: %s %s\n", p->nombre, p->apellido);
    printf("  Edad: %d\n", p->edad);
    printf("  Carrera: %s\n", p->carrera);
    printf("  Materias:\n");

    int vacias = 1;
    for (int i = 0; i < MAX_MATERIAS; i++)
    {
        if (p->materias[i][0] != '\0')
        {
            printf("    - %s\n", p->materias[i]);
            vacias = 0;
        }
    }
    if (vacias)
        printf("    (Ninguna)\n");
}
