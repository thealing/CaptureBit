#include "Time.h"

TimeFrame* TimeFrame::getInstance()
{
	return &_instance;
}

LARGE_INTEGER TimeFrame::getFrequency() const
{
	return _frequency;
}

LARGE_INTEGER TimeFrame::getStartCounter() const
{
	return _startCounter;
}

TimeFrame::TimeFrame()
{
	QueryPerformanceFrequency(&_frequency);
	QueryPerformanceCounter(&_startCounter);
}

TimeFrame TimeFrame::_instance;

double getTime()
{
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	TimeFrame* timeFrame = TimeFrame::getInstance();
	LARGE_INTEGER frequency = timeFrame->getFrequency();
	LARGE_INTEGER startCounter = timeFrame->getStartCounter();
	return (double)(counter.QuadPart - startCounter.QuadPart) / (double)frequency.QuadPart;
}
