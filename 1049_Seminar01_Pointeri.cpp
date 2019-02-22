//#include<stdio.h>
//#include<malloc.h>
//
//void afisare(int n, int*v) {
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		printf("%d ", v[i]);
//	}
//}
//
//void citire(int n, int*v) {
//	for (int i = 0; i < n; i++) {
//		printf("v[%d]= ", i);
//		scanf("%d", &v[i]);
//	}
//}
//
//void citire2(int *n, int **v) {
//	printf("n= ");
//	scanf("%d", n);
//	*v = (int*)malloc(*n * sizeof(int));
//	for (int i = 0; i < *n; i++) {
//		printf("v[%d]= ", i);
//		scanf("%d", *v+i);
//	}
//}
//void citireM(int *n, int *m, int*** v)
//{
//	printf("n= ");
//	scanf("%d", n);
//	printf("m= ");
//	scanf("%d", m);
//	*v = (int**)malloc(*n * sizeof(int*));
//	for (int i = 0; i < *n; i++) {
//		(*v)[i] = (int*)malloc(*m * sizeof(int));
//		for (int j = 0; j < *m; j++)
//			scanf("%d", &(*v)[i][j]);
//	}
//}
//void afisareM(int n, int m, int **v)
//{
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++)
//			printf("%d ", v[i][j]);
//		printf("\n");
//	}
//	
//}
//
//
//void citire3(int &n, int* &v) {
//	printf("n= ");
//	scanf("%d", &n);
//	v = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++) {
//		printf("v[%d]= ", i);
//		scanf("%d", &v[i]);
//	}
//}
//
//void main() {
//	int n,m;
//	//int **v;
//	//citire2(&n, &v);
//	int **v;
//	//citire3(n, v);
//	citireM(&n,&m, &v);
//	afisareM(n,m, v);

//dezalocari
//}