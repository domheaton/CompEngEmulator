//////////////////////////////////////////////////////////////////
/*
Module: pc.cpp

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
The program counter (PC) is responsible for keeping track of where
the CPU is in the cycle of fetch, decode, execute and returning 
values. It points to the memory address from which to collect
each package of data before pointing to the next slot, allowing
the return of data to the original slot and collection from the 
next available instruction.
*/
//////////////////////////////////////////////////////////////////

#include "pc.h"

void PC::incPC() //increment the program counter
{
	if(programCounter < 20)
	{
		programCounter += 1;	
	}
	else
	{
		cout << "ERROR! PC Incremented too much!" << endl;
	}
}

void PC::resetPC() //reset the program counter
{
	programCounter = 0;
}