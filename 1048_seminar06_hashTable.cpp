#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Masina {
	char* serie;
	int nrKm;
};

Masina initMasina(const char* serie, int nr) {
	Masina m;
	m.serie = (char*)malloc(sizeof(char)*(strlen(serie) + 1));
	strcpy(m.serie, serie);
	m.nrKm = nr;

	return m;
}

void afisareMasina(Masina m) {
	printf("Masina cu seria %s are %d Km parcursi.\n",m.serie,m.nrKm);
}

struct HashTable {
	Masina* *vector;
	int dim;
};

HashTable initializareHT(int dim) {
	HashTable h;
	h.vector = (Masina**)malloc(sizeof(Masina*)*dim);
	for (int i = 0; i < dim; i++) {
		h.vector[i] = NULL;
	}
	h.dim = dim;

	return h;
}


int hashFunction(Masina m, HashTable h) {
	int suma = 0;
	for (int i = 0; i < strlen(m.serie); i++) {
		suma += m.serie[i];
	}
	return suma % h.dim;
}


int inserareMasina(HashTable h, Masina m) {
	if (h.dim > 0) {
		int pozitie = hashFunction(m, h);
		if (h.vector[pozitie]) {
			//avem coliziune
			int index =( pozitie + 1) % h.dim;
			while (h.vector[index] != NULL && index != pozitie) {
				index = (index + 1) % h.dim;
			}
			if (index != pozitie) {
				//realizam inserarea
				h.vector[index] = (Masina*)malloc(sizeof(Masina));
				*(h.vector[index]) = initMasina(m.serie, m.nrKm);
				return index;
			}
			else {
				return -1;//cod de eroare pentru tabela full
			}
		}
		else {
			h.vector[pozitie] = (Masina*)malloc(sizeof(Masina));
			*(h.vector[pozitie]) = initMasina(m.serie, m.nrKm);
			return pozitie;
		}
	}
	else {
		return -2;//cod eraore pentru tabela inexistenta
	}
}

int cautareMasina(HashTable h, Masina m) {
	if (h.dim > 0) {
		int pozitie = hashFunction(m, h);
		if (h.vector[pozitie] && strcmp(m.serie, h.vector[pozitie]->serie)==0) {
			return pozitie;
		}
		else {
			int index = (pozitie + 1) % h.dim;
			while (index != pozitie) {
				if (h.vector[index] && 
					strcmp(m.serie, h.vector[index]->serie) == 0) {
					return index;
				}
				index = (index + 1) % h.dim;
			}
		}	
	}
	else {
		return -2;//cod eroare- nu avem tabela
	}
}

void main() {
	HashTable h = initializareHT(4);
	Masina m = initMasina("B35W", 1000);
	inserareMasina(h, m);
	free(m.serie);
	
	Masina masina = initMasina("A9G6", 1200); 
	inserareMasina(h, masina);
	//free(m.serie);

	m = initMasina("G5T6", 900);
	inserareMasina(h, m);
	free(m.serie);
	m = initMasina("T2F9", 1600);
	inserareMasina(h, m);
	free(m.serie);
	m = initMasina("Y6J9", 600);
	int index = inserareMasina(h, m);
	free(m.serie);

	int indexCautat = cautareMasina(h, masina);

	printf("\n\n");
	afisareMasina(*(h.vector[indexCautat]));
	printf("%d", index);





	
}

