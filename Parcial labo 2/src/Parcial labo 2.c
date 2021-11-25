#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Editorial.h"
#define OPCIONES 6
int main(void) {
	setbuf(stdout, NULL);
	LinkedList *listaLibro;
	LinkedList *listaEditorial;
	int banderaEditorial;
	int banderaLibro;
	int opciones;
	listaLibro = ll_newLinkedList();
	listaEditorial = ll_newLinkedList();
	banderaEditorial = 0;
	banderaLibro = 0;
	do {
		if (utn_getInt(&opciones, 2,
				"1.Leer archivo libro\n2.Leer archivo editorial\n3.Ordenar lista por autor\n4.Imprimir libros\n5.Filtrar por MINOTAURO\n6.Salir\nIngrese opcion: ",
				"Opcion invalida ", 1, 6, 4, 0) != 1) {
			break;
		}
		switch (opciones) {
		case 1:
			if (Controller_cargarArchivoLibro(listaLibro) == 0) {
				printf("Archivo libro cargado con exito\n");
				banderaLibro = 1;
			}
			break;
		case 2:
			if (Controller_cargarArchivoEditorial(listaEditorial) == 0) {
				printf("Archivo editorial cargado con exito\n");
				banderaEditorial = 1;
			}
			break;
		case 3:
			if (banderaEditorial == 1 && banderaLibro == 1) {
				if (Controller_ordenarLista(listaLibro) == 0) {
					printf("Lista ordenada correctamente\n");
				}
			} else {
				printf("Debe cargar ambos archivos antes de ordenar\n");
			}
			break;
		case 4:
			if (banderaEditorial == 1 && banderaLibro == 1) {
				Controller_mostrarLibros(listaLibro, listaEditorial);
			} else {
				printf("Debe cargar ambos archivos antes de mostrar\n");
			}
			break;
		case 5:
			if (banderaEditorial == 1 && banderaLibro == 1) {
				if (Controller_filter(listaLibro) == 0) {
					printf("Lista filtrada guardada en Minotauro.csv\n");
				}
			} else {
				printf("No puede filtrar si no hay ningun archivo cargado\n");
			}
			break;
		case 6:
			ll_deleteLinkedList(listaLibro);
			ll_deleteLinkedList(listaEditorial);
			printf("Usted salio del servicio\n");
			break;
		}
	} while (opciones < OPCIONES);
	return 0;
}
