//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Avion
//{
//	int nrMotoare;
//	int nrLocuriPasageri;
//	char* model;
//};
//
//Avion initializareAvion(int nrMotoare, int nrLocuri, const char* m)
//{
//	Avion a;
//	a.nrMotoare = nrMotoare;
//	a.nrLocuriPasageri = nrLocuri;
//	a.model = (char*)malloc(sizeof(char)*(strlen(m)+1));
//	strcpy(a.model, m);
//	return a;
//}
//
//void afisareAvion(Avion a) {
//	printf("Model: %s\t", a.model);
//	printf("Numar motoare: %d\t", a.nrMotoare);
//	printf("Numar locuri: %d\t", a.nrLocuriPasageri);
//}
//Avion citireAvion()
//{
//	Avion a;
//	printf("Introduce nr de motoare : ");
//	scanf("%d", &a.nrMotoare);
//	printf("Numarul de locuri : ");
//	scanf("%d", &a.nrLocuriPasageri);
//	printf("Modelul avionului : ");
//	char buffer[20];
//	scanf("%s", buffer);
//	a.model = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
//	strcpy(a.model, buffer);
//
//	return a;
//}
//
//Avion** citireMatriceAvioane(int* nrLinii, int* *nrColoane)
//{
//	printf("\nNr. linii: ");
//	scanf("%d", nrLinii);
//	Avion** a;
//	a = (Avion**)malloc((*nrLinii) * sizeof(Avion*));
//	*nrColoane = (int*)malloc((*nrLinii) * sizeof(int));
//	for (int i = 0; i < *nrLinii; i++) {
//		printf("Nr. coloane linia %d: ", i+1);
//		scanf("%d", &(*nrColoane)[i]);
//		a[i] = (Avion*)malloc((*nrColoane)[i] * sizeof(Avion));
//		for (int j = 0; j < (*nrColoane)[i]; j++) {
//			printf("Avionul de pe coloana %d(linia %d): ", j + 1, i + 1);
//			a[i][j] = citireAvion();
//		}
//	}
//	return a;
//}
//
//void afisareMatrice(Avion ** matrice, int nrLinii, int*nrColoane) {
//	for (int i = 0; i < nrLinii; i++) {
//		printf("Avionale de pe linia %d:\n", i + 1);
//		for (int j = 0; j < nrColoane[i]; j++) {
//			afisareAvion(matrice[i][j]);
//		}
//	}
//}
//
//void main() {
//	Avion a = initializareAvion(4, 250, "Boeing");
//	afisareAvion(a);
//
//	Avion a1 = citireAvion();
//	afisareAvion(a1);
//
//	Avion **aM;
//	int nrL=0;
//	int *nrC=NULL;
//	aM = citireMatriceAvioane(&nrL,&nrC);
//	afisareMatrice(aM, nrL, nrC);
//
//	for (int i = 0; i < nrL; i++) {
//		for (int j = 0; j < nrC[i]; j++) {
//			free(aM[i][j].model);
//		}
//		free(aM[i]);
//	}
//	free(aM);
//	free(nrC);
//	free(a.model);
//	free(a1.model);
//}