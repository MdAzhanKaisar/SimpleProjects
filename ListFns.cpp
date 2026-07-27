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

	newList->tag = (DataTag*)calloc(10, sizeof(DataTag));
	if (newList->tag == NULL) { listFree(newList); return NULL; }
	// assign the length and size of the list
	newList->len = 0;
	newList->dataSize = 10;
	newList->typeSize = 10;
	newList->tagSize = 10;
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



DataType getType(DataTag tag) {
	switch (tag) {
	case INT:    return INTEGER; 
	case FLOAT:  return FLOATING_POINT; 
	case DOUBLE: return DOUBLE_POINT; 
	case CHAR:   return CHARACTER; 
	case BOOL:   return BOOLING; 
	case STR:    return STRING; 
	case PTR:    return POINTER;
	case LST:    return LIST;
	case OBJ:	 return OBJECT;
	}
	return INTEGER;
}



// Function to add data to a list
void listAppend(List* l, void* data, DataTag tag) {
	if (l == NULL || data == NULL ) { return; }
	// checking if the type array needs to be resized.
	if (l->len == l->typeSize) {
		l->type = (DataType*)realloc(l->type, (l->typeSize + 5) * sizeof(DataType));
		l->typeSize += 5;
	}
	if (l->type == NULL) { return; }
	//checking if tag array needs to be resized
	if (l->len == l->tagSize) {
		l->tag = (DataTag*)realloc(l->type, (l->typeSize + 5) * sizeof(DataTag));
		l->tagSize += 5;
	}
	if (l->tag == NULL) { return; }
	//finding length in bytes.
	int dataSize = (l->len == 0) ? 0 : findDataOffset(l, l->len - 1);
	DataType type = getType(tag);
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
	l->tag[l->len] = tag;
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
void betterListAppend(List* l, char* data)      { listAppend(l, (void*)(&data), STR); }
void betterListAppend(List* l, void* data)      { listAppend(l, (void*)(&data), PTR); }
void betterListAppend(List* l, List* data)		{ listAppend(l, (void*)(&data), LST); }
void betterListAppend(List* l, Object* data)		{ listAppend(l, (void*)(&data), OBJ); }


// Function to free the memory allocated for a list
void listFree(List* l) {
	if (l == NULL) { return; }
	if (l->data != NULL) { free(l->data); l->data = NULL; }
	if (l->type != NULL) { free(l->type); l->type = NULL; }
	if (l->tag != NULL) { free(l->tag); l->tag = NULL; }
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
		(l->tag[i]) = (l->tag[i + 1]);
	} 
	//updating list length
	l->len--;

}



// Function to insert data in the list at a specefic index
void listInsert(List* l , void* data, DataTag tag, int index) {
	if (l == NULL || data == NULL || index < 0 || index >= l->len) { return; }
	// Getting offset and type
	int offset = findDataOffset(l, index);
	if (offset == -1) { return; }
	DataType type = getType(tag);
	// Check and realloc to icrease size of data array, tag array and type array if needed
	if (l->dataSize - offset <= type) {
		l->data = realloc(l->data, (l->dataSize + 10) * sizeof(char));
		l->dataSize += 10;
	}
	if (l->data == NULL) { return; }
	if (l->len == l->typeSize) {
		l->type = (DataType*)realloc(l->type, (l->typeSize + 5) * sizeof(DataType));
		l->typeSize += 5;
	}
	if (l->type == NULL) { return; }
	if (l->len == l->tagSize) {
		l->tag = (DataTag*)realloc(l->type, (l->typeSize + 5) * sizeof(DataTag));
		l->tagSize += 5;
	}
	if (l->tag == NULL) { return; }
	// shifting data towards right to create space
	for (int i = findDataOffset(l, l->len - 1) + type - 1 ; i > offset - l->type[index] - 1; i--) {
		((char*)l->data)[i + type] = ((char*)l->data)[i];
	}
	for (int i = l->len; i > index - 1; i--) {
		l->type[i + 1] = l->type[i];
		l->tag[i + 1] = l->tag[i];
	}
	//Inserting data
	for (int i = 0;i < type;i++) {
		((char*)l->data)[offset - type + i] = ((char*)data)[i];
	}
	l->type[index] = type;
	l->tag[index] = tag;
	// Updating length
	l->len++;

}



// Functions to insert any const value to the list
void betterListInsert(List* l, int data, int index)       { listInsert(l, (void*)(&data), INT, index); }
void betterListInsert(List* l, float data, int index)     { listInsert(l, (void*)(&data), FLOAT, index); }
void betterListInsert(List* l, double data, int index)    { listInsert(l, (void*)(&data), DOUBLE, index); }
void betterListInsert(List* l, char data, int index)      { listInsert(l, (void*)(&data), CHAR, index); }
void betterListInsert(List* l, bool data, int index)      { listInsert(l, (void*)(&data), BOOL, index); }
void betterListInsert(List* l, char* data, int index)     { listInsert(l, (void*)(&data), STR, index); }
void betterListInsert(List* l, void* data, int index)     { listInsert(l, (void*)(&data), PTR, index); }
void betterListInsert(List* l, List* data, int index)     { listInsert(l, (void*)(&data), LST, index); }
void betterListInsert(List* l, Object* data, int index)     { listInsert(l, (void*)(&data), OBJ, index); }



