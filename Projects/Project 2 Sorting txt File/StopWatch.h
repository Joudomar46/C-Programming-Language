
// CLASS SPECIFICATION 
#ifndef __Stopwatch__ 
#define __Stopwatch__ 

#include <iostream>
#include <time.h>
#include <conio.h>
#include <iomanip>      // std::setprecision
using namespace std;

class StopWatch {

private:
	// DATA MEMBERS 
	clock_t beginTime;		// really a 'long int'
	clock_t endTime;
	clock_t elapsedTime;
	bool isStart;
	bool isStop;

public:
	// CONSTRUCTOR(S) 
	StopWatch();

	// OPERATIONS 
	bool Start();
	bool Stop();
	bool IsTicking();

	// DISPLAY METHODS 
	void DisplayTimerInfo();


};

#endif

