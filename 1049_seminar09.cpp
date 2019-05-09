//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Fotbalist {
//	int nrTricou;
//	char* nume;
//	int varsta;
//};
//
//Fotbalist citesteFotbalist(FILE* f) {
//	Fotbalist fotbalist;
//	fscanf(f, "%d", &fotbalist.nrTricou);
//	char buffer[20];
//	fscanf(f, "%s", buffer);
//	fotbalist.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(fotbalist.nume, buffer);
//	fscanf(f, "%d", &fotbalist.varsta);
//
//	return fotbalist;
//}
//
//void afisareFotbalist(Fotbalist f) {
//	printf("%d. %s are %d ani.\n", f.nrTricou, f.nume, f.varsta);
//}
//
//struct NOD {
//	Fotbalist info;
//	NOD* st;
//	NOD* dr;
//};
//
//NOD* initNod(Fotbalist info, NOD* st, NOD*dr) {
//	NOD* nou = (NOD*)malloc(sizeof(NOD));
//	nou->info = info;//shallow copy
//	nou->st = st;
//	nou->dr = dr;
//
//	return nou;
//}
//
//NOD* inserareInArbore(NOD* rad, Fotbalist f) {
//	if (rad) {
//		if (rad->info.nrTricou > f.nrTricou) {
//			rad->st = inserareInArbore(rad->st, f);
//		}
//		else {
//			rad->dr = inserareInArbore(rad->dr, f);
//		}
//		return rad;
//	}
//	else {
//		return initNod(f, NULL, NULL);
//	}
//}
//
//void afisareArbore(NOD* rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		afisareFotbalist(rad->info);
//		afisareArbore(rad->dr);
//	}
//}
//
//Fotbalist cautareFotbalist(NOD * rad, int numar) {
//	if (rad) {
//		if (rad->info.nrTricou == numar) {
//			return rad->info;
//		}
//		else {
//			if (rad->info.nrTricou > numar) {
//				return cautareFotbalist(rad->st, numar);
//			}
//			else {
//				return cautareFotbalist(rad->dr, numar);
//			}
//		}
//	}
//	else {
//		Fotbalist f;
//		f.nrTricou = -1;
//		f.varsta = -1;
//		f.nume = NULL;
//		return f;
//	}
//}
//
//int inaltimeArbore(NOD* rad) {
//	if (rad) {
//		int iST = inaltimeArbore(rad->st);
//		int iDR = inaltimeArbore(rad->dr);
//		return 1 + (iST > iDR ? iST : iDR);
//	}
//	else {
//		return 0;
//	}
//
//}
//
//void afisareDePeNivel(NOD* rad, int nivelDorit, int nivelCurent) {
//	if (rad) {
//		if (nivelDorit == nivelCurent) {
//			afisareFotbalist(rad->info);
//		}
//		else {
//			afisareDePeNivel(rad->st, nivelDorit, nivelCurent + 1);
//			afisareDePeNivel(rad->dr, nivelDorit, nivelCurent + 1);
//		}
//	}
//}
//
//void afisareAtacanti(NOD* rad, int numarMinim) {
//	if (rad) {
//		if (rad->info.nrTricou >= numarMinim) {
//			afisareFotbalist(rad->info);
//			afisareArbore(rad->dr);
//		}
//		else {
//			afisareAtacanti(rad->dr, numarMinim);
//		}
//		afisareAtacanti(rad->st, numarMinim);
//
//	}
//}
//
//void afisareArbore(NOD* rad, int numar) {
//	if (rad) {
//		afisareArbore(rad->st,numar);
//		if (rad->info.nrTricou >= numar)
//			afisareFotbalist(rad->info);
//		afisareArbore(rad->dr,numar);
//	}
//}
//
//void main() {
//	FILE* f = fopen("fotbalisti.txt", "r");
//
//	NOD* rad=NULL;
//
//	int nrFotbalisti = 0;
//	fscanf(f, "%d", &nrFotbalisti);
//	for (int i = 0; i < nrFotbalisti; i++) {
//		rad = inserareInArbore(rad, citesteFotbalist(f));
//	}
//
//	afisareArbore(rad);
//
//	printf("\n\n");
//
//	afisareFotbalist(cautareFotbalist(rad, 3));
//
//	printf("\n\n%d\n\n",inaltimeArbore(rad));
//
//	afisareDePeNivel(rad, 3, 1);
//	printf("\n\n");
//
//	afisareAtacanti(rad, 5);
//}