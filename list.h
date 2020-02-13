//Nicholas Cooke
//2/12/2020
//Notecard App
//
#ifndef _msg_
#define _msg_
/*
 * 1 msg is now card
 * 2 room is now deck
 *
*/

class msg
{
    
    public:
        msg();
        msg(const msg & to_copy);
        msg(const char* d, const char* s);
        ~msg();    
        void display() const;
        msg*& go_next();
        char* get_data() const;
   //     bool operator==(const msg& s) const;

    protected:
        char* data;
        char* source;
        msg* next;    

        void init(const char* data, const char* source);
};
#endif //_msg_


#ifndef _LIST_
#define _LIST_
class list
{    
    public:
        list();
        ~list();
        void push_front(const msg* in);
        void clear(); //make this a bool? 
        void display() const;//NEEDS RECURSION
        msg* search(const char* data) const;
        bool remove(const char* data);
        
    protected:
        msg* head;
        void destroy(msg*& cur); //destroy list
        void display(msg* cur) const;
        msg* search(msg* cur, const char* d) const;
        //returns msg taken out of list
        msg* cut(const char* d);
        msg* cut_body(msg*& cur, const char* d);
};
#endif // LIST

