#include "Controller.h"
#ifndef EDITORIAL_H_
#define EDITORIAL_H_
typedef struct {
	int idEditorial;
	char nombre[20];
} eEditorial;

eEditorial* Editorial_newParametros();
eEditorial* Editorial_ParametrosParametrisados(char* idEditorial,char* nombre);
void Editorial_delete(eEditorial *this);

int Editorial_setId(eEditorial *this, int id);
int Editorial_getId(eEditorial *this, int *id);

int Editorial_setNombre(eEditorial *this, char *nombre);
int Editorial_getNombre(eEditorial *this, char *nombre);

#endif /* EDITORIAL_H_ */
