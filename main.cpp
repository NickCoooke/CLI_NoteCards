//Nicholas Cooke, 2/12/2020
//main interface for notecards
//


#include <iostream>
#include "list.h"

using namespace std;

int main() {
    list test;    
    msg* a = new msg("Hey", "There");
    test.push_front(a);
    test.display();
   
}
