#include "MarkNSweepGC.h"
#include <stdio.h>
#include <stdlib.h>

 

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






