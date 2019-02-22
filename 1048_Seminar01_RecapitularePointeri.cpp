//#include<iostream>
//void citire(int * v, int n)
//{	
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//	}
//}
//void citire2(int * &v, int &n)
//{
//	scanf("%d", &n);
//	v = (int*)malloc(sizeof(int)*n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &v[i]);
//	}
//}
//
//void citire3(int * *v, int *n)
//{
//	scanf("%d", n);
//	(*v) = (int*)malloc(sizeof(int)*(*n));
//	for (int i = 0; i < *n; i++) {
//		scanf("%d", &(*v)[i]);//v[i]
//	}
//}
//
//void afisare(int *v, int n)
//{
//	printf("vectorul contine %d elemente:", n);
//	for (int i = 0; i < n; i++) {
//		printf("%d, ", v[i]);
//	}
//}
//
//void citireMatrice(float** *matrice, int *coloane, int *linii) {
//
//	scanf("%d", linii);
//	scanf("%d", coloane);
//	(*matrice) = (float**)malloc(sizeof(float*)*(*linii));
//	for (int i = 0; i < *linii; i++) {
//		(*matrice)[i] = (float*)malloc(sizeof(float)*(*coloane));
//		for (int j = 0; j < *coloane; j++) {
//			scanf("%f", &(*matrice)[i][j]);
//		}
//	}
//}
//
//void afisareMatrice(float **matrice, int linii, int coloane) {
//	for (int i = 0; i < linii; i++) {
//		for (int j = 0; j < coloane; j++) {
//			printf("%f ", matrice[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void main() {
//	int *v;
//	int n;
//	//scanf("%d", &n);
//	//v = (int*)malloc(sizeof(int)*n);
//	citire3(&v, &n);
//	afisare(v, n);
//
//	int linii;
//	int coloane;
//	float**m;
//	citireMatrice(&m, &coloane, &linii);
//	afisareMatrice(m, linii, coloane);
//
//dezalocari
//}