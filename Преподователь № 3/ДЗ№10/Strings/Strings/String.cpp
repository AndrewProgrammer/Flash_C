#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <type_traits>
using namespace std;

String::String(String&& string)
{
	// Move!!!
	m_capacity = string.m_capacity;
	m_length = string.m_length;
	m_string = string.m_string;

	string.m_capacity = 0u;
	string.m_length = 0u;
	string.m_string = nullptr; //!!!!!!
	cout << "Move constructor" << endl;
}

String::~String()
{
	delete[] m_string;
	cout << "Destructor" << endl;
}

String& String::operator=(const String& right)
{
	if (this != &right)
	{
		String(right).Swap(*this);
	}
	cout << "Assignment operator" << endl;

	return *this;
}

String& String::operator=(String&& right)
{
	if (this != &right)
	{
		String(move(right)).Swap(*this);
	}
	cout << "Move assignment operator" << endl;

	return *this;
}

void String::Swap(String& string)
{
	swap(m_capacity, string.m_capacity);
	swap(m_length, string.m_length);
	swap(m_string, string.m_string);
}
String String::operator +(const String& right)const
{
	String Sum;
	Sum.Append(right);
	return Sum;
	/*String Sum(this->m_string);ВСЕ ВЕРНО
	Sum += right;
	return Sum; */
}
String& String::operator+=(const String& right)
{
	Append(right);
	return *this;
}
bool String::operator <(const String& right)const
{
	return CompareTo(m_string, right.m_string) < 0;
}
bool String::operator<=(const String& right) const
{
	return CompareTo(m_string, right.m_string) <= 0;
}
bool String::operator>(const String& right) const
{
	return CompareTo(m_string, right.m_string) > 0;
}
bool String::operator>=(const String& right) const
{
	return CompareTo(m_string, right.m_string) >= 0;
}
bool String::operator==(const String& right) const
{
	return CompareTo(m_string, right.m_string) == 0;
}
bool String::operator!=(const String& right) const
{
	return CompareTo(m_string, right.m_string) != 0;
}
const char*String::GetCString() const
{
	return m_string;
}
uint String::GetLength() const
{
	return m_length;
}

String::String()
{
	m_string = new char[50];
	m_string[0] = '\0';
}

String::String(const uint capacity)
{
	m_capacity = capacity;
	m_string = new char[m_capacity];
	m_string[0] = '\0';
}

String::String(const char character, const uint count)
{
	m_length = count;
	m_capacity = count + 1;
	m_string = new char[m_capacity];
	for (int i = 0; i < m_length; i++)
	{
		m_string[i] = character;
	}
	m_string[m_length] = '\0';
}

String::String(const char* const string) :String(string, strlen(string)){}

String::String(const char* const string, const uint length)
{
	m_length = length;
	m_capacity = m_length + 1;
	m_string = new char[m_capacity];
	strncpy(m_string, string, m_length);
	m_string[m_length] = '\0';
}

//все верно
//String::String(const String& string)
//{
//	m_length = string.m_length;
//	m_capacity = m_length + 1;
//	m_string = new char[m_capacity];
//	strcpy(m_string, string.m_string);
//}
//делегирование

String::String(const String& string) :String(string, 0, string.m_length){}

String::String(const String& string, const uint startIndex) : String(string, startIndex, string.m_length - startIndex){}

String::String(const String& string, const uint startIndex, const uint length)
{
	m_length = length;
	m_capacity = m_length + 1;
	m_string = new char[m_capacity];
	strncpy_s(m_string, m_capacity, &string.m_string[startIndex], length);
}

//все верно
//void String::Append(const String& string)
//{
//	char * temp = new char[m_length + string.m_length + 1];
//	for (int i = 0; i < m_length; i++)
//	{
//		temp[i] = m_string[i];
//	}
//	for (int j = 0; j < string.m_length; j++)
//	{
//		temp[m_length + j] = string.m_string[j];
//	}
//	temp[m_length + string.m_length] = 0;
//	delete[] m_string;
//	m_string = temp;
//	m_length += string.m_length;
//}

void String::Append(const String& string)
{
	Append(string, 0, string.m_length);
}

