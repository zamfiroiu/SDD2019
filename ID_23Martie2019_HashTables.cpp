#include<stdio.h>
#include<string.h>
#include<malloc.h>
//liste cuirculare

struct Muzeu {
	char* denumire;
	float pret;
	char esteDeschis;
};

Muzeu creareMuzeu(const char* denumire, float pret, char deschis) {
	Muzeu m;
	m.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
	strcpy(m.denumire, denumire);
	m.pret = pret;
	m.esteDeschis = deschis;

	return m;
}

void afisareMuzeu(Muzeu m) {
	printf("Muzeul %s ", m.denumire);
	if (m.esteDeschis) {
		printf("este deschis, ");
	}
	else
		printf("NU este deschis, ");
	printf("iar pretul biletului este de %5.2f.\n", m.pret);
}

struct HashTable {
	Muzeu* *vector;
	int lungime;
};

HashTable initializareHashTable(int lungime) {
	HashTable h;
	h.lungime = lungime;
	h.vector = (Muzeu**)malloc(sizeof(Muzeu*)*lungime);
	for (int i = 0; i < lungime; i++) {
		h.vector[i] = NULL;
	}
	return h;
}

int hashFunction(Muzeu m, HashTable h) {
	return m.denumire[0] % h.lungime;
}

int inserareHashTable(HashTable h, Muzeu m) {
	if (h.lungime > 0) {
		int pozitie = hashFunction(m, h);
		if (h.vector[pozitie]) {
			int index =( pozitie+1)%h.lungime;
			while (h.vector[index] && index != pozitie) {
				index = (index + 1) % h.lungime;
			}
			if (pozitie == index) {
				return -1;//cod eroare pentru tabela full;
			}
			else {
				h.vector[index] = (Muzeu*)malloc(sizeof(Muzeu));
				*(h.vector[index]) =creareMuzeu(m.denumire,m.pret,m.esteDeschis) ;
				return index;
			}
		}
		else{
			h.vector[pozitie] = (Muzeu*)malloc(sizeof(Muzeu));
			*(h.vector[pozitie]) = creareMuzeu(m.denumire, m.pret, m.esteDeschis);
			return pozitie;
		}
	}
	else {
		return -2;//alt cod de eraore
	}
}

void afisareTabela(HashTable h) {
	for (int i = 0; i < h.lungime; i++) {
		if (h.vector[i]) {
			afisareMuzeu(*(h.vector[i]));
		}
	}
}

int cautaMuzeu(Muzeu m, HashTable h) {
	if (h.lungime > 0) {
		int pozitie = hashFunction(m, h);
		if (h.vector[pozitie] && strcmp(m.denumire, h.vector[pozitie]->denumire) == 0) {
			return pozitie;
		}
		else {
			int index = (pozitie + 1) % h.lungime;
			while (index != pozitie) {
				if (h.vector[index] && strcmp(m.denumire, h.vector[index]->denumire) == 0) {
					return index;
				}
				index = (index + 1) % h.lungime;
			}
			return -3;//nu exista in tabela
		}
	}
	else {
		return -2;
	}
}

HashTable stergereTabela(HashTable h) {
	for (int i = 0; i < h.lungime; i++) {
		if (h.vector[i]) {
			free(h.vector[i]->denumire);
			free(h.vector[i]);
		}
	}
	free(h.vector);
	h.vector = NULL;
	return h;
}

void main() {
	HashTable h = initializareHashTable(3);
	Muzeu m = creareMuzeu("Antipa", 20, 1);
	inserareHashTable(h, m);
	free(m.denumire);
	Muzeu muzeu = creareMuzeu("Luvru", 30, 1);
	inserareHashTable(h, muzeu);

	m = creareMuzeu("Geologie", 10, 0);
	inserareHashTable(h, m);
	free(m.denumire);
	m = creareMuzeu("Aviatie", 15, 1);
	int index=inserareHashTable(h, m);
	free(m.denumire);

	printf("%d", index);

	afisareTabela(h);
	
	printf("\n\n");
	int indexLuvru = cautaMuzeu(muzeu, h);
	afisareMuzeu(*(h.vector[indexLuvru]));
	free(muzeu.denumire);
	h = stergereTabela(h);
}

