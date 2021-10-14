#include <iostream>
#include <iomanip>
//#include <conio.h>
using namespace std;

int main() {
	// We will demonstrate the dynamic nature of these arrays by prodiving
	// the rectangular dimensions through variables.
	int height = 0; // initialize variable
	int width = 0; // initialize variable
	int a = 0;
	char verticle = 179;
	cout << "Please enter a number of rows on the interval [1, 10]: ";
	cin >> height; // user input
	while (cin.fail() == true || height < 1 || height > 10 ) // validate user input between range
	{
		cout << "This is not within the range [1, 10]. Please try again..." << endl;
		cin.clear();
		rewind(stdin);
		cout << "Please enter a number of rows on the interval [1, 10]: ";
		cin >> height;
	}
	cout << "Please enter a number of columns on the interval [1, 10]: ";
	cin >> width; // user input
	while (cin.fail() == true || width < 1 or width > 10) // validate user input between range
	{
		cout << "This is not within the range [1, 10]. Please try again..." << endl;
		cin.clear();
		rewind(stdin);
		cout << "Please enter a number of columns on the interval [1, 10]: ";
		cin >> width;
	}



	// Create the root double pointer for the 2D array.
	int** ppRootPointer = NULL;

	// Allocate an array of int* variables and attach to the double pointer.
	ppRootPointer = new(int* [height]);

	// Allocate arrays of int variables and attach each array to one of the
	// pointers in ppRootPointer's array of pointers.
	for (int i = 1; i <= height; i++) {
		ppRootPointer[i] = new(int[width]);
	}

	// Fill the array with a count.

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			ppRootPointer[i][j] = i * j;
		}
	}

	//************************************************
	//begin top lable
	int lables[10];

	// fill the array to count 1-10
	int counter = 1;
	for (int i = 0; i < width; i++) {
		lables[i] = counter++;
	}

	// Print the array on top of multiplication table
	cout << right;
	cout << "   "<< verticle;
	for (int i = 0; i < width; i++) {
		cout << setw(3) << lables[i];
		cout << setw(1) << verticle;
	}
		cout << endl;
	//*************************************************
		// begin side lable
		int lableb[1][10];
	// Fill the array with a count.
		int counterb = 1;
		for (int i = 1; i < height+1; i++) {
			for (int j = 0; j < 1; j++) {
				lableb[i][j] = counterb++;
			}
		}
		// Print the array (full array notation).


	//*************************************************

	cout << right;

	for (int i = 1; i <= height; i++) {
		cout << "---+";
		for (int a = 1; a <= width; a++) { //printing grid sideways
			cout << "---+";
		}
		cout << endl;
		//printing the side lable
			for (int j = 0; j < 1; j++) {
				cout << setw(3) << lableb[i][j];
				cout << setw(1) << verticle;
			}
		//print rows
		for (int j = 1; j <= width; j++) {
			cout << setw(3) << ppRootPointer[i][j];
			cout << setw(1) << verticle; //printing seperation of lines
		}
		cout << endl;
	}
	cout << endl << endl;

	// Deallocate the memory.
	for (int i = 0; i < height; i++) {
		// Since each pointer has multiple elements attached (the widths)
		// we must include the [] with the delete operation.
		// Omitting the [] with the delete operation will only deallocate
		// memory for a single element in the array.  Including the []
		// will use the array size indicated in the new statement used
		// to initially allocate the memory.  If in doubt, use the []
		// with the delete operation.
		delete[] ppRootPointer[i];
	}

	// Now the memory for the pointers that pointed to the first element
	// at the beginning of each row can be deallocated.  This took the
	// form of an array of pointers, so we will still include the []
	// in the delete, but remove the array index operator (also [])
	// and begin decllocating from 'ppRootPointer'.
	delete[] ppRootPointer;

	//_getch();
	return 0;
}

