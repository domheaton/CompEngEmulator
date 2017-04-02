//////////////////////////////////////////////////////////////////
/*
Module: decoder.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the decoder containing the member variables 
and functions required for the decoder's operation.
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

class DECODER
{
private:
	string operandA;
	string operandB;
	string toIR;
	string dataFromMem;

public:
	void setOperandA(const string & opA);
	void setOperandB(const string & opB);
	void setIR(const string & toIR);
	void runDecoder();
	void setDataFromMem(const string & data);
	string getOperandA(){return operandA;}
	string getOperandB(){return operandB;}
	string getIR(){return toIR;}
	string getDataFromMem(){return dataFromMem;}
};