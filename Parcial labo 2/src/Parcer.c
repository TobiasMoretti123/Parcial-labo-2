#include "Parcer.h"
/// \fn int parser_LibroFromText(FILE*, LinkedList*)
/// \brief Carga el archivo de libro en formato por comas .csv y lo añade a una lista
/// de linkedList
/// \param pFile el archivo a cargar
/// \param pArrayListLibro la lista en donde añadirlo
/// \return -1 si hubo error 0 si salio bien
int parser_LibroFromText(FILE *pFile, LinkedList *pArrayListLibro) {
	eLibro *pAux;
	int r;
	int retorno;
	char id[50];
	char titulo[50];
	char autor[50];
	char precio[50];
	char idEditorial[50];
	retorno = -1;
	if (pFile != NULL && pArrayListLibro != NULL) {
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor,
				precio, idEditorial);
		do {
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo,
					autor, precio, idEditorial);
			if (r == 5) {
				pAux = Libro_ParametrosParametrisados(id, titulo, autor, precio,
						idEditorial);
				if (ll_add(pArrayListLibro, pAux) == -1) {
					Libro_delete(pAux);
				} else {
					retorno = 0;
				}
			} else
				break;
		} while (!feof(pFile));
	}
	return retorno;
}
/// \fn int parser_EditorialFromText(FILE*, LinkedList*)
/// \brief Carga el archivo de editorial en formato por comas .csv y lo añade a una lista
/// de linkedList
/// \param pFile el archivo a cargar
/// \param pArrayListEditorial la lista en donde añadirlo
/// \return -1 si hubo error 0 si salio bien
int parser_EditorialFromText(FILE *pFile, LinkedList *pArrayListEditorial) {
	eEditorial *pAux;
	int r;
	int retorno;
	char id[50];
	char nombre[50];
	retorno = -1;
	if (pFile != NULL && pArrayListEditorial != NULL) {
		r = fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
		do {
			r = fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
			if (r == 2) {
				pAux = Editorial_ParametrosParametrisados(id, nombre);
				if (ll_add(pArrayListEditorial, pAux) == -1) {
					Editorial_delete(pAux);
				} else {
					retorno = 0;
				}
			} else
				break;
		} while (!feof(pFile));
	}
	return retorno;
}
/// \fn int parser_GuardarListaFiltrada(FILE*, LinkedList*)
/// \brief Guarda una lista filtrada a modo de archivo en formato por comas .csv
/// \param pFile El archivo a guardar
/// \param pArrayListaFiltrada La lista filtrada para guardar
/// \return -1 si hubo error 0 si salio bien
int parser_GuardarListaFiltrada(FILE *pFile, LinkedList *pArrayListaFiltrada) {
	eLibro *pAux;
	int retorno;
	int i;
	int id;
	char titulo[20];
	char autor[20];
	int precio;
	int len;
	len = ll_len(pArrayListaFiltrada);
	fprintf(pFile, "idLibro,titulo,autor,precio\n");
	for (i = 0; i < len; i++) {
		pAux = (eLibro*) ll_get(pArrayListaFiltrada, i);
		if (pAux == NULL) {
			break;
		}
		if (Libro_getTitulo(pAux, titulo) == 0
				&& Libro_getAutor(pAux, autor) == 0
				&& Libro_getPrecio(pAux, &precio) == 0
				&& Libro_getId(pAux, &id) == 0) {
			fprintf(pFile, "%d,%s,%s,%d\n", id, titulo, autor, precio);
		}
	}
	if (i == len) {
		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}
