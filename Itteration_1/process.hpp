#ifndef PROCESSHPP
#define PROCESSHPP

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class Process {
public:
    int time;
    int memory;
    int serial_device;
    int quantum;
    int jobNumber;
    int runtime;
    int priority;
    int numDevices;
    Process* next;

    Process(){
        time = 0;
        memory = 0;
        serial_device = 0;
        quantum = 0;
        jobNumber = 0;
        runtime = 0;
        priority = 0;
        numDevices = 0;
        next = NULL;
    }
    Process(int t){
        this->time = t;
    }
    Process(int t, int mem, int serial, int q, int j, int r, int p, int d){
        this->time = t;
        this->memory = mem;
        this->serial_device = serial;
        this->quantum = q;
        this->jobNumber = j;
        this->runtime = r;
        this->priority = p;
        this->numDevices = d;
        this->next = NULL;
    }
};
class holdQueue1{
    Process* head;
};
class holdQueue2{
    Process* head;
    
    public:
        void insertNode(int);
};
class waitQueue{
    Process* head;
};
class readyQueue{
    Process* head;
};
#endif /* PROCESSHPP */