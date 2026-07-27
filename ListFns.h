#pragma once
#include <stdbool.h>
#include <stddef.h>
//List of values of different data types
typedef struct List List;
typedef struct Object Object;
void objectPrint(Object* obj);

typedef enum DataType {
	INTEGER=sizeof(int),
	FLOATING_POINT=sizeof(float),
	DOUBLE_POINT=sizeof(double),
	CHARACTER=sizeof(char),
	BOOLING = sizeof(bool),
	STRING=sizeof(char*),
	POINTER = sizeof(void*),
	LIST= sizeof(List*),
	OBJECT=sizeof(Object*),
} DataType;

typedef enum DataTag {
	INT = 0,
	FLOAT ,
	DOUBLE ,
	CHAR ,
	BOOL ,
	STR ,
	PTR ,
	LST ,
	OBJ ,
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
void betterListAppend(List* l, List* data);
void betterListAppend(List* l, Object* data);

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
void betterListInsert(List* l, List* data, int index = 0);
void betterListInsert(List* l, Object* data, int index = 0);

void listPrint(List* l, int from_index = 0, int no_of_elements = -1);
int listFind(List* l, void* data = NULL, DataTag tag = OBJ, int start_index = 0);

int betterListFind(List* l, int data);
int betterListFind(List* l, float data);
int betterListFind(List* l, double data);
int betterListFind(List* l, char data);
int betterListFind(List* l, bool data);
int betterListFind(List* l, char* data);
int betterListFind(List* l, void* data);
int betterListFind(List* l, List* data);
int betterListFind(List* l, Object* data);

List* listAdder(List* L1, List* L2, int from_index_L1 = 0, int from_index_L2 = 0, int no_of_elements_L1 = -1, int no_of_elements_L2 = -1);