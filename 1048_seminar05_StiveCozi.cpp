//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//struct Cinema {
//	char* nume;
//	int nrSali;
//	float incasariLunare;
//};
//
//
//
//Cinema initCinema(const char* nume, int nrSali, float incasari) {
//	Cinema c;
//	c.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(c.nume, nume);
//	c.nrSali = nrSali;
//	c.incasariLunare = incasari;
//
//	return c;
//}
//
//void afisareCinema(Cinema c) {
//	printf("In cinematograful %s sunt %d sali iar incasarile sunt de %5.2f.\n", c.nume, c.nrSali, c.incasariLunare);
//}
//
//struct Nod {
//	Nod* next;
//	Cinema info;
//};
//
//struct NodDublu {
//	Cinema info;
//	NodDublu*next;
//	NodDublu*prev;
//};
//
//struct ListaDubla {
//	NodDublu* prim;
//	NodDublu*ultim;
//};
//
//ListaDubla pushQueue(ListaDubla lista, Cinema c) {
//	NodDublu* nodNou = (NodDublu*)malloc(sizeof(NodDublu));
//	nodNou->info = c;
//	nodNou->prev = lista.ultim;
//	nodNou->next = NULL;
//	if (lista.ultim) {
//		lista.ultim->next = nodNou;
//		lista.ultim = nodNou;
//	}
//	else {
//		lista.prim = lista.ultim = nodNou;
//	}
//	return lista;
//}
//
//Cinema popQueue(ListaDubla &lista) {
//	if (lista.prim) {
//		Cinema rezultat = lista.prim->info;
//		NodDublu* copie = lista.prim;
//		lista.prim = lista.prim->next;
//		if (lista.prim) {
//			lista.prim->prev = NULL;
//		}
//		else {
//			lista.ultim = NULL;
//		}
//		free(copie);
//		return rezultat;
//	}
//	
//	return initCinema("", 0, 0);	
//}
//
//int isEmptyQueue(ListaDubla lista) {
//	return lista.prim == NULL;
//}
//
//Nod* pushStack(Nod*cap, Cinema c) {
//	Nod* temp = (Nod*)malloc(sizeof(Nod));
//	temp->info = c;
//	temp->next = cap;
//
//	return temp;
//}
//
//Cinema popStack(Nod* &cap) {
//	if (cap) {
//		Cinema rezultat = cap->info;
//		Nod* copie = cap;
//		cap = cap->next;
//		free(copie);
//		return rezultat;
//	}
//	return initCinema("", 0, 0);
//}
//
//int isEmptyStack(Nod*cap) {
//	return cap == NULL;
//}
//
//void main(){
//	Nod* stiva = NULL;
//	stiva = pushStack(stiva, initCinema("CinemaCity", 6, 1000));
//	stiva = pushStack(stiva, initCinema("MoviePlex", 7, 2000));
//	stiva = pushStack(stiva, initCinema("Imax", 8, 500));
//	stiva = pushStack(stiva, initCinema("Gloria", 5, 4000));
//
//	while (!isEmptyStack(stiva)) {
//		Cinema c = popStack(stiva);
//		afisareCinema(c);
//		free(c.nume);
//	}
//	printf("\n\n");
//	stiva = pushStack(stiva, initCinema("HappyCinema", 3, 1000));
//	while (!isEmptyStack(stiva)) {
//		afisareCinema(popStack(stiva));
//	}
//
//	printf("\n\n\n");
//	ListaDubla coada;
//	coada.prim = coada.ultim = NULL;
//	coada = pushQueue(coada, initCinema("CinemaCity", 6, 1000));
//	coada = pushQueue(coada, initCinema("MoviePlex", 7, 2000));
//	coada = pushQueue(coada, initCinema("Imax", 8, 500));
//	coada = pushQueue(coada, initCinema("Gloria", 5, 4000));
//
//	while (!isEmptyQueue(coada)) {
//		afisareCinema(popQueue(coada));
//	}
//	printf("\n\n");
//	coada = pushQueue(coada, initCinema("HappyCinema", 3, 1000));
//	while (!isEmptyQueue(coada)) {
//		afisareCinema(popQueue(coada));
//	}
//
//}