//////////////////////////////////////////////////////////////////
/*
Module: memory.cpp

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
The memory module is a bank of registers in the form of an array
of strings. Each memory address can store a data package as 
described in 'decoder.cpp' containing an instruction and two 
input data values.
*/
//////////////////////////////////////////////////////////////////

#include "memory.h"

void MEMORY::memWrite(const int address, const string & returnToMem)
{
	reg[address] = returnToMem;
}

const string & MEMORY::getReg(const int address)
{
	return reg[address];
}