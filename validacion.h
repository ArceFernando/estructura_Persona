#ifndef VALIDACION_H
#define VALIDACION_H

int leerEntero(const char *mensaje);
int leerEdad(const char *mensaje);
void leerCadena(char *cadena, int max);
void leerCadenaSoloLetras(char *destino, int max, const char *mensaje);
int esNumeroEntero(const char *cadena);
int esCadenaSoloLetras(const char *cadena);

#endif