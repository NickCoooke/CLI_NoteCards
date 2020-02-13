//stack.h

/*
Stack class is the second ADT. Stack is a stack which holds information of recent
visitors, class People,  of the restorant that signed up for promotional data. 
After initial contact from the user Stack writes the information into a file, 
"proj2output.txt" for future use. Stack is implemented with a dynamicly allocated
array and an contains automatic up sizing features as well and stack essentials 
like push, pop, and peek. 
 */

#ifndef STACK_H
#define STACK_H
#include "person.h"

class Stack
{
public:
	Stack();
	Stack(const int depth);
	~Stack();


	void push(const char* name, const char* email);
	bool pop(char* name, char* email);
	bool peek(char* name, char* email) const;
	int size() const;
	void printFile() const;
	void print() const;
private:
	Person ** aStack;
	int top;
	const int INIT_CAP = 10;
	const int GROWTH_FACTOR = 2;
	int currCapacity;
	void growStack();
};

#endif
