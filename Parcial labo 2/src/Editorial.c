#include "Editorial.h"
/// \fn eEditorial Editorial_newParametros*()
/// \brief Setea los paremetros del dato de tipo eEditorial en 0 utilizando calloc
/// \return El puntero al dato creado en memoria dinamica
eEditorial* Editorial_newParametros() {
	eEditorial *pEditorial;
	pEditorial = (eEditorial*) calloc(sizeof(eEditorial), 1);
	return pEditorial;
}
/// \fn eEditorial Editorial_ParametrosParametrisados*(char*, char*)
/// \brief Setea el dato de tipo eEditorial con los datos pasados como parametros
/// \param idEditorial El string con el idEditorial
/// \param nombre El string con el nombre
/// \return El puntero al dato creado en memoria dinamica
eEditorial* Editorial_ParametrosParametrisados(char *idEditorial, char *nombre) {
	eEditorial *pEditorial;
	pEditorial = Editorial_newParametros();
	if (pEditorial != NULL && idEditorial != NULL && nombre != NULL) {
		if (Editorial_setId(pEditorial, atoi(idEditorial)) == -1
				|| Editorial_setNombre(pEditorial, nombre) == -1) {
			Editorial_delete(pEditorial);
		}
	}
	return pEditorial;
}
/// \fn void Editorial_delete(eEditorial*)
/// \brief Libera el dato de tipo eEditorial en memoria dinamica
/// \param this El dato a liberar
void Editorial_delete(eEditorial *this) {
	if (this != NULL) {
		free(this);
	}
}
/// \fn int Editorial_setId(eEditorial*, int)
/// \brief Setea el idEditorial al tipo de dato de eEditorial
/// \param this La editorial a ser seteada
/// \param id El id a ser seteado
/// \return -1 si hubo error 0 si salio bien
int Editorial_setId(eEditorial *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id > 0) {
		this->idEditorial = id;
		retorno = 0;
	}
	return retorno;
}
/// \fn int Editorial_getId(eEditorial*, int*)
/// \brief Obtiene el id del dato eEditorial
/// \param this La editorial a obtener el id
/// \param id El id a obtener
/// \return -1 si hubo error 0 si salio bien
int Editorial_getId(eEditorial *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}
/// \fn int Editorial_setNombre(eEditorial*, char*)
/// \brief Setea un nombre del dato eEditorial
/// \param this El dato a setear
/// \param nombre El nombre a setear
/// \return -1 si hubo error 0 si salio bien
int Editorial_setNombre(eEditorial *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
/// \fn int Editorial_getNombre(eEditorial*, char*)
/// \brief Obtiene un nombre del dato eEditorial
/// \param this El dato a obtener el nombre
/// \param nombre El nombre a obtener
/// \return -1 si hubo error 0 si salio bien
int Editorial_getNombre(eEditorial *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

