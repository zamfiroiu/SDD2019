//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Author {
//	char* name;
//	int age;
//};
//
//struct Book {
//	int id;
//	Author author;
//	int noPages;
//};
//
//Book readBook(FILE* f) {
//	Book b;
//	fscanf(f, "%d", &b.id);
//	char buffer[20];
//	fscanf(f, "%s", buffer);
//	b.author.name = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(b.author.name, buffer);
//	fscanf(f, "%d", &b.author.age);
//	fscanf(f, "%d", &b.noPages);
//
//	return b;
//}
//
//void printBook(Book b) {
//	printf("%d. Book writed by %s has %d pages. %d\n", b.id, b.author.name, b.noPages, b.author.age);
//}
//
//
//struct NODE {
//	Book info;
//	NODE* left;
//	NODE* right;
//};
//
//NODE* initNode(Book info, NODE* left, NODE* right) {
//	NODE* newNode = (NODE*)malloc(sizeof(NODE));
//	newNode->info = info;//shallow copy
//	newNode->left = left;
//	newNode->right = right;
//	return newNode;
//}
//
//NODE* insertTree(NODE* root, Book book) {
//	if (root) {
//		if (book.id < root->info.id) {
//			root->left = insertTree(root->left, book);
//			return root;
//		}
//		else {
//			root->right = insertTree(root->right, book);
//			return root;
//		}
//	}
//	else {
//		return initNode(book, NULL, NULL);
//	}
//}
//
//void printTree(NODE* root) {
//	if (root) {
//		printTree(root->left);
//		printBook(root->info);
//		printTree(root->right);
//	}
//}
//
//Book findBookByID(NODE* root, int id) {
//	if (root) {
//		if (root->info.id == id) {
//			return root->info;
//		}
//		else {
//			if (root->info.id > id) {
//				return findBookByID(root->left, id);
//			}
//			else {
//				return findBookByID(root->right, id);
//			}
//		}
//	}
//	else {
//		Book b;
//		b.id = -1;
//		b.author.age = -1;
//		b.author.name = NULL;
//		b.noPages = -1;
//		return b;
//	}
//}
//
//int height(NODE* root) {
//	if (root) {
//		int hL = height(root->left);
//		int hR = height(root->right);
//		return 1 + (hL > hR ? hL : hR);
//	}
//	else {
//		return 0;
//	}
//}
//
//void afisareDePeNivel(NODE* root, int nivelDorit, int currentLevel) {
//	if (root) {
//		if (nivelDorit == currentLevel) {
//			printBook(root->info);
//		}
//		else {
//			afisareDePeNivel(root->left, nivelDorit, currentLevel + 1);
//			afisareDePeNivel(root->right, nivelDorit, currentLevel + 1);
//		}
//	}
//}
//
//void main() {
//
//	FILE * f = fopen("books.txt", "r");
//	NODE* root = NULL;
//	int noBooks = 0;
//	fscanf(f, "%d", &noBooks);
//	for (int i = 0; i < noBooks; i++) {
//		root = insertTree(root, readBook(f));
//	}
//	printTree(root); 
//
//	printf("\n\n");
//
//	printBook(findBookByID(root, 6));
//	printf("\n\n%d\n", height(root));
//
//	afisareDePeNivel(root, 3, 1);
//}