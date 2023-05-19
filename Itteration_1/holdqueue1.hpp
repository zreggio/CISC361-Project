#ifndef HOLDQUEUE1_HPP_
#define HOLDQUEUE1_HPP_

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


class HoldQueue1 {
private: 
    Process* head;

public:
    void insertNode(Process *newNode);
    Process* ready();
};

#endif /* HOLDQUEUE1_HPP_ */