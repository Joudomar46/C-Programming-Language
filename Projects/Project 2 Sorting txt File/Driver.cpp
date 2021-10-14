// INCLUDES & NAMESPACES
#pragma warning(disable:4996)

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "StopWatch.h"
#include "DataHouse.h"
using namespace std;
#define INFILE			"NumFile500.txt"
#define INFILE2			"NumFile5K.txt"
#define INFILE3			"NumFile25k.txt"
#define INFILE4			"NumFile100k.txt"

// MAIN
int main() {
	
	//declare variables
	StopWatch myTimer;
	DataHouse test;
	int tempi; //temp variable to put the input handle in


	//begin counting of the number of elements in the file
	// attempt to open the file with read permission
	ifstream inputHandle(INFILE, ios::in);
	int countElements = 0; //counter of how many elements (numbers) are in the file
	// check to make sure the file opened...
	if (inputHandle.is_open() == true) {
		
		do
		{
			inputHandle >> tempi;
			countElements++;
			
		} while (!inputHandle.eof());// while the file opened, read integers until EOF (end of file) is encountered
		
		
		
		// close the file now that we are done reading
		inputHandle.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE << "\" could not be opened for reading..." << endl;
	}
	//end of counting file elements

	cout << "Populating Arrays... <" << countElements << " elements> <" << endl;

	test.setelementNum(countElements); //set the array size based from countElement
	test.InitializeArray(); //allocate the memory 

	//Filling in the pointer arrays in DataHouse 
	ifstream text(INFILE, ios::in);
	if (text.is_open() == true) {
		
		int i = 0;
		while (!text.eof()) {
			if (i < countElements) {
				text >> tempi;
				test.fillArray(tempi, i);
				i++;
			}
			else {
				// if the file didn't open, echo this to the user
				cout << "ERROR: The file \"" << INFILE << "\" could not be opened for reading..." << endl;
				
			}
		}
		text.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE << "\" could not be opened for reading..." << endl;
	}

	cout << "Sorting..." << endl;
	cout << "SORTS COMPLETE!" << endl;

	//begin sorting and timing 
	//Bubble sort
	myTimer.Start();//start Timer
	test.bubbleSort();
	myTimer.Stop();// stop the timer

	// display the timer contents
	cout << "Elapsed Time <Bubble Sort>           :";
	myTimer.DisplayTimerInfo();
	
	//Selection Sort
	myTimer.Start();
	test.selectionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Selection Sort>        :";
	myTimer.DisplayTimerInfo();

	//Insertion Sort
	myTimer.Start();
	test.insertionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Insertion Sort>        :";
	myTimer.DisplayTimerInfo();

	//deallocate the memory for this file run 
	test.deallocate();
	cout << endl;
	//end of first file Heuristic Algorithm Analysis

	//begin counting of the number of elements in the file2
	ifstream inputHandle2(INFILE2, ios::in);
	countElements = 0; //back to zero
	
	if (inputHandle2.is_open() == true) {

		do
		{
			inputHandle2 >> tempi;
			countElements++;

		} while (!inputHandle2.eof());// while the file opened, read integers until EOF (end of file) is encountered



		// close the file now that we are done reading
		inputHandle2.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE2 << "\" could not be opened for reading..." << endl;
	}
	//end of counting file elements

	cout << "Populating Arrays... <" << countElements << " elements> <" << endl;

	test.setelementNum(countElements); //set the array size based from countElement
	test.InitializeArray(); //allocate the memory 

	//Filling in the pointer arrays in DataHouse 
	ifstream text2(INFILE2, ios::in);
	if (text2.is_open() == true) {

		int i = 0;
		while (!text2.eof()) {
			if (i < countElements) {
				text2 >> tempi;
				test.fillArray(tempi, i);
				i++;
			}
			else {
				// if the file didn't open, echo this to the user
				cout << "ERROR: The file \"" << INFILE2 << "\" could not be opened for reading..." << endl;

			}
		}
		text2.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE2 << "\" could not be opened for reading..." << endl;
	}

	cout << "Sorting..." << endl;
	cout << "SORTS COMPLETE!" << endl;

	//begin sorting and timing 
	//Bubble sort
	myTimer.Start();//start Timer
	test.bubbleSort();
	myTimer.Stop();// stop the timer

	// display the timer contents
	cout << "Elapsed Time <Bubble Sort>           :";
	myTimer.DisplayTimerInfo();

	//Selection Sort
	myTimer.Start();
	test.selectionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Selection Sort>        :";
	myTimer.DisplayTimerInfo();

	//Insertion Sort
	myTimer.Start();
	test.insertionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Insertion Sort>        :";
	myTimer.DisplayTimerInfo();

	//deallocate the memory for this file run 
	test.deallocate();

	cout << endl;
	//end of second file Heuristic Algorithm Analysis

	//begin counting of the number of elements in the file3
	ifstream inputHandle3(INFILE3, ios::in);
	countElements = 0; //back to zero

	if (inputHandle3.is_open() == true) {

		do
		{
			inputHandle3 >> tempi;
			countElements++;

		} while (!inputHandle3.eof());// while the file opened, read integers until EOF (end of file) is encountered



		// close the file now that we are done reading
		inputHandle3.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE3 << "\" could not be opened for reading..." << endl;
	}
	//end of counting file elements

	cout << "Populating Arrays... <" << countElements << " elements> <" << endl;

	test.setelementNum(countElements); //set the array size based from countElement
	test.InitializeArray(); //allocate the memory 

	//Filling in the pointer arrays in DataHouse 
	ifstream text3(INFILE3, ios::in);
	if (text3.is_open() == true) {

		int i = 0;
		while (!text3.eof()) {
			if (i < countElements) {
				text3 >> tempi;
				test.fillArray(tempi, i);
				i++;
			}
			else {
				// if the file didn't open, echo this to the user
				cout << "ERROR: The file \"" << INFILE2 << "\" could not be opened for reading..." << endl;

			}
		}
		text3.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE2 << "\" could not be opened for reading..." << endl;
	}

	cout << "Sorting..." << endl;
	cout << "SORTS COMPLETE!" << endl;

	//begin sorting and timing 
	//Bubble sort
	myTimer.Start();//start Timer
	test.bubbleSort();
	myTimer.Stop();// stop the timer

	// display the timer contents
	cout << "Elapsed Time <Bubble Sort>           :";
	myTimer.DisplayTimerInfo();

	//Selection Sort
	myTimer.Start();
	test.selectionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Selection Sort>        :";
	myTimer.DisplayTimerInfo();

	//Insertion Sort
	myTimer.Start();
	test.insertionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Insertion Sort>        :";
	myTimer.DisplayTimerInfo();

	//deallocate the memory for this file run 
	test.deallocate();

	cout << endl;
	//end of third file Heuristic Algorithm Analysis

	//begin counting of the number of elements in the file4
	ifstream inputHandle4(INFILE4, ios::in);
	countElements = 0; //back to zero

	if (inputHandle4.is_open() == true) {

		do
		{
			inputHandle4 >> tempi;
			countElements++;

		} while (!inputHandle4.eof());// while the file opened, read integers until EOF (end of file) is encountered



		// close the file now that we are done reading
		inputHandle4.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE4 << "\" could not be opened for reading..." << endl;
	}
	//end of counting file elements

	cout << "Populating Arrays... <" << countElements << " elements> <" << endl;

	test.setelementNum(countElements); //set the array size based from countElement
	test.InitializeArray(); //allocate the memory 

	//Filling in the pointer arrays in DataHouse 
	ifstream text4(INFILE4, ios::in);
	if (text4.is_open() == true) {

		int i = 0;
		while (!text4.eof()) {
			if (i < countElements) {
				text4 >> tempi;
				test.fillArray(tempi, i);
				i++;
			}
			else {
				// if the file didn't open, echo this to the user
				cout << "ERROR: The file \"" << INFILE4 << "\" could not be opened for reading..." << endl;

			}
		}
		text4.close();
	}
	else {
		// if the file didn't open, echo this to the user
		cout << "ERROR: The file \"" << INFILE4 << "\" could not be opened for reading..." << endl;
	}

	cout << "Sorting..." << endl;
	cout << "SORTS COMPLETE!" << endl;

	//begin sorting and timing 
	//Bubble sort
	myTimer.Start();//start Timer
	test.bubbleSort();
	myTimer.Stop();// stop the timer

	// display the timer contents
	cout << "Elapsed Time <Bubble Sort>           :";
	myTimer.DisplayTimerInfo();

	//Selection Sort
	myTimer.Start();
	test.selectionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Selection Sort>        :";
	myTimer.DisplayTimerInfo();

	//Insertion Sort
	myTimer.Start();
	test.insertionSort();
	myTimer.Stop();
	cout << "Elapsed Time <Insertion Sort>        :";
	myTimer.DisplayTimerInfo();

	//deallocate the memory for this file run 
	test.deallocate();
	//end of file 4 

	// pause the screen and end the program
	_getch();
	return 0;
}
