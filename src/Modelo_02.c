/*
 ============================================================================
 Name        : Modelo_02.c
 Author      : Agustín Robertazzi - H1
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "union.h"
#include "informe.h"

int main(void) {
	setbuf(stdout, NULL);


	Instrumento instrumentos[INSTRUMENTO_LEN];
	Orquesta orquestas[ORQUESTA_LEN];
	Musico musicos[MUSICO_LEN];

	initOrquestas(orquestas, ORQUESTA_LEN);
	initInstrumentos(instrumentos, INSTRUMENTO_LEN);
	initMusicos(musicos, MUSICO_LEN);

	addOrquestas(orquestas, ORQUESTA_LEN);
	addIntrumentos(instrumentos, INSTRUMENTO_LEN);
	addMusico(musicos, MUSICO_LEN, orquestas, ORQUESTA_LEN, instrumentos, INSTRUMENTO_LEN);
	addMusico(musicos, MUSICO_LEN, orquestas, ORQUESTA_LEN, instrumentos, INSTRUMENTO_LEN);

	if(printOrquesta(orquestas, ORQUESTA_LEN) == FALSE)
	{
		puts("Print - Orquesta no encontrada.");
	}

	if(printInstrumento(instrumentos, INSTRUMENTO_LEN) == FALSE)
	{
		puts("Print - Instrumento no encontrado.");
	}

	if(printMusico(musicos, MUSICO_LEN) == FALSE)
	{
		puts("Print - Músico no encontrado.");
	}

	if(deleteOrquestas(orquestas, ORQUESTA_LEN, musicos, MUSICO_LEN) == FALSE)
	{
		puts("Del - Orquesta no encontrada.");
	}

	if(printOrquesta(orquestas, ORQUESTA_LEN) == FALSE)
	{
		puts("Print - Orquesta no encontrada.");
	}

	if(printMusico(musicos, MUSICO_LEN) == FALSE)
	{
		puts("Print - Músico no encontrado.");
	}

	return EXIT_SUCCESS;
}
