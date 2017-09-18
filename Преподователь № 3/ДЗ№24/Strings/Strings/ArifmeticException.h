#pragma once
#include "ArgumentException.h"
#include "String.h"
class ArifmeticException : public Exception
{
private:
	String WrongRVForOperator;
public:
	ArifmeticException(const String & RVO)
	{
		WrongRVForOperator = RVO;
	}
	ArifmeticException(const String && RVO)
	{
		WrongRVForOperator = RVO;
	}
};