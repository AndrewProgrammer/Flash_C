#include "String.h"
#include "ArgumentIsNullptrException.h"
#include "ArifmeticException.h"
#include "OutofRangeException.h"
#include "UniquePtrh.h"
#include <iostream>
#include <type_traits>
using namespace std;
String RVO()
{
	return String("Hello");
}

String NRVO()
{
	String a("Hello");

	return a;
}

String Create1()
{
	String result("Hello");

	return result;
}

String* Create2()
{
	String* result = new String("Hello");

	return result;
}

void Foo(String& s)
{
	cout << "Lvalue reference" << endl;
}

void Foo(String&& s)
{
	cout << "Rvalue reference" << endl;
}
void main()
{
	setlocale(0, "ru");
   /* String str("abcdefabcdef");
    cout << str.IndexOf('b') << endl;*/
	/*String str("ALELUIAHALELUIAH");
	cout << str.GetCString() << endl;

	String str1("___BY");
	String SumOf;
	str = str1;
	cout << "str = str1 =" << str.GetCString() << endl;
	SumOf = str + str1;
	cout << "str + str1 = " << SumOf.GetCString() << endl;
	str += str1;
	cout << "str += str1 = " << str.GetCString() << endl;
	cout << "str < str1 =" << (str < str1) << endl;
	cout << "str > str1 =" << (str >str1) << endl;
	cout << "str >= str1 =" << (str >=str1) << endl;
	cout << "str <= str1 =" << (str <= str1) << endl;
	cout << "str == str1 =" << (str == str1) << endl; */
	//cout << "str != str1 = " << (str != str1) << endl;
	//cout << str2.GetCString() << endl;

	/*str.Append(str2, 3, 4);
	cout << str.GetCString() << endl;

	str.Assign(str2, 1, 3);
	cout << str.GetCString() << endl;

	str.CompareTo(1, str2, 3, 4);
	cout << str.GetCString() << endl;
	String s = String::Empty();
	String s5(Create1());
	s5 = Create1();*/

	//String s6("Hello");
	//String s7 = move(s6);
	//s7 = s5;
	try// Move
	{
		String s1;
		String s2(s1);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // operator =
	{
		String s1;
		String s2;
		s1 = s2;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try//method Swap
	{
		String s;
		String s2;
		s.Swap(s2);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try//Parametriziered constructor
	{
		char character;
		cin >> character;
		unsigned int count;
		cin >> count;
		String s1(character, count);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try//Parametriziered constructor
	{
		char * str = new char[21];
		cin.getline(str, 21);
		int length;
		cin >> length;
		String s1(str, length);
		delete[] str;
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try//Parametriziered constructor
	{
		String s2;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		String s1(s2, startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try//operator =
	{
		String s1;
		String s2 ;
		s1 = s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator +=
	{
		String s1;
		String s2 ;
		s1 += s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try//operator +
	{
		String s;
		String s2 ;
		s + s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator >
	{
		String s1;
		String s2 ;
		s1 > s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator <
	{
		String s1;
		String s2 ;
		s1 < s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator >=
	{
		String s1;
		String s2 ;
		s1 >= s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator <=
	{
		String s1;
		String s2 ;
		s1 <= s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator ==
	{
		String s1;
		String s2 ;
		s1 == s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// operator !=
	{
		String s1;
		String s2 ;
		s1 != s2;
	}
	catch (ArifmeticException a)
	{
		a.ErrorArifmetic;
	}
	try// method Append
	{
		String s1;
		String s2;
		s1.Append(s2, -20, -30);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method Assign
	{
		String s1;
		String s2;
		s1.Assign(s2, -20, -30);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method Assign
	{
		String s1;
		String s2;
		s1.Assign(s2, -20, -30);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method CompareTo
	{
		String s1;
		String s2;
		int otherIndex;
		cin >> otherIndex;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.CompareTo(-10,s2, -20, -30);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // method EndsWith
	{
		String s1;
		String s2 ;
		s1.EndsWith(s2);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method EqualsTo
	{
		String s1;
		String s2 ;
		s1.EqualsTo(s2);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method IndexOf
	{
		String s1;
		char character;
		cin >> character;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.IndexOf(character, startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try// method IndexOf
	{
		String s1;
		String s2;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.IndexOf(s2, startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try// method Insert
	{
		String s1;
		String s2;
		int otherIndex;
		cin >> otherIndex;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.Insert(startIndex, s2, otherIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // method LastIndexOf
	{
		String s1;
		char character;
		cin >> character;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.LastIndexOf(character, startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try// method LastIndexOf
	{
		String s1;
		String s2;
		int startIndex;
		cin >> startIndex;
		int length;
		cin >> length;
		s1.LastIndexOf(s2, startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // method PadLeft
	{
		String s1;
		char character;
		cin >> character;
		int length;
		cin >> length;
		s1.PadLeft(length, character);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method PadRight
	{
		String s1;
		char character;
		cin >> character;
		int length;
		cin >> length;
		s1.PadRight(length, character);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method Remove
	{
		int length;
		cin >> length;
		int startIndex;
		cin >> startIndex;
		String s1;
		s1.Remove(startIndex, length);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method Replace
	{
		String s1 ;
		String s2 ;
		s1.Replace(s1, s2);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // method StartsWith
	{
		String s1;
		String s2 ;
		s1.StartsWith(s2);
	}
	catch (ArgumentIsNullptrException a)
	{
		a.ErrorNullptr;
	}
	try // method SubString
	{
		String s1;
		int startIndex;
		cin >> startIndex;
		int lenght;
		cin >> lenght;
		s1.Substring(startIndex, lenght);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method Trim
	{
		char trimcharacter;
		cin >> trimcharacter;
		String s1;
		s1.Trim(trimcharacter);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method TrimEnd
	{
		char trimcharacter;
		cin >> trimcharacter;
		String s1;
		s1.TrimBegin(trimcharacter);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
	try // method TrimBegin
	{
		char trimcharacter;
		cin >> trimcharacter;
		String s1;
		s1.TrimEnd(trimcharacter);
	}
	catch (OutOfRangeException a)
	{
		a.ErrorOutOfRange;
	}
}