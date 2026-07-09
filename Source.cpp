#include "StringFns.h"
#include "ListFns.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This is to test the functions
int main() {
	printf("Begin...\n");

	//test code
	List* L1 = listMaker(5);
	printf("List created with length: %d\n", L1->len);

	printf("\nEnd...");
	return 0;
}