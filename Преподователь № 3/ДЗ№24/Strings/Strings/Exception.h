#pragma once
#include "String.h"
#include <string>
#include <iostream>
using namespace std;
class Exception
{
public:
	string ErrorOutOfRange = " �� ����� �� �������� ���������� ��������!";
	string ErrorWithArgument = " ��� ������ �������� ��������!";
	string ErrorNullptr = "������ ������� �� ����� ����� ����� �������� ���������, ������!";
	string ErrorArifmetic = "������������ ����� �������� ��� ��������� ��� ������� ������������ ��������!";
};