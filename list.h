//Nicholas Cooke
//2/12/2020
//Notecard App
//


#ifndef _card_
#define _card_

class card
{
    
    public:
        card();
        card(const card & to_copy);
        card(const char* front, const char* back, const char* thoughts = " ");
        ~card();    
        void display() const;
        card*& go_next();
        //bool operator==(const card& s) const;
        char* get_front() const;
        
        void show_front() const;
        void show_back() const;
        void edit_front(const char* n_front);
        void edit_back( const char* n_back);
        void edit_thoughts(const char* n_thot);

    protected:
        char* front;
        char* back;
        char* thoughts; 
        bool show; //true = card displays, false = card doesnt
        card* next;    
        void init(const char* front, const char* back, const char* thoughts);
};
#endif //_card_


#ifndef _LIST_
#define _LIST_
class list
{    
    public:
        list();
        //list(const char* storage)
        ~list();
        void add(const card* in);
        void clear(); //make this a bool? 
        void display() const;//NEEDS RECURSION
        card* search(const char* data) const;
        bool remove(const char* data);
        card* cut(const char* d);
        
    protected:
        card* head;
        void destroy(card*& cur); //destroy list
        void display(card* cur) const;
        card* search(card* cur, const char* d) const;
        //returns card taken out of list
        card* cut_body(card*& cur, const char* d);
};
#endif // LIST

#ifndef _deck_
#define _deck_
class deck: public list
{
    public: 
        deck();
        deck(const char* file);//file input for a deck
        //deck(const deck& to_copy);
        ~deck();
        void add(card* n);
        void display() const;
        void reset(); //resets all cards to show        

    protected: 
        char* name;
        int size;
        card* tail;
        void display(card* cur, const card* tail) const;
        void in_card();     //display front, pause, flip, pause
        void destroy(card* cur, const card* tail);


};
#endif //deck
 
/*
 * future dev: 
 *  -record number of passes and get user input for successful pass and failing pass
 *  -rank cards by their pass/fail stats
 *
 *  -set up some prompt for user input to test
 */
