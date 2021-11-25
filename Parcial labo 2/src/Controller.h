#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Parcer.h"
#include "Libro.h"
#include "Editorial.h"
#include "utn.h"
#include "validaciones.h"

int Controller_cargarArchivoLibro(LinkedList *pArrayListLibro);
int Controller_cargarArchivoEditorial(LinkedList *pArrayListEditorial);
int Controller_ordenarLista(LinkedList *pArrayListLibro);
int Controller_mostrarLibros(LinkedList *pArrayListLibro,
		LinkedList *pArraylistEditorial);
int Controller_saveAsText(char *path, LinkedList *pArrayListFiltrada);
int Controller_print(eLibro *Libro, eEditorial *Editorial);
int Controller_filter(LinkedList *pArrayListLibro);

#endif /* CONTROLLER_H_ */
