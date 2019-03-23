//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Muzeu {
//	int nrVizitatori;
//	char* denumire;
//	float pretBilet;
//};
//
//Muzeu initializareMuzeu(int nrVizitatori, const char* denumire, float pret) {
//	Muzeu m;
//	m.nrVizitatori = nrVizitatori;
//	m.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	strcpy(m.denumire, denumire);
//	m.pretBilet = pret;
//
//	return m;
//}
//
//void printMuzeu(Muzeu m) {
//	printf("Muzeul %s are incasari de %5.2f\n", m.denumire, m.nrVizitatori*m.pretBilet);
//}
//
//struct Nod {
//	Muzeu info;
//	Nod* next;
//};
//
//
//Nod* pushStack(Nod* cap, Muzeu m) {
//	//la inceput
//	Nod*nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = m;
//	nodNou->next = cap;
//	return nodNou;
//}
//
//Muzeu popStack(Nod* &cap) {
//	if (cap) {
//		Muzeu rezultat = initializareMuzeu(cap->info.nrVizitatori,cap->info.denumire,cap->info.pretBilet);
//		Nod* aux = cap;
//		cap = cap->next;
//		free(aux->info.denumire);
//		free(aux);
//		return rezultat;
//	}
//	else {
//		return initializareMuzeu(0, "", 0);
//	}
//}
//
//int isEmptyStack(Nod* cap) {
//	return cap == NULL;
//}
//
//struct NodDublu {
//	Muzeu info;
//	NodDublu *next; 
//	NodDublu* prev;
//};
//
//struct ListaDubla {
//	NodDublu*prim;
//	NodDublu*ultim;
//};
//
//
//ListaDubla pushQueue(ListaDubla lista, Muzeu m) {
//	NodDublu* nodNou = (NodDublu*)malloc(sizeof(NodDublu));
//	nodNou->info = m;
//	nodNou->next = NULL;
//	nodNou->prev = lista.ultim;
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
//Muzeu popQueue(ListaDubla &lista) {
//	if (lista.prim) {
//		Muzeu rez = lista.prim->info;
//		NodDublu* aux = lista.prim;
//		lista.prim = lista.prim->next;
//		free(aux);
//		if(lista.prim){
//			lista.prim->prev = NULL;
//		}
//		else {
//			lista.ultim = NULL;
//		}
//		return rez;
//	}
//	else {
//		return initializareMuzeu(0, "", 0);
//	}
//}
//
//int isEmptyQueue(ListaDubla lista) {
//	return lista.prim == NULL;
//}
//
//Muzeu IncasariMaxime(Nod* &stiva) {
//	if (stiva) {
//		Muzeu rezultat = initializareMuzeu(0, "Default", 0);
//		Nod* aux = NULL;
//		while (!isEmptyStack(stiva)) {
//			Muzeu m = popStack(stiva);
//			if (m.nrVizitatori*m.pretBilet > rezultat.nrVizitatori*rezultat.pretBilet) {
//				rezultat = m;
//			}
//			aux = pushStack(aux, m);
//		}
//		rezultat = initializareMuzeu(rezultat.nrVizitatori, rezultat.denumire, rezultat.pretBilet);
//		while (!isEmptyStack(aux)) {
//			stiva = pushStack(stiva,popStack(aux));
//		}
//		return rezultat;
//	}
//}
//
//
//void main() {
//
//	Nod* stiva = NULL;
//	stiva = pushStack(stiva, initializareMuzeu(1000, "Luvru", 30));
//	stiva = pushStack(stiva, initializareMuzeu(300, "Antipa", 40));
//	stiva = pushStack(stiva, initializareMuzeu(100, "Muzeul satului", 15));
//	stiva = pushStack(stiva, initializareMuzeu(50, "Ceasului", 20));
//
//	while (!isEmptyStack(stiva)) {
//		printMuzeu(popStack(stiva));
//	}
//
//
//	ListaDubla coada;
//	coada.prim = NULL;
//	coada.ultim = NULL;
//	coada = pushQueue(coada, initializareMuzeu(1000, "Luvru", 30));
//	coada = pushQueue(coada, initializareMuzeu(300, "Antipa", 40));
//	coada = pushQueue(coada, initializareMuzeu(100, "Muzeul satului", 15));
//	coada = pushQueue(coada, initializareMuzeu(50, "Ceasului", 20));
//
//	/*printf("\n\n\n");
//	while (!isEmptyQueue(coada)) {
//		printMuzeu(popQueue(coada));
//	}*/
//	while (!isEmptyQueue(coada)) {
//		stiva=pushStack(stiva,popQueue(coada));
//	}
//
//	Muzeu m = IncasariMaxime(stiva);
//	printf("\n\n\nMaxim");
//	printMuzeu(m);
//	free(m.denumire);
//	printf("\n\n\n");
//
//	while (!isEmptyStack(stiva)) {
//		Muzeu m = popStack(stiva);
//		printMuzeu(m);
//		free(m.denumire);
//	}
//
//	
//
//
//}
//
