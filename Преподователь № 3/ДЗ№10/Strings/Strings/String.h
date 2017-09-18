#pragma once

typedef unsigned int uint;

class String
{
	uint m_length = 0;
	uint m_capacity = 32;
	char* m_string = nullptr;
	//дописать все поля, и все методы в private
	//реализуем один метод,а уже в остальные которые повторяются передаем тот метод который мы написали, и еще с правильными параметрами
public:
	~String();
	//
	//static String Empty()
	//{
	//	String str(" ");
	//	retunr str;
	//}
	//
	//
	String(String&& string); // Move ctor.
	String& operator=(String&& right); // Move assignment oper.
	void Swap(String& string);
	//
	String();//создает объект описывающий пустую строку(длина ее 0)
	//
	String(const uint capacity);//объект с таким размером внутреннего буфера(Пустая строка)
	//
	String(const char character, const uint count);//строка из повторения одного символа
	//
	String(const char* const string);//принимает строку(нормальную)
	//
	String(const char* const string, const uint length);//сколько символов из первых символов из этой строки взять
	//
	String(const String& string);//взять все(конструктор копирования)
	//
	String(const String& string, const uint startIndex);//принимает от индекса до конца
	//
	String(const String& string, const uint startIndex, const uint length);//создает строку на основании части другой строки

	String& operator =(const String& right);
	String& operator +=(const String& right);
	String operator +(const String& right)const;
	bool operator >(const String& right)const;
	bool operator <(const String& right)const;
	bool operator >=(const String& right)const;
	bool operator <=(const String& right)const;
	bool operator ==(const String& right)const;
	bool operator !=(const String& right)const;

	//
	void Append(const String& string);//дописать в текущую строку,все
	//
	void Append(const String& string, const uint startIndex);//дописывает в текущую строку, с какого то символа до конца
	//
	void Append(const String& string, const uint startIndex, const uint length);//дописывает в текущую строку, с какого то символа до какого-то.(В КОНЕЦ)
	//
	void Assign(const String& string);//перезаписать,присвоить всю строку(strcpy)
	//
	void Assign(const String& string, const uint startIndex);//присвоить с индекса и до конца
	//
	void Assign(const String& string, const uint startIndex, const uint length);//присвоить с индекса и до какого-то
	//
	int CompareTo(const String& string)const;//два объекта сравниваются по принцпиу меньше,больше,равно(на основании ACSII)и возвращает int -1 наш объект меньше правого, 1- наш больше чем тот который передали, 0 - одинаково
	//
	int CompareTo(const String& string, const bool ignoreCase)const;//нужно ли нам игнорировать регистр,если true игнорируем регистр функция(stricmp)
	//
	int CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length)const;//сравнение двух подстрок
	//
	int CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length, const bool ignoreCase)const;//сравнение двух подстрок с игнором регистра
	//
	bool EndsWith(const String& string)const;//заканчивается наша строка на вот такую вот строку
	//
	bool EndsWith(const String& string, const bool ignoreCase)const;//заканчивается наша строка на вот такую страку с игнорируемым регистром
	//
	bool EqualsTo(const String& string)const;//равны ли строки(0)
	//
	bool EqualsTo(const String& string, const bool ignoreCase)const;//равны ли строки(0) с учитыванием регистра
	//
	const char* GetCString()const;//должен вернуть адрес строки
	//
	uint GetLength()const;//получить длину строки
	//
	int IndexOf(const char character) const;//найти индекс первого вхождения(найти символ в строке),если нет символа -1
	//
	int IndexOf(const char character, const uint startIndex) const;//найти этот символ startIndex и до конца
	//
	int IndexOf(const char character, const uint startIndex, const uint length) const;//Найти символ по зоне поиска в строке
	//
	int IndexOf(const String& string)const;//мы ищем подстроку в нашей строке
	//
	int IndexOf(const String& string, const uint startIndex) const;
	//
	int IndexOf(const String& string, const uint startIndex, const uint length) const;
	//
	void Insert(const uint thisStartIndex, const String& string) const;//вставка строки в нашу строку
	//
	void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex);
	//---
	void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length);//вставка подстроки по индексу в нашу строку(вставка кусочка)
	//
	bool IsEmpty()const;//пустая ли строка(true если длина равно нулю)
	//
	int LastIndexOf(const char character)const;//поиск символа ведется с конца(ищем последнее вхождение строки, или символа)
	//
	int LastIndexOf(const char character, const uint startIndex)const;
	//
	int LastIndexOf(const char character, const uint startIndex, const uint length)const;
	//
	int LastIndexOf(const String& string)const;
	//
	int LastIndexOf(const String& string, const uint startIndex)const;
	//
	int LastIndexOf(const String& string, const uint startIndex, const uint length)const;
	//
	uint PadLeft(const uint totalWidth);//допиши слева символа чтобы она стала нужного размера(символы заполняются пробелом)
	//
	uint PadLeft(const uint totalWidth, const char padCharacter);//допищи слева каким - то символом чтобы она стала нужного размера,возвращается количевство дописанных символов
	//
	uint PadRight(const uint totalWidth);
	//
	uint PadRight(const uint totalWidth, const char padCharacter);
	//
	void Remove(const uint startIndex);//удалить фрагмент строки,начиная с какого то индекса и до конца и вывести новую длину строки
	//
	void Remove(const uint startIndex, const uint length);//строка склеится
	//
	void Replace(const char oldCharacter, const char newCharacter);//замена всех символов в строке на новые символы(Например:все 1 в строке на 2)
	//
	void Replace(const String& oldString, const String& newString);//заменяет подстроку на подстроку
	//
	void Reverse();//Перевернуть строку
	//
	bool StartsWith(const String& string)const;//начинается ли строка с подстроки
	//
	bool StartsWith(const String& string, const bool ignoreCase)const;//начинается ли строка с подстроки с регистром
	//
	String Substring(const uint startIndex)const;//мы хотим получить новый объект который хранил бы в себе подстроку из нашей строки
	//
	String Substring(const uint startIndex, const uint length)const;//мы хотим получить новый объект который хранил бы в себе подстроку из нашей строки(с длинной)
	//
	void ToLower();//перевод в нижней регистр всей строки
	//
	void ToUpper();//перевод в верхней регистр всей строки
	//
	uint Trim();//обрезает все пробелы с двух сторон(обрезаеют пробелы)
	//
	uint Trim(const char trimCharacter);//обрезает символы со всех сторон 
	//
	uint TrimBegin();//обрезает пробелы начала
	//
	uint TrimBegin(const char trimCharacter);//обрезает символы с начала
	//
	uint TrimEnd();//обрезает все пробелы с конца
	//
	uint TrimEnd(const char trimCharacter);//обрезает все символы с конца
};