# **Procesamiento de Archivos de Audio**

Este proyecto en C proporciona herramientas para procesar archivos de audio, permitiendo la lectura, manipulación e inversión de datos de audio. Soporta audio mono y estéreo, utilizando pilas (implementadas con arrays o listas enlazadas) para almacenar y manipular los datos.

---

## **Características**

* **Lectura de archivos de audio** desde archivos de entrada.
* **Almacenamiento en pilas**, con opción entre array dinámico o lista enlazada.
* **Procesamiento de audio mono y estéreo.**
* **Escritura de archivos de audio** tras el procesamiento.
* **Interfaz de línea de comandos** para configurar el comportamiento del programa.

---

## **Estructura del Proyecto**

* **`main.c`**: Punto de entrada del programa. Gestiona el flujo general.
* **`metodos_main.c` / `metodos_main.h`**: Funciones para procesar argumentos (`entradaTerminal`), leer archivos (`readArchivoEntrada`) y escribir archivos (`writeArchivoSalida`).
* **`pila.c` / `pila.h`**: Implementación de pilas con array dinámico y lista enlazada. Funciones: `push`, `pop`, `top`, `isEmpty`, `destruir`.
* **`Stereo.c` / `stereo.h`**: Define la estructura `Stereo`. Funciones para cargar audio en una pila (`cargarAudioEnPila`) e invertirlo y guardarlo (`guardarAudioInvertido`).
* **`confirm.h`**: Macros para manejo de errores y depuración (`CONFIRM_RETURN`, `CONFIRM_RETVAL`, etc.).
* **`boolean.h`**: Define constantes booleanas (`BOOLEAN`, `TRUE`, `FALSE`, `OK`, `ERROR`).

---

## **Compilación**

Este proyecto utiliza `make`. Para compilar:

```bash
make
```

Esto generará un ejecutable llamado `proyecto2`.

Para limpiar los archivos intermedios:

```bash
make clean
```

---

## **Uso**

El programa se ejecuta desde la línea de comandos:

```bash
./proyecto2 -input <archivo_entrada> -output <archivo_salida> [-type <array|list>] [-channels <mono|stereo>] [-help]
```

### Argumentos:

* `<archivo_entrada>`: Archivo con los datos de audio.
* `<archivo_salida>`: Archivo donde se escribirá el audio procesado.
* `-type <array|list>`: (Opcional) Tipo de pila: `array` (por defecto) o `list`.
* `-channels <mono|stereo>`: (Opcional) Tipo de audio: `mono` (por defecto) o `stereo`.
* `-help`: (Opcional) Muestra el mensaje de ayuda.

### Valores por defecto:

* `Type`: `array`
* `Channels`: `mono`
* `Input`: `../test/input.dat`
* `Output`: `output.dat`

---

## **Ejemplos de Uso**

Procesar archivo `audio.txt` como mono con pila `array`:

```bash
./proyecto2 -input audio.txt -output salida.txt -channels mono -type array
```

Procesar archivo estéreo con pila de lista enlazada:

```bash
./proyecto2 -input estereo.dat -output invertido.dat -channels stereo -type list
```

Usar todos los valores por defecto:

```bash
./proyecto2
```

---

## **Notas Importantes**

* El programa incluye manejo básico de errores, pero se puede mejorar.
* El rendimiento depende del tamaño del archivo y del tipo de pila.
* Asegúrese de que los archivos de entrada estén en el formato esperado: texto plano con un valor numérico por línea representando muestras de audio.

---

## **Autores**

* Héctor Daniel Argüello Tejera — Implementación de pila con arreglo dinámico.
* Francisco David Medina Lourenzo — Implementación de pila con lista enlazada y funcionalidades adicionales.

---
