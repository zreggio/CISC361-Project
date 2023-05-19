#include "process.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

void holdQueue2::insertNode(int time)
{
    // Create the new Node.
    Process* newProcess = new Process(time);

    // Assign to head
    if (head == NULL) {
        head = newProcess;
        return;
    }

    // Traverse till end of list
    Process* temp = head;
    while (temp->next != NULL) {
        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newProcess;
}