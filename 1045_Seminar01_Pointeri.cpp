#include <stdlib.h>
#include <stdio.h>
void citire(int dim, int* vector) {
	for (int i = 0; i < dim; i++)
		scanf("%d", &vector[i]);
}

void afisare(int dim, int* vector) {
	for (int i = 0; i < dim; i++)
		printf("%d  ", vector[i]);
}

void citire2(int &dim, int* &vector) {
	scanf("%d", &dim);
	vector = (int*)malloc(dim*sizeof(int));
	for (int i = 0; i < dim; i++)
		scanf("%d", &vector[i]);
}
void cMatrice(int *m, int *n, int ***a)
{
	scanf("%d", m);
	scanf("%d", n);
	*a = (int**)malloc(sizeof(int*)*(*m));
	for (int i = 0; i < *m; i++)
	{
		(*a)[i] = (int*)malloc(sizeof(int)*(*n));
		for (int j = 0; j < *n; j++)
		{
			scanf("%d", &(*a)[i][j]);
		}
	}
}

void citire3(int* dim, int** vector) {
	scanf("%d", dim);
	*vector = (int*)malloc(*dim * sizeof(int));
	for (int i = 0; i < *dim; i++)
		scanf("%d", &(*vector)[i]); //*vector+i
}

void afisare2(int m, int n, int **vector) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("%d ", vector[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	//int dimensiune;
	//int *vector;
	////scanf("%d", &dimensiune);
	////vector = (int*)malloc(dimensiune*sizeof(int));
	//citire3(&dimensiune,&vector);
	//afisare(dimensiune,vector);

	int **vector;
	int m, n;

	cMatrice(&m, &n, &vector);
	afisare2(m, n, vector);
	
	//dezalocari
}