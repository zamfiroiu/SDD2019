//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Food {
//	float quantity;
//	int expireYear;
//	char* name;
//};
//
//struct node {
//	node*next;
//	node* prev;
//	Food info;
//};
//
//
//Food initFood(const char*name, int expireYear, float quantity) {
//	Food t;
//	t.name = (char*)malloc(sizeof(char)*(strlen(name) + 1));
//	strcpy(t.name, name);
//	t.expireYear = expireYear;
//	t.quantity = quantity;
//	
//	return t;
//}
//
//node* initNode(Food info, node* next, node* prev) {
//	node* newNode = (node*)malloc(sizeof(node));
//	newNode->info = info;//shallow copy
//	newNode->next = next;
//	newNode->prev = prev;
//
//	return newNode;
//}
//
//struct DoubleLinkedList {
//	node* first;
//	node* last;
//};
//
//DoubleLinkedList insertBegin(DoubleLinkedList list, Food info) {
//	node* newNode = initNode(info,NULL,NULL);
//	if (list.first) {
//		newNode->next = list.first;
//		list.first->prev = newNode;
//		list.first = newNode;
//	}
//	else {
//		list.first = newNode;
//		list.last = newNode;
//	}
//	return list;
//}
//DoubleLinkedList insertAtTheEnd(DoubleLinkedList list, Food info) {
//	node* newNode = initNode(info, NULL, NULL);
//	if (list.last) {
//		newNode->prev = list.last;
//		list.last->next = newNode;
//		list.last = newNode;
//	}
//	else {
//		list.first = newNode;
//		list.last = newNode;
//	}
//	return list;
//}
//
//void printFood(Food food) {
//	printf("We have %5.2f %s, that expires in %d\n", food.quantity, food.name, food.expireYear);
//}
//
//void printList(DoubleLinkedList ld) {
//	while (ld.first) {
//		printFood(ld.first->info);
//		ld.first = ld.first->next;
//	}
//}
//
//void deleteList(DoubleLinkedList &list) {
//	if (list.first) {
//		while (list.first->next) {
//			free(list.first->info.name);
//			list.first = list.first->next;
//			free(list.first->prev);
//		}
//		free(list.first->info.name);
//		free(list.first);
//		list.first = NULL;
//		list.last = NULL;
//	}
//}
//
//void main() {
//	DoubleLinkedList dl;
//	dl.first = NULL;
//	dl.last = NULL;
//	dl = insertBegin(dl, initFood("Orange", 2019, 2));
//	dl = insertBegin(dl, initFood("Banana", 2020, 3));
//	dl = insertBegin(dl, initFood("Apple", 2021, 4));
//
//	printList(dl);
//
//	dl = insertAtTheEnd(dl, initFood("Pineapple", 2029, 7));
//	printf("\n");
//	printList(dl);
//
//	deleteList(dl);
//}