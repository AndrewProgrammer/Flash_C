#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
char main_color[] = "color ##";
int snake_size, change_x, change_y, coordinates_x[1000], coordinates_y[1000], food_x = -1, food_y = -1;
char symbol, a[1000][1000];
const int N = 13, M = 17, INTERVAL = 200;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
enum Keys{ UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27 };
void SetCur(int X, int Y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = X;
	pos.Y = Y;
	SetConsoleCursorPosition(h, pos);
}
void change_color()
{
	char x = rand() % 16, y = rand() % 16;
	if (x == y)
		y++;
	y %= 16;
	if (x > 9)
		x += 'A' - 10;
	else x += '0';
	if (y > 9)
		y += 'A' - 10;
	else y += '0';
	main_color[6] = x;
	main_color[7] = y;
	system(main_color);
}
void snakedir()
{
	symbol = _getch();
	switch (symbol)
	{
	case 'w':
	case 'W':
	case UP:
		if (change_x != 1 || change_y != 0)
		{
			change_x = -1;
			change_y = 0;
		}
		break;
	case 'a':
	case 'A':
	case LEFT:
		if (change_x != 0 || change_y != 1)
		{
			change_x = 0;
			change_y = -1;
		}
		break;
	case 's':
	case 'S':
	case DOWN:
		if (change_x != -1 || change_y != 0)
		{
			change_x = 1;
			change_y = 0;
		}
		break;
	case 'd':
	case 'D':
	case RIGHT:
		if (change_x != 0 || change_y != -1)
		{
			change_x = 0;
			change_y = 1;
		}
		break;
	case 32:
		change_color();
		break;
	default: ESC;
	}
}
void show_table()
{
	system("cls");
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
			{
				a[i][j] = 1;
			}
			if (a[i][j] == 1)
			{
				SetConsoleTextAttribute(h, 15);
				cout << char(177);
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}
void clear_snake_on_table()
{
	for (int i = 1; i <= snake_size; i++)
		a[coordinates_x[i]][coordinates_y[i]] = ' ';
}
void showsnake()
{
	if (change_x == 1 && change_y == 0)a[coordinates_x[1]][coordinates_y[1]] = 'v';
	if (change_x == -1 && change_y == 0)a[coordinates_x[1]][coordinates_y[1]] = '^';
	if (change_x == 0 && change_y == 1)a[coordinates_x[1]][coordinates_y[1]] = '>';
	if (change_x == 0 && change_y == -1)a[coordinates_x[1]][coordinates_y[1]] = '<';
	for (int i = 2; i <= snake_size; i++)
	{
		a[coordinates_x[i]][coordinates_y[i]] = '@';
	}
}
void Newgame()
{
	system("cls");
	cout << "Press ESC goto menu" << endl;
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}
}
void LoadGame()
{
	system("cls");
	cout << "Press ESC goto menu" << endl;
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}
}
void Scores()
{
	system("cls");
	cout << "Press ESC goto menu" << endl;
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}
}
void Settings()
{
	system("cls");
	cout << "Press ESC goto menu" << endl;
	int code = 1;
	while (code != 27)
	{
		code = _getch();
	}
}
void Exit()
{
	system("cls");
	COORD c = { 50, 15 };
	SetConsoleTextAttribute(h, 14);
	SetConsoleCursorPosition(h, c);
	cout << "Thank you for playing\n						  Bye i have a great time!" << endl;
	system("pause");
	exit(0);
}

int MenuPrc()
{
	int step = 2;
	int X = 50, Y = 16;
	int PosX = X, PosY = Y;
	int choose = 1;
	SetCur(X, Y);
	cout << ">>>";

	int code = 0;
	while (code != 13)
	{
		code = _getch();
		switch (code)
		{
		case 72:
			if (PosY != Y)
			{
				SetCur(PosX, PosY);
				cout << "   ";
				PosY -= step;
				SetCur(PosX, PosY);
				cout << ">>>";
				choose--;
			}
			break;
		case 80:
			if (PosY != Y + 4 * step)
			{
				SetCur(PosX, PosY);
				cout << "   ";
				PosY += step;
				SetCur(PosX, PosY);
				cout << ">>>";
				choose++;
			}
			break;
		}
	}
	return choose;
}

void PrintMenuList()
{
	SetCur(55, 16);
	cout << "New game";
	SetCur(55, 18);
	cout << "Load game";
	SetCur(55, 20);
	cout << " Scores ";
	SetCur(55, 22);
	cout << "Settings";
	SetCur(55, 24);
	cout << "  Exit  ";
}

void PrintLogo()
{
	system("mode con cols=120 lines=50");
	cout << R"XXX( 
           .----------------.  .-----------------. .----------------.  .----------------.  .----------------. 
          | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
          | |    _______   | || | ____  _____  | || |      __      | || |  ___  ____   | || |  _________   | |
          | |   /  ___  |  | || ||_   \|_   _| | || |     /  \     | || | |_  ||_  _|  | || | |_   ___  |  | |
          | |  |  (__ \_|  | || |  |   \ | |   | || |    / /\ \    | || |   | |_/ /    | || |   | |_  \_|  | |
          | |   '.___`-.   | || |  | |\ \| |   | || |   / ____ \   | || |   |  __'.    | || |   |  _|  _   | |
          | |  |`\____) |  | || | _| |_\   |_  | || | _/ /    \ \_ | || |  _| |  \ \_  | || |  _| |___/ |  | |
          | |  |_______.'  | || ||_____|\____| | || ||____|  |____|| || | |____||____| | || | |_________|  | |
          | |              | || |              | || |              | || |              | || |              | |
          | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
           '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
)XXX";
}
void PrintLogo2()
{
	COORD c1 = { 20, 28 };
	SetConsoleCursorPosition(h, c1);
	cout << R"XXX(                                                                                                                                                                                                                                                                                           
                             +-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+-+
                             |C|r|e|a|t|e|d| |b|y| |A|n|d|r|e|w| |L|y|k|i|a|n|c|h|i|k|o|v|
                             +-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+-+-+ )XXX";

}
void main()
{
	srand(time(0));
	while (1)
	{
		SetConsoleTextAttribute(h, 10);
		PrintLogo();
		PrintLogo2();
		PrintMenuList();
		void(*FncArr[5])() = { Newgame, LoadGame, Scores, Settings, Exit };
		unsigned int choose = MenuPrc();
		choose--;
		choose %= 5;
		cout << choose;
		FncArr[choose]();
		/*switch (MenuPrc())
		{
		case 1:
		system("cls");
		GamePrc();
		break;
		case 2:
		system("cls");
		GamePrc();
		break;
		case 3:
		system("cls");
		GamePrc();
		break;
		case 4:
		exit(0);
		break;
		}*/
	}
	system("pause");
}