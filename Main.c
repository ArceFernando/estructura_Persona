#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "validacion.h"
#include "archivo.h"

#define MAX_PERSONAS 5

int main()
{
    Persona *personas[MAX_PERSONAS] = {0};
    int opcion;

    printf("Nota: Solo se permiten letras y espacios en los campos de texto.\n");

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Crear persona\n");
        printf("2. Mostrar una persona\n");
        printf("3. Mostrar todas\n");
        printf("4. Guardar en archivo\n");
        printf("5. Cargar desde archivo\n");
        printf("6. Modificar persona\n");
        printf("7. Borrar persona\n");
        printf("8. Salir\n");

        opcion = leerEntero("Opcion: ");

        switch (opcion)
        {
        case 1:
        {
            int i;
            for (i = 0; i < MAX_PERSONAS; i++)
                if (!personas[i])
                    break;

            if (i == MAX_PERSONAS)
                printf("Limite alcanzado.\n");
            else
            {
                personas[i] = crearPersona();
                if (personas[i])
                    printf("Persona creada con ID %d.\n", personas[i]->id);
            }
            break;
        }

        case 2:
        {
            int pos = leerEntero("Numero de persona (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posicion invalida o vacia.\n");
            else
                mostrarPersona(personas[pos - 1], pos - 1);
            break;
        }

        case 3:
            for (int i = 0; i < MAX_PERSONAS; i++)
                mostrarPersona(personas[i], i);
            break;

        case 4:
            guardarEnArchivo(personas, MAX_PERSONAS);
            break;

        case 5:
            for (int i = 0; i < MAX_PERSONAS; i++)
            {
                if (personas[i])
                {
                    free(personas[i]);
                    personas[i] = NULL;
                }
            }
            cargarDesdeArchivo(personas, MAX_PERSONAS);
            break;

        case 6:
        {
            int pos = leerEntero("Numero de persona a modificar (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posicion invalida o vacia.\n");
            else
                modificarPersona(personas[pos - 1]);
            break;
        }

        case 7:
        {
            int pos = leerEntero("Numero de persona a borrar (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posicion invalida o vacia.\n");
            else
            {
                free(personas[pos - 1]);
                personas[pos - 1] = NULL;
                printf("Persona borrada.\n");
            }
            break;
        }

        case 8:
            printf("Saliendo...\n");
            for (int i = 0; i < MAX_PERSONAS; i++)
            {
                if (personas[i])
                {
                    free(personas[i]);
                    personas[i] = NULL;
                }
            }
            break;

        default:
            printf("Opcion no valida.\n");
        }

    } while (opcion != 8);

    return 0;
}
