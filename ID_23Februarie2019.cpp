#include<iostream>

struct Cladire {
	int numar;
	char* adresa;
	float suprafata;
};

struct nod {
	Cladire inf;
	nod* st;
	nod* dr;
};

Cladire instantiazaCladire(int numar, const char* adresa, float suparafata) {
	Cladire c;
	c.numar = numar;
	c.adresa = (char*)malloc(sizeof(char)*strlen(adresa) + 1);
	strcpy(c.adresa, adresa);
	c.suprafata = suparafata;
	return c;
}
void afisareCladire(Cladire c) {
	printf("%d.%s are o suparafata de %5.2f\n", c.numar, c.adresa, c.suprafata);
}

nod* creareNod(Cladire c, nod* st, nod* dr) {
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->inf = c;
	nou->st = st;
	nou->dr = dr;
	return nou;
}

nod* inserareInArbore(nod* rad, Cladire c) {
	if (rad != NULL) {
		if (c.numar < rad->inf.numar) {
			rad->st = inserareInArbore(rad->st, c);
		}
		else {
			rad->dr = inserareInArbore(rad->dr, c);
		}
	}
	else {
		rad = creareNod(c, NULL, NULL);
	}
	return rad;
}

void afisareSRD(nod* rad) {
	if (rad != NULL) {
		afisareSRD(rad->st);
		afisareCladire(rad->inf);
		afisareSRD(rad->dr);
	}
}

int maxim(int a, int b) {
	return a < b ? b : a;
}

int getInaltime(nod* rad) {
	if (rad) {
		int s = getInaltime(rad->st);
		int d = getInaltime(rad->dr);
		return maxim(s, d)+1 ;
	}
	else {
		return 0;
	}
}

nod* stergereArbore(nod* rad) {
	if (rad) {
		stergereArbore(rad->st);
		stergereArbore(rad->dr);
		free(rad->inf.adresa);
		free(rad);
		return NULL;
	}
}

void afisareNivel(nod* rad, int nivelDorit, int nivelCurent) {
	if (rad) {
		if (nivelDorit == nivelCurent) {
			afisareCladire(rad->inf);
		}
		else {
			afisareNivel(rad->st, nivelDorit, nivelCurent + 1);
			afisareNivel(rad->dr, nivelDorit, nivelCurent + 1);
		}
	}
}


void main() {
	Cladire c = instantiazaCladire(5, "Bucuresti", 45.6);
	afisareCladire(c);
	//free(c.adresa);
	nod* rad = creareNod(c, NULL, NULL);
	rad = inserareInArbore(rad, instantiazaCladire(3, "Iasi", 34));
	rad = inserareInArbore(rad, instantiazaCladire(8, "Timisoara", 12));
	rad = inserareInArbore(rad, instantiazaCladire(6, "Craiova", 28));
	rad = inserareInArbore(rad, instantiazaCladire(7, "Brasov", 24));
	afisareSRD(rad);
	printf("\n%d\n", getInaltime(rad));

	afisareNivel(rad, 3, 1);

	rad = stergereArbore(rad);
	//free(c.adresa);
}