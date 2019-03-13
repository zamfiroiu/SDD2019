//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Oras {
//	char* nume;
//	int nrLocuitori;
//};
//
//struct nod {
//	Oras info;
//	nod* next;
//};
//
//Oras initOras(const char* nume, int nrLocuitori) {
//	Oras o;
//	o.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(o.nume, nume);
//	o.nrLocuitori = nrLocuitori;
//	return o;
//}
//
//void afisareOras(Oras o) {
//	printf("%s are %d locuitori.\n", o.nume, o.nrLocuitori);
//}
//
//nod* createNode(Oras o, nod*next) {
//	nod*nodNou = (nod*)malloc(sizeof(nod));
//	nodNou->info = o;
//	nodNou->next = next;
//	return nodNou;
//}
//
//nod* inserareSfarsit(nod* cap, Oras o) {
//	nod* nou = createNode(o, NULL);
//	if (cap) {
//		nod* temp = cap;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//
//	return cap;
//}
//
//void afisareLista(nod*cap) {
//	while (cap) {
//		afisareOras(cap->info);
//		cap = cap->next;
//	}
//
//}
//
//nod* inserareInceput(nod* cap, Oras oras) {
//	nod* nou = createNode(oras, cap);
//	return nou;
//}
//
//float medieLocuitori(nod *cap)
//{
//	if (cap)
//	{
//		float suma = 0;
//		int nr = 0;
//		while (cap)
//		{
//			suma += cap->info.nrLocuitori;
//			nr++;
//			cap = cap->next;
//		}
//		return suma / nr;
//	}
//	else return 0;
//	
//}
//
//nod* stergeLista(nod* cap) {
//	while (cap) {
//		nod*aux = cap;
//		cap = cap->next;
//		free(aux->info.nume);
//		free(aux);
//	}
//	return cap;
//
//	//alta viarinta
//	//{
//	//	nod*aux = cap->next;
//	//	free(cap->info.nume);
//	//	free(cap);
//	//	cap = aux;
//	//}
//}
//
//nod* inserareDupaUnNodCuInformatiaData(nod*cap, Oras oras, const char* nume){
//	nod* nou = createNode(oras, NULL);
//	if(cap){
//		nod* temp = cap;
//		while (temp&&strcmp(temp->info.nume, nume) != 0) {
//			temp = temp->next;
//		}
//		/*while (temp) {
//			if(strcmp(temp->info.nume, nume) == 0){
//				nod* nou = createNode(oras, temp->next);
//				temp->next = nou;
//			}
//			temp = temp->next;
//		}*/
//	
//		if (temp == NULL) {
//			cap = inserareSfarsit(cap, oras);
//		}
//		else {
//			nou->next = temp->next;
//			temp->next = nou;
//		}
//	}
//	else {
//		cap = nou;
//	}
//	return cap;
//}
//
//void main() {
//	Oras o = initOras("Bucuresti", 2000);
//	nod* node = createNode(o, NULL);
//	nod* node2 = node;
//
//	nod* cap = NULL;
//
//	cap = inserareSfarsit(cap, initOras("Iasi", 200));
//	cap = inserareSfarsit(cap, initOras("Craiova", 100));
//	cap = inserareSfarsit(cap, initOras("Focsani", 50));
//	cap = inserareSfarsit(cap, initOras("Timisoara", 300));
//	afisareLista(cap);
//	cap = inserareInceput(cap, initOras("Cluj", 600));
//	afisareLista(cap);
//
//	printf("%5.2f", medieLocuitori(cap));
//
//	cap=stergeLista(cap);
//
//	cap = inserareInceput(cap, initOras("Galati", 300));
//
//	afisareLista(cap);
//
//
//}