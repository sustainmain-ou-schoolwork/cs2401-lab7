/*************************************************************************
    This is the main for the Lab 7 Assignment of CS2401. You will need 
to implement the rearview function which should display the list 
backwards. Also, there are problems in the code which you will need to 
diagnose using gdb.
Finally you will also need to write and test the copy constructor for 
this class.
    John Dolan	School of EECS Ohio University, Athens Ohio  Spring 2018
    Patricia Lindner    October 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include "llist.h"
using namespace std;

int main(){

    int n;
    LList somenums;
    for(int i = 0; i < 35; ++i)
    {
        n = rand() % 700 + 1;
	    somenums.add_item(n);
    }

    // Once you have written the rear-view this should let you
    // see the list frontwards and backwards.
    cout << "Front View:\n";
    somenums.frontview();
    cout << "\nRear View:\n";
    somenums.rearview();
    cout << endl;



    LList numcopy(somenums);  // call to the copy constructor
    cout << "Copied List Front View:\n";
    numcopy.frontview();
    cout << "\nCopied List Rear View:\n";
    numcopy.rearview();
    cout << endl;

    // Checking the original list
    cout << "Original List Front View:\n";
    somenums.frontview();
    cout << "\nOriginal List Rear View:\n";
    somenums.rearview();
    cout << endl;
    
    return 0;
}