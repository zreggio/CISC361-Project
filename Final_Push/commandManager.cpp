#include "commandManager.hpp"
#include "processHandler.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int mainMem;
int availMem;
int availDev;
int serialDevices;
int quantumTime;
int time;
int devsHeld = 0;
int t[20];
int tLen;


holdQueue1 hold1;
holdQueue2 hold2;
readyQueue rQueue;
waitQueue wQueue;
finished finishedJobs;

Func::Func(){
	splitStr();
	commandManager();
}

string Func::readInput(){
	string input;
	cout << endl;
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
		//cout << "configure" << endl;
		time = stoi(commandArr[1]);
		t[0] = 1;
		tLen = 1;

		//cout << "Time: " << time << endl;;

		//main mem reader
		string mem;
		//cout << "Main Memory: ";
		int i = 2;
		while(commandArr[2][i] != NULL){
			mem = mem + commandArr[2][i];
			i++;
		}
		mainMem = stoi(mem);
		//cout << mainMem;
		//cout << endl;

		//serial device reader
		string ser;
		//cout << "Serial Devices: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			ser = ser + commandArr[3][j];
			j++;
		}
		serialDevices = stoi(ser);
		//cout << serialDevices;
		availDev = serialDevices;
		//cout << endl;

		//quantum time reader
		string quan;
		//cout << "Quantum Time: ";
		int k = 2;
		while(commandArr[4][k] != NULL){
			quan = quan + commandArr[4][k];
			k++;
		}
		quantumTime = stoi(quan);
		//cout << quantumTime;
		//cout << endl;
		availMem = mainMem;

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

		t[tLen] = time;
		tLen++;
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
		cout << endl;
		cout << "The job was not processed -> not enough memory in system";
		cout << endl;
		}
		else if(mem < mainMem && prior == 1 && mem > availMem){
			hold1.insertNode(jNum,mem,dev,rt,prior, quantumTime,0);
		}
		else if(mem < mainMem && prior == 2 && mem > availMem){
			hold2.insertNode(jNum,mem,dev,rt,prior,quantumTime,0);
			//hold2.printList();
		}
		else if(mem < availMem){
			rQueue.insertNode(jNum,mem,dev,rt,prior,quantumTime,0);
		}


		splitStr();
	}
	else if(commandArr[0] == "Q"){
		int devR;
		cout << "Device Request" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;
		t[tLen] = time;
		tLen++;

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
		devR = stoi(commandArr[3]);


		splitStr();
	}
	else if(commandArr[0] == "L"){
		cout << "Release" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;
		t[tLen] = time;
		tLen++;

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
		//cout << "Display @" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;
		cout << endl;
		t[tLen] = time;
		tLen++;
		rQueue.readyQueueHandler();

		cout << "Jobs on CPU:" << endl;
		rQueue.printCPU();
		cout << endl;

		cout << "Jobs in ready Queue: " << endl;
		rQueue.printList();
		cout << endl;

		cout << "Finished Jobs:" << endl;
		finishedJobs.printList();
		cout << endl;

		cout << "Avail Mem:" << availMem << endl;


		cout << "" << endl;
		splitStr();
	}
	else if(commandArr[0] == "T"){
		for(int i=0; i<20; i++){
			cout << t[i] << endl;
		}
		splitStr();
	}
}
}









