#include "Header.h"



void main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{ 10, 12 };
	//srand(time(0));	
	//int mas[size];
	//InitializeArray(mas, size);
	//PrintArray(mas, size);
	//int mas2[row][cols];
	//InitializeArray(mas2);
	//cout << endl << endl;
	//PrintArray(mas2); 

	PrintField(pos);
	pos.X += 2;
	pos.Y += 2;
	
	GamePrc(pos);


	system("pause");

}