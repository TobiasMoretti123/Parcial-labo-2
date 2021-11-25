#include "Libro.h"
/// \fn eLibro Libro_newParametros*()
/// \brief Le pone parametros en 0 a la entidad libro utilizando memoria dinamica
/// \return El puntero al dato parametrizado en memoria dinamica
eLibro* Libro_newParametros() {
	eLibro *pLibro;
	pLibro = (eLibro*) calloc(sizeof(eLibro), 1);
	return pLibro;
}
/// \fn eLibro Libro_ParametrosParametrisados*(char*, char*, char*, char*, char*)
/// \brief Setea los parametros de la entidad libro segun los parametros pasados como char
/// \param idLibro El string con la idLibro
/// \param titulo El string con el titulo
/// \param autor El string con el autor
/// \param precio El string con el precio
/// \param idEditorial El stringo con el idEditorial
/// \return El puntero al dato parametrizado en memoria dinamica
eLibro* Libro_ParametrosParametrisados(char *idLibro, char *titulo, char *autor,
		char *precio, char *idEditorial) {
	eLibro *pLibro;
	pLibro = Libro_newParametros();
	if (pLibro != NULL && idLibro != NULL && titulo != NULL && autor != NULL
			&& precio != NULL && idEditorial != NULL) {
		if (Libro_setId(pLibro, atoi(idLibro)) == -1
				|| Libro_setTitulo(pLibro, titulo) == -1
				|| Libro_setAutor(pLibro, autor) == -1
				|| Libro_setPrecio(pLibro, atoi(precio)) == -1
				|| Libro_setIdEditorial(pLibro, atoi(idEditorial)) == -1) {
			Libro_delete(pLibro);
		}
	}
	return pLibro;
}
/// \fn void Libro_delete(eLibro*)
/// \brief Libera espacio en memoria dinamica de un tipo de dato de eLibro
/// \param this El puntero a ser liberado
void Libro_delete(eLibro *this) {
	if (this != NULL) {
		free(this);
	}
}
/// \fn int Libro_setId(eLibro*, int)
/// \brief Setea el id de la entidad eLibro
/// \param this La entidad a ser seteada
/// \param id El id a ser seteado
/// \return -1 si hubo error 0 si salio bien
int Libro_setId(eLibro *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id > 0) {
		this->idLibro = id;
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_getId(eLibro*, int*)
/// \brief Obtengo un id de la entidad eLibro
/// \param this La entidad a ser leida
/// \param id El id a obtener
/// \return -1 si hubo error 0 si salio bien
int Libro_getId(eLibro *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->idLibro;
		retorno = 0;
	}

	return retorno;
}
/// \fn int Libro_setTitulo(eLibro*, char*)
/// \brief Setea un titulo a la entidad eLibro
/// \param this La entidad a ser seteada
/// \param titulo El titulo a setear
/// \return -1 si hubo error 0 si salio bien
int Libro_setTitulo(eLibro *this, char *titulo) {
	int retorno;
	retorno = -1;
	if (this != NULL && titulo != NULL) {
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_getTitulo(eLibro*, char*)
/// \brief Obtengo en titulo de la entidad eLibro
/// \param this El libro a leer para obtener el titulo
/// \param titulo El titulo que quiero obtener
/// \return -1 si hubo error 0 si salio bien
int Libro_getTitulo(eLibro *this, char *titulo) {
	int retorno;
	retorno = -1;
	if (this != NULL && titulo != NULL) {
		strcpy(titulo, this->titulo);
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_setAutor(eLibro*, char*)
/// \brief Setea un autor en el entidad eLibro
/// \param this El libro a ser seteado
/// \param autor El autor a ser seteado
/// \return -1 si hubo error 0 si salio bien
int Libro_setAutor(eLibro *this, char *autor) {
	int retorno;
	retorno = -1;
	if (this != NULL && autor != NULL) {
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_getAutor(eLibro*, char*)
/// \brief Obtiene un autor de la entidad eLibro
/// \param this El libro a ser obtenido el autor
/// \param autor El autor a obtener
/// \return -1 si hubo error 0 si salio bien
int Libro_getAutor(eLibro *this, char *autor) {
	int retorno;
	retorno = -1;
	if (this != NULL && autor != NULL) {
		strcpy(autor, this->autor);
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_setIdEditorial(eLibro*, int)
/// \brief Setea el idEditorial del dato eLibro
/// \param this El libro a setear
/// \param idEditorial La idEditorial a ser seteada
/// \return -1 si hubo error 0 si salio bien
int Libro_setIdEditorial(eLibro *this, int idEditorial) {
	int retorno;
	retorno = -1;
	if (this != NULL && idEditorial > 0) {
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_getIdEditorial(eLibro*, int*)
/// \brief Obtiene el idEditorial del dato eLibro
/// \param this El libro a ser leido para obtener el idEditorial
/// \param idEditorial El idEditorial a ser obtenido
/// \return -1 si hubo error 0 si salio bien
int Libro_getIdEditorial(eLibro *this, int *idEditorial) {
	int retorno;
	retorno = -1;
	if (this != NULL && idEditorial != NULL) {
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}
/// \fn int Libro_setPrecio(eLibro*, int)
/// \brief Setea el precio de la entidad eLibro
/// \param this El libro a setear
/// \param precio El precio a setear
/// \return -1 si hubo error 0 si salio bien
int Libro_setPrecio(eLibro *this, int precio) {
	int retorno;
	retorno = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/// \fn int Libro_getPrecio(eLibro*, int*)
/// \brief Obtiene el precio del dato eLibro
/// \param this El libro a ser leido para obtener el precio
/// \param precio El precio a obtener
/// \return -1 si hubo error 0 si salio bien
int Libro_getPrecio(eLibro *this, int *precio) {
	int retorno;
	retorno = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}
/// \fn int Libro_compareByAutor(void*, void*)
/// \brief Compara con punteros el autor del libro
/// \param libro El primer libro a comparar
/// \param libro2 El segundo libro a comparar
/// \return -1 si hubo error 0 si salio bien
int Libro_compareByAutor(void *libro, void *libro2) {
	eLibro *unLibro;
	eLibro *otroLibro;
	char autor1[50];
	char autor2[50];
	int retorno;
	if (libro != NULL && libro2 != NULL) {
		unLibro = (eLibro*) libro;
		otroLibro = (eLibro*) libro2;
		if (Libro_getAutor(unLibro, autor1) == 0
				&& Libro_getAutor(otroLibro, autor2) == 0) {
			retorno = strcmp(autor1, autor2);
		}
	}
	return retorno;
}
/// \fn int Libro_isMinotauro(void*)
/// \brief Filtra el libro por la editorial "MINOTAURO"
/// \param libro El libro a filtrar
/// \return -1 si hubo error 0 si salio bien
int Libro_isMinotauro(void *libro) {
	eLibro *pLibro;
	int editorial;
	int retorno;
	retorno = 0;
	if (libro != NULL) {
		pLibro = (eLibro*) libro;
		if (Libro_getIdEditorial(pLibro, &editorial) == 0) {
			if (editorial == 4) {
				retorno = 1;
			}
		}
	}
	return retorno;
}
