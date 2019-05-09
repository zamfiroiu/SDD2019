//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Mesaj {
//	char* textMesaj;
//	int prioritate;
//};
//
//Mesaj initMesaj(const char* text, int p) {
//	Mesaj m;
//	m.prioritate = p;
//	m.textMesaj = (char*)malloc(sizeof(char)*(strlen(text) + 1));
//	strcpy(m.textMesaj, text);
//
//	return m;
//}
//
//void afisareMesaj(Mesaj m) {
//	printf("%d. %s.\n", m.prioritate, m.textMesaj);
//}
//
//struct HEAP {
//	Mesaj* vector;
//	int dim;
//};
//
//void afisareVector(HEAP heap) {
//	for (int i = 0; i < heap.dim; i++) {
//		afisareMesaj(heap.vector[i]);
//	}
//}
//
//void filtrare(HEAP heap, int pozitie) {
//	int pozitieFiuStanga = 2 * pozitie + 1;
//	int pozitieFiuDreapta = 2 * pozitie + 2;
//	int max = pozitie;
//	if (pozitieFiuStanga < heap.dim && heap.vector[max].prioritate < heap.vector[pozitieFiuStanga].prioritate) {
//		max = pozitieFiuStanga;
//	}
//	if (pozitieFiuDreapta < heap.dim && heap.vector[max].prioritate < heap.vector[pozitieFiuDreapta].prioritate) {
//		max = pozitieFiuDreapta;
//	}
//	if (max != pozitie) {
//		Mesaj aux = heap.vector[max];
//		heap.vector[max] = heap.vector[pozitie];
//		heap.vector[pozitie] = aux;
//		if (max <= (heap.dim - 1) / 2) {
//			filtrare(heap, max);
//		}
//	}
//}
//
//Mesaj extragereDinHeap(HEAP &heap) {
//	if (heap.dim > 0) {
//		Mesaj rezultat = heap.vector[0];
//		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(heap.dim - 1));
//		for (int i = 1; i < heap.dim; i++) {
//			temp[i - 1] = heap.vector[i];
//		}
//		heap.dim--;
//		free(heap.vector);
//		heap.vector = temp;
//
//		for (int i = (heap.dim - 1) / 2; i >= 0; i--) {
//			filtrare(heap, i);
//		}
//		return rezultat;
//	}
//	else {
//		return initMesaj("", -1);
//	}
//
//}
//
//void main() {
//	HEAP heap;
//	heap.dim = 6;
//	heap.vector = (Mesaj*)malloc(sizeof(Mesaj)*heap.dim);
//	heap.vector[0] = initMesaj("Salut", 3);
//	heap.vector[1] = initMesaj("Ce faci?", 7); 
//	heap.vector[2] = initMesaj("bine. Dar tu?", 8); 
//	heap.vector[3] = initMesaj("Ft bine", 6);
//	heap.vector[4] = initMesaj("Intelegem", 5); 
//	heap.vector[5] = initMesaj("Seen", 4);
//
//	afisareVector(heap);
//
//	for (int i = (heap.dim - 1) / 2; i >= 0; i--) {
//		filtrare(heap, i);
//	}
//	printf("\n\n");
//	afisareVector(heap);
//
//	printf("\n\n");
//	Mesaj m = extragereDinHeap(heap);
//	afisareMesaj(m);
//	free(m.textMesaj);
//}
//
