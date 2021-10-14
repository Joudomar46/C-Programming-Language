#include "Project1_C++(Specification)_Header.h"
//point the user input to the constructor in the implentation to set
// the construct to the values the user wanted 

//constuctor methods for private info
SlidingPuzzle::SlidingPuzzle() {
	this->NUM_ROWS = 3;
	this->NUM_COLS = 3;
	int** ppointer = NULL; //NULL so it doesnt point at junk
} 

//GETTERS
int SlidingPuzzle::getNUM_ROWS() {
	return this->NUM_ROWS; //allow access to private 
}
int SlidingPuzzle::getNUM_COLS() {
	return this->NUM_COLS;
}

//setters
bool SlidingPuzzle::setNUM_ROWS(int new_ROWS) {
	//Only accept the new row if its not negative
	bool newValueAccepted = false;
	if (NUM_ROWS > 0) {
		this->NUM_ROWS = new_ROWS;
		newValueAccepted = true;
	}
	// return the bool if accepted =true, or false 
	return newValueAccepted;
}
bool SlidingPuzzle::setNUM_COLS(int new_COLS) {
	bool newValueAccepted = false;
	if (NUM_COLS > 0) {
		this->NUM_COLS = new_COLS;
		newValueAccepted = true;
	}
	return newValueAccepted;
}

//utility
void SlidingPuzzle::InitializeBoard() {

	//allocate array
	this->ppointer = new(int* [getNUM_ROWS()]);
	for (int i = 0; i < getNUM_ROWS(); i++) {
		this->ppointer[i] = new(int[getNUM_COLS()]);
	}

	int i = 1;
	for (int row = 0; row < getNUM_ROWS(); row++)
	{
		for (int column = 0; column < getNUM_COLS(); column++)
		{
			this->ppointer[row][column] = i;		//pointer is changing array numbers
			i++;                                    //2d array filled with numbers
		}
		ppointer[getNUM_ROWS() -1][getNUM_COLS() -1] = PIVOT; // is replaced by -1 
	}
}

void SlidingPuzzle::PrintBoard() {
	// get the handle for the console
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//print board with color
	int counter = 0;
	for (int row = 0; row < getNUM_ROWS(); row++) //building rows
	{
		for (int column = 0; column < getNUM_COLS(); column++) //building columns
		{
			counter++;
			if (this->ppointer[row][column] != PIVOT) //check if numbers are not = -1
			{
				if (this->ppointer[row][column] == counter) //if they are equal to counter that means
															//they are in correct order
					SetConsoleTextAttribute(hConsole, COLOR_GREEN); //coloring correct order in green
				else
				SetConsoleTextAttribute(hConsole, COLOR_RED); //if not in correct order its red
				cout << setw(5) << this->ppointer[row][column]; //spacing
				SetConsoleTextAttribute(hConsole, COLOR_DEFAULT); //coloring the * white
			}
			else
				cout << setw(5) << PIVOT_SYMBOL; //print pivot	
		}
		cout << endl;
	}
}

bool SlidingPuzzle::slideTile(int slideDirection) {

	//Initialize star coordinates
	int pivotX = 0;
	int pivotY = 0;

	// Find pivot spot
	for (int i = 0; i < getNUM_ROWS(); i++)
	{
		for (int j = 0; j < getNUM_COLS(); j++)
		{
			if (this->ppointer[i][j] == PIVOT)
			{
				pivotX = i;
				pivotY = j;
			}
		}
	}

	//legal moves for all keyStrokes

	//use getNUM_ROWS()-1 to choose correct boundery 
	//same logic for COLS
	//0 comparison will always be the same for the index of an array
	//-----------------
	//| 0,0 *| 0,1| 0,2| 
	//| 1,0  | 1,1| 1,2|
	//| 2,0 5| 2,2| 2,2|
	if ((slideDirection == SLIDE_UP) && (getNUM_ROWS()-1 > pivotX))  //W
	{
		int tileToSwap = this->ppointer[pivotX + 1][pivotY];

		this->ppointer[pivotX + 1][pivotY] = PIVOT;
		this->ppointer[pivotX][pivotY] = tileToSwap;
		return true;
	}
	else if ((slideDirection == SLIDE_DOWN) && (0 < pivotX)) //S
	{
		int tileToSwap = this->ppointer[pivotX - 1][pivotY];

		this->ppointer[pivotX - 1][pivotY] = PIVOT;
		this->ppointer[pivotX][pivotY] = tileToSwap;

		return true;
	}
	else if ((slideDirection == SLIDE_RIGHT) && (0 < pivotY)) //D
	{
		int tileToSwap = this->ppointer[pivotX][pivotY - 1];

		this->ppointer[pivotX][pivotY - 1] = PIVOT;
		this->ppointer[pivotX][pivotY] = tileToSwap;
		return true;
	}
	else if ((slideDirection == SLIDE_LEFT) && (pivotY < getNUM_COLS() - 1)) //A
	{
		int tileToSwap = this->ppointer[pivotX][pivotY + 1];

		this->ppointer[pivotX][pivotY + 1] = PIVOT;
		this->ppointer[pivotX][pivotY] = tileToSwap;
		return true;

	}

	return false;
}

void SlidingPuzzle::scrambleBoard() {
	srand(time(NULL));
	//use srand(time(NULL) for random
	int slideDirection;
		for (int i = 0; i < 9000; i++)
		{
			slideDirection = rand() % 5;
			slideTile(slideDirection); //pass random numbers to slide tile
		}
}

bool SlidingPuzzle::isBoardSolved() {
	int counter = 0;
	for (int row = 0; row < getNUM_ROWS(); row++) //building rows
	{
		for (int column = 0; column < getNUM_COLS(); column++) //building columns
		{
			counter++;
			if ((this->ppointer[row][column] != counter) &&
				(this->ppointer[row][column] != PIVOT)) //detects if a number is NOT 
														//in the correct location =set false
				return false;
		}
	}
	return true;
}

void SlidingPuzzle::deallocate() {
	//function to deallocate memory
	for (int i = 0; i < getNUM_ROWS(); i++) {
		delete[] this->ppointer[i];
	}
	delete[] this->ppointer;
}

