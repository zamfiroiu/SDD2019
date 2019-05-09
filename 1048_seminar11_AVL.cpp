//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Marker {
//	int id;
//	char* culoare;
//	int cuCapac;
//};
//
//Marker createMarker(int id, const char* culoare, int cuCapac)  {
//	Marker m;
//	m.culoare = (char*)malloc(sizeof(char*)*(strlen(culoare)+1));
//	strcpy(m.culoare, culoare);
//	m.id = id;
//	m.cuCapac = cuCapac;
//	return m;
//}
//
//struct NOD {
//	Marker info;
//	NOD* st;
//	NOD* dr;
//};
//
//int inaltimeArbore(NOD* rad) {
//	if (rad) {
//		int hS = inaltimeArbore(rad->st);
//		int hD = inaltimeArbore(rad->dr);
//		return 1 + (hS > hD ? hS : hD);
//	}
//	else return 0;
//}
//
//
//int gradEchilibru(NOD* rad) {
//	if (rad) {
//		int hS = inaltimeArbore(rad->st);
//		int hD = inaltimeArbore(rad->dr);
//		return hS - hD;
//	}
//	else {
//		return 0;
//	}
//}
//
//NOD* rotireLaStanga(NOD* rad) {
//	if (rad) {
//		NOD*aux = rad->dr;
//		rad->dr = aux->st;
//		aux->st = rad;
//		return aux;
//	}
//	else {
//		return rad;
//	}
//}
//
//NOD*rotireLaDreapta(NOD*rad) {
//	if (rad) {
//		NOD* aux = rad->st;
//		rad->st = aux->dr;
//		aux->dr = rad;
//		return aux;
//	}
//	else return rad;
//}
//
//NOD* inserareAVL(NOD* rad, Marker m) {
//	if (rad) {
//		if (m.id < rad->info.id) {
//			rad->st = inserareAVL(rad->st, m);
//		}
//		else {
//			rad->dr = inserareAVL(rad->dr, m);
//		}
//		int ge = gradEchilibru(rad); 
//
//		if (ge == -2) {
//			//avem dezchilibru in partea dreapta
//			int ged = gradEchilibru(rad->dr);
//			if (ged != -1) {
//				rad->dr = rotireLaDreapta(rad->dr);
//			}
//
//			rad = rotireLaStanga(rad);
//		}
//		if (ge == 2) {
//			int ges = gradEchilibru(rad->st);
//			if (ges == 1) {
//				rad = rotireLaDreapta(rad);
//			}
//			else {
//				rad->st = rotireLaStanga(rad->st);
//				rad = rotireLaDreapta(rad);
//			}
//		}
//		return rad;
//	}
//	else {
//		NOD* nou = (NOD*)malloc(sizeof(NOD));
//		nou->st = nou->dr = NULL;
//		nou->info = m;
//		return nou;
//	}
//}
//
//void main() {
//	NOD* rad = NULL;
//	rad = inserareAVL(rad, createMarker(1, "Negru", 1));
//	rad = inserareAVL(rad, createMarker(2, "Rosu", 1));
//	rad = inserareAVL(rad, createMarker(3, "Verde", 0));
//	rad = inserareAVL(rad, createMarker(4, "Albastru", 1));
//	rad = inserareAVL(rad, createMarker(5, "Negru", 0));
//	rad = inserareAVL(rad, createMarker(6, "Verde", 1));
//}