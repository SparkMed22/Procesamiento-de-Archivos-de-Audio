# Procesamiento de Audio

Este programa en C permite procesar archivos de audio, soportando tanto audio mono como estéreo, y utilizando pilas (implementadas con arreglos o listas enlazadas) para la manipulación de los datos.

\#\# Estructura del Proyecto

.  
├── include  
│ ├── boolean.h \# Definiciones de tipos booleanos (TRUE, FALSE).  
│ ├── confirm.h \# Macros para manejo de errores y aserciones.  
│ ├── metodos\_main.h \# Declaraciones de funciones para la entrada/salida y procesamiento principal.  
│ ├── pila.h \# Declaraciones de las funciones y estructuras de la pila (arreglo y lista enlazada).  
│ └── stereo.h \# Declaraciones de funciones y estructuras para el manejo de audio estéreo.  
├── src  
│ ├── main.c \# Punto de entrada del programa, maneja la lógica principal.  
│ ├── metodos\_main.c \# Implementaciones de las funciones de entrada/salida y procesamiento.  
│ ├── pila.c \# Implementaciones de las funciones de la pila.  
│ └── Stereo.c \# Implementaciones de las funciones de manejo de audio estéreo.  
├── test \# Contiene archivos de prueba.  
│ ├── input.dat \# Archivo de entrada de prueba para audio mono.  
│ ├── audio\_stereo.dat \# Archivo de entrada de prueba para audio estéreo.  
│ └── audio\_stereo.wav \# Otro archivo de prueba.  
├── Makefile \# Archivo para compilar el proyecto.  
├── Readme.MD \# Este archivo (documentación del proyecto).  
└── proyecto2.exe \# El ejecutable compilado.

\#\# Dependencias

\* Librerías estándar de C (stdio.h, stdlib.h, string.h).

\#\# Compilación

Para compilar el proyecto, puedes usar el \`Makefile\` incluido.  Abre una terminal en el directorio del proyecto y ejecuta:

\`\`\`bash  
make

Esto generará el ejecutable proyecto2.exe (o el nombre apropiado para tu sistema operativo).

## **Ejecución**

El programa se ejecuta desde la línea de comandos con los siguientes argumentos:

proyecto2.exe \-input \<archivo\_entrada\> \-output \<archivo\_salida\> \[-type \<array|list\>\] \[-channels \<mono|stereo\>\] \[-help\]

* \-input \<archivo\_entrada\>: Especifica el archivo de entrada de audio.  
* \-output \<archivo\_salida\>: Especifica el archivo de salida donde se guardará el audio procesado.  
* \-type \<array|list\>: (Opcional) Especifica la implementación de la pila a usar: array (arreglo dinámico) o list (lista enlazada). Por defecto es array.  
* \-channels \<mono|stereo\>: (Opcional) Especifica el tipo de audio: mono o stereo. Por defecto es mono.  
* \-help: (Opcional) Muestra la ayuda del programa.

**Ejemplos:**

* Procesar un archivo mono usando una pila de arreglos:  
  Bash  
  proyecto2.exe \-input entrada.dat \-output salida.dat \-type array \-channels mono

* Procesar un archivo estéreo usando una pila de listas enlazadas:  
  Bash  
  proyecto2.exe \-input stereo\_in.dat \-output stereo\_out.dat \-type list \-channels stereo

## **Funcionalidades**

1. **Entrada/Salida de Audio:**  
   * Lee datos de archivos de entrada en diferentes formatos.  
   * Escribe datos de audio procesados en archivos de salida.  
2. **Soporte Mono/Estéreo:**  
   * Procesa archivos de audio tanto mono como estéreo.  
3. **Implementación de Pilas:**  
   * Implementa pilas utilizando dos estructuras de datos:  
     * Arreglos dinámicos (APila).  
     * Listas enlazadas (LPila).  
   * Permite al usuario seleccionar la implementación de la pila en tiempo de ejecución.  
4. **Procesamiento de Audio:**  
   * Invierte el orden de las muestras de audio utilizando las pilas.  
5. **Manejo de Errores:**  
   * Incluye macros (confirm.h) para facilitar el manejo de errores y las aserciones.  
   * Reporta errores en la entrada de argumentos y en la lectura/escritura de archivos.

## **Estructuras de Datos Clave**

* Stereo (en stereo.h): Estructura para representar una muestra de audio estéreo (canal izquierdo y derecho).  
* APila (en pila.h): Estructura para la implementación de la pila con arreglos dinámicos.  
* LPila (en pila.h): Estructura para la implementación de la pila con listas enlazadas.

## **Notas Adicionales**

* El código está documentado con comentarios para facilitar la comprensión.  
* Se utilizan macros para mejorar la legibilidad y el mantenimiento del código.  
* Se incluye un manejo básico de errores, pero se puede ampliar para hacerlo más robusto.

## **Autores**

* Héctor Daniel Argüello Tejera (Implementación de Pila con arreglo dinámico)  
* Francisco David Medina Lourenzo (Implementación de Pila con lista ligada, funciones entradaTerminal).
