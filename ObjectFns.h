#pragma once
#include "ListFns.h"
#include "MarkNSweepGC.h"
#include "StringFns.h"

typedef struct VirtualMachine VirtualMachine;



typedef union ObjectData {
	int intData;
	float floatData;
	double doubleData; 
	char charData;
	bool boolData;
	str* stringData;
	void* pointerData;
	List* listData;
}ObjectData;

typedef struct Object {
	ObjectData data;
	DataTag tag;
	bool is_marked;
}Object;

Object* objectMaker(VirtualMachine* vm);
Object* newInt(VirtualMachine* vm, int data);
Object* newFloat(VirtualMachine* vm, float data);
Object* newDouble(VirtualMachine* vm, double data);
Object* newChar(VirtualMachine* vm, char data);
Object* newBool(VirtualMachine* vm, bool data);
Object* newString(VirtualMachine* vm, str* data);
Object* newPointer(VirtualMachine* vm, void* data);
Object* newList(VirtualMachine* vm, List* data);

int objectLength(Object* obj);
Object* objectAdder(Object* A, Object* B);
void objectPrint(Object* obj);
void objectFree(Object* obj);