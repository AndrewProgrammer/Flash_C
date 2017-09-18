#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    Foo obj(100);

    int number = obj;

    cout << number << endl;

    return 0;
}