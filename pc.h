//////////////////////////////////////////////////////////////////
/*
Module: pc.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the program counter containing all the member 
functions and variables required.
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

class PC
{
private:
	int programCounter;

public:
	void incPC();
	void resetPC();
	int getPC(){return programCounter;}
};