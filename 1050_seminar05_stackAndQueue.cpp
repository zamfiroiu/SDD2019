//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Drink {
//	char* name;
//	float price;
//	int withAlcohol;
//};
//
//struct Node {
//	Drink info;
//	Node*next;
//};
//
//struct DoubleNode {
//	Drink info;
//	DoubleNode*next;
//	DoubleNode*prev;
//};
//
//struct DoubleList {
//	DoubleNode*first;
//	DoubleNode* last;
//};
//
//DoubleList pushQueue(DoubleList list, Drink drink) {
//	DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
//	newNode->info = drink;
//	newNode->prev = NULL;
//	newNode->next = list.first;
//	if (list.first) {
//		list.first->prev = newNode;
//		list.first = newNode;
//	}
//	else {
//		list.first = list.last = newNode;
//	}
//	return list;
//}
//
//Drink createDrink(const char* name, float price, int withAlcohol) {
//	Drink d;
//	d.name = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
//	strcpy(d.name, name);
//	d.price = price;
//	d.withAlcohol = withAlcohol;
//
//	return d;
//}
//
//Drink popQueue(DoubleList &list) {
//	if (list.last) {
//		Drink result = list.last->info;
//		if (list.first == list.last) {
//			free(list.first);
//			list.first = list.last = NULL;
//		}
//		else {
//			list.last = list.last->prev;
//			free(list.last->next);
//			list.last->next = NULL;
//		}
//		return result;
//	}
//	else {
//		return createDrink("", 0, 0);
//	}
//}
//
//int isEmptyQueue(DoubleList list) {
//	return list.first == NULL;
//}
//
//
//void printDrink(Drink drink) {
//	if (drink.withAlcohol)
//		printf("%s cost %5.2f and is with alcohol.\n", drink.name, drink.price);
//	else
//		printf("%s cost %5.2f and is without alcohol.\n", drink.name, drink.price);
//}
//
//
//Node* pushStack(Drink drink, Node* head) {
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->info = drink;
//	newNode->next = NULL;
//	if (head) {
//		Node* temp = head;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next = newNode;
//	}
//	else {
//		head = newNode;
//	}
//	return head;
//}
//
//Drink popStack(Node* *head) {
//	if (*head) {
//		Node* temp = *head;
//		while (temp->next && temp->next->next) {
//			temp = temp->next;
//		}
//
//		if (temp->next) {
//			Drink result = temp->next->info;
//			free(temp->next);
//			temp->next = NULL;
//			return result;
//		}
//		else {
//			Drink result = temp->info;
//			free(temp);
//			*head = NULL;
//			return result;
//		}
//	}
//	else {
//		return createDrink("", 0, 0);
//	}
//
//}
//
//int isEmptyStack(Node* head) {
//	return head == NULL;
//}
//
//void main() {
//	Node* stack = NULL;
//	stack = pushStack(createDrink("Cola", 3, 0), stack);
//	stack = pushStack(createDrink("Pepsi", 3.5, 0), stack);
//	stack = pushStack(createDrink("Teddy", 1, 0), stack);
//	stack = pushStack(createDrink("Beer", 5, 1), stack);
//
//	//while (!isEmptyStack(stack)) {
//	//	printDrink(popStack(&stack));
//	//}
//	//printf("\n\n");
//	//stack = pushStack(createDrink("Wine", 5, 1), stack);
//
//	//while (!isEmptyStack(stack)) {
//	//	printDrink(popStack(&stack));
//	//}
//
//	DoubleList queue;
//	queue.first = queue.last = NULL;
//
//	while (!isEmptyStack(stack)) {
//		queue = pushQueue(queue, popStack(&stack));
//	}
//
//	while (!isEmptyQueue(queue)) {
//		printDrink(popQueue(queue));
//	}
//
//
//}