#ifndef METODOS_MAIN_H
#define METODOS_MAIN_H


// Archivos del Sistema
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//Archivos Propios
#include "boolean.h"
#include "pila.h"


BOOLEAN entradaTerminal(int argc, char **argv, char **input, char **output, char **type, char **channels);
BOOLEAN readArchivoEntrada(char *input, char *tipo_lpila, LPila *lp, APila *ap, int *count, long *sampleRate);
BOOLEAN writeArchivoSalida(char *output_file, char *tipo_lpila, LPila lp, APila ap, int *count, long sampleRate);
        
#endif 