#include <iostream>
#include "Array.h"
#include <ctime>
using namespace std;

void main()
{
	setlocale(0, "ru");
	srand(time(0));
	Array<int> arr;
	cout << "Количество элементов: " << endl;
	for (auto x : arr)
	{
		cout << x;
	}
	arr.Add(10); cout << endl;
	arr.PrintArr(); cout << endl;
	arr.Remove(7);  // по значению
	arr.PrintArr(); cout << endl;
	arr.RemoveAt(2);  // по индексу
	arr.PrintArr(); cout << endl;
	cout<<arr.Contains(5); cout << endl;
	cout << arr[1] << endl;
	if (arr[1] == arr[2]) 
		cout << "true" << endl; 
	else cout << "false" << endl;
	arr[1] = arr[2]; cout << "arr[4] " << arr[1] << endl; 
}	