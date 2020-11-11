#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int size; // Tamanho da matriz
int **matrix_A;
int **matrix_B;
int **result_matrix;

void Config();
int determinantOfMatrix(int **mat, int n);

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
			Config();
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

void allocMatrixes()
{
	//// Matrix A ////
	matrix_A = (int **) malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++)
		matrix_A[i] = (int *) malloc(size * sizeof(int));

	srand(time(0));

	for(int l = 0; l < size; l++)
		for(int c = 0; c < size; c++)
			matrix_A[l][c] = rand()%31;

	//// Matrix B ////
	matrix_B = (int **) malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++)
		matrix_B[i] = (int *) malloc(size * sizeof(int));


	for(int l = 0; l < size; l++)
		for(int c = 0; c < size; c++)
			matrix_B[l][c] = rand()%31;

	//// Result Matrix ////
	result_matrix = (int **) malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++)
		result_matrix[i] = (int *) malloc(size * sizeof(int));
}

void printMatrix(int **M)
{
	for(int l = 0; l < size; l++) {
		for(int c = 0; c < size; c++) {
			printf("%d ", M[l][c]);
		}
		printf("\n");
	}
	printf("\n");	
	
}

void Config()
{
	system("clear");
	printf("Qual será o tamanho N da matriz N x N?\n\n");
	printf("(Pela limitação de espaço gráfico, a visualiação das matrizes\ne de seus resultados só estão disponíveis para valores de N <= 10)\n\n>> ");
	
	scanf("%d", &size);
	
	printf("\nSerá gerada uma matriz %d x %d de inteiros aleatórios...\n", size, size);

	allocMatrixes();
	sleep(3);

	system("clear");

	if(size <= 10)
	{
		printf("Matrizes Geradas\n\n");
		printf("Matriz A\n\n");
		printMatrix(matrix_A);
		printf("Matriz B\n\n");
		printMatrix(matrix_B);
	}
	else
	{
		printf("Dada o tamanho da matriz, será apresentado somente o elemento na posição [0,0]\n\n");
		printf("Matriz A = %d\n"  , matrix_A[0][0]);
		printf("Matriz B = %d\n\n", matrix_B[0][0]);
	}

	printf("Aperte Enter para prosseguir...\n");
	getchar();
	getchar();
}