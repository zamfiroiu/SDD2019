#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Mesaj {
	char* text;
	int prioritate;
};

Mesaj initMesaj(const char* text, int p) {
	Mesaj m;
	m.text = (char*)malloc(sizeof(char)*(strlen(text) + 1));
	strcpy(m.text, text);
	m.prioritate = p;

	return m;
}

void afisareMesaj(Mesaj m) {
	printf("%s are prioritatea %d\n", m.text, m.prioritate);
}

struct HEAP {
	Mesaj * vector;
	int dim;
};

void printHEAP(HEAP heap) {
	for (int i = 0; i < heap.dim; i++) {
		afisareMesaj(heap.vector[i]);
	}
}

void filter(HEAP heap, int position) {
	int pozLeft = 2 * position + 1;
	int pozRight = 2 * position + 2;
	int max = position;
	if (pozLeft<heap.dim && heap.vector[max].prioritate < heap.vector[pozLeft].prioritate) {
		max = pozLeft;
	}
	if (pozRight < heap.dim && heap.vector[max].prioritate < heap.vector[pozRight].prioritate) {
		max = pozRight;
	}
	if (max != position) {
		Mesaj aux = heap.vector[max];
		heap.vector[max] = heap.vector[position];
		heap.vector[position] = aux;

		if (2 * max + 1 < heap.dim) {
			filter(heap, max);
		}
	}
}

Mesaj extrage(HEAP &heap) {
	if (heap.dim > 0) {
		Mesaj rezultat = heap.vector[0];
		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim - 1));
		for (int i = 1; i < heap.dim; i++) {
			temp[i - 1] = heap.vector[i];
		}
		heap.dim--;
		free(heap.vector);
		heap.vector = temp;
		for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
			filter(heap, i);
		}
		return rezultat;
	}
	else {
		return initMesaj("", -1);
	}
}

void inserare(HEAP &heap, Mesaj m) {
	Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim + 1));
	for (int i = 0; i < heap.dim; i++) {
		temp[i] = heap.vector[i];
	}
	temp[heap.dim] = m;
	free(heap.vector);
	heap.vector = temp;
	heap.dim++;
	for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
		filter(heap, i);
	}
}


void main() {
	HEAP heap;
	heap.dim = 6;
	heap.vector = (Mesaj*)malloc(sizeof(Mesaj)*heap.dim);
	heap.vector[0] = initMesaj("Mesaj", 2);
	heap.vector[1] = initMesaj("Hello", 6);
	heap.vector[2] = initMesaj("How are you?", 8);
	heap.vector[3] = initMesaj("I am fine", 4);
	heap.vector[4] = initMesaj("Thank you", 3);
	heap.vector[5] = initMesaj("But you", 9);

	printHEAP(heap);
	for (int i = (heap.dim - 2) / 2; i >= 0; i--) {
		filter(heap, i);
	}

	printf("\n\n");
	printHEAP(heap);
	printf("\n\n");

	Mesaj m = extrage(heap);
	afisareMesaj(m);
	free(m.text);

	inserare(heap, initMesaj("Element nou", 10));

	printf("\n\n");
	printHEAP(heap);
	printf("\n\n");
	m = extrage(heap);
	afisareMesaj(m);
	free(m.text);

}