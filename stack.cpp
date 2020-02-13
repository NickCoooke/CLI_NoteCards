//stack.cpp
#include "stack.h"
#include <fstream>

Stack::Stack(){
	currCapacity = INIT_CAP;
	aStack = new Person*[currCapacity];
	top = 0;
}

Stack::Stack(const int depth){
	currCapacity = depth;
	aStack = new Person*[currCapacity];
	top = 0;
	
}

Stack::~Stack(){
	for(int i = 0; i < top; i++){ 
		delete aStack[i];
	}
	delete[] aStack;
}

void Stack::push(const char* name, const char* email){
	Person* aPerson = new Person(name, email);
	if (top == currCapacity){
		growStack();
	}
	aStack[top] = aPerson;
	top++;
}

void Stack::growStack(){
	currCapacity *= GROWTH_FACTOR;
	Person ** tempStack = new Person*[currCapacity];
	for (int i = 0; i < top; i++){
		tempStack[i] = aStack[i];
	}
	delete[] aStack;
	aStack = tempStack;
	tempStack = nullptr;
}

bool Stack::pop(char* name, char* email){
	if (top != 0){

		if((aStack[top-1])->writefile()) 
		//	cout << "File Write success.\n";
		strcpy(name, (aStack[top - 1])->getName()); 					
		strcpy(email, (aStack[top - 1])->getEmail()); 					
		
		delete aStack[top - 1];
		top--;

		return true;
	}
	return false;
}

bool Stack::peek(char * name, char * email) const {
	if (top != 0){
		strcpy(name, aStack[top-1]->getName());
		strcpy(email, aStack[top-1]->getEmail());
		return true;
	}
	return false;
}

int Stack::size() const {
	return top;
}
void Stack::printFile() const {
	const char* file = "proj2output.txt"; //CONSESSSION! file should be linked to OUT_FILE in person
	ifstream in;
	in.open(file);
	cout << "\nPromotional data storage file contents: \n";
	if(in.is_open()) 
		cout << in.rdbuf();
    in.close();
}

void Stack::print() const{
	for (int i = 0; i < top; i++)	{
		cout << aStack[i]->getName() << "\t" << aStack[i]->getEmail() << endl;
	}
}
