// PRE-PROCCOR (Multiple Include Protection)
#ifndef __SlidingPuzzle__
#define __SlidingPuzzle__

#define PIVOT		   -1				// used to mark the pivot spot (blank area) on the puzzle
#define PIVOT_SYMBOL	"*"		// used to show the pivot location when drawing the board

// direction codes (part of the slideTile() interface)
#define SLIDE_UP		1		// pass to slideTile() to trigger UP movement
#define SLIDE_DOWN		2		// pass to slideTile() to trigger DOWN movement
#define SLIDE_LEFT		3		// pass to slideTile() to trigger LEFT movement
#define SLIDE_RIGHT		4		// pass to slideTile() to trigger RIGHT movement

#define UNSET			-1		// used to arbitrarily indicate an undetermined state in a constuct

#define COLOR_DEFAULT	7
#define COLOR_RED		12
#define COLOR_GREEN		10


#include <iostream>				// for general IO
#include <iomanip>				// for setw()
using namespace std;

#include <string.h>				// for strcpy()
#include <conio.h>				// for getche()
#include <time.h>
#include <windows.h>			// for COLOR!

class SlidingPuzzle{
private:
	int NUM_ROWS;
	int NUM_COLS;
	int** ppointer;
public:
	//CONSTRUCTOR
	SlidingPuzzle();
	
	//GETTERS
	int getNUM_ROWS();
	int getNUM_COLS();

	//SETTERS for user input and validation
	bool setNUM_ROWS(int new_ROWS);
	bool setNUM_COLS(int new_COLS);
	
	//utility 
	void InitializeBoard();
	void PrintBoard();
	bool slideTile(int);
	void scrambleBoard();
	bool isBoardSolved();
	void deallocate();
};
#endif