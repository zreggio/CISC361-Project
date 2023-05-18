
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
	if(commandArr[0] == "C"){
		cout << "configure" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;;

		//main mem reader
		cout << "Main Memory: ";
		int i = 2;
		while(commandArr[2][i] != NULL){
			cout << commandArr[2][i];
			i++;
		}
		cout << endl;

		//serial device reader
		cout << "Serial Devices: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			cout << commandArr[3][j];
			j++;
		}
		cout << endl;

		//quantum time reader
		cout << "Quantum Time: ";
		int k = 2;
		while(commandArr[4][k] != NULL){
			cout << commandArr[4][k];
			k++;
		}
		cout << endl;
	}
	else if(commandArr[0] == "A"){
		cout << "Arrival" << endl;
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
		cout << "Memory Needed: ";
		int j = 2;
		while(commandArr[3][j] != NULL){
			cout << commandArr[3][j];
			j++;
		}
		cout << endl;

		//max devices
		cout << "Max Devices Held: ";
		int k = 2;
		while(commandArr[4][k] != NULL){
			cout << commandArr[4][k];
			k++;
		}
		cout << endl;

		//run time
		cout << "Time Spent Running: ";
		int l = 2;
		while(commandArr[5][l] != NULL){
			cout << commandArr[5][l];
			l++;
		}
		cout << endl;

		//job priority
		cout << "Priority: ";
		int m = 2;
		while(commandArr[6][m] != NULL){
			cout << commandArr[6][m];
			m++;
		}
		cout << endl;
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
	}
	else if(commandArr[0] == "D"){
		cout << "Display @" << endl;
		time = stoi(commandArr[1]);
		cout << "Time: " << time << endl;

		//mem at time t will be printed here
		cout << "Current avail. Main mem: " << endl;

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
	}
}


