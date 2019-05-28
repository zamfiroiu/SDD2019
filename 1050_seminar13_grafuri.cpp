//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Drink {
//	int id;
//	char* denumire;
//};
//
//struct nodListaPrincipala;
//
//struct nodListaSimpla {
//	nodListaPrincipala* info;
//	nodListaSimpla* next;
//};
//
//struct nodListaPrincipala {
//	nodListaSimpla* noduriAdiacente;
//	nodListaPrincipala* next;
//	Drink info;
//};
//
//nodListaPrincipala* inserareListaPrincipala(nodListaPrincipala*cap, Drink d) {
//	nodListaPrincipala* nodNou = (nodListaPrincipala*)malloc(sizeof(nodListaPrincipala));
//	nodNou->next = cap;
//	nodNou->noduriAdiacente = NULL;
//	nodNou->info = d;
//	return nodNou;
//}
//
//nodListaSimpla* inserareListaSimpla(nodListaSimpla* cap, nodListaPrincipala* info) {
//	nodListaSimpla* nodNou = (nodListaSimpla*)malloc(sizeof(nodListaSimpla));
//	nodNou->next = cap;
//	nodNou->info = info;
//	return nodNou;
//}
//nodListaPrincipala* cautareNodDupaID(nodListaPrincipala* cap, int id) {
//	while (cap && cap->info.id != id) {
//		cap = cap->next;
//	}
//	return cap;
//}
//
//void inserareArcInGraf(nodListaPrincipala* graf, int nodStart, int nodStop) {
//	nodListaPrincipala* from = cautareNodDupaID(graf, nodStart);
//	nodListaPrincipala* to = cautareNodDupaID(graf, nodStop);
//	if (from && to) {
//		from->noduriAdiacente = inserareListaSimpla(from->noduriAdiacente, to);
//		to->noduriAdiacente = inserareListaSimpla(to->noduriAdiacente, from);
//	}
//}
//
//void afisareListaSimpla(nodListaSimpla* cap) {
//	while (cap) {
//		printf("    %d.%s\n", cap->info->info.id,cap->info->info.denumire);
//		cap = cap->next;
//	}
//}
//
//void afisareListaPrincipala(nodListaPrincipala* cap) {
//	while (cap) {
//		printf("%d.%s are vecini:\n", cap->info.id, cap->info.denumire);
//		afisareListaSimpla(cap->noduriAdiacente);
//		cap = cap->next;
//	}
//}
//
//struct nodStiva {
//	int id;
//	nodStiva*next;
//};
//
//nodStiva* push(nodStiva* cap, int id) {
//	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
//	nou->next = cap;
//	nou->id = id;
//	return nou;
//}
//
//int pop(nodStiva*&cap) {
//	if (cap) {
//		int id = cap->id;
//		cap = cap->next;
//		return id;
//	}
//	else {
//		return -1;
//	}
//}
//
//int calculareNumarNoduri(nodListaPrincipala* graf) {
//	int nr = 0;
//	while (graf) {
//		nr++;
//		graf = graf->next;
//	}
//
//	return nr;
//}
//
//void parcurgereInAdancime(nodListaPrincipala* graf, int idNodStart) {
//	if (graf) {
//		//1. initializam stiva si vectorul de vizitate;
//		//2. inseram nodul de start in stiva si il marcam ca vizitat
//		//3. extragem un nod din stiva
//		//4. afisam/procesam nodul extras
//		//5. adaugam in stiva nodurile adiacente nevizitate marcandu-le ca find vizitate
//		//6. ne intoarcem la pasul 3
//		nodStiva* stiva = NULL;
//		int nrNoduri = calculareNumarNoduri(graf);
//		int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
//		for (int i = 0; i < nrNoduri; i++) {
//			vizitate[i] = 0;
//		}
//		stiva = push(stiva, idNodStart);
//		vizitate[idNodStart] = 1;
//		while (stiva) {
//			int idNodCurent = pop(stiva);
//			nodListaPrincipala* nodCurent = cautareNodDupaID(graf, idNodCurent);
//			printf("%d.%s\n", nodCurent->info.id, nodCurent->info.denumire);
//			nodListaSimpla* p = nodCurent->noduriAdiacente;
//			while (p) {
//				if (vizitate[p->info->info.id] == 0) {
//					stiva = push(stiva, p->info->info.id);
//					vizitate[p->info->info.id] = 1;
//				}
//				p = p->next;
//			}
//		}
//	}
//}
//
//
//int**citireMatriceAdiacenta(int &nrNoduri, Drink* &bauturi) {
//	printf("Numar noduri:");
//	scanf("%d", &nrNoduri);
//	int**matrice = (int**)malloc(sizeof(int*)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		matrice[i] = (int*)malloc(sizeof(int)*nrNoduri);
//		for (int j = 0; j < nrNoduri; j++) {
//			matrice[i][j] = 0;
//		}
//	}
//	//citire bauturi
//	bauturi = (Drink*)malloc(sizeof(Drink)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		Drink d;
//		printf("Id-ul bauturii:");
//		scanf("%d", &d.id);
//		char buffer[20];
//		printf("Numele bauturii:");
//		scanf("%s", buffer);
//		d.denumire = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(d.denumire, buffer);
//		bauturi[i] = d;
//	}
//
//	int nrArce = 0;
//	printf("Numar arce:");
//	scanf("%d", &nrArce);
//
//	for (int i = 0; i < nrArce; i++) {
//		int from = 0;
//		printf("Nod start:");
//		scanf("%d", &from);
//		int to = 0;
//		printf("Nod stop:");
//		scanf("%d", &to);
//		matrice[from][to] = 1;
//		matrice[to][from] = 1;
//	}
//	return matrice;
//}
//
//struct nodListaBauturi{
//	Drink info;
//	nodListaBauturi*next;
//};
//
//void inserareBauturaInLista(nodListaBauturi* &cap, Drink d) {
//	nodListaBauturi* nou = (nodListaBauturi*)malloc(sizeof(nodListaBauturi));
//	nou->next = cap;
//	nou->info = d;
//	cap = nou;
//}
//
//struct nodCoada {
//	int id;
//	nodCoada* next;
//};
//
//void inserareCoada(nodCoada* &cap, int id) {
//	nodCoada*nou = (nodCoada*)malloc(sizeof(nodCoada));
//	nou->next = NULL;
//	nou->id = id;
//	if (cap) {
//		nodCoada*p = cap;
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
//		nodCoada*aux = cap;
//		cap = cap->next;
//		free(aux);
//		return rezultat;
//	}
//	else {
//		return -1;//cod eroare
//	}
//}
//
//nodListaBauturi* copiereBauturiDinGrafLatimeInLista(int**matrice, int nrNoduri, int idNodStart, Drink* bauturi) {
//	nodCoada* coada = NULL;
//	int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		vizitate[i] = 0;
//	}
//	inserareCoada(coada, idNodStart);
//	vizitate[idNodStart] = 1;
//	nodListaBauturi* listaBauturi = NULL;
//	while (coada) {
//		int idNodCurent = extragereCoada(coada);
//		//procesare
//		Drink d;
//		d.id = bauturi[idNodCurent].id;
//		d.denumire = (char*)malloc(sizeof(char)*(strlen(bauturi[idNodCurent].denumire) + 1));
//		strcpy(d.denumire, bauturi[idNodCurent].denumire);
//		inserareBauturaInLista(listaBauturi, d);
//
//		for (int i = 0; i < nrNoduri; i++) {
//			if (matrice[idNodCurent][i] == 1 && vizitate[i] == 0) {
//				inserareCoada(coada, i);
//				vizitate[i] = 1;
//			}
//		}
//	}
//	return listaBauturi;
//}
//
//void afisareListaBauturi(nodListaBauturi*cap) {
//	while (cap) {
//		printf("%d.%s\n", cap->info.id, cap->info.denumire);
//		cap = cap->next;
//	}
//}
//
//void afisareListaBauturiRecursiva(nodListaBauturi*cap) {
//	if (cap) {
//		afisareListaBauturiRecursiva(cap->next);
//		printf("%d.%s\n", cap->info.id, cap->info.denumire);
//
//	}
//}
//
//void main() {
//	/*nodListaPrincipala* graf = NULL;
//	int nrNoduri = 0;
//	printf("NUmar noduri:");
//	scanf("%d", &nrNoduri);
//	for (int i = nrNoduri-1; i>=0; i--) {
//		Drink d;
//		d.id = i;
//		char buffer[20];
//		printf("Numele bauturii:");
//		scanf("%s", buffer);
//		d.denumire = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(d.denumire, buffer);
//		graf = inserareListaPrincipala(graf, d);
//	}
//	int nrArce = 0;
//	printf("NUmar arce:");
//	scanf("%d", &nrArce);
//
//	for (int i = 0; i < nrArce; i++) {
//		int from = 0;
//		printf("Nod start:");
//		scanf("%d", &from);
//		int to = 0;
//		printf("Nod stop:");
//		scanf("%d", &to);
//		inserareArcInGraf(graf, from, to);
//	}
//
//	afisareListaPrincipala(graf);
//
//	parcurgereInAdancime(graf, 0);*/
//	
//	int nrNoduri = 0;
//	Drink* vector = NULL;
//	int**graf = citireMatriceAdiacenta(nrNoduri,vector);
//	nodListaBauturi*listaBauturi = copiereBauturiDinGrafLatimeInLista(graf,nrNoduri,0,vector);
//	afisareListaBauturiRecursiva(listaBauturi);
//	
//
//
//
//}