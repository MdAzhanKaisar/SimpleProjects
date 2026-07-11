#pragma once

//List of values of different data types

typedef enum DataType {
	INT=sizeof(int),
	FLOAT=sizeof(float),
	DOUBLE=sizeof(double),
	CHAR=sizeof(char),
	BOOL = sizeof(bool),
	STRING=sizeof(char*),
	POINTER = sizeof(void*)
} DataType;

typedef struct List {
	void* data;
	DataType* type;
	int len;
	int dataSize;
	int typeSize;
} List;

//FUNCTIONS
List* listMaker();
void listAppend(List* l, void* data, DataType type);
int findDataOffset(List* l, int index);
void* listGet(List* l, int index);

void betterListAppend(List* l, int data);
void betterListAppend(List* l, float data);
void betterListAppend(List* l, double data);
void betterListAppend(List* l, char data);
void betterListAppend(List* l, bool data);
void betterListAppend(List* l, char* data);
void betterListAppend(List* l, void* data);

void listFree(List* l);
void listRemove(List* l, int index);