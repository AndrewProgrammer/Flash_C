#include "String.h"
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
int main()
{
   /* String str("abcdefabcdef");
    cout << str.IndexOf('b') << endl;*/
	String str("ALELUIAHALELUIAH");
	//cout << str.GetCString() << endl;

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
	cout << "str == str1 =" << (str == str1) << endl; 
	cout << "str != str1 = " << (str != str1) << endl;
	//cout << str2.GetCString() << endl;

	//str.Append(str2, 3, 4);
	//cout << str.GetCString() << endl;

	//str.Assign(str2, 1, 3);
	//cout << str.GetCString() << endl;

	//str.CompareTo(1, str2, 3, 4);
	//cout << str.GetCString() << endl;
	//String s = String::Empty();
	String s5(Create1());
	s5 = Create1();

	String s6("Hello");
	String s7 = move(s6);
	s7 = s5;
    return 0;
}