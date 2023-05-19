//Main controller

#include "process.hpp"
#include "functions.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//“C” - configuration
//“A” - job arrival
//“Q” - device request
//“L” - device release
//“D” - display


int main() {
	Linkedlist list;

	    // Inserting nodes
	list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    cout << "Elements of the list are: ";

	    // Print the list
    list.printList();
    cout << endl;
	Func();
    return 0;

}



