//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//struct ZOO {
//	char* name;
//	int noAnimals;
//};
//
//struct node {
//	ZOO value;
//	node* next;
//};
//
//ZOO initZOO(const char* name, int noAnimals) {
//	ZOO z;
//	z.name = (char*)malloc(sizeof(char)* strlen(name) + 1);
//	strcpy(z.name, name);
//	z.noAnimals = noAnimals;
//	return z;
//}
//
//node* createNode(ZOO z, node* next) {
//	node* newNode = (node*)malloc(sizeof(node));
//	newNode->value = z;
//	newNode->next = next;
//	return newNode;
//}
//
//void printZOO(ZOO zoo) {
//	printf("%s has %d animals.\n", zoo.name, zoo.noAnimals);
//}
//
//node* insertAtTheEnd(ZOO zoo, node* head) {
//	if (head) {
//		node* temp = head;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next = createNode(zoo, NULL);
//		return head;
//	}
//	else {
//		head = createNode(zoo, NULL);
//		return head;
//	}
//}
//
//void printList(node* head) {
//	while (head) {
//		printZOO(head->value);
//		head = head->next;
//	}
//}
//
//node* insertAtTheBegin(ZOO zoo, node* head) {
//	node* newNode = createNode(zoo, head);
//	return newNode;
//}
//
//float AvgAnimals(node* head)
//{
//	if (head) {
//		float avg = 0;
//		int noNodes = 0;
//		while (head)
//		{
//			avg = avg + head->value.noAnimals;
//			head = head->next;
//			noNodes++;
//		}
//		return avg / noNodes;
//	}
//	else
//		return 0;
//}
//
//void freeList(node* &head) {
//	if (head) {
//		freeList(head->next);
//		free(head->value.name);
//		free(head);
//	}
//}
//
//node* AscendingInsertion(ZOO zoo, node* head) {
//	if (head) {
//		
//		node* temp = head;
//		if (temp->value.noAnimals > zoo.noAnimals) {
//			head = insertAtTheBegin(zoo, head);
//			return head;
//		}
//		while (temp->next && temp->next->value.noAnimals < zoo.noAnimals) {
//			temp = temp->next;
//		}
//		node* newNode = createNode(zoo, temp->next);
//		temp->next = newNode;
//		return head;
//	}
//	else {
//		return createNode(zoo, NULL);
//	}
//}
//
//void main() {
//	ZOO zoo = initZOO("ZOO", 50);
//	node* noode = createNode(zoo, nullptr);
//	printZOO(noode->value);
//	node*head = noode;
//
//	node* list = NULL;
//	list = AscendingInsertion(initZOO("Berlin ZOO", 500), list);
//	list = AscendingInsertion(initZOO("Baneasa ZOO", 100), list);
//	list = AscendingInsertion(initZOO("Munchen ZOO", 200), list);
//	printList(list);
//
//	list = AscendingInsertion(initZOO("Paris ZOO", 300), list);
//
//	printf("%5.2f", AvgAnimals(list));
//
//	freeList(list);
//}
//
//
