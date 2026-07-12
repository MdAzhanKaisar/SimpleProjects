#include "ListFns.h"
#include <stdio.h>
#include <stdlib.h>



// Function to create a new list
List* listMaker() {
	//allocate memory for the list struct, data array and type array
	List* newList = (List*)calloc(1,sizeof(List));
	if (newList == NULL) { return NULL; }

	newList->data = calloc(10,sizeof(char)); 
	if (newList->data == NULL) { listFree(newList); return NULL; }

	newList->type = (DataType*)calloc(10, sizeof(DataType));
	if (newList->type == NULL) { listFree(newList); return NULL; }
	// assign the length and size of the list
	newList->len = 0;
	newList->dataSize = 10;
	newList->typeSize = 10;
	return newList;
}



//to get the data offset for a given index in the list. It returns the offset in bytes from the start of the data array to the data at the specified index.
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
		l->data = realloc(l->data, (l->dataSize + 10) * sizeof(char));
		l->dataSize += 10;
	}
	if (l->data == NULL) { listFree(l); return; }
	//appending data to tha list.
	for (int j = 0; j < type;j++) {
		((char*)l->data)[dataSize + j] = ((char*)data)[j];
	}
	//Appending type and updating length of the list.
	l->type[l->len] = type;
	l->len++;
}



// Function to get data ptr at a given index in the list.
void* listGet(List* l, int index) {
	if (index == 0) { return l->data; }
	int offset = findDataOffset(l, index);
	if (offset == -1) { return NULL; }
	return (void*) ((char*)l->data + offset - l->type[index]);
}



// Functions to append any const value to the list
void betterListAppend(List* l, int data)        { listAppend(l, (void*)(&data), INT); }
void betterListAppend(List* l, float data)      { listAppend(l, (void*)(&data), FLOAT); }
void betterListAppend(List* l, double data)     { listAppend(l, (void*)(&data), DOUBLE); }
void betterListAppend(List* l, char data)       { listAppend(l, (void*)(&data), CHAR); }
void betterListAppend(List* l, bool data)       { listAppend(l, (void*)(&data), BOOL); }
void betterListAppend(List* l, char* data)      { listAppend(l, (void*)(&data), STRING); }
void betterListAppend(List* l, void* data)      { listAppend(l, (void*)(&data), POINTER); }



// Function to free the memory allocated for a list
void listFree(List* l) {
	if (l == NULL) { return; }
	if (l->data != NULL) { free(l->data); l->data = NULL; }
	if (l->type != NULL) { free(l->type); l->type = NULL; }
	free(l);
}



// Function to remove an element from the list at a given index
void listRemove(List* l, int index) {
	if (l == NULL || index < 0 || index >= l->len) { return; }
	// getting offset
	int offset = findDataOffset(l, index);
	if (offset == -1) { return; }
	//check and realloc to increase size if needed
	if (l->dataSize - offset <= l->type[index]) {
		l->data = realloc(l->data, (l->dataSize + 10) * sizeof(char));
		l->dataSize += 10;
	}
	if (l->data == NULL) { listFree(l); return; }
	//removing by shifting the data and the type
	for (int i = offset - l->type[index]; i < findDataOffset(l, l->len - 1) ; i++) {
		((char*)l->data)[i] = ((char*)l->data)[l->type[index] + i];
	} 
	for (int i = index; i < l->len - 1; i++) { 
		(l->type[i]) = (l->type[i + 1]);
	} 
	//updating list length
	l->len--;

}



// Function to insert data in the list at a specefic index
void listInsert(List* l , void* data, DataType type, int index) {
	if (l == NULL || data == NULL || type == 0 || index < 0 || index >= l->len) { return; }
	// Getting offset
	int offset = findDataOffset(l, index);
	if (offset == -1) { return; }
	// Check and realloc to icrease size of data array and type array if needed
	if (l->dataSize - offset <= type) {
		l->data = realloc(l->data, (l->dataSize + 10) * sizeof(char));
		l->dataSize += 10;
	}
	if (l->len == l->typeSize) {
		l->type = (DataType*)realloc(l->type, (l->typeSize + 5) * sizeof(DataType));
		l->typeSize += 5;
	}
	// shifting data towards right to create space
	for (int i = findDataOffset(l, l->len - 1) + type - 1 ; i > offset - l->type[index] - 1; i--) {
		((char*)l->data)[i + type] = ((char*)l->data)[i];
	}
	for (int i = l->len; i > index - 1; i--) {
		l->type[i + 1] = l->type[i];
	}
	//Inserting data
	for (int i = 0;i < type;i++) {
		((char*)l->data)[offset - type + i] = ((char*)data)[i];
	}
	l->type[index] = type;
	// Updating length
	l->len++;

}



// Functions to insert any const value to the list
void betterListInsert(List* l, int data, int index)       { listInsert(l, (void*)(&data), INT, index); }
void betterListInsert(List* l, float data, int index)     { listInsert(l, (void*)(&data), FLOAT, index); }
void betterListInsert(List* l, double data, int index)    { listInsert(l, (void*)(&data), DOUBLE, index); }
void betterListInsert(List* l, char data, int index)      { listInsert(l, (void*)(&data), CHAR, index); }
void betterListInsert(List* l, bool data, int index)      { listInsert(l, (void*)(&data), BOOL, index); }
void betterListInsert(List* l, char* data, int index)     { listInsert(l, (void*)(&data), STRING, index); }
void betterListInsert(List* l, void* data, int index)     { listInsert(l, (void*)(&data), POINTER, index); }



// Function to print the list
void listPrint(List* l, int from_index, int no_of_elements) {
	if (l == NULL || from_index < 0 || from_index >= l->len || no_of_elements < -1) { return; }
	// Correcting no_of_elements
	if (no_of_elements == -1) { no_of_elements = l->len; }
	if (no_of_elements > l->len - from_index) { no_of_elements = l->len - from_index; }
	// Variables for storing data and type temporarily
	void* data;
	DataType type;
	// Print loop
	printf("[ ");
	for (int i = from_index; no_of_elements > 0;i++) {
		data = listGet(l, i);
		type = l->type[i];
		//Could not use switch-case as INT and FLOAT are both associated with 4 which is the size of respective datatypes and so on...
		if (type == INT)     { printf("%i, ", *((int*)data)); }
		else if (type == FLOAT)   { printf("%f, ", *((float*)data)); }
		else if (type == DOUBLE)  { printf("%lf, ", *((double*)data)); }
		else if (type == CHAR)    { printf("%c, ", *((char*)data)); }
		else if (type == BOOL)    { printf("%s, ", (*((bool*)data) ? "true" : "false")); }
		else if (type == STRING)  { printf("%s, ", *((char**)data)); }
		else if (type == POINTER) { printf("%p, ", *((void**)data)); }
		no_of_elements--;
	}
	printf("]");

}

















