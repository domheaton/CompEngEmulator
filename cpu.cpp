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

	cout << "========================================================" << endl;
	//Reading data from external file into memory
	ifstream file;
	file.open("InputData.txt");
	if(!file)
	{
		cout << endl << "ERROR! data.txt couldn't be opened!" << endl;
		cout << "Exiting Program" << endl << endl;
		return -1;
	}
	else
	{
		cout << "Reading from file..." << endl;
	}

	for(noOfInstructions=0; !file.eof(); noOfInstructions++)
	{
	 	getline(file, tempData);
		memory.memWrite(noOfInstructions, tempData);
	}
	//cout << "FILE TEST: " << memory.getReg(2) << endl << endl;
	file.close();
	cout << "Data read. Preparing..." << endl << endl;


	//Reset PC
	cout << "Resetting PC" << endl;
	pc.resetPC();
	cout << "PC is now reset = " << pc.getPC() << endl << endl;

	//Test strings before reading from separate file
	// string testinput = "0011100001";
	// memory.memWrite(pc.getPC(), testinput);
	// cout << "Loaded test string " << testinput << " into memory" << endl << endl;

	ofstream dataLog;
	dataLog.open("DataLogger.txt");
	dataLog << "Welcome to the Data Logger." << endl << endl << "Instruction Meanings:" << endl;
	dataLog << "00 = Addition" << endl << "01 = Subtraction" << endl;
	dataLog << "10 = Multiplication" << endl << "11 = Division" << endl << endl;
	dataLog << "System has Started..." << endl << endl;

	while(pc.getPC()<noOfInstructions)
	{
		cout << "PC = " << pc.getPC() << endl << endl;

		//FETCH - Fetches instruction from Memory & increments PC
		cout << "Fetching from memory..." << endl;
		decoder.setDataFromMem(memory.getReg(pc.getPC()));
		pc.incPC();
		cout << "Fetch completed" << endl << endl;

		//DECODE - Decodes Instruction
		cout << "Decoding..." << endl;
	 	decoder.runDecoder();
		cout << "Decoder has finished" << endl << endl;

		//EXECUTE - Executes ALU instruction
		cout << "Executing the ALU command..." << endl;
		alu.setInputA(decoder.getOperandA());
	 	alu.setInputB(decoder.getOperandB());
	 	alu.setInstruction(decoder.getIR());
	 	alu.runALU();
	 	cout << "ALU has finished" << endl << endl;

	 	//Stores ALU result in ACC
	 	cout << "Accumulator ready to receive..." << endl;
	 	accumulator.setAcc(alu.getResult());
	 	//cout << accumulator.getAcc() << endl; 
	 	cout << "Accumulator has finished" << endl;

	 	//WRITE-BACK - Returns ACC to Memory where it came from
	 	returnToMem = blank + accumulator.getAcc(); //converts to 10bits with 4LSB being the result
	 	memory.memWrite(pc.getPC()-1, returnToMem); //result stored where from @ start
	 	cout << "Writing to memory..." << endl;
	 	cout << "The result read back from memory: " << memory.getReg(pc.getPC()-1) << endl;
	 	cout << "________________________________________________________" << endl;

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
 	dataLog << "System has Finished.";
 	dataLog.close();

 	cout << "System Has Finished Executing All Instructions" << endl;
 	cout << "========================================================" << endl;
 	return 0;
}