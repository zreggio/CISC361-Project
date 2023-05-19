#include "holdqueue1.hpp"
#include "linkedLIst.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

void HoldQueue1::insertNode(Process *newNode){
    if( head == NULL || newNode->runtime < head->runtime ) {
        newNode->next = head;
        head = newNode;
    } else {
        Process* current = head;
        
        while ( current->next != NULL && current->next->runtime <= newNode=>runtime ) {
            current = current->next;
        }

        newNode->next = current->next;
        currnet->next = newNode;
    }
}

Process* HoldQueue1::ready() {
    if (head == NULL){
        return NULL;
    }

    Process* readyNode = head;
    head = head->next;
    readyNode->next = NULL;

    return readyNode;
}