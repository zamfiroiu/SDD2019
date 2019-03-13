//#include <iostream>
//
//using namespace std;
//
//struct Medic
//{
//	char *nume;
//	int varsta;
//	int nrPacienti;
//	char **numePacienti;
//};
//
//void afisare(Medic m)
//{
//	printf("Nume medic %s", m.nume);
//	printf("\nVarsta medic %d", m.varsta);
//	printf("\nNr pacienti %d: \n", m.nrPacienti);
//	for (int i = 0; i < m.nrPacienti; i++)
//	{
//		printf("	%s", m.numePacienti[i]);
//		printf("\n");
//	}
//}
//
//Medic initializareMedic(const char*nume, int varsta, int nrPacienti, char** numePacienti)
//{
//	Medic m;
//	m.nume = (char*)malloc(sizeof(char)*strlen(nume)+1);
//	strcpy(m.nume, nume);
//	m.varsta = varsta;
//	m.nrPacienti = nrPacienti;
//	m.numePacienti = (char**)malloc(sizeof(char*)*nrPacienti);
//	for (int i = 0; i < nrPacienti; i++) {
//		m.numePacienti[i] = (char*)malloc(sizeof(char)*strlen(numePacienti[i])+1);
//		strcpy(m.numePacienti[i], numePacienti[i]);
//	}
//	return m;
//}
//
//Medic citesteMedic() {
//	Medic m;
//	char aux[20];
//	printf("Nume medic:");
//	scanf("%s", aux);
//	m.nume = (char*)malloc(sizeof(char)*strlen(aux) + 1);
//	strcpy(m.nume, aux);
//	printf("Varsta medic:");
//	scanf("%d", &m.varsta);
//
//	printf("Cati pacienti are acest medic:");
//	scanf("%d", &m.nrPacienti);
//
//	m.numePacienti = (char**)malloc(sizeof(char*)*m.nrPacienti);
//	for (int i = 0; i < m.nrPacienti; i++) {
//
//		printf("Nume pacient %d:",(i+1));
//		scanf("%s", aux);
//		m.numePacienti[i] = (char*)malloc(sizeof(char)* strlen(aux) + 1);
//		strcpy(m.numePacienti[i], aux);
//	}
//	return m;
//}
//
//Medic** citireMatriceZigZag(int *nrLinii, int* *nrColoane) {
//	Medic** matrice;
//	printf("Numar linii:");
//	scanf("%d", nrLinii);
//	matrice = (Medic**)malloc(sizeof(Medic*)*(*nrLinii));
//	*nrColoane = (int*)malloc(sizeof(int)*(*nrLinii));
//	for (int i = 0; i < *nrLinii; i++) {
//
//		printf("Numarul de coloane pentru linia %d:",(i+1));
//		scanf("%d", &(*nrColoane)[i]);
//		matrice[i] = (Medic*)malloc(sizeof(Medic)*(*nrColoane)[i]);
//		for (int j = 0; j < (*nrColoane)[i]; j++) {
//			matrice[i][j] = citesteMedic();
//		}
//	}
//	return matrice;
//}
//
//void main() {
//	char**numePacienti = (char**)malloc(sizeof(char*) * 3);//valori hard-codate
//	for (int i = 0; i < 3; i++) {//valori hard-codate
//		numePacienti[i] = (char*)malloc(sizeof(char) * 4);//valori hard-codate
//	}
//	strcpy(numePacienti[0], "Ana");
//	strcpy(numePacienti[1], "Dan");
//	strcpy(numePacienti[2], "Ion");
//	Medic m = initializareMedic("Ion", 30, 3, numePacienti);
//	afisare(m);
//	Medic m2 = citesteMedic();
//	afisare(m2);
//
//	int nrLinii = 0;
//	int*nrColoane = NULL;
//
//	Medic**matrice = citireMatriceZigZag(&nrLinii, &nrColoane);
//
//	for (int i = 0; i < nrLinii; i++) {
//		printf("Linia %d", (i + 1));
//		for (int j = 0; j < nrColoane[i]; j++) {
//			afisare(matrice[i][j]);
//		}
//	}
//
//	for (int i = 0; i < nrLinii; i++) {
//		for (int j = 0; j < nrColoane[i]; j++) {
//			free(matrice[i][j].nume);
//			for (int k = 0; k < matrice[i][j].nrPacienti; k++) {
//				free(matrice[i][j].numePacienti[k]);
//			}
//			free(matrice[i][j].numePacienti);
//		}
//		free(matrice[i]);
//	}
//	free(matrice);
//}