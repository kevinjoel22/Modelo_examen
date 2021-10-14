/*
 * informe.h
 *
 *  Created on: 14 oct. 2021
 *      Author: agust
 */

#ifndef INFORME_H_
#define INFORME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "union.h"
#include "utn_ops.h"

#define TRUE 1
#define FALSE -1
#define ORQUESTA_LEN 50
#define MUSICO_LEN 1000
#define INSTRUMENTO_LEN 20

int orquestasMasCinco(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico);
int musicosMayores(Musico* listMusico, int lenMusico, int edadMinima, Orquesta* listOrquesta, int lenOrquesta, Instrumento* listInstrumento, int lenInstrumento);
int lugarParticular(Orquesta* list, int len);
int orquestaCompleta(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico, Instrumento* listInstrumento, int lenInstrumento);
int orquestaDeterminada(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico, Instrumento* listInstrumento, int lenInstrumento);
int masMusicos(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico);


#endif /* INFORME_H_ */