void String::Append(const String& string, const uint startIndex)
{
	Append(string, startIndex, string.m_length - startIndex);
}

void String::Append(const String& string, const uint startIndex, const uint length)
{
	m_length += length;
	m_capacity = m_length + 1;
	char * temp = new char[m_capacity];
	strcpy_s(temp, m_capacity, m_string);
	strncat_s(temp, m_capacity, &string.m_string[startIndex], length);
	delete[]m_string;
	m_string = temp;
}
void String::Assign(const String& string)
{
	Assign(string, 0, string.m_length);
}
void String::Assign(const String& string, const uint startIndex)
{
	Assign(string, startIndex, string.m_length - startIndex);
}
void  String::Assign(const String& string, const uint startIndex, const uint length)
{
	m_length = length;
	m_capacity = m_length + 1;
	char * temp = new char[m_capacity];
	strncpy_s(temp, m_capacity, &string.m_string[startIndex], length);
	delete[]m_string;
	m_string = temp;
}
bool String::IsEmpty() const
{
	if (m_string == 0)
	{
		return true;
	}
	else return false;
}

int String::CompareTo(const String& string) const
{
	return CompareTo(string, false);
}
int String::CompareTo(const String& string, const bool ignoreCase) const
{
	if (ignoreCase == true)
	{
		return _stricmp(m_string, string.m_string);
	}
	else
	{
		return strcmp(m_string, string.m_string);
	}
}
int String::CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length) const
{
	return CompareTo(thisStartIndex, string, otherStartIndex, length);
}
int String::CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length, const bool ignoreCase) const
{
	if (ignoreCase == true)
	{
		return _strnicmp(&m_string[thisStartIndex], &string.m_string[otherStartIndex], length);
	}
	else return strncmp(&m_string[thisStartIndex], &string.m_string[otherStartIndex], length);
}
bool String::EndsWith(const String& string) const
{
	return strcmp(&m_string[m_length - string.m_length], string.m_string);
}
bool String::EndsWith(const String& string, const bool ignoreCase) const
{
	if (ignoreCase == true)
	{
		return strcmp(&m_string[m_length - string.m_length], string.m_string);
	}
	else return strncmp(&m_string[m_length - string.m_length], string.m_string, false);
}
bool String::EqualsTo(const String& string) const
{
	return strcmp(&m_string[m_length - string.m_length], string.m_string);
}
bool String::EqualsTo(const String& string, const bool ignoreCase) const
{
	if (ignoreCase == true)
	{
		return strcmp(&m_string[m_length - string.m_length], string.m_string);
	}
	else return strncmp(&m_string[m_length - string.m_length], string.m_string, false);
}
int String::IndexOf(const char character) const
{
	return IndexOf(character, 0, m_length);
}

int String::IndexOf(const char character, const uint startIndex) const
{
	return IndexOf(character, startIndex, m_length - startIndex);
}

int String::IndexOf(const char character, const uint startIndex, const uint length) const
{
	char * first = strchr(&m_string[startIndex], character);
	return first == nullptr ? -1 : ((first - m_string) > length ? -1 : first - m_string);
}

int String::IndexOf(const String& string) const
{
	return IndexOf(string, 0, m_length);
}

int String::IndexOf(const String& string, const uint startIndex) const
{
	return IndexOf(string, startIndex, m_length - startIndex);
}

int String::IndexOf(const String& string, const uint startIndex, const uint length) const
{
	char * first = strstr(&m_string[startIndex], string.m_string);
	return  first == nullptr ? -1 : ((first - m_string) > length ? -1 : first - m_string);
}
void String::Insert(const uint thisStartIndex, const String& string) const
{
	return Insert(0, string);
}
void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex)
{
	return Insert(0, string, 0);
}
//void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length)
//{
//	return strncat(string.m_string(m_length - thisStartIndex],m_string,length);
//}
int String::LastIndexOf(const char character)const
{
	return LastIndexOf(character, 0, m_length);
}

int String::LastIndexOf(const char character, const uint startIndex) const
{
	return LastIndexOf(character, startIndex, m_length - startIndex);
}

