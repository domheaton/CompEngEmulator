//////////////////////////////////////////////////////////////////
/*
Module: alu.cpp

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
An ALU capable of taking two 4-bit inputs and calculating the 
addition, subtraction, division or multiplication depending on 
the instruction input. The four bit output is then produced and 
a flag will warn of any overflow.
*/
//////////////////////////////////////////////////////////////////

#include "alu.h"

//Initialisation of Variables
string inputA = "0000"; 		//DO NOT CHANGE
string inputB = "0000";			//DO NOT CHANGE
string instruction = "00";		//DO NOT CHANGE
string resultString = "0000";	//DO NOT CHANGE
bool overflow = 0;				//DO NOT CHANGE

void ALU::setInputA(const string & a)	//set ALU input A
{
	inputA = a;
}

void ALU::setInputB(const string & b)	//set ALU input B
{
	inputB = b;
}

void ALU::setInstruction(const string & inst) //set ALU instruction
{
	instruction = inst;
}

void ALU::setResult(const string & resultString) //set the ALU output
{
result = resultString;
}

void ALU::setOverflowFlag(bool a)	//set up the Overflow flag
{
	overflow = a;
}

void ALU::calculate()	//carry out the ALU operation
{
	//convert inputs from string to ints
	int x = stoi(getInputA(), nullptr, 2); 
	int y = stoi(getInputB(), nullptr, 2);
	int i = stoi(getInstruction(), nullptr, 2);
	int z; //result integer

	//case statements for each operation that can be carried out
	switch(i)
	{
		case 0: z = x + y; break; //addition
		case 1: z = x - y; break; //subtraction
		case 2: z = x * y; break; //multiplication
		case 3: z = x / y; break; //division
	}
	
	//Overflow checker
	bitset<8> b(z);
	if(b[4] | b[5] | b[6] | b[7])
	{
		setOverflowFlag(true); 
	}
	else
	{
		setOverflowFlag(false);
	}

	//Re-sizing for returning 4-bit value
	bitset<4> c(z);
	resultString = c.to_string();
	
	setResult(resultString);
}

void ALU::runALU()
{
	//ALU alu;	//instance of the ALU

	//NEED TO BE SET FROM THE INSTRUCTION DECODER
	//string a = "1010";	//local ALU input A
	//string b = "0010";	//local ALU input B
	//string inst = "00"; //local ALU instruction

	//cout << "A Value is: " << getInputA() << endl;
	//cout << "B Value is: " << getInputB() << endl;

	calculate(); //Runs the ALU to find answer
	if(overflow)
	{
		cout << "WARNING! Overflow has occured in the ALU" << endl;
		cout << "The INCORRECT answer is: " << getResult() << endl;
	}
	else
	{
		cout << "ALU output: " << getResult() << endl;
	}
}