// Function to print the list
void listPrint(List* l, int from_index, int no_of_elements) {
	if (l == NULL || from_index < 0 || from_index >= l->len || no_of_elements < -1) { return; }
	// Correcting no_of_elements
	if (no_of_elements == -1) { no_of_elements = l->len; }
	if (no_of_elements > l->len - from_index) { no_of_elements = l->len - from_index; }
	// Variables for storing data and tag temporarily
	void* data;
	DataTag tag;
	// Print loop
	printf("[ ");
	for (int i = from_index; no_of_elements > 0;i++) {
		data = listGet(l, i);
		tag = l->tag[i];
		//Could not use switch-case as INT and FLOAT are both associated with 4 which is the size of respective datatypes and so on...
		switch(tag){
			case INT: 
				printf("%i, ", *((int*)data)); 
				break;
		    case FLOAT:  
				printf("%f, ", *((float*)data));
				break;
			case DOUBLE: 
				printf("%lf, ", *((double*)data)); 
				break;
			case CHAR:  
				printf("%c, ", *((char*)data)); 
				break;
			case BOOL:  
				printf("%s, ", (*((bool*)data) ? "true" : "false"));
				break;
			case STR: 
				printf("%s, ", *((char**)data)); 
				break;
			case PTR: 
				printf("%p, ", *((void**)data)); 
				break;
			case LST:
				listPrint(*((List**)data)); printf(", ");
			case OBJ:
				objectPrint(*((Object**)data)); printf(", ");
			}
		no_of_elements--;
	}
	printf("]");

}



// Function to find a value in the list and return its index.
int listFind(List* l, void* data, DataTag tag, int start_index) {
	if (l == NULL || start_index >= l->len || start_index < 0) { return -1; }
	//Temporary variables to store data*, type and check if data matches
	void* temp;
	DataType type;
	int check = 0;
	//Checking loop
	for (int i = start_index;i < l->len;i++) {
		if (l->tag[i] == tag) {
			temp = listGet(l, i);

			if (data == NULL) { return i; }
			
			type = getType(tag);
			// Loop checks each byte
			for (int j = 0; j < type;j++) {
				if (((char*)temp)[j] == ((char*)data)[j]) { check++; }
			}
			
			if (check == type) { return i; }
			else { check = 0; }
		}
	}
	return -1;
}



// Functions to find any const value from the list and return its index
int betterListFind(List* l, int data)       { return listFind(l, (void*)(&data), INT); }
int betterListFind(List* l, float data)     { return listFind(l, (void*)(&data), FLOAT); }
int betterListFind(List* l, double data)    { return listFind(l, (void*)(&data), DOUBLE); }
int betterListFind(List* l, char data)      { return listFind(l, (void*)(&data), CHAR); }
int betterListFind(List* l, bool data)      { return listFind(l, (void*)(&data), BOOL); }
int betterListFind(List* l, char* data)     { return listFind(l, (void*)(&data), STR); }
int betterListFind(List* l, void* data)     { return listFind(l, (void*)(&data), PTR); }
int betterListFind(List* l, List* data)     { return listFind(l, (void*)(&data), LST); }
int betterListFind(List* l, Object* data)     { return listFind(l, (void*)(&data), OBJ); }



// Function to add two lists
List* listAdder(List* L1, List* L2, int from_index_L1, int from_index_L2, int no_of_elements_L1, int no_of_elements_L2) {
	if (L1 == NULL || L2 == NULL || from_index_L1 < 0 || from_index_L1 > L1->len ||
		from_index_L2 < 0 || from_index_L2 > L2->len || no_of_elements_L1 < -1 || no_of_elements_L2 < -1) {
		return NULL;
	}
	// Correcting no_of_elements
	if (no_of_elements_L1 == -1) { no_of_elements_L1 = L1->len; }
	if (no_of_elements_L1 > L1->len - from_index_L1) { no_of_elements_L1 = L1->len - from_index_L1; }
	if (no_of_elements_L2 == -1) { no_of_elements_L2 = L2->len; }
	if (no_of_elements_L2 > L2->len - from_index_L2) { no_of_elements_L2 = L2->len - from_index_L2; }
	// Necessary variables
	List* L = listMaker();
	if (L == NULL) { return NULL; }
	void* data;
	DataTag tag;
	// Append Loops
	for (int i = from_index_L1; no_of_elements_L1 > 0;i++) {
		data = listGet(L1, i);
		tag = L1->tag[i];
		listAppend(L, data, tag);
		no_of_elements_L1--;
	}
	for (int i = from_index_L2; no_of_elements_L2 > 0;i++) {
		data = listGet(L2, i);
		tag = L1->tag[i];
		listAppend(L, data, tag);
		no_of_elements_L2--;
	}
	return L;
}




