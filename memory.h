//////////////////////////////////////////////////////////////////
/*
Module: memory.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the memory module, containing the member functions
and variables required.
*/
//////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <array>
#include <stdio.h>
using namespace std;

class MEMORY
{
private:
	array<string, 50> reg; //limited to 50 registers & therefore instructions maximum (for safety)

public:
	void memWrite(const int address, const string & returnToMem);
	const string & getReg(const int address);
};