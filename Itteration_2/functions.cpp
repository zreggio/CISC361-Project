#include "process.hpp"
#include "functions.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Func::Func(){
	splitStr();
	commandManager();
}

string Func::readInput(){
	string input;
	cout << "Please enter a command: ";
	getline(cin, input);
	return input;
}

void Func::splitStr(){
	string s = readInput();
	stringstream ss(s);
	string word;
	int i = 0;
	while (ss >> word) {
	    commandArr[i] = word;
		//cout << commandArr[i] << endl;
		i++;
	}
	cout << endl;
}

void Func::commandManager(){
	while(commandArr[0] != "Exit"){

	if(commandArr[0] == "C"){
		cout << "configure" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;;

		//main mem reader
		string mem;
		cout << "Main Memory: ";
		int i = 2;
		while(commandArr[2][i] != NULL){
			mem = mem + commandArr[2][i];
			i++;
		}
		mainMem = stoi(mem);
		cout << mainMem;
		cout << endl;

		//serial device reader
		string ser;
		cout << "Serial Devices: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			ser = ser + commandArr[3][j];
			j++;
		}
		serialDevices = stoi(ser);
		cout << serialDevices;
		cout << endl;

		//quantum time reader
		string quan;
		cout << "Quantum Time: ";
		int k = 2;
		while(commandArr[4][k] != NULL){
			quan = quan + commandArr[4][k];
			k++;
		}
		quantumTime = stoi(quan);
		cout << quantumTime;
		cout << endl;

		splitStr();
	}
	else if(commandArr[0] == "A"){
		int jNum;
		int mem;
		int dev;
		int rt;
		int prior;

		cout << "Arrival" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;

		//Job number reader
		string jn;
		cout << "Job Number: ";
		int i = 2;
		while(commandArr[2][i] != NULL){

			jn = jn + commandArr[2][i];
			i++;
		}
		jNum = stoi(jn);
		cout << jNum;
		cout << endl;

		//required memory reader
		string mn;
		cout << "Memory Needed: ";
		int j = 2;
		while(commandArr[3][j] != NULL){

			mn = mn + commandArr[3][j];
			j++;
		}
		mem = stoi(mn);
		cout << mem;
		cout << endl;

		//max devices
		string md;
		cout << "Max Devices Held: ";
		int k = 2;
		while(commandArr[4][k] != NULL){

			md = md + commandArr[4][k];
			k++;
		}
		dev = stoi(md);
		cout << dev;
		cout << endl;

		//run time
		string rTime;
		cout << "Time Spent Running: ";
		int l = 2;
		while(commandArr[5][l] != NULL){

			rTime = rTime + commandArr[5][l];
			l++;
		}
		rt = stoi(rTime);
		cout << rt;
		cout << endl;

		//job priority
		string p;
		cout << "Priority: ";
		int m = 2;
		while(commandArr[6][m] != NULL){

			p = p + commandArr[6][m];
			m++;
		}
		prior = stoi(p);
		cout << prior;
		cout << endl;
		
		if(mem > mainMem){
			cout << "Not enough mem";
		}
		else if(mem > availMem && prior == 1){
			//holdQ1
		}
		else if(mem > availMem && prior == 2){
			//holdq2
		}


		splitStr();
	}
	else if(commandArr[0] == "Q"){
		cout << "Device Request" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;

		//Job number reader
		cout << "Job Number: ";
		int i = 2;
		while(commandArr[2][i] != NULL){
			cout << commandArr[2][i];
			i++;
		}
		cout << endl;

		//required memory reader
		cout << "Devices Needed: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			cout << commandArr[3][j];
			j++;
		}
		cout << endl;
		splitStr();
	}
	else if(commandArr[0] == "L"){
		cout << "Release" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;

		//Job number reader
		cout << "Job Number: ";
		int i = 2;
		while(commandArr[2][i] != NULL){
			cout << commandArr[2][i];
			i++;
		}
		cout << endl;

		//required memory reader
		cout << "Devices Released: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			cout << commandArr[3][j];
			j++;
		}
		cout << endl;
		splitStr();
	}
	else if(commandArr[0] == "D"){
		cout << "Display @" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;

		//mem at time t will be printed here
		cout << "Current avail. Main mem: " << mainMem << endl;

		//current # of devices
		cout << "Current Devices: " << endl;

		//jobs displayed -> ID, Arrival time, finish time, turn around time
		cout << "Completed Jobs: " << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Arrival Time]-----[Finish Time]-----[Turnarround Time]" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "" << endl;
		//will print said values from an integer array

		cout << "Hold Queue 1:" << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Run Time]" << endl;
		cout << "" << endl;
		//where we print values

		cout << "Hold Queue 2:" << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Run Time]" << endl;
		cout << "" << endl;
		//where we print values

		cout << "Ready Queue:" << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Run Time]-----[Time Accrued]" << endl;
		cout << "" << endl;

		cout << "Process Running on CPU:" << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Time Accrued]-----[Time Left]" << endl;
		cout << "" << endl;

		cout << "Wait Queue:" << endl;
		cout << "---------------------------------------" << endl;
		cout << "[Job ID]-----[Run Time]-----[Time Accrued]" << endl;
		cout << "" << endl;

		//print system turnaround time
		cout << "System Turnaround Time: " << endl;

		cout << "" << endl;
		splitStr();
	}
	}
}


