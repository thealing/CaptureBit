#pragma once

struct TimeFrame
{
public:

	static TimeFrame* getInstance();

	LARGE_INTEGER getFrequency() const;

	LARGE_INTEGER getStartCounter() const;

private:

	TimeFrame();

private:

	static TimeFrame _instance;

	LARGE_INTEGER _frequency;
	LARGE_INTEGER _startCounter;
};

double getTime();
