//////////////////////////////////////////////////////////////////
/*
Module: cpu.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the cpu containing variables.
To enable debug mode, uncomment line 17 to define debug.
*/
//////////////////////////////////////////////////////////////////

//Control for Enabling and disabling the debug information displayed on terminal
//#define debug
#ifdef debug
	#define debugMode 1
#else
	#define debugMode 0
#endif

#include "decoder.cpp"
#include "alu.cpp"
#include "accumulator.cpp"
#include "memory.cpp"
#include "pc.cpp"

#include <string>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <bitset>
#include <stdio.h>
#include <fstream>
using namespace std;

string returnToMem;
string blank = "000000";
string tempData;
int noOfInstructions;