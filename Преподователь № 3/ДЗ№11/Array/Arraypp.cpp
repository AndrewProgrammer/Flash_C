#include <iostream>
#include "Array.h"
#include <ctime>
using namespace std;
Array NRVO()
{
	Array a;

	return a;
}

Array Create1()
{
	Array result;

	return result;
}

Array* Create2()
{
	Array* result = new Array();

	return result;
}

void Foo(Array& ar)
{
	cout << "Lvalue reference" << endl;
}

void Foo(Array&& ar)
{
	cout << "Rvalue reference" << endl;
}
void main()
{
	//srand(time(0));
	Array arr;
	//arr.PrintArr(); cout << endl;
	//arr.Add(10); cout << endl;
	//arr.PrintArr(); cout << endl;
	//arr.Remove(7);  // по значению
	//arr.PrintArr(); cout << endl;
	//arr.RemoveAt(2);  // по индексу
	//arr.PrintArr(); cout << endl;
	//cout<<arr.Contains(5); cout << endl;
	//cout << arr[-5] << endl;
	//if (arr[3] == arr[2]) cout << "true" << endl; else cout << "false" << endl;
	//arr[3] = arr[2]; cout << "arr[3]" << arr[3];
	Array s5(Create1());
	s5 = Create1();

	Array s6(Create1());
	Array s7 = move(s6);
	s7 = s5;

}