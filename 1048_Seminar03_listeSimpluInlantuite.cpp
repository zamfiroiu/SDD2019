//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//
//struct Carte {
//	char* titlu;
//	int nrAutori;
//};
//
//struct nod {
//	Carte info;
//	nod* next;
//};
//
//Carte initCarte(const char* titlu, int nrAutori) {
//	Carte c;
//	c.titlu = (char*)malloc(sizeof(char)*(strlen(titlu) + 1));
//	strcpy(c.titlu, titlu);
//	c.nrAutori = nrAutori;
//
//	return c;
//}
//
//nod* initNod(Carte c, nod* next) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = c;//shallow copy
//	nou->next=next;
//	return nou;
//}
//
//void afisareCarte(Carte c) {
//	printf("%s este scrisa de %d autori.\n", c.titlu, c.nrAutori);
//}
//
//nod* inserareSfarsit(nod* cap, Carte c) {
//	if (cap) {
//		nod* copie = cap;
//		while (copie->next != NULL) {
//			copie = copie->next;
//		}
//		copie->next = initNod(c, NULL);
//		return cap;
//	}
//	else {
//		nod* nou = initNod(c, NULL);
//		return nou;
//	}
//
//}
//
//void afisareLista(nod* cap) {
//	while (cap != NULL) {
//		afisareCarte(cap->info);
//		cap = cap->next;
//	}
//}
//
//nod* inserareInceput(nod* cap, Carte c) {
//	nod* nou = initNod(c, cap);
//	return nou;
//}
//
//int nrAutoriTotal(nod*cap) {
//	int s = 0;
//	while (cap) {
//		s += cap->info.nrAutori;
//		cap = cap->next;
//	}
//	return s;
//}
//
//nod* stergereLista(nod* cap) {
//	while (cap) {
//		free(cap->info.titlu);
//		nod* copie = cap;
//		cap = cap->next;
//		free(copie);
//	}
//	return NULL;
//}
//
//void main() {
//	Carte c = initCarte("Ion", 1);
//	nod* nodSimplu = initNod(c, NULL);
//	nod* cap = nodSimplu;
//	afisareCarte(nodSimplu->info);
//	afisareCarte(cap->info);
//
//	nodSimplu->info.nrAutori = 5;
//
//	afisareCarte(nodSimplu->info);
//	afisareCarte(cap->info);
//
//	nod* cap2 = NULL;
//	cap2 = inserareSfarsit(cap2, initCarte("Mara", 1));
//
//	cap2 = inserareSfarsit(cap2, initCarte("Morometii", 1));
//	cap2 = inserareSfarsit(cap2, initCarte("C++", 3));
//	cap2 = inserareSfarsit(cap2, initCarte("Iona", 1));
//
//	afisareLista(cap2);
//	cap2 = inserareInceput(cap2, initCarte("Testare", 2));
//
//	afisareLista(cap2);
//
//
//	printf("%d", nrAutoriTotal(cap2));
//
//	cap2=stergereLista(cap2);
//
//	cap2 = inserareSfarsit(cap2, initCarte("carte", 2));
//	afisareLista(cap2);
//
//	cap2 = stergereLista(cap2);
//}