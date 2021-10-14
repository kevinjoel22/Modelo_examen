#include "union.h"

int addMusico(Musico* listMusico,int lenMusico, Orquesta* listOrquesta, int lenOrquesta, Instrumento* listInstrumento, int lenInstrumento)
{
	int status = FALSE;
	int i;

	if(listMusico != NULL && lenMusico > 0 && listOrquesta != NULL && lenOrquesta > 0 && listInstrumento != NULL && lenInstrumento > 0)
	{
		for(i = 0; i < lenMusico; i++)
		{
			if(listMusico[i].isEmpty == TRUE)
			{
				status = TRUE;
				listMusico[i].id = i;
				listMusico[i].isEmpty = FALSE;
				ingresoCadena(listMusico[i].name, 51, "Ingresa el nombre del m�sico\n", "ERROR. Ingrese nuevamente\n");

				ingresoCadena(listMusico[i].lastname, 51, "Ingresa el apellido del m�sico\n", "ERROR. Ingrese nuevamente\n");

				ingresoIntMinMax(&listMusico[i].age, "Ingrese la edad del m�sico\n", "ERROR. Ingrese un n�mero valido\n", 0, 100);

				ingresoIntMinMax(&listMusico[i].idOrquesta, "Ingrese el ID de la orquesta donde pertenece el m�sico\n", "ERROR. Ingrese un n�mero valido\n", 0, lenOrquesta);
				while(listOrquesta[listMusico[i].idOrquesta].isEmpty == TRUE)
				{
					ingresoIntMinMax(&listMusico[i].idOrquesta, "La orquesta selecionada no existe. Intente nuevamente\n", "ERROR. Ingrese un n�mero valido\n", 0, lenOrquesta);
				}

				ingresoIntMinMax(&listMusico[i].idInstrumento, "Ingrese el ID del instrumento que toca el m�sico\n", "ERROR. Ingrese un n�mero valido\n", 0, lenInstrumento);
				while(listInstrumento[listMusico[i].idInstrumento].isEmpty == TRUE)
				{
					ingresoIntMinMax(&listMusico[i].idInstrumento, "El instrumento selecionado no existe. Intente nuevamente\n", "ERROR. Ingrese un n�mero valido\n", 0, lenInstrumento);
				}
				break;
			}
		}
	}

	return status;
}

int modifyMusico(Musico* listMusico, int lenMusico, Orquesta* listOrquesta, int lenOrquesta)
{
	int status = FALSE;
	int index;
	int opcion;

	if(listMusico != NULL && lenMusico > 0 && listOrquesta != NULL && lenOrquesta < 0)
	{
		index = findByIdMusico(listMusico, lenMusico);

		if(index != FALSE)
		{
			status = TRUE;
			ingresoIntMinMax(&opcion, "�Que desea modificar?\n1. Edad\n2. Orquesta", "Error. Ingrese nuevamente\n", 1, 2);
			switch(opcion)
			{
				case 1:
					ingresoIntMinMax(&listMusico[index].age, "�Cual es la nueva edad del M�sico?\n", "ERROR. Ingrese un n�mero valido\n", 0, 100);
					break;
				case 2:
					ingresoIntMinMax(&listMusico[index].idOrquesta, "Ingrese el nuevo ID de la orquesta donde pertenecer� el m�sico\n", "ERROR. Ingrese un n�mero valido\n", 0, lenOrquesta);
					while(listOrquesta[listMusico[index].idOrquesta].isEmpty == TRUE)
					{
						ingresoIntMinMax(&listMusico[index].idOrquesta, "La orquesta selecionada no existe. Intente nuevamente\n", "ERROR. Ingrese un n�mero valido\n", 0, lenOrquesta);
					}
					break;
			}
			puts("�Cambios realizados con �xito!");
		}
	}

	return status;
}

int deleteOrquestas(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico,int lenMusico)
{
		int status = FALSE;
		int i;
		int index;

		if(listOrquesta != NULL && lenOrquesta > 0 && listMusico != NULL && lenMusico > 0)
		{
			index = findByIdOrquesta(listOrquesta, lenOrquesta);

			if(index != FALSE)
			{
				status = TRUE;
				listOrquesta[index].isEmpty = TRUE;
				printf("Orquesta: #%d || Eliminada con �xito\n", listOrquesta[index].id);

				for(i = 0; i < lenMusico; i++)
				{
					if(listMusico[i].isEmpty == FALSE)
					{
						if(listMusico[i].idOrquesta == index)
						{
							listMusico[i].isEmpty = TRUE;
							printf("M�sico: #%d || Eliminado con �xito\n", listMusico[i].id);
						}
					}
				}
			}
		}

		return status;
}
