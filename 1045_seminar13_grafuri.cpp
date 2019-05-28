#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Facultate {
	int id;
	char* nume;
};
struct nodListaPrincipala;

struct nodListaSecundara {
	nodListaSecundara* next;
	nodListaPrincipala* info;
};

struct nodListaPrincipala {
	nodListaSecundara*vecini;
	Facultate info;
	nodListaPrincipala*next;
};

nodListaPrincipala*inserareListaPrincipala(nodListaPrincipala* cap, Facultate f) {
	nodListaPrincipala* nou = (nodListaPrincipala*)malloc(sizeof(nodListaPrincipala));
	nou->info = f;
	nou->vecini = NULL;
	nou->next = NULL;
	if (cap) {
		nodListaPrincipala* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		return nou;
	}
}


nodListaSecundara* inserareListaSecundara(nodListaSecundara*cap, nodListaPrincipala* info) {
	nodListaSecundara* nou = (nodListaSecundara*)malloc(sizeof(nodListaSecundara));
	nou->info = info;
	nou->next = NULL;
	if (cap) {
		nodListaSecundara*p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		return nou;
	}
}

nodListaPrincipala* cautareDupaID(nodListaPrincipala* cap, int id) {
	while (cap && cap->info.id != id) {
		cap = cap->next;
	}
	return cap;
}
void inserareArcInGraf(nodListaPrincipala* graf, int idStart, int idStop) {
	if (graf) {
		nodListaPrincipala*nodStart = cautareDupaID(graf, idStart);
		nodListaPrincipala*nodStop = cautareDupaID(graf, idStop);
		if (nodStart && nodStop) {
			nodStart->vecini = inserareListaSecundara(nodStart->vecini, nodStop);
			nodStop->vecini = inserareListaSecundara(nodStop->vecini, nodStart);
		}
	}
}

void afisareListaSecundara(nodListaSecundara* cap) {
	while (cap) {
		printf("   %d. %s\n", cap->info->info.id, cap->info->info.nume);
		cap = cap->next;
	}
}

void afisareListaPrincipala(nodListaPrincipala*cap) {
	while (cap) {
		printf("%d.%s are urmatorii vecini:\n", cap->info.id, cap->info.nume);
		afisareListaSecundara(cap->vecini);
		cap = cap->next;
	}
}

struct nodStiva {
	int id;
	nodStiva*next;
};

void inserareCoadaSfarsit(nodStiva*&cap, int id) {
	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
	nou->next = NULL;
	nou->id = id;
	if (cap) {
		nodStiva*p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		cap = nou;
	}

}

nodStiva* push(nodStiva* cap, int id) {
	nodStiva* nou = (nodStiva*)malloc(sizeof(nodStiva));
	nou->next = cap;
	nou->id = id;
	return nou;
}

int pop(nodStiva*&cap) {
	if (cap) {
		int id = cap->id;
		nodStiva* temp = cap;
		cap = cap->next;
		free(temp);
		return id;
	}
	else {
		return -1;
	}
}

int calculareNumarNoduri(nodListaPrincipala* graf) {
	int contor = 0;
	while (graf) {
		contor++;
		graf = graf->next;
	}

	return contor;
}

void parcurgereAdancime(nodListaPrincipala*graf, int idNodStart) {
	if (graf) {
		//1. ne luam o stiva si un vector de vizitate cu toate nodurile nevizitate
		//2. inseram nodul de start in stiva si il vizitam
		//3. extragem din stiva un nod - nod curent
		//4. afisam/procesare nodul curent
		//5. inseram in stiva nodurile adiacente nevizitate ale nodului curent si le marcam ca vizitate
		//6. revenim la pasul 3

		nodStiva* stiva = NULL;
		int nrNoduri = calculareNumarNoduri(graf);
		int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
		for (int i = 0; i < nrNoduri; i++) {
			vizitate[i] = 0;
		}
		stiva = push(stiva, idNodStart);
		vizitate[idNodStart] = 1;

		while (stiva) {
			int idNodCurent = pop(stiva);
			nodListaPrincipala* nodCurent = cautareDupaID(graf, idNodCurent);
			printf("%d . %s \n", nodCurent->info.id, nodCurent->info.nume);
			nodListaSecundara* p = nodCurent->vecini;
			while (p) {
				if (vizitate[p->info->info.id] == 0) {
					stiva = push(stiva, p->info->info.id);
					vizitate[p->info->info.id] = 1;
				}
				p = p->next;
			}
		}
	}
}

