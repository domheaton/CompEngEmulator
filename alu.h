//////////////////////////////////////////////////////////////////
/*
Module: alu.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the ALU. Contains the ALU class with its member
functions and functions.
*/
//////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <stdio.h>
using namespace std;

class ALU
{
private:
	string inputA;
	string inputB;
	string instruction;
	string result;

public:
	void setInputA(const string & a);
	void setInputB(const string & b);
	void setInstruction(const string & inst);
	void setResult(const string & resultString);
	void setOverflowFlag(bool a);
	void calculate();
	void runALU();
	string getInputA(){return inputA;}
	string getInputB(){return inputB;}
	string getResult(){return result;}
	string getInstruction(){return instruction;}
};