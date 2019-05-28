//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Comanda {
//	int id;
//	char* denumire;
//};
//
//struct nodStiva {
//	int id;
//	nodStiva*next;
//};
//
//nodStiva * push(nodStiva* cap, int id) {
//	nodStiva* nodNou = (nodStiva*)malloc(sizeof(nodStiva));
//	nodNou->id = id;
//	nodNou->next = NULL;
//	if (cap) {
//		nodStiva* p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nodNou;
//	}
//	else {
//		cap = nodNou;
//	}
//	return cap;
//}
//int pop(nodStiva* &cap) {
//	if (cap) {
//		nodStiva*p = cap;
//		while (p->next && p->next->next) {
//			p = p->next;
//		}
//		if (p->next) {
//			int rezultat = p->next->id;
//			free(p->next);
//			p->next = NULL;
//			return rezultat;
//		}
//		else {
//			int rezultat = p->id;
//			free(p);
//			cap = NULL;
//			return rezultat;
//		}
//	}
//	else {
//		return -1;//nu exista id-ul
//	}
//}
//
//struct nodListaPrincipala;
//
//struct nodListaSimpla {
//	nodListaPrincipala* info;
//	nodListaSimpla*next;
//};
//
//struct nodListaPrincipala {
//	Comanda info;
//	nodListaPrincipala* next;
//	nodListaSimpla* adiacente;
//};
//
//nodListaSimpla* inserareListaSimpla(nodListaSimpla* cap, nodListaPrincipala* nod) {
//	nodListaSimpla* nodNou = (nodListaSimpla*)malloc(sizeof(nodListaSimpla));
//	nodNou->next = NULL;
//	nodNou->info = nod;
//	if (cap) {
//		nodListaSimpla*temp = cap;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next = nodNou;
//	}
//	else {
//		cap = nodNou;
//	}
//	return cap;
//}
//
//nodListaPrincipala* inserareListaPrincipala(nodListaPrincipala* cap, Comanda c) {
//	nodListaPrincipala* nodNou = (nodListaPrincipala*)malloc(sizeof(nodListaPrincipala));
//	nodNou->adiacente = NULL;
//	nodNou->info = c;
//	nodNou->next = NULL;
//	if (cap) {
//		nodListaPrincipala* p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nodNou;
//	}
//	else {
//		cap = nodNou;
//	}
//
//	return cap;
//}
//
//nodListaPrincipala* cautareDupaID(nodListaPrincipala*cap, int id) {
//	while (cap && cap->info.id != id) {
//		cap = cap->next;
//	}
//	return cap;
//}
//
//void adaugareArcInGrafNeorientat(int de_la, int pana_la, nodListaPrincipala* graf) {
//	nodListaPrincipala* DE = cautareDupaID(graf, de_la);
//	nodListaPrincipala* PANA = cautareDupaID(graf, pana_la);
//	if (DE && PANA) {
//		DE->adiacente = inserareListaSimpla(DE->adiacente, PANA);
//		PANA->adiacente = inserareListaSimpla(PANA->adiacente, DE);
//	}
//
//}
//
//void afisareListaSimpla(nodListaSimpla* cap) {
//	while (cap) {
//		printf("     %d. %s\n", cap->info->info.id, cap->info->info.denumire);
//		cap = cap->next;
//	}
//}
//
//void afisareGraf(nodListaPrincipala* graf) {
//	while (graf) {
//		printf("%d.%s are nodurile adiacente:\n", graf->info.id, graf->info.denumire);
//		afisareListaSimpla(graf->adiacente);
//		graf = graf->next;
//	}
//}
//
//int calculareNrNoduri(nodListaPrincipala* cap) {
//	int nr = 0;
//	while (cap) {
//		nr++;
//		cap = cap->next;
//	}
//
//	return nr;
//}
//
//void parcurgereInAdancime(nodListaPrincipala*graf, int nodStart) {
//	//1. ne luam o stiva
//	//2. adaugam nodul de start in stiva;
//	//3. luam un vector de vizitate initializat cu 0 pe toate pozitiile
//	//4. vizitam nodul de start;
//	//5. extragem element din stiva
//	//6. il afisam/ procesam
//	//7. adaugam in stiva nodurile adiacente nevizitate
//	//8. ne intarcem la pasul 5
//	nodStiva* stiva = NULL;
//	stiva = push(stiva, nodStart);
//	int nrNoduri = calculareNrNoduri(graf);
//	int*vizitate = (int*)malloc(sizeof(int)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		vizitate[i] = 0;
//	}
//	vizitate[nodStart] = 1;
//	while (stiva) {
//		int nodCurent = pop(stiva);
//		nodListaPrincipala* nodC = cautareDupaID(graf, nodCurent);
//		printf("%d.%s", nodC->info.id,nodC->info.denumire);
//		nodListaSimpla* temp = nodC->adiacente;
//		while (temp) {
//			if (vizitate[temp->info->info.id] == 0) {
//				stiva = push(stiva, temp->info->info.id);
//				vizitate[temp->info->info.id] = 1;
//			}
//			temp = temp->next;
//		}
//
//	}
//}
//
//int** citireMatriceAdiacenta(int& nrNoduri) {
//	printf("Numar noduri:");
//	scanf("%d", &nrNoduri);
//	int** matrice = (int**)malloc(sizeof(int*)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		matrice[i] = (int*)malloc(sizeof(int)*nrNoduri);
//		for (int j = 0; j < nrNoduri; j++) {
//			matrice[i][j] = 0;
//		}
//	}
//
//	int nrArce;
//	printf("Numar arce:");
//	scanf("%d", &nrArce);
//	for (int i = 0; i < nrArce; i++) {
//		int idStart;
//		printf("Id start:");
//		scanf("%d", &idStart);
//		int idStop;
//		printf("Id stop:");
//		scanf("%d", &idStop);
//		matrice[idStart][idStop] = 1;
//		matrice[idStop][idStart] = 1;
//	}
//	return matrice;
//}
//
//struct nodCoada {
//	nodCoada* next;
//	int id;
//};
//
//void inserareCoada(nodCoada* &cap, int id) {
//	nodCoada* nou = (nodCoada*)malloc(sizeof(nodCoada));
//	nou->id = id;
//	nou->next = NULL;
//	if (cap) {
//		nodCoada* p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//}
//
//int extragereCoada(nodCoada* &cap) {
//	if (cap) {
//		int rezultat = cap->id;
//		nodCoada* aux = cap;
//		cap = cap->next;
//		free(aux);
//		return rezultat;
//	}
//	else {
//		return -1;//id inexistent sau de cod eroare
//	}
//}
//
//
//void parcurgereInLatimeMatrice(int** graf, int idNodStart, int nrNoduri) {
//	//1. definim o coada
//	//2. punem nodul de start in coada
//	//3. luam un vector de vizitate
//	//4. vizitam nodul de start;
//	//5. Cat timp avem elemente in coada:
//	//6. extragem nod din coada
//	//7. cautam nodurile adiacente nevizitate si le inseram in coada
//	//8. procesam nodul curent-cel extras
//	nodCoada*coada = NULL;
//	inserareCoada(coada, idNodStart);
//	int*vizitate = (int *)malloc(sizeof(int)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		vizitate[i] = 0;
//	}
//	vizitate[idNodStart] = 1;
//	while (coada) {
//		int idNodCurent = extragereCoada(coada);
//		printf("%d", idNodCurent);
//		for (int i = 0; i < nrNoduri; i++) {
//			if (graf[idNodCurent][i] == 1 && vizitate[i] == 0) {
//				inserareCoada(coada, i);
//				vizitate[i] = 1;
//			}
//		}
//	}
//}
//
//struct nodListaComenzi{
//	Comanda info;
//	nodListaComenzi*next;
//};
//
//void inserareComandaInLista(nodListaComenzi*&cap, Comanda c) {
//	nodListaComenzi*nou = (nodListaComenzi*)malloc(sizeof(nodListaComenzi));
//	nou->next = cap;
//	nou->info = c;
//	cap = nou;
//}
//
//nodListaComenzi * transformareGrafLatimeInLista(nodListaPrincipala*graf, int idNodStart) {
//	//1. definim o coada
//	//2. punem nodul de start in coada
//	//3. luam un vector de vizitate
//	//4. vizitam nodul de start;
//	//5. Cat timp avem elemente in coada:
//	//6. extragem nod din coada
//	//7. cautam nodurile adiacente nevizitate si le inseram in coada
//	//8. procesam nodul curent-cel extras
//	nodCoada* coada = NULL;
//	inserareCoada(coada, idNodStart);
//	int nrNoduri = calculareNrNoduri(graf);
//	int*vizitate = (int *)malloc(sizeof(int)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		vizitate[i] = 0;
//	}
//	vizitate[idNodStart] = 1;
//	nodListaComenzi*cap = NULL;
//	while (coada) {
//		int idNodCurent = extragereCoada(coada);
//		nodListaPrincipala* nodCurent = cautareDupaID(graf,idNodCurent);
//		//procesare
//		Comanda c;
//		c.id = idNodCurent;
//		c.denumire = (char*)malloc(sizeof(char)*(strlen(nodCurent->info.denumire) + 1));
//		strcpy(c.denumire, nodCurent->info.denumire);
//
//		inserareComandaInLista(cap, c);
//		nodListaSimpla*p = nodCurent->adiacente;
//		while (p) {
//			if (vizitate[p->info->info.id] == 0) {
//				inserareCoada(coada, p->info->info.id);
//				vizitate[p->info->info.id] = 1;
//			}
//			p = p->next;
//		}
//	}
//	return cap;
//}
//
//void afisareListaComenzi(nodListaComenzi* cap) {
//	while (cap) {
//		printf("%d.%s", cap->info.id, cap->info.denumire);
//		cap = cap->next;
//	}
//}
//
//void main() {
//	//int nrNoduri = 0;
//	//int** matrice = citireMatriceAdiacenta(nrNoduri);
//
//	//parcurgereInLatimeMatrice(matrice, 3, nrNoduri);
//
//
//	nodListaPrincipala* graf = NULL;
//	printf("Cate noduri avem:");
//	int nrNoduri = 0;
//	scanf("%d", &nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		Comanda c;
//		c.id = i;
//		char buffer[20];
//		printf("Denumirea comenzii:");
//		scanf("%s", buffer);
//		c.denumire = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(c.denumire, buffer);
//		graf = inserareListaPrincipala(graf, c);
//	}
//	printf("Cate Arce avem:");
//	int nrArce = 0;
//	scanf("%d", &nrArce);
//	for (int i = 0; i < nrArce; i++) {
//		printf("De la:");
//		int de_la = 0;
//		scanf("%d", &de_la);
//		printf("Pana la:");
//		int pana_la = 0;
//		scanf("%d", &pana_la);
//		adaugareArcInGrafNeorientat(de_la, pana_la, graf);
//	}
//	nodListaComenzi* cap = transformareGrafLatimeInLista(graf, 3);
//	afisareListaComenzi(cap);
//}