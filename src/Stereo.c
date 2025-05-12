#include "../include/stereo.h"

BOOLEAN cargarAudioEnPila(const char *input_file, char *tipo_lpila, LPila *lp, APila *ap)
{

    FILE *file = fopen(input_file, "rb");
    if (!file)
    {
        printf("ERROR: No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    if (strcmp(tipo_lpila, "array") == 0)
        *ap = apila_crear(100);
    else
        *lp = lpila_crear();

    Stereo stereo;
    while (fread(&stereo, sizeof(Stereo), 1, file) == 1)
    {

        Stereo *_stereo = (Stereo *)malloc(sizeof(Stereo));

        *_stereo = stereo;
        if (strcmp(tipo_lpila, "array") == 0)
        {

            if (apila_push(*ap, _stereo) == ERROR)
            {
                fprintf(stderr, "Error al insertar en la pila (array)\n");
                free(_stereo);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (lpila_push(*lp, _stereo) == ERROR)
            {
                fprintf(stderr, "Error al insertar en la pila (lista)\n");
                free(_stereo);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
    return OK;
}

BOOLEAN guardarAudioInvertido(char *archivoSalida, char *tipo_lpila, LPila lp, APila ap)
{
    FILE *out = fopen(archivoSalida, "wb");
    if (!out)
    {
        perror("No se pudo abrir el archivo de salida");
        return ERROR;
    }

    void *dato;
    BOOLEAN result = OK;

    if (strcmp(tipo_lpila, "array") == 0)
    {
        while (!apila_isEmpty(ap))
        {
            if (apila_pop(ap, &dato) == OK)
            {
                Stereo *sample = (Stereo *)dato;
                if (fwrite(sample, sizeof(Stereo), 1, out) != 1)
                {
                    perror("Error al escribir la muestra de audio");
                    result = ERROR; // Indica que hubo un error
                    break;          // Salir del bucle si falla la escritura
                }
                free(sample);
            }
            else
            {
                fprintf(stderr, "Error al extraer de la pila (array)\n");
                result = ERROR;
                break;
            }
        }
    }
    else
    {
        while (!lpila_isEmpty(lp))
        {
            if (lpila_pop(lp, &dato) == OK)
            {
                Stereo *sample = (Stereo *)dato;
                if (fwrite(sample, sizeof(Stereo), 1, out) != 1)
                {
                    perror("Error al escribir la muestra de audio");
                    result = ERROR;
                    break;
                }
                free(sample);
            }
            else
            {
                fprintf(stderr, "Error al extraer de la pila (lista)\n");
                result = ERROR;
                break;
            }
        }
    }

    fclose(out);
    return result;
}