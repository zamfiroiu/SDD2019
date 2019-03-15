//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//struct Animal {
//	float greutate;
//	char* nume;
//	int anNastere;
//};
//
//struct Nod {
//	Animal info;
//	Nod* next;
//	Nod* prev;
//};
//
//Animal initAnimal(const char* nume, int an, float greutate) {
//	Animal a;
//	a.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(a.nume, nume);
//	a.greutate = greutate;
//	a.anNastere = an;
//	
//	return a;
//}
//
//Nod* initNod(Animal a, Nod* next, Nod* prev) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = next;
//	nou->prev = prev;
//	
//	return nou;
//}
//
//struct ListaDubluInlantuita {
//	Nod* prim;
//	Nod* ultim;
//};
//
//ListaDubluInlantuita inserareInceput(ListaDubluInlantuita lista, Animal a) {
//	Nod* nou = initNod(a, NULL, NULL);
//	if (lista.prim) {
//		nou->next = lista.prim;
//		lista.prim->prev = nou;
//		lista.prim = nou;
//	}
//	else {
//		lista.prim = nou;
//		lista.ultim = nou;
//	}
//	return lista;
//
//}
//
//ListaDubluInlantuita inserareSfarsit(ListaDubluInlantuita lista, Animal a) {
//	Nod* nou = initNod(a, NULL, NULL);
//	if (lista.ultim) {
//		nou->prev = lista.ultim;
//		lista.ultim->next = nou;
//		lista.ultim = nou;
//	}
//	else {
//		lista.prim = nou;
//		lista.ultim = nou;
//	}
//	return lista;
//
//}
//
//void afisareAnimal(Animal a) {
//	printf("%s are o greutate de %5.2f si este nascut in %d.\n", a.nume, a.greutate, a.anNastere);
//}
//
//void printLista(ListaDubluInlantuita lista) {
//	while (lista.prim) {
//		afisareAnimal(lista.prim->info);
//		lista.prim = lista.prim->next;
//	}
//}
//
//
//void stergereLista(ListaDubluInlantuita &lista) {
//	while (lista.ultim) {
//		Nod* aux = lista.ultim;
//		lista.ultim = lista.ultim->prev;
//		free(aux->info.nume);
//		free(aux);
//	}
//	lista.ultim = NULL;
//	lista.prim = NULL;
//}
//
//Animal extragereDinListaDupaNume(ListaDubluInlantuita &lista, const char* nume) {
//	Nod* temp = lista.prim;
//	while (temp && strcmp(temp->info.nume, nume) != 0) {
//		temp = temp->next;
//	}
//	if (temp) {
//		Animal rezultat = temp->info;
//		//Animal rez = initAnimal(temp->info.nume, temp->info.anNastere, temp->info.greutate);
//		if (temp->prev) {
//			temp->prev->next = temp->next;
//			if (temp->next) {
//				temp->next->prev = temp->prev;
//			}
//			else{
//				lista.ultim = temp->prev;
//			}
//			//free(temp->info.nume);
//			free(temp);
//		}
//		else {
//			lista.prim = temp->next;
//			lista.prim->prev = NULL;
//			free(temp);
//		}
//		return rezultat;
//	}
//	else {
//		return initAnimal("", 0, 0);
//	}
//}
//
//void main() {
//	ListaDubluInlantuita lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//	lista = inserareInceput(lista, initAnimal("Pisica", 2010, 6));
//	lista = inserareInceput(lista, initAnimal("Caine", 2016, 8));
//	lista = inserareInceput(lista, initAnimal("Hamster", 2017, 1));
//
//	printLista(lista);
//
//
//
//	lista = inserareSfarsit(lista, initAnimal("Papagal", 2016, 8));
//
//	printLista(lista);
//
//	printf("\n\n");
//	afisareAnimal(extragereDinListaDupaNume(lista, "Hamster"));
//
//	printf("\n\n");
//
//	printLista(lista);
//	stergereLista(lista);
//}