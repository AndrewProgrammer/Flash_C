#include <iostream>
#include <Windows.h>

/*
	���������� �������� � ������ �������������� ������ � ���������, ��������� � ��������� ������
	���������.

	��� ������ �������������� ������ ���������� ���� ������������ � ��������� ������� setlocale.
	Ÿ ������������� ������ �� ����� ������������ ��������� � ������ ������ (output buffer) � 
	��������� DOS-866 (������� ������������ ��-��������� � �������) �� ��������� Windows-1251,
	������� ��-��������� ������������ � ��������� Visual Studio.
*/

using namespace std;

char *ConvertTo1251 (char *text);

void main ()
{

	/*
		���� ������� setlocale �� ������������, �� �������� � ������ � ����������� ������� ������ �� ���������.
		�.�. � ������ ����� (input buffer) �� ��������� ��������� DOS-866 � ���������� � ������ ������.
		�.�. ������ ����� � DOS-866 � ������� � ��� �� ���������.
	*/

	char str[80] {};
	cout << "Enter cyrillic text: ";
	cin.getline (str, 80);

	cout << "Your text: " << str << endl;
	 
	cout << "\n========================================\n";
	/*
		������, ���� ��������� setlocale ����������� ��������� � ������ ������, �� ����� ����� �������, 
		�.�. � ������ ������ ������ ��������� Windows-1251, � � ������ ����� ��� � �������� .866

		� �����: ������ ����� � 866 ���������, � ������� � 1251.
	*/
	cout << "\nAfter setlocale: \n";

	setlocale (LC_ALL, "Russian");

	cout << "Enter cyrillic text: ";
	cin.getline (str, 80);

	cout << "Your text: " << str << endl;


	/*
		�������: ������������ ������� ��� ����������� ���������� ������������� ������ (������� � ��������� 866)
		� ��������� (������� �������� � ������ ������) Windows-1251.
	*/

	char *convertedString = ConvertTo1251 (str);
	cout << "Converted text: " << convertedString << endl;
	

	delete[] convertedString;
}

char *ConvertTo1251 (char *text)
{
	if (!text)
		return nullptr;

	/*
		������� ����� ������������ ������ ��� ������ ����� ��� ����� ������, + 1 ������ ��� ����-������� (\0).
	*/
	char *newString = new char[strlen (text) + 1];

	/*
		���������� Windows API ������� �� header-����� Windows.h:
			int OemToCharA (const char *src, char *destination);
			
			������������ ������ �� ������� src � ��������� 1251 � ���������� � � ������ destination.
			
			���������� 0 ������ �����, ����� src � destination ���������.
			� ��������� ������� ���������� �� ����.

			�������: https://msdn.microsoft.com/en-us/library/windows/desktop/ms647493(v=vs.85).aspx

	*/
	OemToCharA (text, newString);
	return newString;
}

/*
	�������������� ��������� �������� ������������� �������, ������� ������������� ��������� ��-����������� �� ������ �����:
		SetConsoleCP			- ������������� ��������� ��� �������� ������ (����� �����, input buffer)
	�
		SetConsoleOutputCP		- ������������� ��������� ��� ������ ������ (output buffer)

	���������� ����� �������: ������������� ������� ������������ ������, � ������� �� Lucida Console
*/