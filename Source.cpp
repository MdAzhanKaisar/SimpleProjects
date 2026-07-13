#include "StringFns.h"
#include "ListFns.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This is to test the functions
int main() {
	printf("Begin...\n");

	//test code
	List* L1 = listMaker();
	printf("List L1 created with length: %d\n", L1->len);
	int i = 25;

	listAppend(L1, (void*)(&i), INT); printf("Appended 25\n");
	betterListAppend(L1, 'a'); printf("Appended \'a\'\n");
	betterListAppend(L1, 50.2); printf("Appended 50.2\n");
	betterListAppend(L1, (float)20.1); printf("Appended 20.1\n");
	betterListAppend(L1, 100); printf("Appended 100\n\n\n");
	//L2

	List* L2 = listMaker();
	printf("List L2 created with length: %d\n", L2->len);


	listAppend(L2, (void*)(&i), INT); printf("Appended 25\n");
	betterListAppend(L2, 'b'); printf("Appended \'b\'\n");
	betterListAppend(L2, 69.2); printf("Appended 69.2\n");
	betterListAppend(L2, (float)42.0); printf("Appended 42.0\n");
	betterListAppend(L2, 1000); printf("Appended 1000\n\n\n");
	//L3
	List* L3 = listAdder(L1, L2,1,2,3,6);


	printf("L1 = "); listPrint(L1);
	printf("\nL2 = "); listPrint(L2);
	printf("\nL3 = "); listPrint(L3);





	printf("\nEnd...");
	return 0;
}