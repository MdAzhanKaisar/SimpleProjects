#pragma once
#include "ListFns.h"
#include "StackFns.h"

/*
typedef struct VirtualMachine {
  // stack frames: stack_t frame_t
  Stack *frames;
  // These are the rest of the objects: for example List
  Stack *objects;
} VirtualMachine;

typedef struct StackFrame {
  Stack *references;
} Frame;

VirtualMachine* vm_new();
void vm_free(VirtualMachine* vm);
void vm_track_object(VirtualMachine* vm, Object obj);

Frame* vm_new_frame(VirtualMachine* vm);
void vm_frame_push(VirtualMachine* vm, Frame* frame);
Frame* vm_frame_pop(VirtualMachine* vm);

void frame_free(Frame* frame);














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















