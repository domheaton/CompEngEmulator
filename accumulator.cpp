//////////////////////////////////////////////////////////////////
/*
Module: accumulator.cpp

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
The accumulator register stores the output of the ALU before it 
is sent back to memory for storing.
*/
//////////////////////////////////////////////////////////////////

#include "accumulator.h"

void ACCUMULATOR::setAcc(const string & result)
{
	acc = result;
}