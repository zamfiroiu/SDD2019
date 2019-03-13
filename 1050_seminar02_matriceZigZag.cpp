//#include <iostream>
//enum TYPE {
//	withCoffeine=0,
//	decaf
//};
//
//struct Coffee
//{
//	char* name;
//	float price;
//	TYPE type;
//};
//
//Coffee initCoffe(const char* name, float price, TYPE type)
//{
//	Coffee c;
//	c.name = (char*)malloc((strlen(name) + 1) * sizeof(char));
//	strcpy(c.name, name);
//	c.price = price;
//	c.type = type;
//	return c;
//}
//
//Coffee readCoffee()
//{
//	printf("The name is ");
//	char buffer[20];
//	scanf("%s", buffer);
//	Coffee c;
//	c.name = new char[strlen(buffer) + 1];
//	strcpy(c.name, buffer);
//	printf("The price is ");
//	scanf("%f", &c.price);
//	printf("The type is (1=decaf/0=with caffeine) ");
//	scanf("%d", &c.type);
//	return c;
//}
//
//void printCoffee(Coffee c) {
//	printf("Coffee'name: %s ", c.name);
//	printf("Price: %5.2f ", c.price);
//	if (c.type == TYPE::decaf)
//		printf("Decaf.\n");
//	else {
//		printf("with coffeine\n");
//	}
//}
//
//Coffee** readZigZagMatrix(int* nrLines, int* *nrColumns) {
//	printf("numaber of lines:");
//	scanf("%d", nrLines);
//
//	Coffee** matrix;
//	matrix = (Coffee**)malloc(sizeof(Coffee*)*(*nrLines));
//	*nrColumns = (int*)malloc(sizeof(int)*(*nrLines));
//	for (int i = 0; i < *nrLines; i++) {
//		printf("nr of elemnts for the line %d", i+1);
//		scanf("%d", &(*nrColumns)[i]);
//		matrix[i] = (Coffee*)malloc(sizeof(Coffee)*(*nrColumns)[i]);
//		for (int j = 0; j < (*nrColumns)[i]; j++) {
//			matrix[i][j] = readCoffee();
//		}
//	}
//	return matrix;
//}
//
//void printZigZagMatrix(Coffee** m, int l, int* c)
//{
//	for (int i = 0; i < l; i++)
//	{
//		printf("The line %d", i + 1);
//		for (int j = 0; j < c[i]; j++)
//			printCoffee(m[i][j]);
//
//	}
//}
//
//void main() {
//	Coffee c = initCoffe("Jacobs", 10, TYPE::decaf);
//	printCoffee(c);
//	Coffee c2=readCoffee();
//	printCoffee(c2);
//
//	int nrLines = 0;
//	int* nrColumns = NULL;
//	Coffee**matrix = readZigZagMatrix(&nrLines, &nrColumns);
//	printZigZagMatrix(matrix, nrLines, nrColumns);
//
//	for (int i = 0; i < nrLines; i++) {
//		for (int j = 0; j < nrColumns[i]; j++) {
//			free(matrix[i][j].name);
//		}
//		free(matrix[i]);
//	}
//	free(nrColumns);
//	free(matrix);
//	free(c.name);
//	free(c2.name);
//}