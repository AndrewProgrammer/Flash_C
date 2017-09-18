#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    cout << Foo<int>::s_count << endl;
    cout << Foo<double>::s_count << endl;

    return 0;
}