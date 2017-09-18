#include "Header.h"

void PrintField(COORD pos)
{
	SetCursor(pos);
	for (size_t i = 0; i < 17; i++)
	{
		for (size_t j = 0; j < 21; j++)
		{
			if (i % 4 == 0 || j % 5 == 0)
				cout << char(177);
			else
				cout << " ";
		}
		pos.Y++;
		SetCursor(pos);
	}
}

void SetCursor(COORD pos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos);
}

void InitArray(int field[row][cols])
{
	int index = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if(index !=15)
				field[i][j] = ++index;
		}
	}
}

void PrintArray(COORD pos, int field[row][cols])
{	
	COORD StartPos = pos;
	for (size_t i = 0; i < row; i++, pos.Y += 4)
	{
		for (size_t j = 0; j < cols; j++, pos.X += 5)
		{
			SetCursor(pos);
			cout << field[i][j];
		}
		pos.X = StartPos.X;
	}
}

void Navigation(COORD pos,int field[row][cols])
{
	//COORD cursor;
	//COORD StartPos = pos;
	//SetCursor(pos);
	while (true)
	{
		int k = _getch();
		switch (k)
		{
		case 72:
			//if (pos.Y > StartPos.Y)
			//{
			field[pos.Y][pos.X] = field[pos.Y - 1][pos.X];
			field[pos.Y - 1][pos.X] = 0;
			//cursor.X = pos.X * 5 + StartPos.X;
			//cursor.Y = pos.Y * 5 + StartPos.Y;
				/*pos.Y -= 4;
				SetCursor(pos);*/
			//}
			break;
		case 80:
			//if (pos.Y > StartPos.Y)
			//{
				pos.Y += 4;
				SetCursor(pos);
			//}
			break;
		}
	}
}