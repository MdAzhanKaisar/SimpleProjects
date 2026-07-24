#pragma once

typedef struct Stack {
	void** data;
	int count;
	int capacity;
}Stack;


Stack* stackMaker();
void stackFree(Stack* stk);
bool push(Stack* stk, void* data);
void* pop(Stack* stk);
bool stackFreeNulls(Stack* stk);




