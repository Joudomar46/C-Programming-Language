
// CLASS SPECIFICATION 
#ifndef __DataHouse__ 
#define __DataHouse__ 

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class DataHouse {
private:
	int elementNum;
	int* BPointer; //bubble sort pointer
	int* SPointer; //Selection Sort pointer
	int* IPointer;//Insertion Sort pointer

public:
	//CONSTRUCTOR
	DataHouse();

	//GETTERS
	int GETelementNum();
	
	//SETTERS 
	bool setelementNum(int new_elementNum);

	//utility
	void InitializeArray();
	void fillArray(int numbersArray, int i);
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void deallocate();
};

#endif
