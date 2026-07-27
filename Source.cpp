#include "StringFns.h"
#include "ListFns.h"
#include "StackFns.h"
#include "ObjectFns.h"
#include "MarkNSweepGC.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This is to test the functions
int main() {
	printf("Begin...\n");

	VirtualMachine* vm = vmMaker();
	Frame* frame = vmNewFrame(vm);
	Object* A = newInt(vm, 12);
	printf("%p\n", vm->objects->data[0]);
	Object* B = newDouble(vm, 4.8);
	printf("%p , %p -> ", A,B);

	frameReferenceObject(frame, B);
	vmCollectGarbage(vm);

	printf("%p", vm->objects->data[0]);

	vmFree(vm);

	printf("\nEnd...");
	return 0;
}