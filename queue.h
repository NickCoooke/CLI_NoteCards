//queue.h

/*
 * Barebones Circularly linked list Queue class
 *  contians file initilization function
 *  
 *
 * needs copy constructor 
*/

#ifndef QUEUE_H
#define QUEUE_H
//#include "party.h" //this is for whatever object you are storing
class Queue {
public:
	Queue();
	Queue(const char* masterfile);
    Queue(const Queue& to_copy);
	~Queue();
	
	void enqueue(const char* name, const char* notes, const bool promo, const int number);
        //do this with object pointers
	bool dequeue(char* name, char* notes, bool& promo, int& number);
        //and this
	bool peek(char* name) const; // Mostly a pointless function
	int getSize() const;
	void print() const; //change to display

private:
    //change this to exist in the object class
	struct Node	{
		Node(Party* s)	{// equating pointers. should work without overload? 
			data = s;
			next = nullptr;
		}
		Party * data;
		Node * next;
	};
	Node * front, *end;
	int size;
	bool readfile(const char* masterfile);
	void destroy(Node *& curh);
};
#endif
