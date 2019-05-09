
#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Mesaj {
	char* text;
	int prioritate;
};

Mesaj initMesaj(const char* text, int p) {
	Mesaj m;
	m.prioritate = p;
	m.text = (char*)malloc(sizeof(char)*(strlen(text) + 1));
	strcpy(m.text, text);
	return m;
}

void afisareMesaj(Mesaj m) {
	printf("%d. Text: %s\n", m.prioritate, m.text);
}

struct HEAP {
	Mesaj* vector;
	int dim;
};

void afisareHEAP(HEAP heap) {
	for (int i = 0; i < heap.dim; i++) {
		afisareMesaj(heap.vector[i]);
	}
}

void filtrare(HEAP heap, int pozitie) {
	int fiuS = 2 * pozitie + 1;
	int fiuD = 2 * pozitie + 2;
	int max = pozitie;
	if (fiuS < heap.dim && heap.vector[max].prioritate < heap.vector[fiuS].prioritate) {
		max = fiuS;
	}
	if (fiuD < heap.dim && heap.vector[max].prioritate < heap.vector[fiuD].prioritate) {
		max = fiuD;
	}
	if (max != pozitie) {
		Mesaj aux = heap.vector[max];
		heap.vector[max] = heap.vector[pozitie];
		heap.vector[pozitie] = aux;
		if (2 * max + 1 < heap.dim) {
			filtrare(heap, max);
		}
	}
}

Mesaj extragereHEAP(HEAP &heap) {
	if (heap.dim > 0) {
		Mesaj rezultat = heap.vector[0];
		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim - 1));
		for (int i = 1; i < heap.dim; i++) {
			temp[i - 1] = heap.vector[i];
		}
		free(heap.vector);
		heap.vector = temp;
		heap.dim--;
		for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
			filtrare(heap, i);
		}
		return rezultat;
	}
	else {
		return initMesaj("", -1);
	}
}

void inserareHeap(HEAP &heap, Mesaj m) {
	if (heap.dim >= 0) {
		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim + 1));
		for (int i = 0; i < heap.dim; i++) {
			temp[i] = heap.vector[i];
		}
		temp[heap.dim] = m;
		free(heap.vector);
		heap.vector = temp;
		heap.dim++;
		for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
			filtrare(heap, i);
		}
	}

}

void afisareConditionata(HEAP& heap, int p) {
	while (heap.vector[0].prioritate >= p) {
		Mesaj m = extragereHEAP(heap);
		afisareMesaj(m);
		free(m.text);
	}
}

void main() {
	HEAP heap;
	heap.dim = 6;
	heap.vector = (Mesaj*)malloc(sizeof(Mesaj)*heap.dim);
	heap.vector[0] = initMesaj("Salut", 4);
	heap.vector[1] = initMesaj("buna", 8);
	heap.vector[2] = initMesaj("la multi ani", 7);
	heap.vector[3] = initMesaj("ce faci?", 6);
	heap.vector[4] = initMesaj("La revedere", 9);
	heap.vector[5] = initMesaj("Felicitari", 3);

	afisareHEAP(heap);

	for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
		filtrare(heap, i);
	}

	printf("\n\n");
	afisareHEAP(heap);


	printf("\n\n");
	Mesaj m = extragereHEAP(heap);
	afisareMesaj(m);
	free(m.text);

	inserareHeap(heap, initMesaj("Mesaj nou", 12));

	printf("\n\n");
	afisareHEAP(heap);
}