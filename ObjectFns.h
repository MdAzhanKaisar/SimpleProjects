#pragma once
#include "ListFns.h"

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
	char* stringData;
	void* pointerData;
	Vector3 vector3Data;
	List* listData;
}ObjectData;

typedef struct Object {
	ObjectData data;
	DataTag tag;
	bool is_marked;
}Object;

Object* objectMaker();


/*
object* new_object(vm_t* vm);
object* new_int(int data);
object* new_float(float data);
object* new_string(char* data);
object* new_vector3(object* x, object* y, object* z);
object* new_array(size_t size);


bool array_set(object* obj, size_t index, object* value);
object* array_get(object* obj, size_t index);
int length(object* obj);
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