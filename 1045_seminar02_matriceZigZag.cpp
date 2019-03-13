#include<stdlib.h>
#include<stdio.h>
#include<string>

struct Bilet {
	int cod;
	float pretBilet;
	char* destinatie;
};

Bilet initializare(int c, float p,const char* den) {
	Bilet b;
	b.cod = c;
	b.pretBilet = p;
	b.destinatie = (char*)malloc(sizeof(char)*(strlen(den)+1));
	strcpy(b.destinatie, den);
	return b;
}

void afisare(Bilet b)
{
	printf(" Codul:%d \n", b.cod);
	printf("Pret:%f \n", b.pretBilet);
	printf("Destinatie:%s ", b.destinatie);

}
 Bilet citire()
{
	 Bilet b1;
	 char nume[10];

	 scanf("%d", &b1.cod);
	 scanf("%f", &b1.pretBilet);
	 scanf("%s", nume);
	 b1.destinatie = (char*)malloc(sizeof(char)*strlen(nume)+1);
	 strcpy(b1.destinatie, nume);
	 return b1;
}

 Bilet** citire_masiv(int *nr_lini, int* *col) {
	 printf("\nIntrodu nr lini: ");
	 scanf("%d", nr_lini);

	 Bilet** b;
	 b = (Bilet**)malloc(*nr_lini * sizeof(Bilet*));
	
	 *col = (int*)malloc(sizeof(int) * (*nr_lini));
	
	 for (int i = 0; i < *nr_lini; i++)
	 {
		 printf("Lungimea liniei %d", i + 1);
		 scanf("%d", &(*col)[i]);
		 b[i] = (Bilet*)malloc((*col)[i] * sizeof(Bilet));
		 for (int j = 0; j < (*col)[i]; j++)
		 {
			 printf("Introdu biletul[%d][%d]: ", i + 1, j + 1);
			 b[i][j] = citire();
		 }
	 }
	 return b; 
 }

 void afisareMatrice(Bilet **b, int nrLinii, int *nrColoane) {
	 for (int i = 0; i < nrLinii; i++) {
		 printf("Biletele de pe linia %d\n", i);
		 for (int j = 0; j < nrColoane[i]; j++) {
			 afisare(b[i][j]);
		 }
	 }
 }

 void afisareVector(Bilet* vector, int dim) {
	 for (int i = 0; i < dim; i++) {
		 afisare(vector[i]);
	 }
 }


void main()
{
	Bilet b1 = initializare(1, 99.77, "Malibu");
	afisare(b1);
	//Bilet b2 = citire();
	//afisare(b2);

	Bilet** matrice;
	int* nrColoane = NULL;
	int nrLinii = 0;

	matrice = citire_masiv(&nrLinii, &nrColoane);
	afisareMatrice(matrice, nrLinii, nrColoane);

	afisareVector(matrice[0], nrColoane[0]);
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			free(matrice[i][j].destinatie);
		}
		free(matrice[i]);
	}
	free(matrice);
	free(nrColoane);
	free(b1.destinatie);
	//free(b2.destinatie);
}