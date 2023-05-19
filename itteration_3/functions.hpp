
#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Func{
	string input;
	int time;
	int mainMem;
	int availMem = 5;
	int serialDevices;
	int quantumTime;
	string commandArr[8];

public:
	Func();
	string readInput();
	void splitStr();
	void commandManager();
};

#endif /* FUNCTIONS_HPP_ */
