#ifndef VALIDACION_H
#define VALIDACION_H

#ifdef __cplusplus
extern "C"
{
#endif

// Tamaño fijo de buffer para lectura de cadenas
#define TAM_BUFFER 100

    // Funciones de lectura y validación
    void leerCadena(char *cadena, int max);
    int esNumeroEntero(const char *cadena);
    int esCadenaSoloLetras(const char *cadena);
    int leerEntero(const char *mensaje);
    int leerEdad(const char *mensaje);
    void leerCadenaSoloLetras(char *destino, int max, const char *mensaje);

#ifdef __cplusplus
}
#endif

#endif // VALIDACION_H
