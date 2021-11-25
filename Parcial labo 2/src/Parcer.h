#include "Controller.h"

#ifndef PARCER_H_
#define PARCER_H_

int parser_LibroFromText(FILE *pFile, LinkedList *pArrayListLibro);
int parser_EditorialFromText(FILE *pFile, LinkedList *pArrayListEditorial);
int parser_GuardarListaFiltrada(FILE *pFile, LinkedList *pArrayListaFiltrada);

#endif /* PARCER_H_ */
