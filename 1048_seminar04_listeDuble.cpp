//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Tara {
//	char*nume;
//	int nrLocuitori;
//	float suprafata;
//};
//
//struct nod {
//	Tara informatie;
//	nod* urmator;
//	nod* precedent;
//};
//
//Tara initializareTara(const char*nume, int nrLocuitori, float suprafata) {
//	Tara t;
//	t.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(t.nume, nume);
//	t.nrLocuitori = nrLocuitori;
//	t.suprafata = suprafata;
//	return t;
//}
//
//nod* initializareNod(Tara info, nod* next, nod* prev) {
//	nod* nodNou = (nod*)malloc(sizeof(nod));
//	nodNou->informatie = info;
//	nodNou->urmator = next;
//	nodNou->precedent = prev;
//
//	return nodNou;
//}
//
//struct ListaDubluInlantuita {
//	nod* primNod;
//	nod* ultimNod;
//};
//
//ListaDubluInlantuita inserareInceput(ListaDubluInlantuita lista, Tara tara) {
//	nod* nodNou = initializareNod(tara, NULL, NULL);
//	if (lista.primNod == NULL) {
//		lista.primNod = nodNou;
//		lista.ultimNod = nodNou;
//	}
//	else {
//		nodNou->urmator = lista.primNod;
//		lista.primNod->precedent = nodNou;
//		lista.primNod = nodNou;
//	}
//	return lista;
//}
//ListaDubluInlantuita inserareSfarsit(ListaDubluInlantuita lista, Tara tara) {
//	nod* nodNou = initializareNod(tara, NULL, NULL);
//	if (lista.ultimNod == NULL) {
//		lista.primNod = nodNou;
//		lista.ultimNod = nodNou;
//	}
//	else {
//		nodNou->precedent = lista.ultimNod;
//		lista.ultimNod->urmator = nodNou;
//		lista.ultimNod = nodNou;
//	}
//	return lista;
//}
//
//ListaDubluInlantuita stergereListaDubla(ListaDubluInlantuita lista) {
//
//	while (lista.primNod) {
//		nod* nodTemporar = lista.primNod;
//		free(lista.primNod->informatie.nume);
//		
//		lista.primNod = lista.primNod->urmator;
//		free(nodTemporar);
//	}
//	lista.primNod= NULL;
//	lista.ultimNod = NULL;
//	return lista;
//}
//
//void afisareTara(Tara t) {
//	printf("Tara %s are %d locuitori si o suprafata de %5.2f.\n", t.nume, t.nrLocuitori, t.suprafata);
//}
//
//void afisareLista(ListaDubluInlantuita lista) {
//	while (lista.primNod) {
//		afisareTara(lista.primNod->informatie);
//		lista.primNod = lista.primNod->urmator;
//	}
//}
//
//Tara extragereDinListaDupaNume(ListaDubluInlantuita lista, const char* nume) {
//	while (lista.primNod && strcmp(lista.primNod->informatie.nume,nume)!=0) {
//		lista.primNod = lista.primNod->urmator;
//	}
//	if (lista.primNod) {
//		Tara t = lista.primNod->informatie;
//		if (lista.primNod->precedent) {
//			lista.primNod->precedent->urmator = lista.primNod->urmator;
//			lista.primNod->urmator->precedent = lista.primNod->precedent;
//			free(lista.primNod);
//		}
//		else {
//			nod*temp = lista.primNod;
//			lista.primNod = lista.primNod->urmator;
//			free(temp);
//		}
//		return t;
//	}
//	else {
//		return initializareTara("", 0, 0);
//	}
//}
//void main() {
//	ListaDubluInlantuita lista;
//	lista.primNod = lista.ultimNod = NULL;
//	lista = inserareSfarsit(lista, initializareTara("Ungaria", 5000, 300));
//	lista = inserareSfarsit(lista, initializareTara("Bulgaria", 3000, 200));
//	lista = inserareSfarsit(lista, initializareTara("Serbia", 2000, 100));
//
//	afisareLista(lista);
//
//	afisareTara(extragereDinListaDupaNume(lista, "Ungaria"));
//	printf("\n");
//	afisareLista(lista);
//	lista = stergereListaDubla(lista);
//}