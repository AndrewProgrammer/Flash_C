#include <stdio.h> 
#include <conio.h> 
#include <iostream>
using namespace std;
void main()
{
	cout << "Vce cymvoli ASCII\n";
	char p[300];
	gets_s(p);
	int i = atoi(p);
	putc(i, stdout);
}
