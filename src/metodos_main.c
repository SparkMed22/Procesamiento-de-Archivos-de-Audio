// Archivos propios
#include "../include/metodos_main.h"
#include "../include/confirm.h"
#include "../include/pila.h"

/**
 * Condicional de preprocesador
 * Evitar  warning en VScode
 * Alumno: Francisco David Medina Lourenzo
 */
#ifdef _MSC_VER
    #pragma warning(disable : 4996)
#endif

/**
 * Implementacion de GlobalReportarError
 */
void GlobalReportarError(char *pszFile, int iLine)
{
    fprintf(stderr, "Error en %s:%d\n", pszFile, iLine);
}
/**
 * Metodo generado por la profesora
 */
void printFormaDeUso()
{
    printf("Forma de uso minimo: \n");
    printf(">proyecto2.exe -input entrada.dat -output salida.dat\n");
}

/**
 * Implementacion de METODOS_MAIN_H
 */

/**
 * Implementacion de Pila con lista ligada 
 * Alumno: Francisco David Medina Lourenzo
 */
BOOLEAN entradaTerminal(int argc, char **argv, char **input, char **output, char **type, char **channels)
{
    // Variables para almacenar los aargumentos de entrada y salida
    *input = "../test/input.dat";
    *output = "output.dat";
    // Variables con doble opcion  -type array|list -channels mono|stereo
    *type = "array";
    *channels = "mono";


    for (size_t i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-input") == 0 && i + 1 < argc)
        {
            *input = argv[++i];
        }
        else if (strcmp(argv[i], "-output") == 0 && i + 1 < argc)
        {
            *output = argv[++i];
        }
        else if (strcmp(argv[i], "-type") == 0 && i + 1 < argc)
        {
            char *val = argv[++i];
            if (strcmp(val, "array") == 0 || strcmp(val, "list") == 0)
                *type = val;
            else
                printf("Advertencia: valor inválido para -type. Usando 'array' por defecto.\n");
        }
        else if (strcmp(argv[i], "-channels") == 0 && i + 1 < argc)
        {
            char *val = argv[++i];
            if (strcmp(val, "mono") == 0 || strcmp(val, "stereo") == 0)
                *channels = val;
            else
                printf("Advertencia: valor inválido para -channels. Usando 'mono' por defecto.\n");
        }
        else if (strcmp(argv[i], "-help") == 0)
        {
            printf("Usage: -input <input_file> -output <output_file> [-type <array|list>] [-channels <mono|stereo>]\n");
            exit(0);
        }
    }
    // Validación especial para el input rechazado
    if (strcmp(*input, "../test/input.dat") == 0)
    {
        printf("Advertencia: valor inválido para -input. Usando 'input.dat' por defecto.\n");
        *input = "test/input.dat";
    }

    if (strcmp(*output, "output.dat") == 0)
    {
        printf("Advertencia: valor inválido para -output. Usando 'output.dat' por defecto.\n");
        *output = "output.dat";
    }

    // Mostrar configuración final
    printf("Input: %s\n", *input);
    printf("Output: %s\n", *output);
    printf("Type: %s\n", *type);
    printf("Channels: %s\n", *channels);

    char res[10];
    printf("Quiere continuar (s/n):");
    scanf("%9s", res);
    if (res[0] == 'n' || res[0] == 'N')
    {
        printf("Terminando el programa.\n");
        exit(0);
    }
    if (!*input || !*output)
    {
        fprintf(stderr,"Error: input o output no funciona\n");
    }
    
    return OK;
}


BOOLEAN readArchivoEntrada(char *input, char *tipo_lpila, LPila *lp, APila *ap, int *count, long *sampleRate)
{
    printf("Testeando entrada: %s ", input);
    FILE *fd = fopen(input, "r");
    if (!fd)
    {
        printf("ERROR: No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    if (strcmp(tipo_lpila, "array") == 0)
        *ap = apila_crear(100);
    else
        *lp = lpila_crear();

    if (NULL == *lp && NULL == *ap)
    {
        printf("error al crear la pila \n ");
        fclose(fd);
        assert(0);
        return EXIT_SUCCESS;
    }
    /*leer cabecera del archivo*/
    char str[100];
    char str1[500];
    int cont = 1;
    char strTimeStep[100];
    fscanf(fd, "%s%s%s%ld", str, str, str, sampleRate);
    printf("; sample Rate %ld \n", *sampleRate);
    /*leer comentarios dejados por el programa de conversion*/
    fgets(str1, 500, fd);
    /*ignorar comentarios
    printf("fgets:%s\n",str1);*/
    while (!feof(fd) && cont == 1)
    {
        char c = fgetc(fd);
        if (c == ';')
        {
            fgets(str1, 500, fd);
        }
        else
        {
            cont = 0;
        }
    }

    while (!feof(fd))
    {
        /*usamos malloc para reservar esta memoria y no perder el dato como en una variable local
        notese que si se usa una variable local el dato se perderia al salir del bloque while*/
        char *strData = (char *)malloc(sizeof(char) * 100); /*tamanho 100, para evitar complejidad al proyecto*/
        fscanf(fd, "%s%s", strTimeStep, strData);
        if (feof(fd))
        {
            free(strData);
            break;
        }

        if (strlen(strData) > 0)
        {
            if (strcmp(tipo_lpila, "array") == 0)
            {
                if (ERROR == apila_push(*ap, strData))
                {
                    printf("error al cargar la pila");
                    assert(0);
                }
            }
            else
            {
                if (ERROR == lpila_push(*lp, strData))
                {
                    printf("error al cargar la pila");
                    assert(0);
                }
            }
        }
        (*count)++;
    }

    fclose(fd);
    return OK; 
}

BOOLEAN writeArchivoSalida(char *output_file, char *tipo_lpila, LPila lp, APila ap, int *count, long sampleRate)
{
    printf("%d samples in file\n", *count);

    FILE *fd2 = fopen(output_file, "w");
    if (NULL != fd2)
    {
        int numSteps = 0;
        char *strData; /*aqui el dato va a ser referenciado a esta direccion (puntero a char) */
        fprintf(fd2, "; Sample Rate %ld\n", sampleRate);

        if (strcmp(tipo_lpila, "array") == 0)
        {
            while (!apila_isEmpty(ap))
            {
                if (ERROR == apila_pop(ap, (void **)&strData))
                {
                    printf("error al sacar de la pila");
                    assert(0);
                }
                else
                {
                    fprintf(fd2, "%f\t%s\n", (double)numSteps / sampleRate, strData);
                    numSteps++;
                    free(strData); /* liberamos ese malloc hecho dentro del while*/
                }
            }
        }
        else
        {
            while (!lpila_isEmpty(lp))
            {
                if (ERROR == lpila_pop(lp, (void **)&strData))
                {
                    printf("error al sacar de la pila");
                    assert(0);
                }
                else
                {
                    fprintf(fd2, "%f\t%s\n", (double)numSteps / sampleRate, strData);
                    numSteps++;
                    free(strData); /* liberamos ese malloc hecho dentro del while*/
                }
            }
        }

        fclose(fd2);
    }
    if (strcmp(tipo_lpila, "array") == 0)
    {
        if (apila_destruir(ap) == ERROR)
        {
            printf("error al sacar de la pila");
            assert(0);
        }
    }
    else
    {
        if (lpila_destruir(lp) == ERROR)
        {
            printf("error al sacar de la pila");
            assert(0);
        }
    }
    return OK; 
}