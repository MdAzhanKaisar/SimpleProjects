#include "ListFns.h"
#include <stdio.h>
#include <stdlib.h>

List* listMaker(int len) {
	//allocate memory for the list struct, data array and type array
	List* newList = (List*)calloc(1,sizeof(List));
	if (newList == NULL) { return NULL; }

	newList->data = calloc(len,sizeof(void*));
	if (newList->data == NULL) { free(newList); return NULL; }

	newList->type = (DataType*)calloc(len, sizeof(DataType));
	if (newList->type == NULL) { free(newList->data); free(newList); return NULL; }

	newList->len = len;
	return newList;
}