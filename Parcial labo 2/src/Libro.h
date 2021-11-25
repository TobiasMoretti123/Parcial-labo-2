#include "Controller.h"
#include "Editorial.h"
#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct {
	int idLibro;
	char titulo[20];
	char autor[20];
	int precio;
	int idEditorial;
} eLibro;

eLibro* Libro_newParametros();
eLibro* Libro_ParametrosParametrisados(char* idLibro, char* titulo, char* autor, char* precio,char* idEditorial);
void Libro_delete(eLibro *this);

int Libro_setId(eLibro *this, int id);
int Libro_getId(eLibro *this, int *id);

int Libro_setTitulo(eLibro *this, char *titulo);
int Libro_getTitulo(eLibro *this, char *titulo);

int Libro_setAutor(eLibro *this, char *autor);
int Libro_getAutor(eLibro *this, char *autor);

int Libro_setIdEditorial(eLibro *this, int idEditorial);
int Libro_getIdEditorial(eLibro *this, int *idEditorial);

int Libro_setPrecio(eLibro *this, int precio);
int Libro_getPrecio(eLibro *this, int *precio);

int Libro_compareByAutor(void *libro, void *libro2);
int Libro_isMinotauro(void *libro);
int Libro_mapeado(void *this);

#endif /* LIBRO_H_ */
