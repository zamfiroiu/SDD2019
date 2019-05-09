//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Avion {
//	int id;
//	int nrPasageri;
//	char* *numePasageri;
//};
//
//Avion citesteAvion(FILE* f) {
//	Avion a;
//	fscanf(f, "%d", &a.id);
//	fscanf(f, "%d", &a.nrPasageri);
//	a.numePasageri = (char**)malloc(sizeof(char*)*a.nrPasageri);
//	for (int i = 0; i < a.nrPasageri; i++) {
//		char buffer[20];
//		fscanf(f, "%s", buffer);
//		a.numePasageri[i] = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(a.numePasageri[i], buffer);
//	}
//	return a;
//}
//
//void afisareAvion(Avion a) {
//	printf("%d. Avionul are %d pasageri: \n", a.id, a.nrPasageri);
//	//afisarea pasagerilor cu un for
//}
//
//struct NOD {
//	Avion info;
//	NOD* st;
//	NOD* dr;
//};
//
//NOD* initNod(Avion a, NOD* st, NOD* dr) {
//	NOD* nou = (NOD*)malloc(sizeof(NOD));
//	nou->info = a;//shallow copy
//	nou->st = st;
//	nou->dr = dr;
//	return nou;
//}
//
//NOD* inserare(NOD* rad, Avion a) {
//	if (rad) {
//		if (rad->info.id > a.id) {
//			rad->st = inserare(rad->st, a);
//		}
//		else {
//			rad->dr = inserare(rad->dr, a);
//		}
//		return rad;
//	}
//	else {
//		return initNod(a, NULL, NULL);
//	}
//}
//
//void afisareArbore(NOD* rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		afisareAvion(rad->info);
//		afisareArbore(rad->dr);
//	}
//}
//
//Avion cautareAvion(NOD* rad, int id) {
//	if (rad) {
//		if (rad->info.id == id) {
//			return rad->info;
//		}
//		else
//		{
//			if (rad->info.id < id) {
//				return cautareAvion(rad->dr, id);
//			}
//			else {
//				return cautareAvion(rad->st, id);
//			}
//		}
//	}
//	else {
//		Avion a;
//		a.id = -1;
//		a.nrPasageri = 0;
//		a.numePasageri = NULL;
//		return a;
//	}
//}
//
//int inaltimeArbore(NOD* rad) {
//	if (rad) {
//		int hST = inaltimeArbore(rad->st);
//		int hDR = inaltimeArbore(rad->dr);
//		return 1 + (hST > hDR ? hST : hDR);
//	}
//	else {
//		return 0;
//	}
//}
//
//void afisareDePeNivel(NOD* rad, int nivelCautat, int nivelCurent) {
//	if (rad) {
//		if (nivelCautat == nivelCurent) {
//			afisareAvion(rad->info);
//		}
//		else {
//			afisareDePeNivel(rad->st, nivelCautat, nivelCurent + 1);
//			afisareDePeNivel(rad->dr, nivelCautat, nivelCurent + 1);
//		}
//	}
//}
//
//void main() {
//	NOD* rad = NULL;
//	FILE* f = fopen("avioane.txt", "r");
//	int nrAvioane = 0;
//	fscanf(f, "%d", &nrAvioane);
//	for (int i = 0; i < nrAvioane; i++) {
//		rad = inserare(rad, citesteAvion(f));
//	}
//	afisareArbore(rad);
//
//	afisareAvion(cautareAvion(rad, 8));
//
//	printf("\n\n\n %d\n\n", inaltimeArbore(rad));
//
//	afisareDePeNivel(rad, 2, 1);
//}
//
//
