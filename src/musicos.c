#include "musicos.h"

int initMusicos(Musico* list, int len)
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

int findByIdMusico(Musico* list, int len)
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

int deleteMusico(Musico* list, int len)
{
	int status = FALSE;
	int index;

	if(list != NULL && len > 0)
	{
		index = findByIdMusico(list, len);

		if(index != FALSE)
		{
			status = TRUE;
			list[index].isEmpty = TRUE;
			puts("Músico eliminado");
		}
	}

	return status;
}

int printMusico(Musico* list, int len)
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
				printf("Músico #%d\n", list[i].id);
				printf("Nombre: %s\n", list[i].name);
				printf("Apellido: %s\n", list[i].lastname);
				printf("Edad: %d\n", list[i].age);
				printf("ID de Orquesta: %d\n", list[i].idOrquesta);
				printf("ID de Del instrumento: %d\n", list[i].idInstrumento);
				puts("---------------------------------");
			}
		}
	}

	return status;
}

