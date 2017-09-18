#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// ������������� � ���������: http://www.cplusplus.com/doc/tutorial/other_data_types/
// ������: Enumerated types (enum) � Enumerated types with enum class

enum keys { W = 87, w = 119, A = 65, a = 97, S = 83, s = 115, d = 100, D = 68, Esc = 27, Enter = 13,
			UpArrow = 72, DownArrow = 80, LeftArrow = 75, RightArrow = 77};

void main ()
{
	/*
		��� ��������� ������� �� ���������� ������������ ������� _getch. (��. ������ 11)
		��� ������� ���������� ��� ������� �������, ��� ���� ������������� ���������� ���������, �� ��� ���, ���� ������� �� ����� ������.
		� ����� ����� �������, �� ������� ������ �� �����.
		��� ���������-�������� ������ - �� ��������� ������ - ������������ ASCII ���.
	*/
	
	int code = 0;
	bool looping = true;

	cout << "Test WASD keys. Press WASD keys to see action, or any other key to stop!" << endl;
	while (looping)
	{
		code = _getch ();
		switch (code)
		{
			case W:
			case w:
				cout << "Up" << endl;
				break;
			case A:
			case a:
				cout << "Left" << endl;
				break;
			case S:
			case s:
				cout << "Down" << endl;
				break;
			case d:
			case D:
				cout << "Right" << endl;
				break;
			default:
				looping = false;
				break;
		}
	}

	looping = true;

	/*
		���� � ���������-��������� ��������� �� ������, �� � ���������� �� �� ��� ������. 
		������, � ��������� ��������� Escape, Enter ���� �� ������. �� ���� ���� ����� ������ 32 (�����������) ������� ASCII.
		��������, Esc - ��� 27, � Enter - 13.

		�� ��� � ��������� ��������� �������, F1-F12 �������� ���� �������.
		�������� � ���, ��� �� ���� ���-�� �������� �� ��������� ��������, �.�. �� ���� ������������.
		���� ������������ ����� �����-�� ����.������� (�������, ��� F1-F12) ������� _getch ������ ���� 224 ���� 0.
		��� ����, ����� ������, ��� �� ������� ��������� ���� ������ ���������� ����� ������� ������� _getch ��� ���.

	
	*/
	system ("cls");
	cout << "Testing special keys. Press Esc to stop." << endl;
	while (looping)
	{
		code = _getch ();
		
		

		if (code == 0 || code == 224) // ���� ���� ������ ����. �������, �� �������� _getch ��� ���
		{
			code = _getch ();

			// �.�. ���� ���������-�������� � ����.������ �����������, switch ��������� ������ if, ����� �� �������� ����������� �����������
			// �� ASCII �������
			switch (code)
			{
				case UpArrow:
					cout << "Up" << endl;
					break;
				case DownArrow:
					cout << "Down" << endl;
					break;
				case LeftArrow:
					cout << "Left" << endl;
					break;
				case RightArrow:
					cout << "Right" << endl;
					break;
			}


			// ���������� �������� � �������� ��� ������� ����� "�" � ������� ��������� .866, �.�. ��� ����� ��� 224
			// � ����� ����� ������� ��������, �� �.�. ��� �� ����. �������, �� ������� ���� � ������ �� �����
			// � ����� _getch ��������� ��������� ��� �������� �������. ���������� ����� ��������� �����������
			// ������ ��� �������� ����� ��� ������ ������� _kbhit() �� conio.h
			// ��� ������� ���������, ���� �� � ������ ��� ������� �������. ���� �� - ���������� ��������� ��������, ���� ��� - 0.
			// � � ������� ����� ������ ������ ��������. ����� ����, ��� �������, ����� �� ����� ������������� ���������� ��������� ��� �������� ������� �������.
			// ���������� � _kbhit: https://msdn.microsoft.com/ru-ru/library/58w7c94c.aspx
		}
		else if (code == Esc)
			looping = false;

	}
	
	// � ������������ ����� Windows.h ���������� �������� �������� ������� Sleep
	// ������� Sleep ������������� ��������� �� ������������ ���-�� ����������
	Sleep (2000); // ����������� ������������� ����� � 2 �������, � ����� ����������
	cout << "After 2sec delay\n";
}