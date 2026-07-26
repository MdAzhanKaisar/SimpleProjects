#include "ObjectFns.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#pragma warning(push)
#pragma warning(disable : 4996) // Disables the C4996 'unsafe' warning



//Makes object.
Object* objectMaker(VirtualMachine* vm) {
	Object* obj = (Object*)calloc(1, sizeof(Object));
	if (obj == NULL) { return NULL; }
	obj->is_marked = false;
	return obj;
}



//int object
Object* newInt(VirtualMachine* vm, int data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	(obj->data).intData = data;
	obj->tag = INT;
	return obj;
}



//Float object
Object* newFloat(VirtualMachine* vm, float data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	(obj->data).floatData = data;
	obj->tag = FLOAT;
	return obj;
}



//Double object
Object* newDouble(VirtualMachine* vm, double data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	(obj->data).doubleData = data;
	obj->tag = DOUBLE;
	return obj;
}



//char object
Object* newChar(VirtualMachine* vm, char data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	(obj->data).charData = data;
	obj->tag = CHAR;
	return obj;
}



//bool object
Object* newBool(VirtualMachine* vm, bool data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	(obj->data).boolData = data;
	obj->tag = BOOL;
	return obj;
}



//string object
Object* newString(VirtualMachine* vm, str* data) {
	Object* obj = objectMaker(vm);
	if (obj == NULL) { return NULL; }
	obj->data.stringData = data;
	obj->tag = STR;
	return obj;
}



//Find length of object
int length(Object* obj) {
	if (obj == NULL) { return -1; }
	switch (obj->tag) {
	case INT:
	case FLOAT:
	case DOUBLE:
	case CHAR:
	case BOOL:
	case PTR:
		return 1;
	case STR:
		return obj->data.stringData->len;
	case LST:
		return obj->data.listData->len;
	default:
		return -1;
	}
}

//Work on double cases and more
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Add 2 objects and return a new object
Object* objectAdder(VirtualMachine* vm, Object* A, Object* B) {
	if (A == NULL || B == NULL) { return NULL; }
	ObjectData AD = A->data, BD = B->data;
	DataTag BK = B->tag;
	switch (A->tag) {
	case INT:
		if (BK == INT) { return newInt(vm, AD.intData + BD.intData); }
		else if (BK == FLOAT) { return newFloat(vm, (float)((float)AD.intData + BD.floatData)); }
		else { return NULL; }
	case FLOAT:
		if (BK == INT) { return newFloat(vm, (float)(AD.floatData + (float)BD.intData)); }
		else if (BK == FLOAT) { return newFloat(vm, (float)(AD.floatData + BD.floatData)); }
		else { return NULL; }
	case DOUBLE:
		if (BK == INT) { return newFloat(vm, (float)(AD.floatData + (float)BD.intData)); }
		else if (BK == FLOAT) { return newFloat(vm, (float)(AD.floatData + BD.floatData)); }
		else { return NULL; }
	case CHAR:
		if (BK == INT) { return newFloat(vm, (float)(AD.floatData + (float)BD.intData)); }
		else if (BK == FLOAT) { return newFloat(vm, (float)(AD.floatData + BD.floatData)); }
		else { return NULL; }
	case BOOL:
		if (BK == INT) { return newFloat(vm, (float)(AD.floatData + (float)BD.intData)); }
		else if (BK == FLOAT) { return newFloat(vm, (float)(AD.floatData + BD.floatData)); }
		else { return NULL; }
	case STR:
		if (BK == STR) {
			Object* obj = newString(vm, strAdder(AD.stringData,BD.stringData));
			return obj;
		}
		else { return NULL; }
	case LST:
		if (BK == LST) {
			Object* obj = newList(vm, listAdder(AD.listData, BD.listData));
			return obj;
		}
		else { return NULL; }
	default: return NULL;
	}


}













*/























































#pragma warning(pop)






