#pragma warning(disable:4996)

#include <iostream>				// for general IO
#include <iomanip>				// for setw()
using namespace std;

#include <string.h>				// for strcpy()
#include <conio.h>				// for getche()
#include <time.h>
#include <windows.h>			// for COLOR!

#define NUM_ROWS		3		// should not be changed for this solution
#define NUM_COLS		3		// should not be changed for this soultion

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


// PROTOTYPES
void InitializeBoard(int[NUM_ROWS][NUM_COLS]);
void PrintBoard(int[NUM_ROWS][NUM_COLS]);
bool slideTile(int[NUM_ROWS][NUM_COLS], int);
void scrambleBoard(int[NUM_ROWS][NUM_COLS]);		// depends upon slideTile()
bool isBoardSolved(int[NUM_ROWS][NUM_COLS]);		// indicates if the board is in the SOLVED state


int main() {
    // Declarations
    int slidingBoard[NUM_ROWS][NUM_COLS];		// the board that holds the sliding tiles
    char keyStroke = NULL;						// holds the user's keystrokes as they come in
    int directionCode = UNSET;					// used to build a direction code to be sent to slideTile()

    // Seed the Pseudo-Random Number Generator (system clock)

    // Driver Logic
    // 1.) This is the part where you show the board, get the moves, process the moves, and re-draw
    //  the board each time something changes.  This is the core logic of the simulation and
    //  none of the problem specific calculations should take place in main().  Instead,
    //  main() should consist of a series of controlled calls to your functions that
    //  orchestrate the top-level behavior of the simulation.

    InitializeBoard(slidingBoard);
    PrintBoard(slidingBoard);
    cout << boolalpha;

    cout << "isBoardSolved(): " << isBoardSolved(slidingBoard) << endl;

    cout << "Press enter to begin" << endl;

    cin.get();

    cout << "Scrambling the game tiles..." << endl;

    scrambleBoard(slidingBoard);

    cout << "Scrambling complete.... press enter again to begin solving. " << endl;

    cin.get();

    // playing the game while the bored is not solved
    while (!isBoardSolved(slidingBoard))
    {
        //everytime we come back to re-enter a move it is vitaly important to
        //reset both the keystroke and the direction code
        //otherwise it will keep the same value every time
        system("CLS");

        PrintBoard(slidingBoard);
        cout << "isBoardSolved(): " << isBoardSolved(slidingBoard) << endl;

        cout << endl << endl;
        cout << "[w - Up] [a - Left] [s - Down] [d - Right]" << endl;
        cout << "Which Way To Slide: ";

        //set the keystroke to the system input

        keyStroke = NULL;
        directionCode = UNSET;
        bool keyRecived = false; //to check user input

        while(keyRecived == false) {
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
                cout << endl << "'" << keyStroke << "' " << "is not a valid selection." << endl;
                cout << "Please try again...";
                cout << "[w - Up] [a - Left] [s - Down] [d - Right]" << endl;
                cout << "Which Way To Slide: ";
                keyStroke = _getch();
            } //end of else statement
        }
        slideTile(slidingBoard, directionCode);
        //make the system close so that every time you make a move it will reprint the board
        system("CLS");
        PrintBoard(slidingBoard);
    }//exit game when bored is solved
    //display solved message
    cout << endl;
    cout << "Congratulations: BOARD SOLVED" << endl;
    // Exit
    _getch();
    return 0;
}

void InitializeBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
    int i = 1;
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int column = 0; column < NUM_COLS; column++)
        {
            theBoard[row][column] = i;
            i++;                                    //2d array filled 1 through 9
        }
        theBoard[2][2] = PIVOT; //9 is replaced by -1
    }
}

void PrintBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
    // get the handle for the console
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //print board with color
    for (int row = 0; row < NUM_ROWS; row++) //building rows
    {
        for (int column = 0; column < NUM_COLS; column++) //building columns
        {
            if (theBoard[row][column] == PIVOT)
            {
                SetConsoleTextAttribute(hConsole, COLOR_DEFAULT); //coloring the * white
                cout << " " << PIVOT_SYMBOL;
            }
            else
            {
                if (theBoard[row][column] == ((row * 3) + (column + 1)))
                    SetConsoleTextAttribute(hConsole, COLOR_GREEN); //coloring correct order in green
                else

                    SetConsoleTextAttribute(hConsole, COLOR_RED); //if not in correct order its red

                cout << " " << theBoard[row][column]; //spacing
            }
        }

        cout << endl;
    }

    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT); //to control color of other text on screen
}

bool slideTile(int theBoard[NUM_ROWS][NUM_COLS], int slideDirection) {

    //Initialize star coordinates
    int pivotX=0;
    int pivotY=0;

    // Find pivot spot
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (theBoard[i][j] == PIVOT)
            {

                pivotX = i;
                pivotY = j;
            }
        }
    }

    //legal moves for all keyStrokes
    if ((slideDirection == SLIDE_UP) && (2 > pivotX))  //W
    {
        int tileToSwap = theBoard[pivotX + 1][pivotY];

        theBoard[pivotX + 1][pivotY] = PIVOT;
        theBoard[pivotX][pivotY] = tileToSwap;
        return true;
    }
    else if ((slideDirection == SLIDE_DOWN) && (0 < pivotX)) //S
    {
        int tileToSwap = theBoard[pivotX - 1][pivotY];

        theBoard[pivotX - 1][pivotY] = PIVOT;
        theBoard[pivotX][pivotY] = tileToSwap;

        return true;
    }
    else if ((slideDirection == SLIDE_RIGHT) && (0 < pivotY)) //D
    {
        int tileToSwap = theBoard[pivotX][pivotY - 1];

        theBoard[pivotX][pivotY - 1] = PIVOT;
        theBoard[pivotX][pivotY] = tileToSwap;
        return true;
    }
    else if ((slideDirection == SLIDE_LEFT) && (pivotY < 2)) //A
    {
        int tileToSwap = theBoard[pivotX][pivotY + 1];

        theBoard[pivotX][pivotY + 1] = PIVOT;
        theBoard[pivotX][pivotY] = tileToSwap;
        return true;

    }

    return false;
}

void scrambleBoard(int theBoard[NUM_ROWS][NUM_COLS]) {
    srand(time(NULL));
    //use srand(time(NULL) for random

    int slideDirection;

    while (isBoardSolved(theBoard))
    {
        for (int i = 0; i < 9000; i++)
        {
            slideDirection = rand() % 5;
            slideTile(theBoard, slideDirection); //pass random numbers to slide tile
        }
    }
}


bool isBoardSolved(int amISolved[NUM_ROWS][NUM_COLS]) {
    int solvedBoard[3][3] = { {1,2,3}, {4,5,6}, {7,8,-1} }; //[2][2] is -1 for pivot
    bool boardSolved = true;
    int row = 0;
    int col = 0;
    while (boardSolved && row <= 2)
    {
        if (solvedBoard[row][col] == amISolved[row][col])
        {
            col++;
            if (col >= 3)
            {
                row++;
                col = 0;
            }
        }
        else
            boardSolved = false;
    }
    return boardSolved;
}
