#include "User.h"
#include <cstdio>
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "ru");
	User f;
	f.WriteInFile();
	f.ReadFile();
}