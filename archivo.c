#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"

extern int ultimoID;

void guardarEnArchivo(Persona *personas[], int total)
{
    FILE *f = fopen(ARCHIVO_PERSONAS, "w");
    if (!f)
    {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        if (personas[i])
        {
            fprintf(f, "ID: %d\n", personas[i]->id);
            fprintf(f, "%s\n%s\n%d\n%s\n", personas[i]->nombre, personas[i]->apellido, personas[i]->edad, personas[i]->carrera);

            int count = 0;
            for (int j = 0; j < MAX_MATERIAS; j++)
                if (personas[i]->materias[j][0] != '\0')
                    count++;

            fprintf(f, "Materias: %d\n", count);
            for (int j = 0; j < count; j++)
                fprintf(f, "%s\n", personas[i]->materias[j]);

            fprintf(f, "---\n");
        }
    }

    fclose(f);
    printf("Personas guardadas en '%s'.\n", ARCHIVO_PERSONAS);
}

void cargarDesdeArchivo(Persona *personas[], int total)
{
    FILE *f = fopen(ARCHIVO_PERSONAS, "r");
    if (!f)
    {
        printf("Archivo '%s' no encontrado.\n", ARCHIVO_PERSONAS);
        return;
    }

    char buffer[100];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), f) && index < total)
    {
        Persona *p = (Persona *)malloc(sizeof(Persona));
        if (!p)
            break;

        sscanf(buffer, "ID: %d", &p->id);
        if (p->id > ultimoID)
            ultimoID = p->id;

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->nombre, buffer, MAX_NOMBRE);

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->apellido, buffer, MAX_APELLIDO);

        fgets(buffer, sizeof(buffer), f);
        p->edad = atoi(buffer);

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->carrera, buffer, MAX_CARRERA);

        fgets(buffer, sizeof(buffer), f);
        int numMaterias = 0;
        sscanf(buffer, "Materias: %d", &numMaterias);

        for (int i = 0; i < MAX_MATERIAS; i++)
            p->materias[i][0] = '\0';

        for (int i = 0; i < numMaterias && i < MAX_MATERIAS; i++)
        {
            fgets(buffer, sizeof(buffer), f);
            buffer[strcspn(buffer, "\n")] = '\0';
            strncpy(p->materias[i], buffer, MAX_MATERIA_NOMBRE - 1);
        }

        fgets(buffer, sizeof(buffer), f); // separador ---
        personas[index++] = p;
    }

    fclose(f);
    printf("%d persona(s) cargadas desde '%s'.\n", index, ARCHIVO_PERSONAS);
}
