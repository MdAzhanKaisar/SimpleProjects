#include "MarkNSweepGC.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(push)
#pragma warning(disable : 4703)
 

//create new VirtualMachine
VirtualMachine* vmMaker() {
	VirtualMachine* vm = (VirtualMachine*)calloc(1, sizeof(VirtualMachine));
	if (vm == NULL) { return NULL; }

	vm->frames = stackMaker();
	if (vm->frames == NULL) { free(vm); return NULL; }
	
	vm->objects = stackMaker();
	if (vm->objects == NULL) { stackFree(vm->frames); free(vm); return NULL; }

	return vm;
}



//free the virtual machine
void vmFree(VirtualMachine* vm) {
	if (vm == NULL) { return; }
	while (vm->frames->count != 0) {
		frameFree((Frame*)pop(vm->frames));
	}
	stackFree(vm->frames);
	while (vm->objects->count != 0) {
		objectFree((Object*)pop(vm->objects));
	}
	stackFree(vm->objects);
	free(vm);
}



//free the frame
void frameFree(Frame* frame) {
	if (frame == NULL) { return; }
	stackFree(frame->references);
	free(frame);
}



//Tracks objects inside virtual machine
void vmTrackObject(VirtualMachine* vm, Object* obj) {
	push(vm->objects, obj);
}



//Create a frame
Frame* vmNewFrame(VirtualMachine* vm) {
	Frame* frame = (Frame*)calloc(1, sizeof(Frame));
	if (frame == NULL) { return NULL; }
	frame->references = stackMaker();
	if (frame->references == NULL) { free(frame); return NULL; }
	push(vm->frames, frame);
	return frame;
}



//reference the object into the frame
void frameReferenceObject(Frame* frame, Object* obj) {
	push(frame->references, obj);
}



// Marks all objects referenced in the frame
void vmFrameMark(VirtualMachine* vm) {
	if (vm == NULL) { return; }
	Frame* frame;
	Object* obj;
	for (int i = 0; i < vm->frames->count;i++) {
		frame = (Frame*)vm->frames->data[i];
		for (int j = 0; j < frame->references->count;j++) {
			obj = (Object*)frame->references->data[j];
			obj->is_marked = true;
		}

	}
}



//Mark objects and push into the stack
void traceMarkObject(Stack* gray_objects, Object* ref) {
	if (ref == NULL || ref->is_marked == true || gray_objects == NULL) { return; }
	ref->is_marked = true;
	push(gray_objects, ref);
}



//Mark objects referenced by the given object and push the reference back into the stack
void traceBlackenObject(Stack* gray_objects, Object* ref) {
	if (gray_objects == NULL || ref == NULL) { return; }
	switch (ref->tag) {
	case LST:
		int index = listFind(ref->data.listData);
		while (index != -1) {
			Object* obj = *((Object**)listGet(ref->data.listData, index));
			traceMarkObject(gray_objects, obj);
			index = listFind(ref->data.listData, NULL, OBJ, index + 1);
		}
	}
}



//Main trace function
void trace(VirtualMachine* vm) {
	if (vm == NULL) { return; }

	Stack* gray_object = stackMaker();
	Object* obj;
	//Add all marked objects into te stack gray_objects
	for (int i = 0; i < vm->objects->count;i++) {
		obj = (Object*) vm->objects->data[i];
		if (obj->is_marked) { push(gray_object, obj); }
	}
	//reference all objects referenced by a marked object and so on
	while (gray_object->count != 0) {
		traceBlackenObject(gray_object, (Object*)pop(gray_object));
	}
	stackFree(gray_object);
}



//free all unmarked objects after tracing
void sweep(VirtualMachine* vm) {
	if (vm == NULL) { return; }
	Object* obj;
	for (int i = 0; i < vm->objects->count;i++) {
		obj = (Object*)vm->objects->data[i];
		if (obj->is_marked == false) { 
			objectFree(obj);
			vm->objects->data[i] = NULL; 
		}
		else { obj->is_marked = false; }
	}
	stackFreeNulls(vm->objects);
}



//Main garbage collector function
void vmCollectGarbage(VirtualMachine* vm) {
	vmFrameMark(vm);
	trace(vm);
	sweep(vm);
}




#pragma warning(pop)