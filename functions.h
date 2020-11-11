#include <stdio.h>
#include <stdlib.h>

void Menu1()
{
	system("clear");
	printf("Multiplicação de Matrizes Quadradas\n\n");

	printf("1) Configurar matrizes\n");
	printf("2) Sair\n\n");
	printf(">> ");

	int entrada;
	scanf("%d", &entrada);

	switch(entrada)
	{
		case 1:
			//Config();
			break;

		case 2:
			exit(EXIT_SUCCESS);
			break;
	}

}


void Menu2()
{
	system("clear");
	printf("Multiplicação de Matrizes Quadradas\n\n");

	printf("1) Prosseguir com a execução\n");
	printf("2) Sair\n\n");
	printf(">> ");

	int entrada;
	scanf("%d", &entrada);

	switch(entrada)
	{
		case 1:
			//Multiply();
			break;

		case 2:
			exit(EXIT_SUCCESS);
			break;
	}



}