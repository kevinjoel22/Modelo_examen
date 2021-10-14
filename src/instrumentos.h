/*
 * instrumentos.h
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */

#ifndef INSTRUMENTOS_H_
#define INSTRUMENTOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"

#define TRUE 1
#define FALSE -1
#define ORQUESTA_LEN 50
#define MUSICO_LEN 1000
#define INSTRUMENTO_LEN 20

typedef struct
{
	char name[100];
	char type[50];
	int id;
	int isEmpty;
}Instrumento;

int initInstrumentos(Instrumento* list, int len);
int addIntrumentos(Instrumento* list, int len);
int findByIdInstrumento(Instrumento* list, int len);
int printInstrumento(Instrumento* list, int len);

#endif /* INSTRUMENTOS_H_ */
