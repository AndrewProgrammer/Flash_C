#pragma once 
#include "ArgumentException.h"
#include "String.h"
class ArgumentIsNullptrException : public ArgumentException
{
private:
	String wrong_index,wrond_index2;
public:
	ArgumentIsNullptrException(String & s)
	{
		wrong_index = s;
	}
	ArgumentIsNullptrException(const String & s)
	{
		wrong_index = s;
	}
	ArgumentIsNullptrException(const String & oldstr, const String & newstr)
	{
		wrong_index = oldstr;
		wrong_index = newstr;
	}
};