int String::LastIndexOf(const char character, const uint startIndex, const uint length) const
{
	char * last = strrchr(&m_string[startIndex], character);
	return last == nullptr ? -1 : ((last - m_string) > length ? -1 : last - m_string);
}

int String::LastIndexOf(const String& string) const
{
	return LastIndexOf(string, 0, m_length);
}

int String::LastIndexOf(const String& string, const uint startIndex) const
{
	return LastIndexOf(string, startIndex, m_length - startIndex);
}

int String::LastIndexOf(const String& string, const uint startIndex, const uint length) const
{
	char * last = strstr(&m_string[startIndex], string.m_string);
	char * next = nullptr;
	do
	{
		next = strstr(&last[1], string.m_string);
		if (next != nullptr)
		{
			last = next;
		}
	} while (next != nullptr);
	return  last == nullptr ? -1 : ((last - m_string) > length ? -1 : last - m_string);
}
uint String::PadLeft(const uint totalWidth) // дописать слева кол-во пробелов, чтобы в общем было переданное число. возвращает сколько дописали
{
	return PadLeft(totalWidth, ' ');
}

uint String::PadLeft(const uint totalWidth, const char padCharacter)
{
	int res = totalWidth - m_length;
	if (totalWidth > m_length)
	{
		String temp(padCharacter, res);
		this->Insert(0, temp);
	}
	return (res != totalWidth - m_length) ? res : 0;
}

void String::Remove(const uint startIndex) // удалить фрагмент строки от индекса и до конца
{
	m_length = startIndex;
	m_string[startIndex] = '\0';
}

void String::Remove(const uint startIndex, const uint length)
{
	m_length -= length;
	String temp(m_capacity);
	temp.Assign(m_string, 0, startIndex);
	temp.Append(*this, startIndex + length);
	temp.m_string[m_length] = '\0';
	this->Assign(temp);
	m_string[m_length] = '\0';
}
String String::Substring(const uint startIndex) const // получаем новый объект хранящий подстроку из нашей строки с указанного индекса
{
	return String(*this, startIndex);
}

String String::Substring(const uint startIndex, const uint length) const
{
	return String(*this, startIndex, length);
}

void String::Replace(const char oldCharacter, const char newCharacter)
{
	_strset(m_string, newCharacter);
}
void String::Replace(const String& oldString, const String& newString)
{
	_strset(oldString.m_string, newString.m_string[m_length - newString.m_length]);
}
void String::Reverse()
{
	_strrev(m_string);
}
bool String::StartsWith(const String& string) const
{
	return strcmp(m_string, &string.m_string[m_length - string.m_length]);
}
bool String::StartsWith(const String& string, const bool ignoreCase) const
{
	if (ignoreCase == true)
	{
		return strcmp(m_string, &string.m_string[m_length - string.m_length]);
	}
	else return strncmp(m_string, &string.m_string[m_length - string.m_length], false);
}
void String::ToLower()
{
	for (int i = 0; m_string[i] != 0; i++)
	{
		if (m_string[i] >= 65 && m_string[i] <= 90)
		{
			m_string[i] += 32;
		}
	}
}
void String::ToUpper()
{
	for (int i = 0; m_string[i] != 0; i++)
	{
		if (m_string[i] >= 97 && m_string[i] <= 122)
		{
			m_string[i] -= 32;
		}
	}
}
uint String::Trim()
{
	return Trim(' ');
}

uint String::Trim(const char trimCharacter)
{
	return TrimEnd(trimCharacter) + TrimBegin(trimCharacter);

}

uint String::TrimBegin()
{
	return TrimBegin(' ');
}

uint String::TrimBegin(const char trimCharacter)
{
	uint deleted = 0;
	while (m_string[0] == trimCharacter)
	{
		Remove(0, 1);
		deleted++;
	}
	return deleted;
}

uint String::TrimEnd()
{
	return TrimEnd(' ');
}

uint String::TrimEnd(const char trimCharacter)
{
	uint deleted = 0;
	while (m_string[m_length - 1] == trimCharacter)
	{
		Remove(m_length - 1);
		deleted++;
	}
	return deleted;
}