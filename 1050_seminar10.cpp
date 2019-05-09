//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
////heap
////bst
////hasTable
//
//struct listNode {
//	int info;
//	listNode* next;
//};
//
//struct HashTable {
//	listNode* *heads;
//	int length;
//};
//
//HashTable initHashTable(int length) {
//	HashTable h;
//	h.length = length;
//	h.heads = (listNode**)malloc(sizeof(listNode*)*length);
//	for (int i = 0; i < length; i++) {
//		h.heads[i] = NULL;
//	}
//
//	return h;
//}
//
//int hashFunction(int length, int info) {
//	return info % length;
//}
//
//void insertInList(listNode* &head, int info) {
//	listNode* newNode = (listNode*)malloc(sizeof(listNode));
//	newNode->next = head;
//	newNode->info = info;
//	head = newNode;
//}
//
//void insertInHashTable(HashTable h, int info) {
//	if (h.length > 0) {
//		int code = hashFunction(h.length, info);
//		insertInList(h.heads[code], info);
//	}
//}
//
//
//struct HEAP {
//	int* vector;
//	int length;
//};
//
//HEAP initHeap(int length) {
//	HEAP h;
//	h.vector = (int*)malloc(sizeof(int)*length);
//	h.length = length;
//	return h;
//}
//
//void filter(HEAP heap, int index) {
//	if (index < heap.length) {
//		int leftPos = 2 * index + 1;
//		int rightPos = 2 * index + 2;
//		int maxPos = index;
//		if (leftPos < heap.length && heap.vector[maxPos] < heap.vector[leftPos]) {
//			maxPos = leftPos;
//		}
//		if (rightPos < heap.length && heap.vector[maxPos] < heap.vector[rightPos]) {
//			maxPos = rightPos;
//		}
//		if (maxPos != index) {
//			int aux = heap.vector[index];
//			heap.vector[index] = heap.vector[maxPos];
//			heap.vector[maxPos] = aux;
//			if (2 * maxPos + 1 < heap.length) {
//				filter(heap, maxPos);
//			}
//		}
//	}
//}
//
//
//struct treeNode {
//	treeNode* leftChild;
//	treeNode* rightChild;
//	int info;
//};
//
//treeNode*insertInTree(treeNode*root, int info) {
//	if (root) {
//		if (info < root->info) {
//			root->leftChild = insertInTree(root->leftChild, info);
//		}
//		else {
//			root->rightChild = insertInTree(root->rightChild, info);
//		}
//		return root;
//	}
//	else {
//		treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
//		newNode->leftChild = newNode->rightChild = NULL;
//		newNode->info = info;
//		return newNode;
//	}
//}
//
//void printTreeInOrder(treeNode* root) {
//	if (root) {
//		printTreeInOrder(root->leftChild);
//		printf("%d ", root->info);
//		printTreeInOrder(root->rightChild);
//	}
//}
//
//void transformTreeToHashTable(treeNode* root, HashTable h) {
//	if (root) {
//		transformTreeToHashTable(root->leftChild,h);
//		insertInHashTable(h, root->info);
//		transformTreeToHashTable(root->rightChild,h);
//	}
//}
//
//void printList(listNode*head) {
//	while (head) {
//		printf("%d, ", head->info);
//		head = head->next;
//	}
//}
//
//void printHashTable(HashTable h) {
//	for (int i = 0; i < h.length; i++) {
//		printf("%d.", (i + 1));
//		if (h.heads[i]) {
//			printList(h.heads[i]);
//		}
//		printf("\n");
//	}
//}
//
//void main() {
//	HEAP heap = initHeap(6);
//	for (int i = 0; i < heap.length; i++) {
//		heap.vector[i] = i+1;
//	}
//
//	for (int i = (heap.length - 2) / 2; i >= 0; i--) {
//		filter(heap, i);
//	}
//
//	for (int i = 0; i < heap.length; i++) {
//		printf("%d, ", heap.vector[i]);
//	}
//
//	treeNode* root = NULL;
//	for (int i = 0; i < heap.length; i++) {
//		root = insertInTree(root, heap.vector[i]);
//	}
//	printf("\nTree: \n");
//	printTreeInOrder(root);
//
//	HashTable h = initHashTable(9);
//	transformTreeToHashTable(root, h);
//	printf("\nHashTable:\n");
//	printHashTable(h);
//}