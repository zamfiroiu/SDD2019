#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Actor {
	char* nume;
	int nrPremiiCastigate;
};

struct Serial {
	int id;
	int numarActori;
	Actor* actori;
};

Serial citesteSerial(FILE* f) {
	Serial s;
	fscanf(f, "%d", &s.id);
	fscanf(f, "%d", &s.numarActori);
	s.actori = (Actor*)malloc(sizeof(Actor)*s.numarActori);
	for (int i = 0; i < s.numarActori; i++) {
		char buffer[20];
		fscanf(f, "%s", buffer);
		s.actori[i].nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
		strcpy(s.actori[i].nume, buffer);
		fscanf(f, "%d", &s.actori[i].nrPremiiCastigate);
	}
	return s;
}

void afisareSerial(Serial s) {
	printf("%d. Serialul are %d actori\n", s.id, s.numarActori);
}

struct NOD {
	Serial info;
	NOD* st;
	NOD* dr;
};

NOD* initNod(Serial s, NOD* st, NOD* dr) {
	NOD* nou = (NOD*)malloc(sizeof(NOD));
	nou->info = s;//shallow copy
	nou->dr = dr;
	nou->st = st;

	return nou;
}

NOD* inserareArbore(NOD* rad, Serial s) {
	if (rad) {
		if (rad->info.id > s.id) {
			rad->st = inserareArbore(rad->st, s);
			return rad;
		}
		else {
			rad->dr = inserareArbore(rad->dr, s);
			return rad;
		}
	}
	else {
		return initNod(s, NULL, NULL);
	}
}

void afisareArbore(NOD* rad) {
	if (rad) {
		afisareArbore(rad->st);
		afisareSerial(rad->info);
		afisareArbore(rad->dr);
	}
}

Serial cautareSerialDupaID(NOD* rad, int id) {
	if (rad) {
		if (rad->info.id == id) {
			return rad->info;
		}
		else {
			if (rad->info.id > id) {
				return cautareSerialDupaID(rad->st, id);
			}
			else {
				return cautareSerialDupaID(rad->dr, id);
			}
		}
	}
	else {
		Serial s;
		s.id = -1;
		s.numarActori = -1;
		s.actori = NULL;
		return s;
	}
}

int inaltimeArbore(NOD* rad) {
	if (rad) {
		int hSt = inaltimeArbore(rad->st);
		int hDr = inaltimeArbore(rad->dr);
		return 1 + (hSt > hDr ? hSt : hDr);
	}
	else {
		return 0;
	}
}

void afisareDePeNivel(NOD* rad, int nivelCurent, int nivelDorit) {
	if (rad) {
		if (nivelCurent == nivelDorit) {
			afisareSerial(rad->info);
		}
		else {
			afisareDePeNivel(rad->st, nivelCurent + 1, nivelDorit);
			afisareDePeNivel(rad->dr, nivelCurent + 1, nivelDorit);
		}
	}
}

int numarPremiiPentruSerial(Serial s) {
	int suma = 0;
	for (int i = 0; i < s.numarActori; i++) {
		suma += s.actori[i].nrPremiiCastigate;
	}
	return suma;
}

void afisareSerialeCuActoriBuni(NOD* rad, int nrPremiiMinim) {
	if (rad) {
		afisareSerialeCuActoriBuni(rad->st,nrPremiiMinim);
		if(numarPremiiPentruSerial(rad->info)>=nrPremiiMinim)
			afisareSerial(rad->info);
		afisareSerialeCuActoriBuni(rad->dr, nrPremiiMinim);
	}
}

void main() {

	FILE* f = fopen("seriale.txt", "r");
	NOD* rad = NULL;

	int nrSeriale = 0;
	fscanf(f, "%d", &nrSeriale);
	for (int i = 0; i < nrSeriale; i++) {
		rad = inserareArbore(rad, citesteSerial(f));
	}

	afisareArbore(rad);
	printf("\n\n");
	afisareSerial(cautareSerialDupaID(rad, 6));

	printf("\n\n%d\n\n",inaltimeArbore(rad));

	afisareDePeNivel(rad, 1, 2);
	printf("\n\n");
	afisareSerialeCuActoriBuni(rad, 8);
	
}