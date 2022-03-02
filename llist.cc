/************************************************************************
    This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
    John Dolan    Ohio University    Spring 2018
************************************************************************/
#include <iostream>
#include <iomanip>
#include "llist.h"
using namespace std;

// node constructor
node::node(int d, node *p, node *n) {
    data_field = d;
    nextptr = n;
    previousptr = p;
}

// Llist functions
LList::LList() {
    head = tail = NULL;
    nodecount = 0;
}

LList::~LList() {
    node *rmptr;
    while (head != NULL) {
        rmptr = head;
        head = head -> next();
        delete rmptr;
    }
}

LList::LList(const LList& other) {
    // remember, using the add_item function won't work correctly because of the special case for items divisible by 5

    nodecount = other.nodecount;

    if (other.head == NULL) {
        head = tail = NULL;
        return;
    }

    // copy first node
    node* cursor = other.head;
    head = tail = new node(cursor -> data());

    // copy the rest of the nodes
    while (cursor -> next() != NULL) {
        cursor = cursor -> next();
        tail -> set_next(new node(cursor -> data(), tail));

        tail = tail -> next();
    }
}


void LList::frontview() const {
    node *cursor = head;
    while (cursor != NULL) {
        cout << left << setw(5) << cursor -> data();
        cursor = cursor -> next();
    }
    cout << flush;
}

// The student is required to write the implementation of this function
void LList::rearview() const {
    node *cursor = tail;
    while (cursor != NULL) {
        cout << left << setw(5) << cursor -> data();
        cursor = cursor -> previous();
    }
    cout << flush;
}

void LList::add_item(int item) {
    if (head == NULL) {
        head = tail = new node(item);
        nodecount++;
    }
    else if (item % 5 == 0 && nodecount > 3) {
        int i = 0;
        node *cursor = head;
        while (i < nodecount / 2) {
            cursor = cursor -> next();
            i++;
        }
        cursor -> previous() -> set_next(new node(item, cursor -> previous(), cursor));
        cursor -> set_previous(cursor -> previous() -> next());
        nodecount++;
    }
    else {
        tail -> set_next(new node(item, tail));
        tail = tail -> next();
        nodecount++;
    }
}