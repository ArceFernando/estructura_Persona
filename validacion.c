#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacion.h"

void leerCadena(char *cadena, int max)
{
    fgets(cadena, max, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

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
        if (!isdigit(*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

int esCadenaSoloLetras(const char *cadena)
{
    while (*cadena)
    {
        if (!isalpha(*cadena) && !isspace(*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

int leerEntero(const char *mensaje)
{
    char buffer[100];
    int valor;
    while (1)
    {
        printf("%s", mensaje);
        leerCadena(buffer, sizeof(buffer));
        if (esNumeroEntero(buffer))
        {
            valor = atoi(buffer);
            return valor;
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }
}

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
