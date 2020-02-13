#include "list.h"
#include "myutil.h"

msg::msg():data(NULL), source(NULL), next(NULL)
{}

msg::msg(const msg& copy)
{
    init(copy.data, copy.source); 
}

msg::msg(const char* d, const char* s)
{
    init(d, s);

}

msg::~msg()
{
    if (data) 
    {
        delete[] data;
        data = NULL;
    }
    if (source) 
    {
        delete[] source;
        source = NULL;
    }
}

void msg::display() const
{
    if (this == NULL) return;
    cout<< source << ":\t" << data << "\"\n";
}

msg*& msg::go_next()
{
    return next;
}

char* msg::get_data() const
{
    return data;
}

void msg::init(const char* d, const char* s)
{

    data = new char[strlen(d)+1];
    strcpy(data, d);
    source = new char[strlen(s)+1];
    strcpy(source, s);
}

/*bool msg::operator==(const msg& s) const 
 {
    //strcmp(data, s.get_data()) == 0? return true: return false;
    if(strcmp(data, s.get_data()) == 0) 
        return true;
    return false;
}*/
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
void list::push_front(const msg* in) {//in = "new kidk

    msg* dk = new msg(*in);   
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
msg* list::search(const char* d) const
{
    return search(head, d);
}


//public member function that searches via msg.data and deletes the match
bool list::remove(const char* d)
{
    msg* holder = cut(d);
    if(!holder)
    {
        delete holder;
        return false;
    }
    delete holder;
    return true;
}


//recursive helper function that displays list
void list::display(msg* cur) const
{
    if(cur != NULL) 
    {
        display(cur->go_next());
        cur->display(); 
    }
}


//destroys list recursively
void list::destroy(msg*& cur)
{
     
    if (cur) 
    {
        destroy(cur->go_next());
        delete cur;
    }
}


//recursive helper that searches list for a msg whose data matches d
msg* list::search(msg* cur, const char* d) const
{   
    if (cur)
    {
        if (strcmp(d, cur->get_data()) == 0)
        {
            return cur; 
        }  
        return search(cur->go_next(), d);
    }
    return NULL; 
}



//searches begining of list for message. calls cut_body to search body for msg, cuts and returns
msg* list::cut(const char* d)
{
    if (strcmp(head->get_data(), d) == 0)
    {
        msg* temp = head;
        head = head->go_next();
        return temp;
    }
    else
       return cut_body(head, d);
}


//recursively searches body for msg to remove from list. returns said msg
msg* list::cut_body(msg*& cur, const char* d)
{
    //ok. 1. remove the head. going to need to reach into this and reset head
    //2. remove a body: reset previous pointer. 
    if (cur == NULL) 
        return NULL;
    if (strcmp (cur->go_next()->get_data(), d) == 0)
    {
        msg* ret = cur->go_next();
        cur->go_next() = cur->go_next()->go_next();
        return ret; 
    }
    
    else 
        return cut_body(cur->go_next(), d); 
}




