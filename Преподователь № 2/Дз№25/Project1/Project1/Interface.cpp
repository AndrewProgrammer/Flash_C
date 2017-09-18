#include "Header.h"


int field[3][3]{};
COORD pole{ 0, 0 };
bool is_player = true;


void PrintField(COORD pos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos);
	for (size_t i = 0; i <13; i++)
	{
		for (size_t j = 0; j < 13; j++)
		{
			if (i % 4 == 0 || j % 4 == 0)
				cout << char(177);
			else 
				cout << " ";
		}
		pos.Y++;
		SetConsoleCursorPosition(h, pos);
	}
}

void GamePrc(COORD pos)
{
	COORD StartPos = pos;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, pos);
	while (true)
	{	
		int k = 0;
		//if (_getch() == 224)
			k = _getch();
		switch (k)
		{
		case 72:
			if (pos.Y > StartPos.Y)
			{
				pos.Y -= 4;
				pole.Y--;
			}
			SetConsoleCursorPosition(h, pos);
			break;
		case 80:
			if (pos.Y< StartPos.Y + 8)
			{
				pos.Y += 4;
				pole.Y++;
			}
			SetConsoleCursorPosition(h, pos);
			break;
		case 75:
			if (pos.X > StartPos.X)
			{
				pos.X -= 4;
				pole.X--;
			}
			SetConsoleCursorPosition(h, pos);
			break;
		case 77:
			if (pos.X < StartPos.X + 8)
			{
				pos.X += 4;
				pole.X++;
			}
			SetConsoleCursorPosition(h, pos);
			break;
		case 13:
			Insert();
			break;
		}
	}
}

void Insert()
{
	if (field[pole.Y][pole.X] == 0)
	{
		if (is_player)
		{
			field[pole.Y][pole.X] = 1;
			cout << "X";
		}
		else
		{
			/*field[pole.Y][pole.X] = 2;
			cout << "O";*/
			Computer();
		}
		is_player = !is_player;
	}
}

void Computer()
{
	int Y = rand() % 3;
	int X = rand() % 3;
	if (field[Y][X] == 0)
	{
		field[Y][X] = 2;
		cout << "O";
	}
	else
		Computer();

}
