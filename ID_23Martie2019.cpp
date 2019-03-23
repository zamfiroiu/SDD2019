//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
////liste cuirculare
//
//struct Muzeu {
//	char* denumire;
//	float pret;
//	char esteDeschis;
//};
//
//Muzeu creareMuzeu(const char* denumire, float pret, char deschis) {
//	Muzeu m;
//	m.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	strcpy(m.denumire, denumire);
//	m.pret = pret;
//	m.esteDeschis = deschis;
//
//	return m;
//}
//
//void afisareMuzeu(Muzeu m) {
//	printf("Muzeul %s ", m.denumire);
//	if (m.esteDeschis) {
//		printf("este deschis, ");
//	}
//	else
//		printf("NU este deschis, ");
//	printf("iar pretul biletului este de %5.2f.\n", m.pret);
//}
//
//struct Nod {
//	Muzeu info;
//	Nod* next;
//};
//
//Nod* inserareInceputListaCirculara(Nod* cap, Muzeu m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = m;//shallow copy
//	if (cap) {
//		nou->next = cap;
//		Nod* temp = cap;
//		while (temp->next != cap) {
//			temp = temp->next;
//		}
//		temp->next = nou;	
//	}
//	else {
//		nou->next = nou;
//	}
//	return nou;
//}
//
//void afisareListaCirculara(Nod*cap) {
//	Nod* temp = cap;
//	while (temp && temp->next != cap) {
//		afisareMuzeu(temp->info);
//		temp = temp->next;
//	}
//	afisareMuzeu(temp->info);
//}
//
//Nod* stergereListaCirculara(Nod* cap) {
//	Nod* temp = cap;
//	while (temp && temp->next != cap) {
//		free(temp->info.denumire);
//		Nod*aux = temp;
//		temp = temp->next;
//		free(aux);
//	}
//	free(temp);
//	return NULL;
//}
//
//void main() {
//	Nod* cap = NULL;
//	Muzeu m = creareMuzeu("Antipa", 20, 1);
//	cap = inserareInceputListaCirculara(cap, m);
//
//	cap = inserareInceputListaCirculara(cap, creareMuzeu("Luvru", 30, 1));
//	cap = inserareInceputListaCirculara(cap, creareMuzeu("Geologie", 10, 0));
//	cap = inserareInceputListaCirculara(cap, creareMuzeu("Aviatiei", 30, 1));
//
//	afisareListaCirculara(cap);
//	cap=stergereListaCirculara(cap);
//	cap = inserareInceputListaCirculara(cap, creareMuzeu("ASE", 30, 1));
//
//	afisareListaCirculara(cap);
//
//
//}