//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Marker {
//	int id;
//	char* color;
//	int withCap;
//};
//
//Marker createMarker(int id, const char* color, int withCap) {
//	Marker m;
//	m.color = (char*)malloc(sizeof(char*)*(strlen(color) + 1));
//	strcpy(m.color, color);
//	m.id = id;
//	m.withCap = withCap;
//	return m;
//}
//
//struct NODE {
//	Marker info;
//	NODE* left;
//	NODE* right;
//};
//
//int calculateHeight(NODE* root) {
//	if (root) {
//		int rH = calculateHeight(root->right);
//		int lH = calculateHeight(root->left);
//		return 1 + (rH > lH ? rH : lH);
//	}
//	else {
//		return 0;
//	}
//}
//
//int calculateED(NODE*root) {
//	if (root) {
//		int hR = calculateHeight(root->right);
//		int hL = calculateHeight(root->left);
//		return hR - hL;
//	}
//	else return 0;
//}
//
//NODE* rotateToLeft(NODE* root) {
//	if (root) {
//		NODE* pivot = root->right;
//		root->right = pivot->left;
//		pivot->left = root;
//		return pivot;
//	}
//	else {
//		return root;
//	}
//}
//
//NODE* rotateToRight(NODE* root) {
//	if (root) {
//		NODE* pivot = root->left;
//		root->left = pivot->right;
//		pivot->right = root;
//		return pivot;
//	}
//	else {
//		return root;
//	}
//}
//
//NODE* insertAVL(NODE* rad, Marker m) {
//	if (rad) {
//		if (m.id < rad->info.id) {
//			rad->left = insertAVL(rad->left, m);
//		}
//		else {
//			rad->right = insertAVL(rad->right, m);
//		}
//		int ED = calculateED(rad);
//		if (ED == 2) {
//			int EDR = calculateED(rad->right);
//			if (EDR == 1) {
//				rad = rotateToLeft(rad);
//			}
//			else {
//				rad->right = rotateToRight(rad->right);
//				rad = rotateToLeft(rad);
//			}
//		}
//		if (ED == -2) {
//			int EDL = calculateED(rad->left);
//			if (EDL == -1) {
//				rad = rotateToRight(rad);
//			}
//			else {
//				rad->left = rotateToLeft(rad->left);
//				rad = rotateToRight(rad);
//			}
//		}
//		return rad;
//	}
//	else {
//		NODE* nou = (NODE*)malloc(sizeof(NODE));
//		nou->left = nou->right = NULL;
//		nou->info = m;
//		return nou;
//	}
//}
//
//void main() {
//	//one article
//	//the structure for the tree node
//	//the function to insert 
//	//a new node in a Binary search tree
//
//	NODE* rad = NULL;
//	rad = insertAVL(rad, createMarker(1, "Black", 1));
//	rad = insertAVL(rad, createMarker(2, "Red", 1));
//	rad = insertAVL(rad, createMarker(3, "Green", 0));
//	rad = insertAVL(rad, createMarker(4, "Blue", 1));
//	rad = insertAVL(rad, createMarker(5, "Black", 0));
//	rad = insertAVL(rad, createMarker(6, "Green", 1));
//}
