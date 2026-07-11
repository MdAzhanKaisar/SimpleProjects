#include "StringFns.h"
#include "ListFns.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This is to test the functions
int main() {
	printf("Begin...\n");

	//test code
	printf("\n\n\n            Append \n\n\n");

	List* L1 = listMaker();
	printf("List created with length: %d\n", L1->len);
	int i = 25;
	listAppend(L1, (void*)(&i), INT);
	printf("List length after appending an int: %d\n", L1->len);
	printf("List data: %d\n", *((int*) listGet(L1, 0)));
	printf("List type: %d\n", L1->type[0]);
	printf("List data size: %d\n", L1->dataSize);
	printf("List type size: %d\n", L1->typeSize);

	printf("\n\n\n            Append \n\n\n");

	char s = 'A';
	listAppend(L1, (void*)(&s), CHAR);
	listAppend(L1, (void*)(&s), CHAR);
	listAppend(L1, (void*)(&s), CHAR);
	listAppend(L1, (void*)(&s), CHAR);
	listAppend(L1, (void*)(&s), CHAR);
	printf("List length after appending a char: %d\n", L1->len);
	printf("List data: %c\n", *( (char*) listGet(L1,5) ) );
	printf("List type: %d\n", L1->type[5]);
	printf("List data size: %d\n", L1->dataSize);
	printf("List type size: %d\n", L1->typeSize);

	printf("\n\n\n            Append \n\n\n");

	listAppend(L1, (void*)(&i), INT);
	printf("List length after appending an int: %d\n", L1->len);
	printf("List data: %d\n", *((int*)listGet(L1, 6)));
	printf("List type: %d\n", L1->type[6]);
	printf("List data size: %d\n", L1->dataSize);
	printf("List type size: %d\n", L1->typeSize);







	printf("\nEnd...");
	return 0;
}