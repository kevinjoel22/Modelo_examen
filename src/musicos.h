/*
 * musicos.h
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */

#ifndef MUSICOS_H_
#define MUSICOS_H_
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
	char name[51];
	char lastname[51];
	int age;
	int id;
	int idOrquesta;
	int idInstrumento;
	int isEmpty; // TRUE = 1 || FALSE = -1
}Musico;

int initMusicos(Musico* list, int len);
int findByIdMusico(Musico* list, int len);
int deleteMusico(Musico* list, int len);
int printMusico(Musico* list, int len);


#endif /* MUSICOS_H_ */
