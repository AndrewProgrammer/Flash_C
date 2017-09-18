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
    //String s1 = RVO();
    //String s2 = NRVO();

    //String s3 = Create1();
    //String* s4 = Create2();
    //delete s4;

    //Foo(s3);
    //Foo(String("Hello"));
    //Foo(Create1());

    String s5(Create1());
    s5 = Create1();

    String s6("Hello");
    String s7 = move(s6);
    s7 = s5;

    return 0;
}