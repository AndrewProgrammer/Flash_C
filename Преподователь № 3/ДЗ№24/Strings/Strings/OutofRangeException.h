#pragma once
#include "Exception.h"
#include "String.h"
class OutOfRangeException : public Exception
{
private:
	int wrong_znach,wrong_start,wrong_end;
	char wrong_char;
public:
	OutOfRangeException(const unsigned int lenght)
	{
		wrong_znach = lenght;
	}
	OutOfRangeException(const int lenght)
	{
		wrong_znach = lenght;
	}
	OutOfRangeException(const char character)
	{
		wrong_char = character;
	}
	OutOfRangeException(const char character, const unsigned int lenght)
	{
		wrong_znach = lenght;
		wrong_char = character;
	}
	OutOfRangeException(const unsigned int lenght,const char character)
	{
		wrong_znach = lenght;
		wrong_char = character;
	}
	OutOfRangeException(const int startIndex, const int lastIndex, const int lenght, const int count)
	{
		wrong_znach = count;
		wrong_znach = lenght;
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const unsigned int startIndex, const unsigned int lastIndex, const unsigned int lenght, const unsigned int count)
	{
		wrong_znach = count;
		wrong_znach = lenght;
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const  int startIndex, const  int lastIndex, const  int lenght)
	{
		wrong_znach = lenght;
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const unsigned int startIndex, const unsigned int lastIndex, const unsigned int lenght)
	{
		wrong_znach = lenght;
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const  int startIndex, const  int lastIndex)
	{
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const unsigned int startIndex, const unsigned int lastIndex)
	{
		wrong_start = startIndex;
		wrong_end = lastIndex;
	}
	OutOfRangeException(const char character, const unsigned int startIndex, const unsigned int lenght)
	{
		wrong_start = startIndex;
		wrong_znach = lenght;
		wrong_char = character;
	}
	OutOfRangeException(const char character, const  int startIndex, const  int lenght)
	{
		wrong_start = startIndex;
		wrong_znach = lenght;
		wrong_char = character;
	}
};