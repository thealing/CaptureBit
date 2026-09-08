#include "MediaApplication.h"

MediaApplication::MediaApplication(bool console) : Application(console)
{
	initPlatform();
	setAccurateTimer();
	setDpiAwareness();
}

MediaApplication::~MediaApplication()
{
	uninitPlatform();
}

void MediaApplication::initPlatform()
{
	if (_status)
	{
		_status = CoInitialize(NULL);
	}
	if (_status)
	{
		_status = MFStartup(MF_VERSION);
	}
	if (!_status)
	{
		LogUtil::logComError(__FUNCTION__, _status);
	}
}

void MediaApplication::uninitPlatform()
{
	if (_status)
	{
		_status = MFShutdown();
	}
	if (_status)
	{
		CoUninitialize();
	}
	if (!_status)
	{
		LogUtil::logComError(__FUNCTION__, _status);
	}
}

void MediaApplication::setAccurateTimer()
{
	double timerResolution = Timer::setResolution(0);
	LogUtil::logDebug(L"Changed timer resolution to %g.", timerResolution);
}

void MediaApplication::setDpiAwareness()
{
	BOOL result = SetProcessDPIAware();
	if (result == FALSE)
	{
		LogUtil::logWarning(L"Failed to set DPI awareness.");
	}
}
