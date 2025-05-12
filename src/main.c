// Archivos del Sistema
#include <string.h>

// Archivos Propios
#include "../include/metodos_main.h"
#include "../include/stereo.h"
#include "../include/pila.h"

int main(int argc, char **argv)
{
    // Variables para almacenar los aargumentos de entrada y salida
    char *input_file = "../test/input.dat";
    char *output_file = "output.dat";
    // Variables con doble opcion  -type array|list -channels mono|stereo
    char *tipo_lpila = "array";
    char *channels = "mono";

    long sampleRate = 0;
    int count = 0;
    LPila lp = NULL;
    APila ap = NULL;

    // Llamada a la función para procesar los argumentos de entrada
    entradaTerminal(argc, argv, &input_file, &output_file, &tipo_lpila, &channels);

    if (strcmp(channels, "mono") == 0 )
    {
        readArchivoEntrada(input_file, tipo_lpila, &lp, &ap, &count, &sampleRate);
        writeArchivoSalida(output_file, tipo_lpila, lp, ap, &count, sampleRate);
    }
    else
    {
        cargarAudioEnPila(input_file, tipo_lpila, &lp, &ap);
        guardarAudioInvertido(output_file, tipo_lpila, lp, ap);
    }

    return 0;
}