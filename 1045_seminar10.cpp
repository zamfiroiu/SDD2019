#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Film {
	char* titlu;
	int durata;
};

struct nodLista {
	Film info;
	nodLista* next;
};

nodLista* inserareLaInceputListaCirculara(nodLista* cap, Film f) {
	nodLista* nou = (nodLista*)malloc(sizeof(nodLista));
	nou->info = f;
	if (cap) {
		nou->next = cap;
		nodLista* temp = cap;
		while (temp->next != cap) {
			temp = temp->next;
		}
		temp->next = nou;
		return nou;
	}
	else {
		nou->next = nou;
		return nou;
	}
}

Film initFilm(const char*titlu, int durata) {
	Film f;
	f.durata = durata;
	f.titlu = (char*)malloc(sizeof(char)*(strlen(titlu) + 1));
	strcpy(f.titlu, titlu);
	return f;
}


void afisareFilm(Film f) {
	printf("%s are o durata de %d minute.\n", f.titlu, f.durata);
}

void afisareLista(nodLista* cap) {
	if (cap) {
		nodLista* temp = cap->next;
		afisareFilm(cap->info);
		while (temp != cap) {
			afisareFilm(temp->info);
			temp = temp->next;
		}
	}
}

void afisareListaDoWhile(nodLista* cap) {
	if (cap) {
		nodLista*temp = cap;
		do {
			afisareFilm(temp->info);
			temp = temp->next;
		} while (temp != cap);
	}
}

Film* copiazaFilmeCuDurataMare(nodLista* cap, int prag, int &lungimeVector) {
	if (cap) {
		lungimeVector = 0;
		
		nodLista*temp = cap;
		do {
			if (temp->info.durata > prag) {
				lungimeVector++;
			}
			temp = temp->next;
		} while (temp != cap);
		Film* filme = (Film*)malloc(sizeof(Film)*lungimeVector);
		temp = cap;
		lungimeVector = 0;
		do {
			if (temp->info.durata > prag) {
				filme[lungimeVector++] = initFilm(temp->info.titlu, temp->info.durata);
			}
			temp = temp->next;
		} while (temp != cap);
		return filme;
	}
	else {
		return NULL;
	}
}

void stergereListaCirculara(nodLista* &cap) {
	if (cap) {
		nodLista* temp = cap->next;
		while (temp != cap) {
			nodLista*aux = temp->next;
			free(temp->info.titlu);
			free(temp);
			temp = aux;
		}
		free(cap->info.titlu);
		free(cap);
		cap = NULL;
	}
}

struct nodArbore {
	Film info;
	nodArbore* st;
	nodArbore* dr;
};

nodArbore* inserareInArbore(nodArbore*rad, Film f) {
	if (rad) {
		if (f.durata < rad->info.durata) {
			rad->st = inserareInArbore(rad->st, f);
		}
		else {
			if (f.durata > rad->info.durata) {
				rad->dr = inserareInArbore(rad->dr, f);
			}
			else {
				throw "Elementul exista deja";
			}
		}
		return rad;
	}
	else {
		nodArbore* nou = (nodArbore*)malloc(sizeof(nodArbore));
		nou->info = f;
		nou->dr = NULL;
		nou->st = NULL;
		return nou;
	}
}

nodArbore* copiereFilmeDinListaInArbore(nodLista* cap) {
	if (cap) {
		nodArbore* rad = NULL;
		nodLista* temp = cap;
		do {
			rad = inserareInArbore(
				rad, 
				initFilm(temp->info.titlu,
					temp->info.durata));
			temp = temp->next;
		} while (temp != cap);
		return rad;
	}
	else {
		return NULL;
	}
}

void afisareArbore(nodArbore*rad) {
	if (rad) {
		afisareArbore(rad->st);
		afisareFilm(rad->info);
		afisareArbore(rad->dr);
	}
}

void main() {
	nodLista* cap = NULL;

	cap = inserareLaInceputListaCirculara(cap, initFilm("EndGame", 180));
	cap = inserareLaInceputListaCirculara(cap, initFilm("Ramona", 120));
	cap = inserareLaInceputListaCirculara(cap, initFilm("Morometii", 90));
	cap = inserareLaInceputListaCirculara(cap, initFilm("Pistruiatu", 85));

	afisareLista(cap);
	
	int dim = 0;
	Film* filme = copiazaFilmeCuDurataMare(cap, 89, dim);
	printf("Vector:\n");
	for (int i = 0; i < dim; i++) {
		afisareFilm(filme[i]);
	}

	for (int i = 0; i < dim; i++) {
		free(filme[i].titlu);
	}
	free(filme);
	printf("Arbore:\n");
	nodArbore* rad = copiereFilmeDinListaInArbore(cap);
	afisareArbore(rad);

}