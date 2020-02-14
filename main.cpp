//Nicholas Cooke, 2/12/2020
//main interface for notecards
//


#include "myutil.h"
#include "list.h"

using namespace std;

void card_switch(card* cur, bool side); 
void pause();
void study(deck* my_deck);

int main() {
    deck* test = new deck;    
    card b("Front", "Back");
    card* a = &b;
    test->add(a);
    
    card_switch(a, true);
    /*
    test->add(a);
    test->add(a);
    test->add(a);
    test->display();
    //test->clear(); 
    test->display();
    */
    delete test;
}



//wait for user input and continue tp next page after
void pause()
{
    cin.ignore();
    system("./clear.sh");
}

//retrieves and proceeses user options on a card
void card_switch(card* cur, bool side)
{
    //side = 0: were on the front, side = 1: were on the back
    char in; 
    bool flag = true;

    while (flag)
    {
        cout << "[f] flip card, [e] edit,   [s] next card, [h] hide ,"
                " [q] quite deck\n";
        //display side of card
        side?cur->show_front():cur->show_back();
        cin >> in;
        switch (in)
        {
            case 'f': in = '0';
                //flip the card;l
                side = !side;
                break;
            case 'e': in = '0';
                 //edit whatever side of the card we are on
                 break;
            case 's': in = '0';
                 //go to next card. side = true;
                 break;
            case 'h': in = '0';
                  //set show = false 
                  break;
            case 'q': in = '0';
                  //leave current study run
                  flag = false;
                  break;
            defualt: in = '0';
                  cout << "Sorry, I didn't catch that.";
                  break;
        }
        pause();
    }
    //swith. e = edit whatever page we are on. n flip. s = next card. q = quit run. h = hide 
}


