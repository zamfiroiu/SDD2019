//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Muzeu {
//	int id;
//	char* nume;
//};
//
//struct nodListaPrincipala;
//
//struct nodListaSecundara {
//	nodListaPrincipala*info;
//	nodListaSecundara* next;
//};
//
//struct nodListaPrincipala {
//	Muzeu info;
//	nodListaSecundara* vecini;
//	nodListaPrincipala*next;
//};
//
//nodListaSecundara* inserareListaSecundara(nodListaSecundara* cap, nodListaPrincipala* info) {
//	nodListaSecundara* nou = (nodListaSecundara*)malloc(sizeof(nodListaSecundara));
//	nou->next = cap;
//	nou->info = info;
//	return nou;
//}
//
//nodListaPrincipala* inseareListaPrincipala(nodListaPrincipala* cap, Muzeu info) {
//	nodListaPrincipala* nou = (nodListaPrincipala*)malloc(sizeof(nodListaPrincipala));
//	nou->info = info;
//	nou->next = NULL;
//	nou->vecini = NULL;
//	if (cap) {
//		nodListaPrincipala*p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//	return cap;
//}
//
//nodListaPrincipala* cautareNodDupaIDMuzeu(nodListaPrincipala*cap, int id) {
//	while (cap && cap->info.id != id) {
//		cap = cap->next;
//	}
//	return cap;
//}
//
//void adaugareArcInGraf(nodListaPrincipala* graf, int idStart, int idStop) {
//	nodListaPrincipala*nodStart = cautareNodDupaIDMuzeu(graf, idStart);
//	nodListaPrincipala*nodStop = cautareNodDupaIDMuzeu(graf, idStop);
//	if (nodStart && nodStop) {
//		nodStart->vecini = inserareListaSecundara(nodStart->vecini, nodStop);
//		nodStop->vecini = inserareListaSecundara(nodStop->vecini, nodStart);
//	}
//}
//
//
//void afisareListaSecundara(nodListaSecundara* cap) {
//	while (cap) {
//		printf("      %d.%s\n", cap->info->info.id, cap->info->info.nume);
//		cap = cap->next;
//	}
//}
//
//void afisareListaPrincipala(nodListaPrincipala* cap) {
//	while (cap) {
//		printf("      %d.%s are ca vecini urmatoarele muzee\n", cap->info.id, cap->info.nume);
//		afisareListaSecundara(cap->vecini);
//		cap = cap->next;
//	}
//}
//
//struct nodCoada {
//	int id;
//	nodCoada* next;
//};
//
//nodCoada* inserareCoada(nodCoada* cap, int id) {
//	nodCoada* nou = (nodCoada*)malloc(sizeof(nodCoada));
//	nou->id = id;
//	nou->next = NULL;
//	if (cap) {
//		nodCoada*p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//		return cap;
//	}
//	else {
//		return nou;
//	}
//}
//
//int extragereDinCoada(nodCoada* &cap) {
//	if (cap) {
//		int rezultat = cap->id;
//		nodCoada* aux = cap;
//		cap = cap->next;
//		free(aux);
//		return rezultat;
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
//	return nr;
//}
//
//void parcurgereInLatime(nodListaPrincipala* graf, int idStart) {
//	if (graf) {
//		nodCoada* coada = NULL;
//		int nrNoduri = calculareNumarNoduri(graf);
//		int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
//		for (int i = 0; i < nrNoduri; i++) {
//			vizitate[i] = 0;
//		}
//
//		coada = inserareCoada(coada, idStart);
//		vizitate[idStart] = 1;
//
//		while (coada) {
//			int idNodCurent = extragereDinCoada(coada);
//			nodListaPrincipala* nodCurent = cautareNodDupaIDMuzeu(graf, idNodCurent);
//			printf("%d.%s\n", nodCurent->info.id, nodCurent->info.nume);
//			nodListaSecundara* p = nodCurent->vecini;
//
//			while (p) {
//				if (vizitate[p->info->info.id] == 0) {
//					vizitate[p->info->info.id] = 1;
//					coada = inserareCoada(coada, p->info->info.id);
//				}
//				p = p->next;
//			}
//
//		}
//	}
//}
//
//void citireGrafDeMuzee(Muzeu* &muzee, int** &matrice, int &nrNoduri) {
//
//	
//	printf("Numar noduri:");
//	scanf("%d", &nrNoduri);
//
//	muzee = (Muzeu*)malloc(sizeof(Muzeu)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		printf("Id-ul muzeului:");
//		scanf("%d", &muzee[i].id);
//		char buffer[20];
//		printf("Numele muzeului:");
//		scanf("%s", buffer);
//		muzee[i].nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//		strcpy(muzee[i].nume, buffer);
//	}
//
//	matrice = (int**)malloc(sizeof(int*)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		matrice[i] = (int*)malloc(sizeof(int)*nrNoduri);
//		for (int j = 0; j < nrNoduri; j++) {
//			matrice[i][j] = 0;
//		}
//	}
//	int nrArce = 0;
//	printf("Numar arce:");
//	scanf("%d", &nrArce);
//	for (int i = 0; i < nrArce; i++) {
//		int idNodStart = 0;
//		printf("Id nod start:");
//		scanf("%d", &idNodStart);
//		int idNodStop = 0;
//		printf("Id nod stop:");
//		scanf("%d", &idNodStop);
//		matrice[idNodStart][idNodStop] = 1;
//		matrice[idNodStop][idNodStart] = 1;
//	}
//}
//
//struct nodListaMuzee {
//	Muzeu info;
//	nodListaMuzee*next;
//};
//
//void inserareListaMuzee(nodListaMuzee*&cap, Muzeu m) {
//	nodListaMuzee*nou = (nodListaMuzee*)malloc(sizeof(nodListaMuzee));
//	nou->info.id = m.id;
//	nou->info.nume = (char*)malloc(sizeof(char)*(strlen(m.nume) + 1));
//	strcpy(nou->info.nume, m.nume);
//	nou->next = cap;
//	cap = nou;
//}
//
//struct nodStiva {
//	int id;
//	nodStiva* next;
//};
//
//void push(nodStiva*&stiva, int id) {
//	nodStiva*nou = (nodStiva*)malloc(sizeof(nodStiva));
//	nou->id = id;
//	nou->next = stiva;
//	stiva = nou;
//}
//
//int pop(nodStiva*&stiva) {
//	if (stiva) {
//		int rezultat = stiva->id;
//		nodStiva*aux = stiva;
//		stiva = stiva->next;
//		free(aux);
//		return rezultat;
//	}
//	else {
//		return -1;//cod eroare;
//	}
//}
//nodListaMuzee*copiereMuzeeDinGrafAdancimeInLista(int**matrice, Muzeu* muzee, int nrNoduri, int nodStart) {
//	//1. luam o stiva si  un vector de vizitate
//	//2. inseram nodul de start in stiva si il marcam ca vizitat
//	//3. pornim un loop
//	//4. extragem un nod din stiva - nodCurent
//	//5. procesam nodul;
//	//6. inseram in stiva vecinii nevizitati ai nodului curent si ii marcam ca vizitati
//	//6.1 cautam nodurile vecine ale nodului curent
//	//6.2 vericam daca a fost vizitat
//
//	//7. ne intoarcem la 4.
//	nodStiva*stiva = NULL;
//	int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
//	for (int i = 0; i < nrNoduri; i++) {
//		vizitate[i] = 0;
//	}
//	push(stiva, nodStart);
//	vizitate[nodStart] = 1;
//	nodListaMuzee*listaMuzee = NULL;
//	while (stiva) {
//		int idCurent = pop(stiva);
//		inserareListaMuzee(listaMuzee, muzee[idCurent]);
//		for (int i = 0; i < nrNoduri; i++) {
//			if (matrice[idCurent][i] == 1)
//			{
//				if (vizitate[i] == 0) {
//					push(stiva, i);
//					vizitate[i] = 1;
//				}
//			}
//		}
//	}
//	return listaMuzee;
//}
//
//void afisareListaMuzee(nodListaMuzee*cap) {
//	while (cap) {
//		printf("%d.%s\n", cap->info.id, cap->info.nume);
//		cap = cap->next;
//	}
//}
//
//void afisareListaMuzeeRecursiva(nodListaMuzee*cap) {
//	if (cap) {
//		afisareListaMuzeeRecursiva(cap->next);
//		printf("%d.%s\n", cap->info.id, cap->info.nume);
//	}
//}
//void main() {
//	int nrNoduri;
//	Muzeu*muzee;
//	int**matrice;
//	citireGrafDeMuzee(muzee, matrice, nrNoduri);
//	nodListaMuzee* lista = copiereMuzeeDinGrafAdancimeInLista(matrice, muzee, nrNoduri, 1);
//	afisareListaMuzeeRecursiva(lista);
//}