// Archivos propios
#include "../include/pila.h"
/**
 * Implementacion de Pila con arreglo dinamico
 * Alumno: Héctor Daniel Argüello Tejera
 */

APila apila_crear(int tamInicial){
	CONFIRM_RETVAL(tamInicial > 0, NULL);
	APila pila = (APila)malloc(sizeof(_APila));
	CONFIRM_RETVAL(pila != NULL,NULL);

	pila->arr = (void**)malloc(sizeof(void**)*tamInicial);

	if (pila->arr == NULL)
	{
		free(pila);
		GlobalReportarError(__FILE__,__LINE__);
		return NULL; 
	}
	
	pila->tam = tamInicial; 
	pila->sp = 0;

	return pila;
}

void apila_realloc(APila pila){
	CONFIRM_RETURN(pila != NULL);
	int new_tamano = pila->tam*2;
	void** new_arr = realloc(pila->arr,sizeof(void*)*new_tamano); 
	CONFIRM_RETURN(new_arr != NULL);
	pila->tam = new_tamano;
	pila->arr = new_arr;
}

BOOLEAN apila_push(APila pila, void* valor){
	
	if (pila->sp >=  pila->tam)
	{
		//printf("Ampliando Memoria.....\n ");
		apila_realloc(pila);
		CONFIRM_RETVAL(pila->arr!= NULL,ERROR);
		//printf("Memoria Ampliada con éxito\n");
	}
	pila->arr[pila->sp++] = valor;
	return OK; 
}


BOOLEAN apila_pop(APila pila, void** retval){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	CONFIRM_RETVAL(retval != NULL,ERROR);
	CONFIRM_RETVAL(pila->sp > 0,ERROR);	
	*retval = pila->arr[pila->sp-1];
	pila->arr[pila->sp-1] = NULL; 
	pila->sp--;
	return OK; 
}


BOOLEAN apila_top(APila pila, void** retval){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	CONFIRM_RETVAL(retval != NULL,ERROR);
	CONFIRM_RETVAL(pila->sp > 0,ERROR);	
	*retval = pila->arr[pila->sp-1];
	return OK; 
}
BOOLEAN apila_isEmpty(APila pila){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	return pila->sp == 0;
}
BOOLEAN apila_destruir(APila pila){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	free(pila->arr);
	free(pila);
	return OK; 
}

/**
 * Implementacion de Pila con lista ligada 
 * Alumno: Francisco David Medina Lourenzo
 */

LPila lpila_crear(){
	LPila pila = malloc(sizeof(Nodo));
	CONFIRM_RETVAL(pila != NULL,ERROR);
	pila->sig = NULL; 
	pila->valor = NULL;
	return pila; 
}
BOOLEAN lpila_push(LPila pila, void* valor){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	CONFIRM_RETVAL(nodo != NULL,ERROR);
	nodo->sig = pila->sig;
	nodo->valor = valor;
	pila->sig= nodo;
	return OK; 
}
BOOLEAN lpila_pop(LPila pila, void** valor){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	CONFIRM_RETVAL(valor != NULL,ERROR);
	CONFIRM_RETVAL(pila->sig != NULL,ERROR);
	
	Nodo *temp = pila->sig;
	*valor = temp->valor;
	pila->sig = temp->sig; 
	free(temp);
	return OK; 
}
BOOLEAN lpila_top(LPila pila, void** valor){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	CONFIRM_RETVAL(valor != NULL,ERROR);
	CONFIRM_RETVAL(pila->sig != NULL,ERROR);

	*valor = pila->sig->valor;
	return OK; 
}


BOOLEAN lpila_isEmpty(LPila pila){
	CONFIRM_RETVAL(pila != NULL,ERROR);
	return pila->sig == NULL ? OK : ERROR;; 
}
BOOLEAN lpila_destruir(LPila pila){
	CONFIRM_RETVAL(pila != NULL,ERROR);

	Nodo *nodo = pila->sig; 
	Nodo *temp; 
	while (nodo != NULL)
	{
		temp = nodo; 
		nodo = nodo->sig;
		free(temp);
	}
	free(pila);

	return OK; 
}