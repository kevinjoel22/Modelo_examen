#include "informe.h"

int orquestasMasCinco(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico)
{
	int status = FALSE;
	int i;
	int j;
	int contador = 0;

	if(listOrquesta != NULL && lenOrquesta > 0 && listMusico != NULL && lenMusico > 0)
	{

		for(i = 0; i < lenOrquesta; i++)
		{
			for(j = 0; j < lenMusico; i++)
			{
				if(listMusico[j].idOrquesta == i && listMusico[j].isEmpty == FALSE)
				{
					contador++;
				}
			}

			if(contador > 5)
			{
				status = TRUE;
				puts("---------------------------------");
				printf("Orquesta #%d\n", listOrquesta[i].id);
				printf("Nombre: %s\n", listOrquesta[i].name);
				printf("Lugar: %s\n", listOrquesta[i].lugar);
				printf("Tipo: %s\n", listOrquesta[i].tipo);
				puts("---------------------------------");
			}
			contador = 0;

		}

	}

	return status;
}

int musicosMayores(Musico* listMusico, int lenMusico, int edadMinima, Orquesta* listOrquesta, int lenOrquesta, Instrumento* listInstrumento, int lenInstrumento)
{
	int status = FALSE;
	int i;
	int indexOrquesta;
	int indexInstrumento;

	if(listMusico != NULL && lenMusico > 0 && listOrquesta != NULL && lenOrquesta > 0 && listInstrumento != NULL && lenInstrumento > 0 && edadMinima > 0 && edadMinima < 100)
	{
		for(i = 0; i < lenMusico; i++)
		{
			if(listMusico[i].age > 30 && listMusico[i].isEmpty == FALSE)
			{
				status = TRUE;
				indexOrquesta = findByIdOrquesta(listOrquesta, ORQUESTA_LEN);
				indexInstrumento = findByIdInstrumento(listInstrumento, INSTRUMENTO_LEN);
				puts("---------------------------------");
				printf("Músico #%d\n", listMusico[i].id);
				printf("Nombre: %s\n", listMusico[i].name);
				printf("Apellido: %s\n", listMusico[i].lastname);
				printf("Edad: %d\n", listMusico[i].age);
				if(indexOrquesta != FALSE)
				{
					printf("Orquesta: %s\n", listOrquesta[indexOrquesta].name);
				}
				else
				{
					puts("Orquesta: no encontrada");
				}

				if(indexInstrumento != FALSE)
				{
					printf("Instrumento: %s\n", listInstrumento[indexInstrumento].name);
				}
				else
				{
					puts("Instrumento: no encontrado");
				}
				puts("---------------------------------");
			}
		}
	}

	return status;
}


