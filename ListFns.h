#pragma once

//List of values of different data types

typedef enum DataType {
	INTEGER=sizeof(int),
	FLOATING_POINT=sizeof(float),
	DOUBLE_POINT=sizeof(double),
	CHARACTER=sizeof(char),
	BOOLING = sizeof(bool),
	STRING=sizeof(char*),
	POINTER = sizeof(void*)
} DataType;

typedef enum DataTag {
	INT = 0,
	FLOAT ,
	DOUBLE ,
	CHAR ,
	BOOL ,
	STR ,
	PTR 
}DataTag;

typedef struct List {
	void* data;
	DataType* type;
	DataTag* tag;
	int len;
	int dataSize;
	int typeSize;
	int tagSize;
} List;

//FUNCTIONS
List* listMaker();
void listAppend(List* l , void* data , DataTag tag);
int findDataOffset(List* l, int index = 0);
DataType getType(DataTag tag);
void* listGet(List* l, int index = 0);

void betterListAppend(List* l, int data);
void betterListAppend(List* l, float data);
void betterListAppend(List* l, double data);
void betterListAppend(List* l, char data);
void betterListAppend(List* l, bool data);
void betterListAppend(List* l, char* data);
void betterListAppend(List* l, void* data);

void listFree(List* l);
void listRemove(List* l, int index = 0);
void listInsert(List* l, void* data, DataType tag, int index = 0);

void betterListInsert(List* l, int data, int index = 0);
void betterListInsert(List* l, float data, int index = 0);
void betterListInsert(List* l, double data, int index = 0);
void betterListInsert(List* l, char data, int index = 0);
void betterListInsert(List* l, bool data, int index = 0);
void betterListInsert(List* l, char* data, int index = 0);
void betterListInsert(List* l, void* data, int index = 0);

void listPrint(List* l, int from_index = 0, int no_of_elements = -1);


