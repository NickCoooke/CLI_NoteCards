#include "list.h"
#include "myutil.h"

card::card():front(NULL), back(NULL), thoughts(NULL), next(NULL), show(true)
{}



card::card(const card& copy)
{
    show = true;
    init(copy.front, copy.back, copy.thoughts); 
}



card::card(const char* d, const char* s, const char* t)
{
    show = true;
    init(d, s, t);
}



card::~card()
{
    if (front) 
    {
        delete[] front;
        front = NULL;
    }
    if (back) 
    {
        delete[] back;
        back = NULL;
    }
    if (thoughts) 
    {
        delete[] thoughts;
        thoughts = NULL;
    }
    show = false;
    next = NULL;
}



void card::display() const
{
    if (this == NULL) return;
    cout<< back << ":\t" << front << "\"\n";
}



card*& card::go_next()
{
    return next;
}



void card::show_front() const 
{
    cout << front;
}



void card::show_back() const  
{
    cout << back << "\n\n\n\n\n\n\n" << thoughts;
}



void card::edit_front(const char* n_front)
{
    char* n = new char[strlen(n_front)+1];
    strcmp(n, n_front);
    delete[] front;
    front = n;
}



void card::edit_back(const char* n_back)
{

    char* n = new char[strlen(n_back)+1];
    strcmp(n, n_back);
    delete[] back;
    back = n;
}



void card::edit_thoughts(const char* thot)
{
   
    char* n = new char[strlen(thot)+1];
    strcmp(n, thot);
    delete[] thoughts;
    thoughts = n;
}



char* card::get_front() const
{
    return front;
}



void card::init(const char* d, const char* s, const char* t)
{
    front = new char[strlen(d)+1];
    strcpy(front, d);
    back = new char[strlen(s)+1];
    strcpy(back, s);
    thoughts = new char[strlen(t)+1];
    strcpy(thoughts, t);

}


/*
bool card::operator==(const card& s) const 
 {
    //strcmp(front, s.get_front()) == 0? return true: return false;
    if(strcmp(front, s.get_front()) == 0) 
        return true;
    return false;
}
*/
////////////////////////LIST///////////////////////////////



list::list(): head(NULL)
{}



list::~list()
{
    if (head)
    {
        destroy(head);
        head = NULL;

    }
}



//inserts element at the front of list
void list::add(const card* in) {//in = "new kidk

    card* dk = new card(*in);   
    head?dk->go_next() = head: dk->go_next() = NULL;
    head = dk;

}



//publci member that clears contents of list
void list::clear()
{
    destroy(head);
    head = NULL;
}



//public member that displays list
void list::display() const
{
    display(head);    
}



//public member function for searching list
card* list::search(const char* d) const
{
    return search(head, d);
}



//public member function that searches via card.front and deletes the match
bool list::remove(const char* d)
{
    card* holder = cut(d);
    if(!holder)
    {
        delete holder;
        return false;
    }
    delete holder;
    return true;
}



//recursive helper function that displays list
void list::display(card* cur) const
{
    if(cur != NULL) 
    {
        display(cur->go_next());
        cur->display(); 
    }
}



//destroys list recursively
void list::destroy(card*& cur)
{
     
    if (cur) 
    {
        destroy(cur->go_next());
        delete cur;
    }
}



//recursive helper that searches list for a card whose front matches d
card* list::search(card* cur, const char* d) const
{   
    if (cur)
    {
        if (strcmp(d, cur->get_front()) == 0)
        {
            return cur; 
        }  
        return search(cur->go_next(), d);
    }
    return NULL; 
}



//searches begining of list for message. calls cut_body to search body for card, cuts and returns
card* list::cut(const char* d)
{
    if (strcmp(head->get_front(), d) == 0)
    {
        card* temp = head;
        head = head->go_next();
        return temp;
    }
    else
       return cut_body(head, d);
}



//recursively searches body for card to remove from list. returns said card
card* list::cut_body(card*& cur, const char* d)
{
    if (cur == NULL) 
        return NULL;
    if (strcmp (cur->go_next()->get_front(), d) == 0)
    {
        card* ret = cur->go_next();
        cur->go_next() = cur->go_next()->go_next();
        return ret; 
    }
    
    else 
        return cut_body(cur->go_next(), d); 
}



//////////////////////////////////////////////////////////////////////////////////////////

deck::deck():size(0), tail(NULL), name(NULL)
{
}



deck::deck(const char* file)
{

}



deck::~deck()
{
    destroy(head, tail);
    head = NULL;
    tail = NULL;
}


void deck::destroy(card* cur, const card* tail)
{
    if (cur && cur != tail) 
    {
        destroy(cur->go_next(), tail);
        delete cur;
    }
}



void deck::add(card* n)
{
    card*  n_card = new card(*n);
    n_card->go_next() = NULL;
    
    (!tail)? head = tail = n_card: tail->go_next() = n_card;

    n_card->go_next() = head;
    head = n_card;
}



void deck::display() const
{
    if (head == NULL)
        return;

    display(head, tail);
}



//displays front of each card
void deck::display(card* cur, const card* tail) const
{
    if(cur == NULL || cur == tail)
        return;

    cur->display();
    display(cur->go_next(), tail);
}



