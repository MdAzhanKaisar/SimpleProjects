#pragma once
#include "ListFns.h"
#include "MarkNSweepGC.h"
#include "StringFns.h"

typedef struct Vector3 {
	Object* x;
	Object* y;
	Object* z;
}Vector3;

typedef union ObjectData {
	int intData;
	float floatData;
	double doubleData; 
	char charData;
	bool boolData;
	str* stringData;
	void* pointerData;
	Vector3 vector3Data;
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
Object* newVector3(VirtualMachine* vm, Object* x, Object* y, Object* z);
Object* newList(VirtualMachine* vm, List* data);

int length(Object* obj);
/*
object* add(object* A, object* B);


*/

/*
typedef struct VirtualMachine {
	stack_t* frames;
	stack_t* objects;
} vm_t;

typedef struct StackFrame {
	stack_t* references;
} frame_t;

vm_t* vm_new();
void vm_free(vm_t* vm);

void vm_frame_push(vm_t* vm, frame_t* frame);
frame_t* vm_new_frame(vm_t* vm);

void frame_free(frame_t* frame);
void vm_track_object(vm_t* vm, object* obj);
void frame_reference_object(frame_t* frame, object* obj);
void object_free(object* obj);

void mark(vm_t* vm);
void trace(vm_t* vm);
void trace_blacken_object(stack_t* gray_objects, object* ref);
void trace_mark_object(stack_t* gray_objects, object* ref);
void sweep(vm_t* vm);

void vm_collect_garbage(vm_t* vm);




*/