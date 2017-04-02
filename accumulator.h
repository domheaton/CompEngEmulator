//////////////////////////////////////////////////////////////////
/*
Module: accumulator.h

Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
Header file for the accumulator containing the member varaibles 
and functions for accessing the register.
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

class ACCUMULATOR
{
private:
	string acc;

public:
	void setAcc(const string & result);
	string getAcc(){return acc;}
};