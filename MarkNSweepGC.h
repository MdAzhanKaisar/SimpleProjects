#pragma once
//#include "ListFns.h"
#include "StackFns.h"
#include "ObjectFns.h"
//#include "StringFns.h"

typedef struct Object Object;



typedef struct VirtualMachine {
  Stack* frames;
  Stack* objects;
} VirtualMachine;

typedef struct StackFrame {
  Stack *references;
} Frame;

VirtualMachine* vmMaker();
void vmFree(VirtualMachine* vm);

Frame* vmNewFrame(VirtualMachine* vm);
void frameFree(Frame* frame);

void vmTrackObject(VirtualMachine* vm, Object* obj);
void frameReferenceObject(Frame* frame, Object* obj);

void vmFrameMark(VirtualMachine* vm);

void traceMarkObject(Stack* gray_objects, Object* ref);
void traceBlackenObject(Stack* gray_objects, Object* ref);
void trace(VirtualMachine* vm);


void sweep(VirtualMachine* vm);

void vmCollectGarbage(VirtualMachine* vm);








/*










*/



















/*
/// Our main functions for garbage collection.
void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);

void vm_collect_garbage(vm_t *vm);

/// Helper functions for `trace`
void trace_blacken_object(stack_t *gray_objects, snek_object_t *ref);
void trace_mark_object(stack_t *gray_objects, snek_object_t *ref);

/// This is the function that gets called to actually do the garbage collection,
/// but is just composed of `mark`, `trace`, and `sweep`.
///
/// Don't worry, it's not going to delete your code (hopefully!)

void vm_collect_garbage(vm_t *vm);

/// Already implemented

// Marks the object as referenced in the current stack frame.
void frame_reference_object(frame_t *frame, snek_object_t *obj);
*/















