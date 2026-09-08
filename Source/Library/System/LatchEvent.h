#pragma once

class LatchEvent : NonCopyable
{
public:

	LatchEvent();

	~LatchEvent();

	bool set();

	void wait() const;

private:

	HANDLE _handle;
};

