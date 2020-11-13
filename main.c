#include "functions.h"

int main(int argc, char const *argv[])
{
	int n;
	system("clear");
	printf("Multiplicação de Matrizes Quadradas\n\n");

	printf("1) Gerar matrizes\n");
	printf("2) Sair\n\n");
	printf(">> ");

	int entrada;
	scanf("%d", &entrada);

	if(entrada == 1)
	{
		n = GenerateMatrixes();

		printf("Multiplicando...\nResultado:\n\n");
		C = strassenMultiply(A, B, n);

		printMatrix(C, n);
	}
	else { exit(EXIT_SUCCESS); }

	return 0;
}