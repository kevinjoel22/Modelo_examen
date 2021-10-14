/*
 * orquesta.h
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */

#ifndef ORQUESTA_H_
#define ORQUESTA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_ops.h"

#define TRUE 1
#define FALSE -1
#define ORQUESTA_LEN 50
#define MUSICO_LEN 1000
#define INSTRUMENTO_LEN 20

typedef struct{
	char name[51];
	char lugar[51];
	char tipo[20];
	int id;
	int isEmpty;
}Orquesta;

int initOrquestas(Orquesta* list, int len);
int addOrquestas(Orquesta* list, int len);
int findByIdOrquesta(Orquesta* list, int len);
int printOrquesta(Orquesta* list, int len);

#endif /* ORQUESTA_H_ */
