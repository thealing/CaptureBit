#pragma once

template <typename Object>
class ComPointer : NonCopyable
{
public:

	ComPointer();

	~ComPointer();

	Object* operator->() const;

	Object& operator*() const;

	operator Object*() const;

	Object** operator&();

private:

	Object* _object;
};
