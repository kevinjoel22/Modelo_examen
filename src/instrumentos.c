/*
 * instrumentos.c
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */
#include "instrumentos.h"

int initInstrumentos(Instrumento* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
	}

	return status;
}

int addIntrumentos(Instrumento* list, int len)
{
	int status = FALSE;
	int i;
	int option;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				status = TRUE;
				list[i].id = i;
				list[i].isEmpty = FALSE;
				ingresoCadena(list[i].name, 100, "Ingrese el nombre del instrumento\n", "Error, intente nuevamente\n");
				ingresoIntMinMax(&option, "Ingrese el tipo de instrumento:\n1.Cuerdas \n2.Viento-madera \n3.Viento-metal \n4.Percusión\n", "Error, intente nuevamente\n", 1, 4);
				switch(option)
				{
					case 1:
						strcpy(list[i].type, "Cuerdas");
						break;
					case 2:
						strcpy(list[i].type, "Viento-madera");
						break;
					case 3:
						strcpy(list[i].type, "Viento-metal");
						break;
					case 4:
						strcpy(list[i].type, "Percusión");
						break;
				}
				break;
			}
		}
	}

	return status;
}

int findByIdInstrumento(Instrumento* list, int len)
{
	int status = FALSE;
	int i;
	int index;

	if(list != NULL && len > 0)
	{
		index = ingresoInt("Ingrese el número de ID\n", "ERROR - Intente nuevamente\n");

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				if(index == list[i].id)
				{
					status = i;
					break;
				}
			}
		}
	}

	return status;
}

int printInstrumento(Instrumento* list, int len)
{
	int status = FALSE;
	int i;

	if(list != NULL && len > 0)
	{
		status = TRUE;
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				puts("---------------------------------");
				printf("Instrumento #%d\n", list[i].id);
				printf("Nombre: %s\n", list[i].name);
				printf("Tipo: %s\n", list[i].type);
				puts("---------------------------------");
			}
		}
	}

	return status;
}
