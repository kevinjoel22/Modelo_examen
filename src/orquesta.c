/*
 * orquesta.c
 *
 *  Created on: 13 oct. 2021
 *      Author: agust
 */
#include "orquesta.h"

int initOrquestas(Orquesta* list, int len)
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

int addOrquestas(Orquesta* list, int len)
{
	int status = FALSE;
	int i;
	int opcionTipo;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				status = TRUE;
				list[i].id = i;
				list[i].isEmpty = FALSE;
				ingresoCadena(list[i].name, 51, "Ingresa un nombre para la orquesta\n", "ERROR. Ingrese nuevamente\n");
				ingresoCadena(list[i].lugar, 51, "Ingresa lugar donde recide la orquesta\n", "ERROR. Ingrese nuevamente\n");
				ingresoIntMinMax(&opcionTipo, "Ingrese el tipo de orquesta\n1. Sinfónica\n2. Filarmónica\n3. Cámara\n", "ERROR - Ingrese un número valido\n", 1, 3);
				switch(opcionTipo)
				{
					case 1:
						strcpy(list[i].tipo,"Sinfónica");
						break;
					case 2:
						strcpy(list[i].tipo,"Filarmónica");
						break;
					case 3:
						strcpy(list[i].tipo,"Cámara");
						break;
				}
				break;
			}
		}
	}

	return status;
}

int findByIdOrquesta(Orquesta* list, int len)
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

int printOrquesta(Orquesta* list, int len)
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
				printf("Orquesta #%d\n", list[i].id);
				printf("Nombre: %s\n", list[i].name);
				printf("Lugar: %s\n", list[i].lugar);
				printf("Tipo: %s\n", list[i].tipo);
				puts("---------------------------------");
			}
		}
	}

	return status;
}
