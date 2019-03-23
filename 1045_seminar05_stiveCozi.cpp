#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Vagon {
	int nrPasageri;
	float* preturi;
	int id;
};

Vagon createVagon(int nrPasageri, float*preturi, int id) {
	Vagon v;
	v.nrPasageri = nrPasageri;
	v.preturi = (float*)malloc(sizeof(float)*nrPasageri);
	for (int i = 0; i < nrPasageri; i++) {
		v.preturi[i] = preturi[i];
	}
	v.id = id;
	return v;
}

void afisareVagon(Vagon v) {
	printf("%d. Vagonul are %d pasageri care au platit: ", v.id, v.nrPasageri);
	for (int i = 0; i < v.nrPasageri; i++) {
		printf("%5.2f, ", v.preturi[i]);
	}
	printf("\n");
}

struct Nod {
	Vagon info;
	Nod*next;
};

Nod* pushStack(Nod* cap, Vagon v) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = v;
	nou->next = cap;
	return nou;
}

Vagon popStack(Nod*&cap) {
	if (cap) {
		Vagon rezultat = createVagon(cap->info.nrPasageri,cap->info.preturi,cap->info.id);
		Nod*aux = cap;
		cap = cap->next;
		free(aux->info.preturi);
		free(aux);
		return rezultat;
	}
	else {
		return createVagon(0, NULL, 0);
	}
}

int isEmptyStack(Nod* cap) {
	return cap == NULL;
}


struct NodDublu{
	Vagon info;
	NodDublu*next;
	NodDublu*prev;
};

struct ListaDubla {
	NodDublu* prim;
	NodDublu* ultim;
};

ListaDubla pushQueue(ListaDubla lista, Vagon v) {
	NodDublu* nodNou = (NodDublu*)malloc(sizeof(NodDublu));
	nodNou->info = v;
	nodNou->next = lista.prim;
	nodNou->prev = NULL;
	if (lista.prim) {
		lista.prim->prev = nodNou;
		lista.prim = nodNou;
	}
	else {
		lista.prim = lista.ultim = nodNou;
	}
	return lista;
}

Vagon popQueue(ListaDubla &lista) {
	if (lista.ultim) {
		Vagon rezultat = lista.ultim->info;
		if (lista.ultim != lista.prim) {
			lista.ultim = lista.ultim->prev;
			free(lista.ultim->next);
			lista.ultim->next = NULL;
		}
		else {
			free(lista.ultim);
			lista.ultim = lista.prim = NULL;
		}
		return rezultat;
	}
	else {
		return createVagon(0, NULL, 0);
	}
}

int isEmptyQueue(ListaDubla lista) {
	return lista.prim == NULL;
}

void main() {
	Nod* stiva = NULL;
	int nrPasageri = 3;
	float* vector = (float*)malloc(sizeof(float)*nrPasageri);
	for (int i = 0; i < nrPasageri; i++) {
		vector[i] = i + 10;
	}
	stiva = pushStack(stiva, createVagon(nrPasageri, vector, 1));
	free(vector);

	int nrPasageri2 = 2;
	float* vector2 = (float*)malloc(sizeof(float)*nrPasageri2);
	for (int i = 0; i < nrPasageri2; i++) {
		vector2[i] = i + 10;
	}
	stiva = pushStack(stiva, createVagon(nrPasageri2, vector2, 2));
	free(vector2);


	/*while (!isEmptyStack(stiva)) {
		Vagon v = popStack(stiva);
		afisareVagon(v);
		free(v.preturi);
	}*/


	ListaDubla coada;
	coada.prim = NULL;
	coada.ultim = NULL;

	while (!isEmptyStack(stiva)) {
		coada = pushQueue(coada, popStack(stiva));
	}
	while (!isEmptyQueue(coada)) {
		Vagon v = popQueue(coada);
		afisareVagon(v);
		free(v.preturi);
	}

}

