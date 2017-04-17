//////////////////////////////////////////////////////////////////
/*
Module: cpu.cpp
 
Author: Dominic Heaton
UoS - 2777 9009
dhh1g15@soton.ac.uk

Description:
The CPU file which controls the whole emulator. This file controls
the flow of data around the system.
-Program counter (PC) points to first memory address
-The data is written from a file 'InputData.txt' into the memory
	in neighbouring registers pointed to by the PC.
-Data is then read into the decoder from the first register.
-Decoder separates the data into inputs and control signals 
	for the ALU.
-ALU then executes producing an output which is written to 
	the accumulator (AC).
-ALU will flag any overflow caused in the ALU.
-Accumulator contents is then written back to memory space 
	that the instruction was collected from using the 
	4 least-significant-bit slots.
-All data for each cycle is written into a 'DataLogger.txt' file
	to allow analysis of the data the system produces.
-Data is also placed on the command line to show each stage of 
	the processor being used.
*/
//////////////////////////////////////////////////////////////////
#include "cpu.h"

int main()
{
	//Creates Instances of each module
	DECODER decoder;
	ALU alu;
	ACCUMULATOR accumulator;
	PC pc;
	MEMORY memory;

	cout << "View results in the generated text file - 'DataLogger.txt'." << endl;
	cout << "Alternatively enable the debug mode in 'cpu.h'." << endl;

	if(debugMode)
	{
		cout << endl << "========================================================" << endl;
		cout << "DEBUG MODE STARTED" << endl;
		cout << "========================================================" << endl;
	}
	
	//Reading data from external file into memory
	ifstream file;
	file.open("InputData.txt");
	if(!file)
	{
		if(debugMode)
		{
		cout << endl << "ERROR! data.txt couldn't be opened!" << endl;
		cout << "Exiting Program" << endl << endl;
		}
		return -1;
	}
	else
	{
		if(debugMode)
			cout << "Reading from file..." << endl;
	}

	for(noOfInstructions=0; !file.eof(); noOfInstructions++)
	{
	 	getline(file, tempData);
		memory.memWrite(noOfInstructions, tempData);
	}
	file.close();

	if(debugMode)
		cout << "Data read. Preparing..." << endl << endl;


	//Reset PC
	if(debugMode)
		cout << "Resetting PC" << endl;
	pc.resetPC();
	if(debugMode)
		cout << "PC is now reset = " << pc.getPC() << endl << endl;

	//Start up the Data-logger
	ofstream dataLog;
	dataLog.open("DataLogger.txt");
	dataLog << "Welcome to the Data Logger." << endl << endl << "Instruction Meanings:" << endl;
	dataLog << "00 = Addition" << endl << "01 = Subtraction" << endl;
	dataLog << "10 = Multiplication" << endl << "11 = Division" << endl << endl;
	dataLog << "System has Started..." << endl << endl;

	//While loop to execute every instruction in the memory
	while(pc.getPC()<noOfInstructions)
	{
		//Print current state of Program Counter
		if(debugMode)
			cout << "PC = " << pc.getPC() << endl << endl;

		//FETCH - Fetches instruction from Memory & increments PC
		if(debugMode)
			cout << "Fetching from memory..." << endl;
		decoder.setDataFromMem(memory.getReg(pc.getPC()));
		pc.incPC();
		if(debugMode)
			cout << "Fetch completed" << endl << endl;

		//DECODE - Decodes Instruction
		if(debugMode)
			cout << "Decoding..." << endl;
	 	decoder.runDecoder();
	 	if(debugMode)
			cout << "Decoder has finished" << endl << endl;

		//EXECUTE - Executes ALU instruction
		if(debugMode)
			cout << "Executing the ALU command..." << endl;
		alu.setInputA(decoder.getOperandA());
	 	alu.setInputB(decoder.getOperandB());
	 	alu.setInstruction(decoder.getIR());
	 	alu.runALU();
	 	if(debugMode)
	 		cout << "ALU has finished" << endl << endl;

	 	//Stores ALU result in ACC
	 	if(debugMode)
	 		cout << "Accumulator ready to receive..." << endl;
	 	accumulator.setAcc(alu.getResult());
	 	//cout << accumulator.getAcc() << endl; 
	 	if(debugMode)
	 		cout << "Accumulator has finished" << endl << endl;

	 	//WRITE-BACK - Returns ACC to Memory where it came from
	 	returnToMem = blank + accumulator.getAcc(); //converts to 10bits with 4LSB being the result
	 	memory.memWrite(pc.getPC()-1, returnToMem); //result stored where from @ start
	 	if(debugMode)
	 	{
		 	cout << "Writing to memory..." << endl;
		 	cout << "The result read back from memory: " << memory.getReg(pc.getPC()-1) << endl;
		 	cout << "________________________________________________________" << endl;
	 	}

	 	//Data Logger
	 	dataLog << "PC          : " << pc.getPC()-1 << endl;
	 	dataLog << "Raw Memory  : " << decoder.getDataFromMem() << endl;
	 	dataLog << "Instruction : " << decoder.getIR() << endl;
		dataLog << "Operand A   : " << decoder.getOperandA() << endl;
		dataLog << "Operand B   : " << decoder.getOperandB() << endl;
		dataLog << "Value Stored: " << memory.getReg(pc.getPC()-1) << endl;
		if(overflow)
		{
			dataLog << "OVERFLOW HAS OCCURED!" << endl << endl;
		}
		else
		{
			dataLog << endl;
		}
 	}
 	//close the data-logger
 	dataLog << "System has Finished.";
 	dataLog.close();

 	if(debugMode)
 	{
 		cout << "System Has Finished Executing All Instructions" << endl;
 		cout << "========================================================" << endl;	
 	}
 	
 	return 0;
}