int lugarParticular(Orquesta* list, int len)
{
	int status = FALSE;
	int i;
	char busqueda[51];
	char auxEncontrado[51];

	ingresoCadena(busqueda, 51, "¿Que residencia querés investigar?\n", "Error. Intente nuevamente\n");
	strlwr(busqueda);

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			auxEncontrado = list[i].lugar;
			strlwr(auxEncontrado);

			if(strcmp(busqueda,auxEncontrado) == 0 && list[i].isEmpty == FALSE)
			{
				status = TRUE;
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

int orquestaCompleta(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico, Instrumento* listInstrumento, int lenInstrumento)
{
	int status = FALSE;
	int i;
	int j;
	int k;
	int contadorCuerda = 0;
	int contadorViento = 0;
	int contadorPercusion = 0;

	if(listOrquesta != NULL && lenOrquesta > 0 && listMusico != NULL && lenMusico > 0 && listInstrumento != NULL && lenInstrumento > 0)
	{

		for(i = 0; i < lenOrquesta; i++)
		{
			if(listOrquesta[i].isEmpty == FALSE)
			{
				for(j = 0; i < lenMusico; j++)
				{
					if(listMusico[j].idOrquesta == listOrquesta[i].id && listMusico[j].isEmpty == FALSE)
					{
						for(k = 0; i < lenInstrumento; k++)
						{
							if(listMusico[j].idInstrumento == listInstrumento[k].id)
							{
								if(strcmp(listInstrumento[k].name, "Cuerdas") == 0)
								{
									contadorCuerda++;
								}
								else
								{
									if(strcmp(listInstrumento[k].name, "Viento-madera") == 0 || strcmp(listInstrumento[k].name, "Viento-metal") == 0)
									{
										contadorViento++;
									}
									else
									{
										contadorCuerda++;
									}
								}
							}
						}
					}
				}
			}
			if(contadorCuerda >= 5 && contadorViento >= 3 && contadorPercusion >= 2)
			{
				status = TRUE;
				puts("---------------------------------");
				printf("Orquesta #%d\n", listOrquesta[i].id);
				printf("Nombre: %s\n", listOrquesta[i].name);
				printf("Lugar: %s\n", listOrquesta[i].lugar);
				printf("Tipo: %s\n", listOrquesta[i].tipo);
				puts("---------------------------------");
			}
			contadorCuerda = 0;
			contadorViento = 0;
			contadorPercusion = 0;
		}
	}

	return status;
}

int orquestaDeterminada(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico, Instrumento* listInstrumento, int lenInstrumento)
{
	int status = FALSE;
	int i;
	int index;
	int indexInstrumento;

	if(listOrquesta != NULL && lenOrquesta > 0 && listMusico != NULL && lenMusico > 0 && listInstrumento != NULL && lenInstrumento > 0)
	{
		index = findByIdOrquesta(listOrquesta, lenOrquesta);

		if(index != 1)
		{
			for(i = 0; i < lenMusico; i++)
			{
				if(listMusico[i].isEmpty == FALSE && listMusico[i].idOrquesta == index)
				{
					status = TRUE;
					indexInstrumento = findByIdInstrumento(listInstrumento, INSTRUMENTO_LEN);
					puts("---------------------------------");
					printf("Músico #%d\n", listMusico[i].id);
					printf("Nombre: %s\n", listMusico[i].name);
					printf("Apellido: %s\n", listMusico[i].lastname);
					printf("Edad: %d\n", listMusico[i].age);
					printf("Tipo de instrumento: %s\n", listInstrumento[indexInstrumento].type);
					puts("---------------------------------");
				}
			}
		}
	}

	return status;
}

int masMusicos(Orquesta* listOrquesta, int lenOrquesta, Musico* listMusico, int lenMusico)
{
	int status = FALSE;
	int i;
	int j;
	int contador = 0;
	int flagIngreso = FALSE;
	int maximo;
	int idMaximo;

	if(listOrquesta != NULL && lenOrquesta > 0 && listMusico != NULL && lenMusico > 0)
	{
		for(i = 0; i < lenOrquesta; i++)
		{
			if(listOrquesta[i].isEmpty == FALSE)
			{
				for(j = 0; i < lenMusico; j++)
				{
					if(listMusico[j].isEmpty == FALSE && listMusico[j].idOrquesta == listOrquesta[i].id)
					{
						contador++;
					}
				}
			}

			if(flagIngreso == FALSE || contador > maximo)
			{
				flagIngreso = TRUE;
				maximo = contador;
				idMaximo = listOrquesta[i].id;
				status = TRUE;
			}
		}

		puts("---------------------------------");
		printf("Orquesta #%d\n", listOrquesta[idMaximo].id);
		printf("Nombre: %s\n", listOrquesta[idMaximo].name);
		printf("Lugar: %s\n", listOrquesta[idMaximo].lugar);
		printf("Tipo: %s\n", listOrquesta[idMaximo].tipo);
		printf("Cantidad de Músicos: %d\n", maximo);
		puts("---------------------------------");

	}

	return status;
}

int ordenamientoApellido(Musico* listMusico, int lenMusico, Instrumento listInstrumento, int lenInstrumento)
{
	int status = FALSE;
	int i;
	int j;
	int posMusico = 0;
	Musico listCuerdas[MUSICO_LEN];
	Musico auxCuerdas;
	int indexInstrumento;


	if(listMusico != NULL && lenMusico > 0 && listInstrumento != NULL && lenInstrumento > 0)
	{

		for(i = 0; i < lenMusico; i++)
		{
			for(j = 0; j < lenInstrumento; j++)
			{
				if(listMusico[i].idInstrumento == listInstrumento[j].id && listMusico[i].isEmpty == FALSE)
				{
					if(strcmp(listInstrumento[j].type, "Cuerdas") == 0)
					{
						listCuerdas[posMusico].name = listMusico[i].name;
						listCuerdas[posMusico].lastname = listMusico[i].lastname;
						listCuerdas[posMusico].age = listMusico[i].age;
						listCuerdas[posMusico].idInstrumento = listMusico[i].idInstrumento;
						posMusico++;
					}
				}
			}
		} // Terminó de rastrear

		for(i=0; i<lenMusico-1; i++)
		{
			for (j=i+1; j<lenMusico; j++)
		    {
				if( (strcmp(listCuerdas[i].lastname,listCuerdas[j].lastname)>0) && (listCuerdas[i].isEmpty == FALSE && listCuerdas[j].isEmpty == FALSE) )
		        {
					auxCuerdas=listCuerdas[i];
					listCuerdas[i]=listCuerdas[j];
		            listCuerdas[j]=auxCuerdas;
		        }
		     }
		}
		// Terminó de ordenar

		for(i = 0; i < lenMusico; i++)
		{
			puts("---------------------------------");
			printf("Músico #%d\n", listMusico[i].id);
			printf("Nombre: %s\n", listMusico[i].name);
			printf("Apellido: %s\n", listMusico[i].lastname);
			printf("Edad: %d\n", listMusico[i].age);
			printf("Tipo de instrumento: %s\n", listInstrumento[indexInstrumento].type);
			puts("---------------------------------");
		}

	}

	return status;
}

