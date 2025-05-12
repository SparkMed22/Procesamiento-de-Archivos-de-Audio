#ifndef STEREO_H
#define STEREO_H

// Archivos del Sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Archivo propios
#include "boolean.h"
#include "confirm.h"
#include "pila.h"

typedef struct _stereo
{
    short izquierdo;
    short derecho;
} Stereo;

BOOLEAN cargarAudioEnPila(const char* input_file, char* tipo_lpila, LPila *lp, APila *ap);

BOOLEAN guardarAudioInvertido(char *archivoSalida, char *tipo_lpila, LPila lp, APila ap);


#endif 