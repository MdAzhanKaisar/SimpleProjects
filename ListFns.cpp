#include "ListFns.h"
#include <stdio.h>
#include <stdlib.h>





// Function to create a new list
List* listMaker() {
	//allocate memory for the list struct, data array and type array
	List* newList = (List*)calloc(1,sizeof(List));
	if (newList == NULL) { return NULL; }

	newList->data = calloc(10,sizeof(void*));
	if (newList->data == NULL) { free(newList); return NULL; }

	newList->type = (DataType*)calloc(10, sizeof(DataType));
	if (newList->type == NULL) { free(newList->data); free(newList); return NULL; }
	// assign the length and size of the list
	newList->len = 0;
	newList->dataSize = 10;
	newList->typeSize = 10;
	return newList;
}





// Function to add data to a list
void listAppend(List* l, void* data, DataType type) {
	if (l == NULL || data == NULL ) { return; }
	// checking if the type array needs to be resized.
	if (l->len == l->typeSize) {
		l->type = (DataType*)realloc(l->type, (l->typeSize + 5) * sizeof(DataType));
		l->typeSize += 5;
	}
	if (l->type == NULL) { return; }
	//finding length in bytes.
	int dataSize = 0;
	for (int i = 0; i < l->len; i++) {
		dataSize += ((l->type)[i]);
	}
	//checking if the data array needs to be resized.
	if ((l->dataSize - dataSize) <= type) {
		l->data = realloc(l->data, (l->dataSize + 10) * sizeof(void*));
		l->dataSize += 10;
	}
	if (l->data == NULL) { return; }
	//appending data to tha list.
	for (int j = 0; j < type;j++) {
		((char*)l->data)[dataSize + j] = ((char*)data)[j];
	}
	//Appending type and updating length of the list.
	l->type[l->len] = type;
	l->len++;
}

