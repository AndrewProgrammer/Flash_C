#include <iostream>
#include <Windows.h>

/*
	Существует проблема с вводом кириллического текста в программу, связанная с различием таблиц
	кодировки.

	Для вывода кириллического текста достаточно было использовать в программе функцию setlocale.
	Её использование влечет за собой переключение кодировки в буфере вывода (output buffer) с 
	кодировки DOS-866 (которая используется по-умолчанию в консоли) на кодировку Windows-1251,
	которая по-умолчанию используется в редакторе Visual Studio.
*/

using namespace std;

char *ConvertTo1251 (char *text);

void main ()
{

	/*
		Если функцию setlocale не использовать, то проблемы с вводом и последующим выводом текста не возникнет.
		Т.к. в буфере ввода (input buffer) по умолчанию кодировка DOS-866 и аналогично в буфере вывода.
		Т.е. вводим текст в DOS-866 и выводим в той же кодировке.
	*/

	char str[80] {};
	cout << "Enter cyrillic text: ";
	cin.getline (str, 80);

	cout << "Your text: " << str << endl;
	 
	cout << "\n========================================\n";
	/*
		Однако, если используя setlocale переключить кодировку в буфере вывода, то текст будет искажен, 
		т.к. в буфере вывода теперь кодировка Windows-1251, а в буфере ввода так и осталась .866

		В итоге: вводим текст в 866 кодировке, а выводим в 1251.
	*/
	cout << "\nAfter setlocale: \n";

	setlocale (LC_ALL, "Russian");

	cout << "Enter cyrillic text: ";
	cin.getline (str, 80);

	cout << "Your text: " << str << endl;


	/*
		Решение: использовать функцию для конвертации введенного пользователем текста (который в кодировке 866)
		в кодировку (которая включена в буфере вывода) Windows-1251.
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
		Создаем новый динамический массив под строку четко под длину строки, + 1 символ для нуль-символа (\0).
	*/
	char *newString = new char[strlen (text) + 1];

	/*
		Используем Windows API функцию из header-файла Windows.h:
			int OemToCharA (const char *src, char *destination);
			
			Конвертирует строку из массива src в кодировку 1251 и записывает её в массив destination.
			
			Возвращает 0 только тогда, когда src и destination совпадают.
			В остальных случаях возвращает не ноль.

			Справка: https://msdn.microsoft.com/en-us/library/windows/desktop/ms647493(v=vs.85).aspx

	*/
	OemToCharA (text, newString);
	return newString;
}

/*
	Альтернативным вариантом является использование функций, которые устанавливают кодировки по-отдельности на каждый буфер:
		SetConsoleCP			- устанавливает кодировку для входного буфера (буфер ввода, input buffer)
	и
		SetConsoleOutputCP		- устанавливает кодировку для буфера вывода (output buffer)

	Недостаток этого подхода: необходимость ручного переключения шрифта, к примеру на Lucida Console
*/