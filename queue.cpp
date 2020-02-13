#include "queue.h"
#include <fstream>

Queue::Queue(): front(nullptr), end(nullptr), size(0){
}
Queue::Queue(const char* masterfile): front(nullptr), end(nullptr), size(0) {
	//read in from file. enque each element
	if(readfile(masterfile))
		cout << masterfile << " read in success\n";
}

Queue::~Queue(){
	destroy(front);
	front = nullptr;
	end = nullptr;
}

void Queue::destroy(Node *& curh) { //good
	if (curh){
		destroy(curh->next);
		delete curh->data;
		delete curh;
	}	
}

void Queue::enqueue(const char* name, const char* notes, const bool promo, const int number){
	Party* aParty = new Party(name, notes, promo, number);
	Node * newNode = new Node(aParty);
	if (!end){
		front = end = newNode;
	}
	else{
		end->next = newNode;
		end = newNode;
	}
	size++;
}

bool Queue::peek(char* name) const
{
	if (size == 0)
		return false;
	strcpy(name, front->data->getName());	
	return true;
}

bool Queue::dequeue(char* name, char* note, bool& promo, int& number){
	if (size == 0)
		return false;
	Node * temp = front;
	front = front->next;

	//set passing variables

	//copy content of name into new location to pass out
	strcpy(name, temp->data->getName());
	strcpy(note, temp->data->getNote());
	promo = temp->data->getPromo();
	number = temp->data->getNumber();
	
	//aParty = *(temp->data);
	delete temp->data;
	delete temp;
	size--;
	return true;
}

void Queue::print() const{
	for (Node * curr = front; curr; curr = curr->next){
		cout <<  "\n"  << curr->data->getName() << "\nNotes: " << curr->data->getNote()
			 << "\nParty of " << curr->data->getNumber() << endl;
	}
}

int Queue::getSize() const{
	return size;
}

bool Queue::readfile(const char* masterfile) {
    ifstream in;
    in.open(masterfile);
    if (!in)
        return false; // checks if file is open.
    //now we read into our class....
    char name[MAX_CHAR];
    char note[MAX_CHAR];
    bool promo;
	int number;
	in.get(name, MAX_CHAR, ';');
    while (!in.eof()) {
		in.get();
        in.get(note, MAX_CHAR, ';');
        in.get();
        in >> promo;
		in.get();
		in >> number;
		in.ignore(MAX_CHAR, '\n'); //moves to new line
        
		enqueue(name, note, promo, number);
		in.get(name, MAX_CHAR, ';');
        }
    in.close();
    return true;
}


