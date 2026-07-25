#include "StackFns.h"
#include <stdio.h>
#include <stdlib.h>

//Create an empty stack with capacity of 10 elements.
Stack* stackMaker() {
	//Heap alloc
	Stack* stk = (Stack*)calloc(1, sizeof(Stack));
	if (stk == NULL) { return NULL; }
	stk->data = (void**)calloc(10, sizeof(void*));
	if (stk->data == NULL) { free(stk); return NULL; }
	//variables initialization
	stk->capacity = 10;
	stk->count = 0;
	return stk;
}



//Free a stack
void stackFree(Stack* stk) {
	if (stk == NULL) { return; }
	if (stk->data != NULL) { free(stk->data); }
	free(stk);
}



//Push an element into the stack.
bool push(Stack* stk, void* data) {
	if (stk == NULL) { return NULL; }
	//When resize is needed
	if (stk->count == stk->capacity) {
		stk->capacity += 10;
		stk->data = (void**)realloc(stk->data, sizeof(void*) * stk->capacity);
		if (stk->data == NULL) { stackFree(stk); return false; }
	}
	//Push and increase count
	stk->data[stk->count++] = data;
}



//Pop an element from the stack.
void* pop(Stack* stk) {
	if (stk == NULL) { return NULL; }
	//Storing data temporarily
	void* data = stk->data[stk->count];
	//Pop and decrease count
	stk->data[stk->count--] = NULL;
	return data;
}



//Remove all the NULL elements from a stack
bool stackFreeNulls(Stack* stk) {
	if (stk == NULL or stk->count == 0) { return false; }
	//temporary alloc
	void** data = (void**)calloc(stk->count,sizeof(void*));
	if (data == NULL) { return false; }
	int c = 0;
	//storing all values excluding NULLs
	for (int i = 0; i < stk->count;i++) {
		if (stk->data[i] != NULL) {
			data[c++] = stk->data[i];
		}
	}
	//restoring all stored values
	for (int i = 0;i < c;i++) {
		stk->data[i] = data[i];
	}
	stk->count = c;
	free(data);
	return true;
}





