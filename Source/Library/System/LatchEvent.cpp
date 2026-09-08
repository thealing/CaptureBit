#include "LatchEvent.h"

LatchEvent::LatchEvent()
{
	_handle = CreateEvent(NULL, TRUE, FALSE, NULL);
}

LatchEvent::~LatchEvent()
{
	CloseHandle(_handle);
}

bool LatchEvent::set()
{
	DWORD result = WaitForSingleObject(_handle, 0);
	if (result == WAIT_TIMEOUT)
	{
		SetEvent(_handle);
		return true;
	}
	return false;
}

void LatchEvent::wait() const
{
	WaitForSingleObject(_handle, INFINITE);
}
