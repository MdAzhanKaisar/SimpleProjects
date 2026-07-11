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

//to get the data pointer for a given index in the list. It returns the offset in bytes from the start of the data array to the data at the specified index.
int findDataOffset(List* l, int index) {
	if (l == NULL || index < 0 || index >= l->len || l->data==NULL || l->type==NULL) { return -1; }
	int dataSize = 0;
	for (int i = 0; i <= index; i++) {
		dataSize += ((l->type)[i]);
	}
	return dataSize;
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
	int dataSize = (l->len == 0) ? 0 : findDataOffset(l, l->len - 1);

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


// Function to get data ptr at a given index in the list.
void* listGet(List* l = NULL, int index = 0) {
	if (index == 0) { return l->data; }
	int offset = findDataOffset(l, index);
	if (offset == -1) { return NULL; }
	return (void*) ((char*)l->data + offset - l->type[index]);
}



// Functions to append any const value to the list
void betterListAppend(List* l, int data) { listAppend(l, (void*)(&data), INT); }
void betterListAppend(List* l, float data) { listAppend(l, (void*)(&data), FLOAT); }
void betterListAppend(List* l, double data) { listAppend(l, (void*)(&data), DOUBLE); }
void betterListAppend(List* l, char data) { listAppend(l, (void*)(&data), CHAR); }
void betterListAppend(List* l, bool data) { listAppend(l, (void*)(&data), BOOL); }
void betterListAppend(List* l, char* data) { listAppend(l, (void*)(&data), STRING); }
void betterListAppend(List* l, void* data) { listAppend(l, (void*)(&data), POINTER); }




















