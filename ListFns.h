#pragma once

//List of values of different data types

typedef enum DataType {
	INT=sizeof(int),
	FLOAT=sizeof(float),
	DOUBLE=sizeof(double),
	CHAR=sizeof(char),
	STRING=sizeof(char*)
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

