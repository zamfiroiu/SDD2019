#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Cofetarie {
	char* nume;
	int nrPrajituri;
};

//vom modifica
Cofetarie initCofetarie(const char* nume, int nr) {
	Cofetarie c;
	c.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(c.nume, nume);
	c.nrPrajituri = nr;

	return c;
}

void afisareCofetarie(Cofetarie c) {
	printf("Cofetaria %s are %d prajituri.\n", c.nume, c.nrPrajituri);
}


struct HashTable {
	Cofetarie* *vector;
	int dim;
};


int hashFunction(Cofetarie c, HashTable h) {
	int suma = 0;
	for (int i = 0; i < strlen(c.nume); i++) {
		suma += c.nume[i];
	}

	return suma % h.dim;
}

int inserareCofetarie(HashTable h, Cofetarie c) {
	if (h.dim > 0) {
		int hashCode = hashFunction(c, h);
		if (h.vector[hashCode]) {
			//avem coliziune
			int index = (hashCode + 1) % h.dim;
			while (index != hashCode) {
				if (h.vector[index] == NULL) {
					h.vector[index] = (Cofetarie*)malloc(sizeof(Cofetarie));
					h.vector[index]->nrPrajituri = c.nrPrajituri;
					h.vector[index]->nume = (char*)malloc(sizeof(char)*(strlen(c.nume) + 1));
					strcpy(h.vector[index]->nume, c.nume);
					break;
				}
				else {
					index = (index + 1) % h.dim;
				}
			}
			if (index == hashCode) {
				return -1;//codul de eroare pentru tabela full
			}
			return index;
		}
		else {
			h.vector[hashCode] = (Cofetarie*)malloc(sizeof(Cofetarie));
			*(h.vector[hashCode]) = initCofetarie(c.nume, c.nrPrajituri);
			return hashCode;
		}
	}
	else {
		return -2;//nu exista tabela
	}
}

HashTable initHashTable(int dim) {
	HashTable h;
	h.dim = dim;
	h.vector = (Cofetarie**)malloc(sizeof(Cofetarie*)*dim);
	for (int i = 0; i < dim; i++) {
		h.vector[i] = NULL;
	}

	return h;
}

void afisareTabela(HashTable h) {
	for (int i = 0; i < h.dim; i++) {
		if (h.vector[i]) {
			afisareCofetarie(*(h.vector[i]));
		}
	}
}

int cautareCofetarie(HashTable h, Cofetarie c) {
	if (h.dim > 0) {
		int pozitie = hashFunction(c, h);
		if (strcmp(c.nume, h.vector[pozitie]->nume) == 0) {
			return pozitie;
		}
		else {
			int index = (pozitie + 1) % h.dim;
			while (index != pozitie && strcmp(c.nume, h.vector[index]->nume) == 0) {
				index = (index + 1) % h.dim;
			}
			if (index == pozitie) {
				return -1;//nu exista in tabela
			}
			else {
				return index;
			}
		}
	}
	else {
		return -2;//nu avem tabela
	}
}

Cofetarie stergereByIndex(HashTable h, int index) {
	if (h.dim > 0 && h.vector[index]!=NULL) {
		Cofetarie rezultat = *(h.vector[index]);
		free(h.vector[index]);
		h.vector[index] = NULL;
		return rezultat;
	}
	else {
		return initCofetarie("", 0);
	}
}

void main() {
	HashTable h = initHashTable(5);
	Cofetarie c = initCofetarie("Ana", 6);
	inserareCofetarie(h, c);
	free(c.nume);
	c = initCofetarie("Iepurasul", 8);	
	inserareCofetarie(h, c);
	free(c.nume);
	Cofetarie d = initCofetarie("Alice", 9);
	inserareCofetarie(h, c);
	

	c = initCofetarie("Paris", 5);
	inserareCofetarie(h, c);
	free(c.nume);
	c = initCofetarie("Cofetarie", 3);
	inserareCofetarie(h, c);
	free(c.nume);
	c = initCofetarie("Capsa", 7);
	int index=inserareCofetarie(h, c);
	free(c.nume);

	printf("%d\n", index);
	afisareTabela(h);
	printf("\n\n");
	int pozitieAlice = cautareCofetarie(h, d);
	free(d.nume);
	afisareCofetarie(*(h.vector[pozitieAlice]));



}