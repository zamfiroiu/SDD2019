//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct nodLista {
//	int nota;
//	nodLista* next;
//};
//
//nodLista* inserareLaInceput(nodLista*cap, int nota) {
//	nodLista*nou = (nodLista*)malloc(sizeof(nodLista));
//	nou->nota = nota;
//	nou->next = cap;
//	return nou;
//}
//
//struct Student {
//	int id;
//	char* nume;
//	nodLista* note;
//};
//
//Student citesteStudentDinFisier(FILE* f) {
//	Student s;
//	fscanf(f,"%d", &s.id);
//	char buffer[20];
//	fscanf(f, "%s", buffer);
//	s.nume = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(s.nume, buffer);
//	int nrNote = 0;
//	fscanf(f, "%d", &nrNote);
//	s.note = NULL;
//	for (int i = 0; i < nrNote; i++) {
//		int nota = 0;
//		fscanf(f, "%d", &nota);
//		s.note = inserareLaInceput(s.note, nota);
//	}
//	return s;
//}
//
//void afisareListaNote(nodLista* cap) {
//	while (cap) {
//		printf("%d ", cap->nota);
//		cap = cap->next;
//	}
//}
//
//void afisareStudent(Student s) {
//	printf("%d. %s are notele: ", s.id, s.nume);
//	afisareListaNote(s.note);
//	printf("\n");
//}
//
//struct nodArbore {
//	Student info;
//	nodArbore* st;
//	nodArbore* dr;
//};
//
//nodArbore* inserareInArbore(nodArbore*rad, Student s) {
//	if (rad) {
//		if (s.id < rad->info.id) {
//			rad->st = inserareInArbore(rad->st, s);
//		}
//		else {
//			rad->dr = inserareInArbore(rad->dr, s);
//		}
//		return rad;
//	}
//	else {
//		nodArbore* nou = (nodArbore*)malloc(sizeof(nodArbore));
//		nou->dr = NULL;
//		nou->st = NULL;
//		nou->info = s;
//		return nou;
//	}
//}
//
//void afisareArbore(nodArbore*rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		afisareStudent(rad->info);
//		afisareArbore(rad->dr);
//	}
//}
//
//void stergereLista(nodLista* &cap) {
//	while (cap) {
//		nodLista* temp = cap->next;
//		free(cap);
//		cap = temp;
//	}
//}
//
//nodArbore* cautaMinim(nodArbore*rad) {
//	if (rad) {
//		if (rad->st)
//			return cautaMinim(rad->st);
//		else {
//			return rad;
//		}
//	}
//}
//
//nodArbore* stergereNod(nodArbore* rad, int id, Student& student) {
//	if (rad) {
//		if (id < rad->info.id) {
//			rad->st = stergereNod(rad->st, id, student);
//			return rad;
//		}
//		else {
//			if (id > rad->info.id) {
//				rad->dr = stergereNod(rad->dr, id, student);
//				return rad;
//			}
//			else {
//				if (rad->st == NULL) {
//					student = rad->info;
//					nodArbore*temp = rad->dr;
//					free(rad);
//					return temp;
//				}
//				else {
//					if (rad->dr == NULL) {
//						student = rad->info;
//						nodArbore*temp = rad->st;
//						free(rad);
//						return temp;
//					}
//					else {
//						nodArbore* minim = cautaMinim(rad->dr);
//						Student aux = minim->info;
//						minim->info = rad->info;
//						rad->info = aux;
//						rad->dr=stergereNod(rad->dr, id, student);
//						return rad;
//					}
//				}
//			}
//		}
//	}
//}
//
//void main() {
//	FILE*f = fopen("studenti.txt", "r");
//	nodArbore* rad = NULL;
//	if (f) {
//		int nrStudenti = 0;
//		fscanf(f, "%d", &nrStudenti);
//		for (int i = 0; i < nrStudenti; i++) {
//			Student s = citesteStudentDinFisier(f);
//			afisareStudent(s);
//			rad = inserareInArbore(rad, s);
//		}
//	}
//	printf("\n");
//	afisareArbore(rad);
//	Student student;
//	stergereNod(rad, 3,student);
//
//	printf("\n");
//	afisareArbore(rad);
//
//	printf("\nStudentul extras:");
//	afisareStudent(student);
//
//}