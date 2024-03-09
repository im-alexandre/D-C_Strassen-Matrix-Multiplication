#include "functions.c"


int main(int argc, char const *argv[])
{
	int n = 9;
	printf("Multiplicação de Matrizes Quadradas\n\n");
    GenerateMatrixes(n);

    printf("Multiplicando...\nResultado:\n\n");
    C = strassenMultiply(A, B, n);

    printMatrix(C, n);

	return 0;
}
