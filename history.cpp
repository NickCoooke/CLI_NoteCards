#include "history.h"
#include "myutil.h"

history::history():size(0), tail(NULL)
{
}

history::~history()
{
    destroy(head);
    head = NULL;
    tail = NULL;
}

void history::add(msg* n)
{
    msg*  n_msg = new msg(*n);
    n_msg->go_next() = NULL;
   
//    tail == NULL ? head = tail = n_msg: tail->go_next() = n_msg; 
    if (!tail)
    {
        head = tail = n_msg;
    }
    else
    {
        tail->go_next() = n_msg;
    }
    n_msg->go_next() = head;
    head = n_msg;
}

void history::display() const
{
    if (head == NULL)
        return;
    
    display(head, tail);
}


void history::display(msg* cur, const msg* tail) const
{
    if(cur == NULL || cur == tail)
        return;
        
    cur->display();
    display(cur->go_next(), tail);
}

void history::read()
{
    char input[MAX_CHAR];
    //int rating, index;
    char n = 0;
    bool flag = true;

    while(flag == true) 
    {
        cout << "History Menu\n" 
            << "[1] View history\n"
            << "[2] Remove\n"
            << "[3] Clear\n"
            << "[z] Back\n";
        cin >> n;
        cin.ignore();

        system("./clear.sh");
        switch (n) 
        {
            case '1': n ='0';
                      display();
                      break;
            case '2': n = '0';
                      cout << "Enter log you wish to remove. \n";
                      cin.getline(input, MAX_CHAR, '\n');
                      if (!(remove(input)))
                      {
                          cout << "Log not found.";
                          cin.ignore(); 
                      }
                      break;
            case '3': n = '0';
                      cout << "Empty...\n";
                      //my_user->print_mail(); 
                      break;	
            case 'z': n = '0';
                      flag = false;
                      break;
            default: n = '0';
                     cout << "I'm sorry, I didn't catch that. Please try again... \n";
                     break; 
        }//_switch
        clear();
    }//_while
} //menu






