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
	printf("%s are prioritatea %d\n", m.text, m.prioritate);
}

struct HEAP {
	Mesaj* vector;
	int dim;
};

void afisareHeap(HEAP heap) {
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


Mesaj extragereMesaj(HEAP &heap) {
	if (heap.dim > 0) {
		Mesaj rezultat = heap.vector[0];
		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim - 1));
		for (int i = 0; i < heap.dim - 1;i++) {
			temp[i] = heap.vector[i + 1];
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

void afisareCuPrioritateMare(HEAP &heap, int p) {
	while (heap.dim > 0 && heap.vector[0].prioritate >= p) {
		Mesaj m = extragereMesaj(heap);
		afisareMesaj(m);
		free(m.text);
	}
}
void main() {
	HEAP heap;
	heap.dim = 6;
	heap.vector = (Mesaj*)malloc(sizeof(Mesaj)*heap.dim);
	heap.vector[0] = initMesaj("Salut", 4);
	heap.vector[1] = initMesaj("Ce faci?", 8);
	heap.vector[2] = initMesaj("Bine...tu?", 3);
	heap.vector[3] = initMesaj("Foarte bine", 6);
	heap.vector[4] = initMesaj("Cum asa?", 9);
	heap.vector[5] = initMesaj("pai, nimeni nu zice nimic", 2);

	afisareHeap(heap);

	for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
		filtrare(heap, i);
	}
	printf("\n\n");

	afisareHeap(heap);
	printf("\n\n");
	Mesaj m = extragereMesaj(heap);
	afisareMesaj(m);
	free(m.text);
	m = extragereMesaj(heap);
	afisareMesaj(m);
	free(m.text);

	inserareHeap(heap, initMesaj("Mesaj nou", 10));
	printf("\n\n");

	afisareHeap(heap);
	printf("\n\n");
	afisareCuPrioritateMare(heap, 6);
	printf("\n\n");

	afisareHeap(heap);

}