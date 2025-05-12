#ifndef PILA_H
#define PILA_H

// Archivos del Sistema
#include <stdio.h>
#include <stdlib.h>

// Archivos propios
#include "boolean.h"
#include "confirm.h"

/**
 * Implementacion de Pila con arreglo dinamico
 * Alumno: Héctor Daniel Argüello Tejera
 */

typedef struct __APila{
	void** arr;
	int tam;
	int sp;
}_APila;

typedef _APila* APila;

APila apila_crear(int tamInicial);
BOOLEAN apila_push(APila p, void* valor);
BOOLEAN apila_pop(APila p, void** retval);
BOOLEAN apila_top(APila p, void** retval);
BOOLEAN apila_isEmpty(APila p);
BOOLEAN apila_destruir(APila p);


/**
 * Implementacion de Pila con lista ligada 
 * Alumno: Francisco David Medina Lourenzo
 */
typedef struct _Nodo{
	struct _Nodo *sig;
	void* valor;
}Nodo;

typedef Nodo* LPila;
LPila lpila_crear();
BOOLEAN lpila_push(LPila pila, void* valor);
BOOLEAN lpila_pop(LPila pila, void** valor);
BOOLEAN lpila_top(LPila pila, void** valor);
BOOLEAN lpila_isEmpty(LPila pila);
BOOLEAN lpila_destruir(LPila pila);

#endif