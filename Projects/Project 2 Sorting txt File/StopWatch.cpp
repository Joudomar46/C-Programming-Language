#include "StopWatch.h"

StopWatch::StopWatch()
{
	beginTime = 0;
	endTime = 0;
	elapsedTime = 0;
	isStart = false;
	isStop = true;
}

bool StopWatch::Start()
{

	if (this->isStop) {
		this->beginTime = clock();
		this->isStart = true;
		this->isStop = false;
		return true;
	}
	else
	{
		cout << "ERROR: STOP did not run correctly. Incorrect time displayed" << endl;
		return false;
	}
}

bool StopWatch::Stop()
{

	if (IsTicking()) {
		this->endTime = clock();
		this->isStart = false;
		this->isStop = true;
		return true;
	}
	else
	{
		cout << "ERROR: START did not run correctly. Incorrect time displayed" << endl;
		return false;
	}
}

bool StopWatch::IsTicking()
{

	if (this->isStart) {
		return true;
	}
	return false;
}

void StopWatch::DisplayTimerInfo()
{
	double long timer = 0;
	this->elapsedTime = this->endTime - this->beginTime;
	timer = (this->elapsedTime / (CLOCKS_PER_SEC /1000));
	cout  << timer << " milliseconds" << endl;
}
