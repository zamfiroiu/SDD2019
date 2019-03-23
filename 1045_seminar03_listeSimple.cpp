#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Ferma {
	char* nume;
	int nrAnimale;
};

struct nod {
	Ferma info;
	nod*next;
};

Ferma createFerma(const char* nume, int nrAnimale) {
	Ferma f;
	f.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(f.nume, nume);
	f.nrAnimale = nrAnimale;
	return f;
}

nod* createNod(Ferma f, nod* next) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->info = f;
	nou->next = next;
	return nou;
}

nod* inserareSfarsit(nod* cap, Ferma f) {
	nod* nou = createNod(f, NULL);
	if (cap) {
		nod* temp = cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;

	}
	else {
		cap = nou;
	}
	return cap;

}


void afisareFerma(Ferma f) {
	printf("Ferma %s are %d animale.\n", f.nume, f.nrAnimale);
}

void afisareListaFerme(nod* cap) {
	while (cap) {
		afisareFerma(cap->info);
		cap = cap->next;
	}

	//for (; cap != NULL; cap = cap->next) {
	//	afisareFerma(cap->info);
	//}
}

nod* inserareInceput(nod* cap, Ferma f) {
	nod* nou = createNod(f, cap);
	return nou;
}

float medieAnimale(nod* cap) {
	if (cap) {
		int nr = 0, s = 0;
		while (cap) {
			nr++;
			s += cap->info.nrAnimale;
			cap = cap->next;
		}
		return s / nr;
	}
	else {
		return 0;
	}
}

nod* stergereLista(nod* cap) {
	while (cap) {
		nod*aux = cap;
		cap = cap->next;
		free(aux->info.nume);
		free(aux);
	}
	return cap;
}

void stergereListaRecursiv(nod* *cap) {
	if (*cap) {
		stergereListaRecursiv(&(*cap)->next);
		free((*cap)->info.nume);
		free(*cap);
		*cap = NULL;
	}
}

nod* inserareInainteDeUnNodCuValoareaData(nod* cap, const char* nume, Ferma f) {
	nod* nou = createNod(f, NULL);
	if (cap) {
		nod* p = cap;
		nod* adresaMax = NULL;
		while (p) {
			if (p->next && strcmp(p->next->info.nume, nume) == 0) {
				if (!adresaMax) { 
					adresaMax = p;
				}
				if (p->next->info.nrAnimale > adresaMax->next->info.nrAnimale) {
					adresaMax = p;
				}
			}
			p = p->next;
		}
		if (adresaMax==NULL) {
			if (strcmp(cap->info.nume, nume) == 0) {
				cap = inserareInceput(cap, f);
			}
			else {
				cap = inserareSfarsit(cap, f);
			}
		}
		else {
			if (strcmp(cap->info.nume, nume) == 0) {
				if (cap->info.nrAnimale > adresaMax->info.nrAnimale) {
					cap = inserareInceput(cap, f);
					return cap;
				}
			}
			nou->next = adresaMax->next;
			adresaMax->next = nou;
		}
	}
	else {
		cap = nou;
	}
	return cap;
}

void main() {
	Ferma f = createFerma("faraAnimale", 1);
	nod* node = createNod(f, NULL);
	nod* cap = NULL;
	cap = inserareSfarsit(cap, createFerma("Cocosul vesel", 200));
	cap = inserareSfarsit(cap, createFerma("Ferma", 100));
	cap = inserareSfarsit(cap, createFerma("Avicola", 400));
	cap = inserareSfarsit(cap, createFerma("Crevedia", 1200));

	afisareListaFerme(cap);

	cap = inserareInceput(cap, createFerma("Avicola", 1200));

	afisareListaFerme(cap);
	printf("%5.2f", medieAnimale(cap));

	//stergereListaRecursiv(&cap);

	//cap = inserareInceput(cap, createFerma("Ferma", 400));

	afisareListaFerme(cap);
	printf("\n\n");

	cap = inserareInainteDeUnNodCuValoareaData(cap, "Avicola", createFerma("NOUA", 90));

	afisareListaFerme(cap);
}