void citesteGrafMemoratInMatriceAdiacenta(int** &matrice, int &nrNoduri, Facultate* &facultati) {
	nrNoduri = 0;
	printf("Numarul de noduri:");
	scanf("%d", &nrNoduri);

	facultati = (Facultate*)malloc(sizeof(Facultate)*nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		printf("ID-ul facultatii:");
		scanf("%d", &facultati[i].id);
		char buffer[20];
		printf("Numele facultatii:");
		scanf("%s", buffer);
		facultati[i].nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(facultati[i].nume, buffer);
	}

	matrice = (int**)malloc(sizeof(int*)*nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		matrice[i] = (int*)malloc(sizeof(int)*nrNoduri);
		for (int j = 0; j < nrNoduri; j++) {
			matrice[i][j] = 0;
		}
	}
	int nrArce = 0;
	printf("Numarul de arce:");
	scanf("%d", &nrArce);

	for (int i = 0; i < nrArce; i++) {
		int idStart = 0;
		printf("Id-ul nodului de start:");
		scanf("%d", &idStart);
		int idStop = 0;
		printf("Id-ul nodului de stop:");
		scanf("%d", &idStop);
		matrice[idStart][idStop] = 1;
		matrice[idStop][idStart] = 1;
	}
}

struct nodListaFacultate{
	Facultate info;
	nodListaFacultate*next;
};

void inserareFacultateInLista(nodListaFacultate*&cap, Facultate f) {
	nodListaFacultate*nou = (nodListaFacultate*)malloc(sizeof(nodListaFacultate));
	nou->next = cap;
	nou->info = f;
	cap = nou;
}

nodListaFacultate* copiereGrafLatimeInLista(int**matrice, int nrNoduri, Facultate*facultati, int nodStart) {
	nodStiva* coada = NULL;
	int* vizitate = (int*)malloc(sizeof(int)*nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		vizitate[i] = 0;
	}
	inserareCoadaSfarsit(coada, nodStart);
	vizitate[nodStart] = 1;
	nodListaFacultate* listaFacultati = NULL;
	while (coada) {
		int idCurent = pop(coada);
		Facultate f;
		f.id = facultati[idCurent].id;
		f.nume = (char*)malloc(sizeof(char)*(strlen(facultati[idCurent].nume) + 1));
		strcpy(f.nume, facultati[idCurent].nume);
		inserareFacultateInLista(listaFacultati, f);
		for (int i = 0; i < nrNoduri; i++) {
			if (matrice[idCurent][i] == 1 && vizitate[i] == 0) {
				vizitate[i] = 1;
				inserareCoadaSfarsit(coada, i);
			}
		}
	}
	return listaFacultati;
}

void afisareListaFacultati(nodListaFacultate* cap) {
	while (cap) {
		printf("%d.%s\n", cap->info.id, cap->info.nume);
		cap = cap->next;
	}
}

void afisareListaFacultatiRecursiv(nodListaFacultate* cap) {
	if (cap) {
		afisareListaFacultatiRecursiv(cap->next);
		printf("%d.%s\n", cap->info.id, cap->info.nume);

	}
}
void main() {
	int**matrice;
	Facultate*facultati;
	int nrNoduri;
	citesteGrafMemoratInMatriceAdiacenta(matrice, nrNoduri, facultati);

	nodListaFacultate*cap = copiereGrafLatimeInLista(matrice, nrNoduri, facultati, 2);
	afisareListaFacultatiRecursiv(cap);

}