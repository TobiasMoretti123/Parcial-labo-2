#include "Controller.h"
/// \fn int Controller_cargarArchivoLibro(LinkedList*)
/// \brief Carga el archivo de libros en modo texto este archivo debe ser en modo .csv
/// \param pArrayListLibro La lista a guardar el archivo
/// \return -1 si hubo error 0 si salio bien
int Controller_cargarArchivoLibro(LinkedList *pArrayListLibro) {
	FILE *pArchivo;
	int retorno;
	char path[20];
	retorno = -1;
	if (pArrayListLibro != NULL) {
		if (utn_getText(path, 20, "Ingrese nombre de archivo libro: ",
				"Nombre invalido ", 4) == 1) {
			pArchivo = fopen(path, "r");
			if (parser_LibroFromText(pArchivo, pArrayListLibro) == 0) {
				retorno = 0;
			}
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int Controller_cargarArchivoEditorial(LinkedList*)
/// \brief Carga el archivo de la editorial en modo texto este archivo debe ser en modo .csv
/// \param pArrayListEditorial La lista a guardar el archivo
/// \return -1 si hubo error 0 si salio bien
int Controller_cargarArchivoEditorial(LinkedList *pArrayListEditorial) {
	FILE *pArchivo;
	int retorno;
	char path[20];
	retorno = -1;
	if (pArrayListEditorial != NULL) {
		if (utn_getText(path, 20, "Ingrese nombre de archivo editorial: ",
				"Nombre invalido ", 4) == 1) {
			pArchivo = fopen(path, "r");
			if (parser_EditorialFromText(pArchivo, pArrayListEditorial) == 0) {
				retorno = 0;
			}
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int Controller_ordenarLista(LinkedList*)
/// \brief Ordena la lista por autor en orden descendente (A-Z)
/// \param pArrayListLibro La lista a ordenar
/// \return -1 si hubo error 0 si salio bien
int Controller_ordenarLista(LinkedList *pArrayListLibro) {
	int retorno;
	retorno = -1;
	if (ll_sort(pArrayListLibro, Libro_compareByAutor, 1) == 0) {
		retorno = 0;
	}
	return retorno;
}
/// \fn int Controller_mostrarLibros(LinkedList*, LinkedList*)
/// \brief Muestra un listado con todos los libros y sus editoriales
/// \param pArrayListLibro La lista de libros a mostrar
/// \param pArraylistEditorial La lista de editoriales a mostrar
/// \return -1 si hubo error 0 si salio bien
int Controller_mostrarLibros(LinkedList *pArrayListLibro,
		LinkedList *pArraylistEditorial) {
	eLibro *pAuxLibro;
	eEditorial *pAuxEditorial;
	int retorno;
	retorno = -1;
	if (pArrayListLibro != NULL && pArraylistEditorial != NULL) {
		printf(" __________ _______________ _______________ __________ ____________________ \n");
		printf("|ID Libro  |Titulo         |Autor          |Precio    |Editorial           |\n");
		for (int i = 0; i < ll_len(pArrayListLibro); i++) {
			pAuxLibro = (eLibro*) ll_get(pArrayListLibro, i);
			for (int j = 0; j < ll_len(pArraylistEditorial); j++) {
				pAuxEditorial = (eEditorial*) ll_get(pArraylistEditorial, j);
				if (Controller_print(pAuxLibro, pAuxEditorial) == 0) {
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/// \fn int Controller_saveAsText(char*, LinkedList*)
/// \brief Guarda un archivo en modo texto .csv
/// \param path El nombre del archivo a guardar o su ruta
/// \param pArrayListFiltrada La lista a guardar
/// \return -1 si hubo error 0 si salio bien
int Controller_saveAsText(char *path, LinkedList *pArrayListFiltrada) {
	FILE *pArchivo;
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListFiltrada != NULL && pArrayListFiltrada != NULL
			&& ll_isEmpty(pArrayListFiltrada) == 0) {
		pArchivo = fopen(path, "w");
		if (parser_GuardarListaFiltrada(pArchivo, pArrayListFiltrada) == 0) {
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int Controller_print(eLibro*, eEditorial*)
/// \brief Imprime un elemento de la lista de libros con su editorial
/// \param Libro El libro a imprimir
/// \param Editorial La editorial a imprimir
/// \return -1 si hubo error 0 si salio bien
int Controller_print(eLibro *Libro, eEditorial *Editorial) {
	int idLibro;
	char titulo[20];
	char autor[20];
	int precio;
	int idEditorial;
	int idEditorial2;
	char nombre[20];
	int retorno;
	retorno = -1;
	if (Editorial_getId(Editorial, &idEditorial) == 0
			&& Editorial_getNombre(Editorial, nombre) == 0
			&& Libro_getId(Libro, &idLibro) == 0
			&& Libro_getTitulo(Libro, titulo) == 0
			&& Libro_getAutor(Libro, autor) == 0
			&& Libro_getPrecio(Libro, &precio) == 0
			&& Libro_getIdEditorial(Libro, &idEditorial2) == 0) {
		if (idEditorial == idEditorial2) {
			printf("|%-10d|%-15s|%-15s|%-10d|%-20s|\n", idLibro, titulo, autor,
					precio, nombre);
		}
	}
	return retorno;
}
/// \fn int Controller_filter(LinkedList*)
/// \brief Filtra la lista de libros segun un parametro y guarda la lista en un archivo de texto
/// \param pArrayListLibro La lista a filtrar
/// \return -1 si hubo error 0 si salio bien
int Controller_filter(LinkedList *pArrayListLibro) {
	LinkedList *listaMinotauro;
	int retorno;
	retorno = -1;
	if (pArrayListLibro != NULL) {
		listaMinotauro = ll_filter(pArrayListLibro, Libro_isMinotauro);
		if (listaMinotauro != NULL) {
			Controller_saveAsText("Minotauro.csv", listaMinotauro);
			ll_deleteLinkedList(listaMinotauro);
			retorno = 0;
		}
	}
	return retorno;
}
