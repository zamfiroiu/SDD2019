#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Za {
	char* material;
	int diametru;
	int cod;
};

Za* createZa(const char* material, int diametru, int cod) {
	Za *za=(Za*)malloc(sizeof(Za));
	za->material = (char*)malloc(sizeof(char)*(strlen(material) + 1));
	strcpy(za->material, material);
	za->cod = cod;
	za->diametru = diametru;

	return za;
}

void afisareZa(Za z) {
	printf("%d. Avem o za din %s cu diametru %d.\n", z.cod, z.material, z.diametru);
}

struct HashTable {
	Za* *vector;
	int dim;
};

HashTable initializareHashTable(int dim) {
	HashTable ht;
	ht.dim = dim;
	ht.vector = (Za**)malloc(sizeof(Za*)*dim);
	for (int i = 0; i < dim; i++) {
		ht.vector[i] = NULL;
	}

	return ht;
}

int hashFunction(Za z, HashTable table) {
	return (z.cod + z.diametru) % table.dim;
}

int inserareZa(HashTable h, Za *z) {
	if (h.dim > 0) {
		int pozitie = hashFunction(*z, h);
		if (h.vector[pozitie] != NULL) {
			//coliziune
			int index = (pozitie+1)%h.dim;
			while (h.vector[index] != NULL && index != pozitie) {
				index = (index + 1) % h.dim;
			}
			if (index == pozitie) {
				return -1;
			}
			else {
				h.vector[index] = z;
				return index;
			}

		}
		else {
			h.vector[pozitie] = z;
			return pozitie;
		}
	}
	else {
		return -2;
	}
}

void afisareTabela(HashTable h) {
	for (int i = 0; i < h.dim; i++) {
		if (h.vector[i]) {
			afisareZa(*h.vector[i]);
		}
	}
}

int cautaZaInTabela(HashTable h, Za*z) {
	if (h.dim > 0) {
		int pozitie = hashFunction(*z, h);
		if (h.vector[pozitie]->cod == z->cod) {
			return pozitie;
		}
		else {
			int index = pozitie;
			do {
				index = (index + 1) % h.dim;
				if (h.vector[index] && h.vector[index]->cod == z->cod) {
					break;
				}

			} while (index != pozitie);
			if (index == pozitie) {
				return -1;
			}
			else {
				return index;
			}
		}
	}
	else {
		return -2;
	}
}

Za* extragereZaDinTabela(HashTable h, int pozitie) {
	if (h.dim > 0 && pozitie < h.dim && pozitie >= 0) {
		if (h.vector[pozitie]) {
			Za* zaPointer = h.vector[pozitie];
			h.vector[pozitie] = NULL;
			return zaPointer;
		}
	}
	return NULL;
}

void main() {
	HashTable h = initializareHashTable(5);
	Za* pointerZa = createZa("Otel", 3, 1);
	inserareZa(h, pointerZa);
	inserareZa(h, createZa("Otel", 3, 2));
	inserareZa(h, createZa("Otel", 3, 3));
	inserareZa(h, createZa("Otel", 3, 4));
	inserareZa(h, createZa("Otel", 3, 5));
	int index=inserareZa(h, createZa("Otel", 3, 6));
	printf("%d\n", index);
	afisareTabela(h);
	printf("Pozitie:%d", cautaZaInTabela(h, pointerZa));
}
