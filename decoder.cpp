//////////////////////////////////////////////////////////////////
/*
Module: decoder.cpp

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
The decoder capable of taking the 10-bit input from memory and 
separating the data up into the instructions, inputA and inputB
ready for the ALU to act upon them.

Data packages are in the following form:
|--2 bit instruction--4 bit operand--4 bit operand--|
*/
//////////////////////////////////////////////////////////////////

#include "decoder.h"

void DECODER::setIR(const string & dataFromMem)
{
	toIR = dataFromMem.substr(0,2);
	cout << "Instruction: " << toIR << endl;
}

void DECODER::setOperandA(const string & dataFromMem)
{
	operandA = dataFromMem.substr(2,4);
	cout << "Input A: " << operandA << endl;
}

void DECODER::setOperandB(const string & dataFromMem)
{
	operandB = dataFromMem.substr(6,4);
	cout << "Input B: " << operandB << endl;
}

void DECODER::setDataFromMem(const string & data)
{
	dataFromMem = data;
}

void DECODER::runDecoder()
{
	//place data into correct variables for ALU
	setIR(dataFromMem);
	setOperandA(dataFromMem);
	setOperandB(dataFromMem);
}