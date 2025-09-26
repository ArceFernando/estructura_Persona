#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacion.h"

// Leer cadena de forma segura, evitando desbordamientos y limpiando stdin si es necesario
void leerCadena(char *cadena, int max)
{
    if (fgets(cadena, max, stdin) != NULL)
    {
        size_t len = strlen(cadena);
        if (len > 0 && cadena[len - 1] == '\n')
        {
            cadena[len - 1] = '\0'; // eliminar salto de linea
        }
        else
        {
            // Limpiar stdin si la entrada fue mas larga que el buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    }
    else
    {
        // Si fgets falla, aseguramos una cadena vacia
        cadena[0] = '\0';
    }
}

// Verifica si una cadena representa un numero entero valido
int esNumeroEntero(const char *cadena)
{
    if (*cadena == '\0')
        return 0;

    if (*cadena == '-' || *cadena == '+')
        cadena++;

    if (*cadena == '\0')
        return 0;

    while (*cadena)
    {
        if (!isdigit((unsigned char)*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

// Verifica si una cadena contiene solo letras y espacios
int esCadenaSoloLetras(const char *cadena)
{
    while (*cadena)
    {
        if (!isalpha((unsigned char)*cadena) && !isspace((unsigned char)*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

// Leer un número entero desde consola, con validación
int leerEntero(const char *mensaje)
{
    char buffer[100];
    long valor;
    char *endptr;

    while (1)
    {
        printf("%s", mensaje);
        leerCadena(buffer, sizeof(buffer));

        valor = strtol(buffer, &endptr, 10);

        if (endptr == buffer || *endptr != '\0')
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
        else
        {
            return (int)valor;
        }
    }
}

// Leer una edad válida entre 0 y 120
int leerEdad(const char *mensaje)
{
    int edad;
    while (1)
    {
        edad = leerEntero(mensaje);
        if (edad >= 0 && edad <= 120)
            return edad;
        else
            printf("Edad invalida. Debe estar entre 0 y 120.\n");
    }
}

// Leer una cadena que solo contenga letras y espacios
void leerCadenaSoloLetras(char *destino, int max, const char *mensaje)
{
    while (1)
    {
        printf("%s", mensaje);
        leerCadena(destino, max);

        if (strlen(destino) == 0)
        {
            printf("No puede estar vacio. Intente de nuevo.\n");
        }
        else if (!esCadenaSoloLetras(destino))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            return;
        }
    }
}