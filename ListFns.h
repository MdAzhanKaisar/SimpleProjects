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

//helpful in input
void* getPtr(int a);
void* getPtr(char a);
void* getPtr(float a);
void* getPtr(double a);
void* getPtr(bool a);
