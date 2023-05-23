In this folder you will find .cpp and .hpp files pertaining to this project.
The code is programed in c++ and compilded using MinGW (g++). All inputs/outputs are handdled in the console.
You will be prompted to "Enter a command" when running the code. Here (in the console) you can input each command 
with the propor format. The hold queues, ready and wait queues code can mostly be found in the 
processHandler.cpp/hpp respectively and input/output handdling can be found in the 
commandManager.cpp/hpp files respectievly.

Here are some examples of correctly formated inputs:
C 1 M=200 S=12 Q=4 
A 3 J=1 M=20 S=5 R=10 P=1
Q 10 J=1 D=5
L 32 J=3 D=2
D 9999

Coresponding Commands:
“C” - configuration	
“A” - job arrival
“Q” - device request
“L” - device release
“D” - display