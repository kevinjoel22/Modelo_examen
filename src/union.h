/*
 * union.h
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */

#ifndef UNION_H_
#define UNION_H_

#include "musicos.h"
#include "orquesta.h"
#include "instrumentos.h"

#define TRUE 1
#define FALSE -1
#define ORQUESTA_LEN 50
#define MUSICO_LEN 1000
#define INSTRUMENTO_LEN 20

int addMusico(Musico* listMusico,int lenMusico, Orquesta* listOrquesta, int lenOrquesta, Instrumento* listInstrumento, int lenInstrumento);
int deleteOrquestas(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico,int lenMusico);

#endif /* UNION_H_ */
