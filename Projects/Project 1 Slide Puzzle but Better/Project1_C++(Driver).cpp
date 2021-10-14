//Driver file
//Project1_C++(Specification)_Header.h
//Project1_C++(Implementation).cpp

#pragma warning(disable:4996)

#include <iostream>				// for general IO
#include <iomanip>				// for setw()
using namespace std;

#include "Project1_C++(Specification)_Header.h"


int main(){
	// Declarations
	
	char keyStroke = NULL;						// holds the user's keystrokes as they come in
	int directionCode = UNSET;	// used to build a direction code to be sent to slideTile()
	int userRow = 0; //user input spot
	int userCol = 0;

	SlidingPuzzle myPuzzle;
	cout << "How many Rows would you like: " << endl;
	cin >> userRow;
	//input validation
	while (cin.fail() == true || userRow < 0) {
		cout << "this is not a number. Try again..." << endl;
		cin.clear();
		rewind(stdin);
		cout << "How many Rows would you like: " << endl;
		cin >> userRow;
	}
	myPuzzle.setNUM_ROWS(userRow); //passes user input to setNUM_ROWS in myPuzzle

	cout << "How many Column would you like: " << endl;
	cin >> userCol;
	while (cin.fail() == true || userCol < 0) {
		cout << "this is not a number. Try again..." << endl;

		cin.clear();
		rewind(stdin);
		//reprompt
		cout << "How many Column would you like: " << endl;
		cin >> userCol;

	}
	myPuzzle.setNUM_COLS(userCol);
	//begin board
	myPuzzle.InitializeBoard();
	myPuzzle.PrintBoard();
	
	cout << "isBoardSolved(): True" << endl;
	cout << "Press enter to begin" << endl;
	cin.get();

	cout << "Scrambling the game tiles..." << endl;
	myPuzzle.scrambleBoard();
	cout << "Scrambling complete.... press enter again to begin solving. " << endl;
	cin.get();

	// playing the game while the bored is not solved

	while (!myPuzzle.isBoardSolved())
	{
		//everytime we come back to re-enter a move it is vitaly important to 
		//reset both the keystroke and the direction code
		//otherwise it will keep the same value every time 
		system("CLS");

		myPuzzle.PrintBoard();
		cout << "isBoardSolved(): " << myPuzzle.isBoardSolved() << endl;

		cout << endl << endl;
		cout << "[w - Up] [a - Left] [s - Down] [d - Right]" << endl;
		cout << "Which Way To Slide: ";

		//set the keystroke to the system input

		keyStroke = NULL;
		directionCode = UNSET;
		bool keyRecived = false; //to check user input

		while (keyRecived == false) {
			keyStroke = _getch(); //recive input
			if (toupper(keyStroke) == 'W')
			{
				directionCode = SLIDE_UP;
				keyRecived = true; //get out of while loop for input validation
			}
			else if (toupper(keyStroke) == 'S')
			{
				directionCode = SLIDE_DOWN;
				keyRecived = true;
			}
			else if (toupper(keyStroke) == 'A')
			{
				directionCode = SLIDE_LEFT;
				keyRecived = true;
			}
			else if (toupper(keyStroke) == 'D')
			{
				directionCode = SLIDE_RIGHT;
				keyRecived = true;
			}
			else 
			{
				//keystroke validation
				cout << endl << "'" << keyStroke << "' " << "is not a valid selection." << endl;
				cout << "Please try again...";
				cout << "[w - Up] [a - Left] [s - Down] [d - Right]" << endl;
				cout << "Which Way To Slide: ";
				keyStroke = _getch();
			} //end of else statement

		}
	

		myPuzzle.slideTile(directionCode);
		//make the system close so that every time you make a move it will reprint the board
		system("CLS");
		myPuzzle.PrintBoard();
		
	}//exit game when bored is solved
	//display solved message
	myPuzzle.deallocate(); //deallocate the memory
	cout << endl;
	cout << "Congratulations: BOARD SOLVED" << endl;
	// Exit

	_getch();
	return 0;
}