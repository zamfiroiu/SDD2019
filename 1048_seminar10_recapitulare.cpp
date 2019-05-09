//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Proiect {
//	int id;
//	char* titlu;
//	int nrPagini;
//};
//
//
//struct nodArbore {
//	Proiect info;
//	nodArbore* st;
//	nodArbore* dr;
//};
//
//nodArbore* inserareInArbore(nodArbore* rad, Proiect p) {
//	if (rad) {
//		if (rad->info.id > p.id) {
//			rad->st = inserareInArbore(rad->st, p);
//		}
//		else {
//			rad->dr = inserareInArbore(rad->dr, p);
//		}
//		return rad;
//	}
//	else {
//		nodArbore* nou = (nodArbore*)malloc(sizeof(nodArbore));
//		nou->info = p;
//		nou->dr = nou->st = NULL;
//		return nou;
//	}
//}
//
//Proiect iniProiect(int id, const char* titlu, int nrPagini) {
//	Proiect p;
//	p.id = id;
//	p.titlu = (char*)malloc(sizeof(char)*(strlen(titlu) + 1));
//	strcpy(p.titlu, titlu);
//	p.nrPagini = nrPagini;
//	return p;
//}
//
//void afisareInordine(nodArbore*rad) {
//	if (rad) {
//		afisareInordine(rad->st);
//		printf("%d.Proiectul %s are %d pagini.\n", rad->info.id, rad->info.titlu, rad->info.nrPagini);
//		afisareInordine(rad->dr);
//	}
//}
//
//struct NodLista {
//	Proiect info;
//	NodLista* next;
//};
//
//NodLista*inserareLaInceputInLista(NodLista*cap, Proiect p) {
//	NodLista*nou = (NodLista*)malloc(sizeof(NodLista));
//	nou->info = p;//shallow copy
//	nou->next = cap;
//	return nou;
//}
//
//void transformareDinArboreInLista(nodArbore* rad, NodLista* &cap) {
//	if (rad) {
//		transformareDinArboreInLista(rad->st, cap);
//		cap = inserareLaInceputInLista(
//			cap,
//			iniProiect(rad->info.id,
//				rad->info.titlu,
//				rad->info.nrPagini));
//		transformareDinArboreInLista(rad->dr, cap);
//	}
//}
//
//void transformareDinArboreInListaCuConditie(nodArbore* rad, NodLista* &cap,int prag) {
//	if (rad) {
//		transformareDinArboreInListaCuConditie(rad->st, cap,prag);
//		if (rad->info.nrPagini >= prag) {
//			cap = inserareLaInceputInLista(
//				cap,
//				iniProiect(rad->info.id,
//					rad->info.titlu,
//					rad->info.nrPagini));
//		}
//		transformareDinArboreInListaCuConditie(rad->dr, cap,prag);
//	}
//}
//
//void afisareLista(NodLista*cap) {
//	while (cap) {
//		printf("%d.Proiectul %s are %d pagini.\n", cap->info.id, cap->info.titlu, cap->info.nrPagini);
//		cap = cap->next;
//	}
//}
//
//nodArbore* adresaNoduluiMaxim(nodArbore*rad) {
//	if (rad->dr) {
//		return adresaNoduluiMaxim(rad->dr);
//	}
//	else {
//		return rad;
//	}
//}
//
//nodArbore* adresaNoduluiMaximIterativ(nodArbore* rad) {
//	if (rad) {
//		while (rad->dr) {
//			rad = rad->dr;
//		}
//		return rad;
//	}
//}
//
//nodArbore* extragereDinArbore(nodArbore* rad, int id, Proiect &p) {
//	if (rad) {
//		if (id > rad->info.id) {
//			rad->dr=extragereDinArbore(rad->dr, id, p);
//			return rad;
//		}
//		else {
//			if (id < rad->info.id) {
//				rad->st = extragereDinArbore(rad->st, id, p);
//				return rad;
//			}
//			else {
//				p = rad->info;//shallow copy
//				if (rad->st == NULL) {
//					nodArbore*temp = rad->dr;
//					free(rad);
//					return temp;
//				}
//				else {
//					if (rad->dr == NULL) {
//						nodArbore*temp = rad->st;
//						free(rad);
//						return temp;
//					}
//					else {
//						nodArbore* maxim = adresaNoduluiMaxim(rad->st);
//						Proiect aux = maxim->info;
//						maxim->info = rad->info;
//						rad->info = aux;
//						rad->st = extragereDinArbore(rad->st, id, p);
//						return rad;
//					}
//				}
//
//			}
//		}
//	}
//	else {
//		return rad;
//	}
//}
//
//void main() {
//	nodArbore* rad = NULL;
//	rad = inserareInArbore(rad, iniProiect(5, "Titlu 5", 15));
//	rad = inserareInArbore(rad, iniProiect(7, "Titlu 7", 50));
//	rad = inserareInArbore(rad, iniProiect(8, "Titlu 8", 30));
//	rad = inserareInArbore(rad, iniProiect(3, "Titlu 3", 20));
//	rad = inserareInArbore(rad, iniProiect(4, "Titlu 4", 10));
//	
//	afisareInordine(rad);
//	//NodLista* cap = NULL;
//	//transformareDinArboreInListaCuConditie(rad, cap, 18);
//	//printf("\n\nLista:\n");
//	//afisareLista(cap);
//	
//	Proiect p;
//	rad = extragereDinArbore(rad, 4, p);
//	printf("dupa extragere:\n");
//	afisareInordine(rad);
//
//
//}