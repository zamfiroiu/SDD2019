//#include<iostream>
//
//void print(int *v, int n) {
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d, ", v[i]);
//	}
//}
//void read(int *v, int n) {
//	
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//	}
//}
//void read2(int* &v, int& n) {
//	printf("N=");
//	scanf("%d", &n);
//	v = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//	}
//}
//
//void read3(int **v, int* n)
//{
//	printf("N= ");
//	scanf("%d", n);
//	*v = (int*)malloc(*n * sizeof(int));
//	for (int i = 0; i < *n; i++)
//		scanf("%d", &((*v)[i]));
//}
//
//
//void readMarix(float** *m, int* lines, int* columns) {
//	printf("Lines:");
//	scanf("%d", lines);
//	printf("Columns:");
//	scanf("%d", columns);
//
//	*m = (float**)malloc(sizeof(float*)*(*lines));
//	for (int i = 0; i < *lines; i++) {
//		(*m)[i] = (float*)malloc(sizeof(float)*(*columns));
//		for (int j = 0; j < *columns; j++) {
//			scanf("%f", &(*m)[i][j]);
//		}
//	}
//
//}
//
//void printMatrix(float**m, int lines, int columns) {
//	for (int i = 0; i < lines; i++) {
//		for (int j = 0; j < columns; j++) {
//			printf("%5.2f, ", m[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void main() {
//	/*int n;
//	printf("N=");
//	scanf("%d", &n);
//	int *v = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//	}*/
//	//int n=3;
//	//int *v=NULL;// = (int*)malloc(n * sizeof(int));
//	//read3(&v, &n);
//	//print(v, n);
//
//	float ** matrix = NULL;
//	int lines = 0;
//	int columns = 0;
//	readMarix(&matrix, &lines, &columns);
//	printMatrix(matrix, lines, columns);
//
//dezalocari
//}